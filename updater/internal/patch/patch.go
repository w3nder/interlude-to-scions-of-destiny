// Package patch aplica o patch do porte (patch/manifest.json do repositorio)
// sobre um cliente Interlude: baixa so o que difere por SHA-256, confere cada
// arquivo antes de trocar e nunca deixa um arquivo pela metade no cliente.
package patch

import (
	"crypto/sha256"
	"encoding/hex"
	"encoding/json"
	"errors"
	"fmt"
	"io"
	"net/http"
	"os"
	"path"
	"path/filepath"
	"strings"
	"time"
)

type File struct {
	Path   string `json:"path"`
	Bytes  int    `json:"bytes"`
	SHA256 string `json:"sha256"`
}

type Manifest struct {
	Build          string `json:"build"`
	RequiredEngine string `json:"required_engine_sha256"`
	Files          []File `json:"files"`
}

type Update struct {
	Manifest *Manifest
	Download []File
	Bytes    int64
}

type Progress func(done, total int64, path string)

var httpClient = &http.Client{Timeout: 10 * time.Minute}

// Fetch le o manifest em <base>manifest.json (base termina em /).
func Fetch(base string) (*Manifest, error) {
	resp, err := httpClient.Get(base + "manifest.json")
	if err != nil {
		return nil, err
	}
	defer resp.Body.Close()
	if resp.StatusCode != 200 {
		return nil, fmt.Errorf("manifest: HTTP %d", resp.StatusCode)
	}
	var m Manifest
	if err := json.NewDecoder(io.LimitReader(resp.Body, 4<<20)).Decode(&m); err != nil {
		return nil, fmt.Errorf("manifest: %w", err)
	}
	if len(m.Files) == 0 || m.RequiredEngine == "" {
		return nil, errors.New("manifest: vazio ou sem engine exigida")
	}
	return &m, nil
}

func fileSHA(p string) (string, error) {
	f, err := os.Open(p)
	if err != nil {
		return "", err
	}
	defer f.Close()
	h := sha256.New()
	if _, err := io.Copy(h, f); err != nil {
		return "", err
	}
	return hex.EncodeToString(h.Sum(nil)), nil
}

// safePath garante que o caminho do manifest fica dentro da raiz do cliente.
func safePath(root, rel string) (string, error) {
	clean := path.Clean("/" + strings.ReplaceAll(rel, "\\", "/"))
	if clean == "/" || strings.Contains(rel, "..") {
		return "", fmt.Errorf("caminho invalido no manifest: %q", rel)
	}
	return filepath.Join(root, filepath.FromSlash(clean[1:])), nil
}

// Plan confere a base do cliente e decide o que precisa ser baixado.
func Plan(m *Manifest, root string) (*Update, error) {
	engine := filepath.Join(root, "system", "engine.dll")
	got, err := fileSHA(engine)
	if err != nil {
		return nil, errors.New("esta pasta nao parece ser a raiz de um cliente Interlude (system/engine.dll nao encontrado)")
	}
	if got != m.RequiredEngine {
		return nil, errors.New("este cliente nao e a base validada do porte (system/engine.dll difere); use a system C6_System_Win10Supported")
	}
	p := &Update{Manifest: m}
	for _, f := range m.Files {
		dst, err := safePath(root, f.Path)
		if err != nil {
			return nil, err
		}
		if cur, err := fileSHA(dst); err == nil && cur == f.SHA256 {
			continue
		}
		p.Download = append(p.Download, f)
		p.Bytes += int64(f.Bytes)
	}
	return p, nil
}

// Apply baixa cada arquivo do plano para <destino>.unkbot-tmp, confere o
// SHA-256 e so entao renomeia por cima do original.
func Apply(base string, p *Update, root string, progress Progress) error {
	var done int64
	for _, f := range p.Download {
		dst, err := safePath(root, f.Path)
		if err != nil {
			return err
		}
		if err := os.MkdirAll(filepath.Dir(dst), 0o755); err != nil {
			return err
		}
		tmp := dst + ".unkbot-tmp"
		if err := download(base+f.Path, tmp, f.SHA256, func(n int64) {
			if progress != nil {
				progress(done+n, p.Bytes, f.Path)
			}
		}); err != nil {
			os.Remove(tmp)
			return fmt.Errorf("%s: %w", f.Path, err)
		}
		if err := os.Rename(tmp, dst); err != nil {
			os.Remove(tmp)
			return fmt.Errorf("%s: %w", f.Path, err)
		}
		done += int64(f.Bytes)
		if progress != nil {
			progress(done, p.Bytes, f.Path)
		}
	}
	return nil
}

func download(url, tmp, want string, tick func(n int64)) error {
	resp, err := httpClient.Get(url)
	if err != nil {
		return err
	}
	defer resp.Body.Close()
	if resp.StatusCode != 200 {
		return fmt.Errorf("HTTP %d", resp.StatusCode)
	}
	out, err := os.Create(tmp)
	if err != nil {
		return err
	}
	h := sha256.New()
	buf := make([]byte, 256<<10)
	var n int64
	for {
		k, rerr := resp.Body.Read(buf)
		if k > 0 {
			if _, err := out.Write(buf[:k]); err != nil {
				out.Close()
				return err
			}
			h.Write(buf[:k])
			n += int64(k)
			tick(n)
		}
		if rerr == io.EOF {
			break
		}
		if rerr != nil {
			out.Close()
			return rerr
		}
	}
	if err := out.Sync(); err != nil {
		out.Close()
		return err
	}
	if err := out.Close(); err != nil {
		return err
	}
	if got := hex.EncodeToString(h.Sum(nil)); got != want {
		return errors.New("download corrompido (SHA-256 nao confere)")
	}
	return nil
}
