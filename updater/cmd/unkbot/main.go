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
	base    = "https://raw.githubusercontent.com/w3nder/interlude-to-scions-of-destiny/main/patch/"
	version = "1.0.0"
)

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
		w.Status("Baixando lista de arquivos...")
		m, err := patch.Fetch(base)
		if err != nil {
			w.Failed("Sem acesso ao servidor de atualizacao: " + err.Error())
			return
		}
		plan, err := patch.Plan(m, root)
		if err != nil {
			w.Failed(err.Error())
			return
		}
		if len(plan.Download) == 0 {
			w.Status(fmt.Sprintf("Cliente atualizado (%s). Bom jogo!", m.Build))
			w.Progress(1, 1)
			w.Ready()
			return
		}
		w.Status(fmt.Sprintf("Baixando %d arquivos (%.0f MB)...", len(plan.Download), float64(plan.Bytes)/1048576))
		last := time.Now()
		err = patch.Apply(base, plan, root, func(done, total int64, path string) {
			if time.Since(last) > 150*time.Millisecond || done == total {
				last = time.Now()
				w.Progress(done, total)
				w.Status(fmt.Sprintf("%s  (%.0f/%.0f MB)", filepath.Base(path), float64(done)/1048576, float64(total)/1048576))
			}
		})
		if err != nil {
			w.Failed("Falha na atualizacao: " + err.Error() + "\nSe o jogo estiver aberto, feche e tente de novo.")
			return
		}
		w.Status(fmt.Sprintf("Atualizado para %s. Bom jogo!", m.Build))
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
