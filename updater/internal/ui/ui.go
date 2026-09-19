// Package ui e a janela do updater. A implementacao Win32 fica em win.go;
// nas outras plataformas (testes e build no macOS) sobra um console.
package ui

// Window recebe status e progresso da atualizacao e devolve a decisao do
// jogador (jogar/fechar) por Done.
type Window interface {
	Status(text string)
	Progress(done, total int64)
	// Ready libera o botao Jogar; Failed mostra o erro e deixa so Fechar.
	Ready()
	Failed(text string)
	// Run bloqueia ate a janela fechar; devolve true se o jogador pediu Jogar.
	Run() bool
}
