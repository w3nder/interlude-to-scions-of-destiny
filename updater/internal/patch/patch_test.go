package patch

import (
	"crypto/sha256"
	"encoding/hex"
	"encoding/json"
	"net/http"
	"net/http/httptest"
	"os"
	"path/filepath"
	"testing"
)

func sha(b []byte) string { s := sha256.Sum256(b); return hex.EncodeToString(s[:]) }

// Servidor falso no lugar do raw.githubusercontent.com: manifest + arquivos.
func server(t *testing.T, files map[string][]byte, engine string) (*httptest.Server, *Manifest) {
	m := &Manifest{Build: "teste", RequiredEngine: engine}
	mux := http.NewServeMux()
	for p, b := range files {
		m.Files = append(m.Files, File{Path: p, Bytes: len(b), SHA256: sha(b)})
		body := b
		mux.HandleFunc("/patch/"+p, func(w http.ResponseWriter, r *http.Request) { w.Write(body) })
	}
	raw, _ := json.Marshal(m)
	mux.HandleFunc("/patch/manifest.json", func(w http.ResponseWriter, r *http.Request) { w.Write(raw) })
	s := httptest.NewServer(mux)
	t.Cleanup(s.Close)
	return s, m
}

func client(t *testing.T, engine []byte) string {
	root := t.TempDir()
	os.MkdirAll(filepath.Join(root, "system"), 0o755)
	os.WriteFile(filepath.Join(root, "system", "engine.dll"), engine, 0o644)
	return root
}

func TestPlanListsOnlyFilesWhoseHashDiffers(t *testing.T) {
	engine := []byte("ENGINE")
	files := map[string][]byte{"system/L2KProtocolCore.dll": []byte("dll-v2"), "system/l2.ini": []byte("ini"), "systextures/x.utx": []byte("utx")}
	s, _ := server(t, files, sha(engine))
	root := client(t, engine)
	os.WriteFile(filepath.Join(root, "system", "l2.ini"), []byte("ini"), 0o644)                 // igual
	os.WriteFile(filepath.Join(root, "system", "L2KProtocolCore.dll"), []byte("dll-v1"), 0o644) // difere
	m, err := Fetch(s.URL + "/patch/")
	if err != nil {
		t.Fatal(err)
	}
	plan, err := Plan(m, root)
	if err != nil {
		t.Fatal(err)
	}
	got := map[string]bool{}
	for _, f := range plan.Download {
		got[f.Path] = true
	}
	if len(plan.Download) != 2 || !got["system/L2KProtocolCore.dll"] || !got["systextures/x.utx"] || plan.Bytes != 6+3 {
		t.Fatalf("plano: %+v", plan)
	}
}

func TestPlanRefusesUnsupportedEngine(t *testing.T) {
	s, m := server(t, map[string][]byte{"system/l2.ini": []byte("ini")}, sha([]byte("OUTRA")))
	_ = s
	if _, err := Plan(m, client(t, []byte("ENGINE"))); err == nil {
		t.Fatal("engine diferente da base validada devia ser recusada")
	}
	if _, err := Plan(m, t.TempDir()); err == nil {
		t.Fatal("pasta sem system/engine.dll nao e um cliente")
	}
}

func TestApplyDownloadsVerifiesAndWritesAtomically(t *testing.T) {
	engine := []byte("ENGINE")
	files := map[string][]byte{"system/L2KProtocolCore.dll": []byte("dll-v2"), "animations/a.ukx": []byte("ukx")}
	s, m := server(t, files, sha(engine))
	root := client(t, engine)
	plan, _ := Plan(m, root)
	var progress []int64
	if err := Apply(s.URL+"/patch/", plan, root, func(done, total int64, path string) { progress = append(progress, done) }); err != nil {
		t.Fatal(err)
	}
	for p, b := range files {
		got, err := os.ReadFile(filepath.Join(root, filepath.FromSlash(p)))
		if err != nil || string(got) != string(b) {
			t.Fatalf("%s: %q %v", p, got, err)
		}
	}
	if len(progress) == 0 || progress[len(progress)-1] != plan.Bytes {
		t.Fatalf("progresso: %v (total %d)", progress, plan.Bytes)
	}
	if left, _ := filepath.Glob(filepath.Join(root, "**", "*.unkbot-tmp")); len(left) != 0 {
		t.Fatalf("temporarios sobrando: %v", left)
	}
	// Segunda passada: nada a baixar.
	plan2, _ := Plan(m, root)
	if len(plan2.Download) != 0 {
		t.Fatalf("depois de aplicar nao deve restar nada: %+v", plan2.Download)
	}
}

func TestApplyRejectsCorruptDownloadAndKeepsOldFile(t *testing.T) {
	engine := []byte("ENGINE")
	s, m := server(t, map[string][]byte{"system/L2KProtocolCore.dll": []byte("dll-v2")}, sha(engine))
	// O manifest promete outro hash: simula download corrompido/MITM.
	m.Files[0].SHA256 = sha([]byte("outro"))
	root := client(t, engine)
	os.WriteFile(filepath.Join(root, "system", "L2KProtocolCore.dll"), []byte("dll-v1"), 0o644)
	plan, _ := Plan(m, root)
	if err := Apply(s.URL+"/patch/", plan, root, nil); err == nil {
		t.Fatal("hash divergente devia falhar")
	}
	got, _ := os.ReadFile(filepath.Join(root, "system", "L2KProtocolCore.dll"))
	if string(got) != "dll-v1" {
		t.Fatalf("arquivo antigo foi sobrescrito por conteudo invalido: %q", got)
	}
}

func TestPathsOutsideTheClientAreRejected(t *testing.T) {
	m := &Manifest{Files: []File{{Path: "../fora.txt", SHA256: sha([]byte("x"))}}, RequiredEngine: sha([]byte("ENGINE"))}
	if _, err := Plan(m, client(t, []byte("ENGINE"))); err == nil {
		t.Fatal("caminho fora da raiz devia ser recusado")
	}
}
