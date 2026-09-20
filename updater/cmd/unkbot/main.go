// UnkBot Updater: fica na raiz do cliente Interlude, baixa do repositorio do
// porte os arquivos do patch que estiverem desatualizados e abre o jogo.
package main

import (
	"fmt"
	"os"
	"os/exec"
	"path/filepath"
	"runtime"
	"time"

	"killer/updater/internal/assets"
	"killer/updater/internal/patch"
	"killer/updater/internal/ui"
)

const (
	defaultRepo = "https://raw.githubusercontent.com/w3nder/interlude-to-scions-of-destiny/main/"
	version     = "1.1.0"
)

// UNKBOT_REPO troca a origem (testes contra um servidor local).
var (
	repo      = envOr("UNKBOT_REPO", defaultRepo)
	baseURL   = repo + "base/C6_System_Win10Supported/"
	baseIndex = repo + "base/"  // base/manifest.json
	patchURL  = repo + "patch/" // patch/manifest.json
)

func envOr(name, fallback string) string {
	if v := os.Getenv(name); v != "" {
		return v
	}
	return fallback
}

// A janela Win32 precisa nascer e ser bombeada na MESMA thread do SO; o Go
// migra goroutines entre threads, entao a main fica presa a sua thread.
func init() { runtime.LockOSThread() }

func clientRoot() string {
	if len(os.Args) > 1 {
		return os.Args[1]
	}
	exe, err := os.Executable()
	if err != nil {
		wd, _ := os.Getwd()
		return wd
	}
	return filepath.Dir(exe)
}

func main() {
	root := clientRoot()
	w := ui.New("UnkBot Updater "+version+" — L2Killer", assets.Logo)
	go func() {
		if _, err := os.Stat(filepath.Join(root, "system")); err != nil {
			w.Failed("Coloque o UnkBot Updater na raiz do cliente Interlude (a pasta que contem system/).")
			return
		}
		w.Status("Baixando listas de arquivos...")
		baseM, err := patch.Fetch(baseIndex)
		if err != nil {
			w.Failed("Sem acesso ao servidor de atualizacao: " + err.Error())
			return
		}
		patchM, err := patch.Fetch(patchURL)
		if err != nil {
			w.Failed("Sem acesso ao servidor de atualizacao: " + err.Error())
			return
		}
		// 1) Base: system/ original validada, sem tocar no que o patch substitui.
		owned := map[string]bool{}
		for _, f := range patchM.Files {
			owned[f.Path] = true
		}
		basePlan, err := patch.PlanWith(baseM, root, patch.Options{Prefix: "system/", Skip: owned})
		if err != nil {
			w.Failed(err.Error())
			return
		}
		last := time.Now()
		report := func(label string) patch.Progress {
			return func(done, total int64, path string) {
				if time.Since(last) > 150*time.Millisecond || done == total {
					last = time.Now()
					w.Progress(done, total)
					w.Status(fmt.Sprintf("%s: %s  (%.0f/%.0f MB)", label, filepath.Base(path), float64(done)/1048576, float64(total)/1048576))
				}
			}
		}
		if len(basePlan.Download) > 0 {
			w.Status(fmt.Sprintf("Base Interlude: %d arquivos (%.0f MB)...", len(basePlan.Download), float64(basePlan.Bytes)/1048576))
			if err := patch.ApplyWith(baseURL, basePlan, root, "system/", report("Base")); err != nil {
				w.Failed("Falha na base: " + err.Error() + "\nSe o jogo estiver aberto, feche e tente de novo.")
				return
			}
		}
		// 2) Patch: o porte por cima da base (agora a engine.dll e a validada).
		patchPlan, err := patch.Plan(patchM, root)
		if err != nil {
			w.Failed(err.Error())
			return
		}
		if len(patchPlan.Download) > 0 {
			w.Status(fmt.Sprintf("Patch L2Killer: %d arquivos (%.0f MB)...", len(patchPlan.Download), float64(patchPlan.Bytes)/1048576))
			if err := patch.Apply(patchURL, patchPlan, root, report("Patch")); err != nil {
				w.Failed("Falha no patch: " + err.Error() + "\nSe o jogo estiver aberto, feche e tente de novo.")
				return
			}
		}
		if len(basePlan.Download)+len(patchPlan.Download) == 0 {
			w.Status(fmt.Sprintf("Cliente atualizado (%s). Bom jogo!", patchM.Build))
			w.Progress(1, 1)
			w.Ready()
			return
		}
		w.Status(fmt.Sprintf("Atualizado para %s. Bom jogo!", patchM.Build))
		w.Progress(1, 1)
		w.Ready()
	}()
	if w.Run() {
		exe := filepath.Join(root, "system", "l2.exe")
		cmd := exec.Command(exe)
		cmd.Dir = filepath.Join(root, "system")
		if err := cmd.Start(); err != nil && runtime.GOOS == "windows" {
			fmt.Fprintln(os.Stderr, err)
			os.Exit(1)
		}
	}
}
