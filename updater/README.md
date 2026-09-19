# UnkBot Updater

Launcher/atualizador do porte para Windows. Fica na **raiz do cliente Interlude**
(a pasta que contem `system/`), baixa do repositorio os arquivos de `patch/`
que estiverem diferentes (por SHA-256), confere cada download antes de trocar
o arquivo e abre `system/l2.exe`.

Uso pelo jogador: copiar `dist/UnkBot Updater.exe` para a raiz do cliente
(base `C6_System_Win10Supported`) e abrir. Na primeira vez baixa ~200 MB; nas
seguintes so o que mudou (normalmente a DLL e alguns DATs).

Regras de seguranca: recusa clientes cuja `system/engine.dll` nao seja a base
validada; nunca grava fora da raiz; grava em `.unkbot-tmp` e so renomeia com o
hash conferido; se o jogo estiver aberto a troca falha e o updater pede para
fechar.

Compilar (macOS/Linux, sem cgo):

    cd updater && GOOS=windows GOARCH=amd64 go build -trimpath -ldflags "-H windowsgui -s -w" -o "dist/UnkBot Updater.exe" ./cmd/unkbot

Testes: `go test ./...` (a logica de atualizacao roda em qualquer sistema; a
janela Win32 so compila para Windows). O repositorio precisa ser publico para o
`raw.githubusercontent.com` servir o `patch/`.
