# Núcleo nativo de protocolo — biblioteca experimental

Esta biblioteca C++17 implementa o fluxo C4 de referência. **Não é uma DLL para
copiar na system**: ainda não possui loader, hooks, callbacks da interface nem
conversão dos pacotes de personagem. Não altera as pastas originais.

## O que está implementado

- ABI C versão 1, sem exceptions atravessando a fronteira; buffers/capacidades explícitos.
- Blowfish de login com palavras externas little endian e chave estática do perfil C4.
- Checksum e alinhamento da rotina nativa C4 `0x103f3d00`.
- Fluxo de login C4: Init → RequestAuthLogin → LoginOk → RequestServerList →
  ServerList → RequestServerLogin → PlayOk, preservando LoginKey/PlayKey.
- Política atual: primeiro servidor anunciado, como no backend, exigindo porta válida e online.
- Estado separado por instância; recusa/capacidade insuficiente não viram sucesso.
- Cifra de jogo por direção com evolução de chave uint64, incluindo carry.
- Conversão estrita de ProtocolVersion 746 para 656 com verificação do bloco inteiro.

`l2k_login_step` recebe **payload já decifrado**, incluindo opcode, e produz
uma resposta cifrada sem cabeçalho TCP. Init é recebido em claro; os posteriores
devem passar por `l2k_login_decrypt`. A extração de frames e a escolha de quando
decriptar ainda cabem ao adaptador de socket. A API de decriptação preserva o
padding: não presume o tamanho semântico nem valida checksum de todas as respostas.

User/password são sequências de bytes de até 14/16 posições. A conversão do
texto Unicode da interface Interlude para o encoding do login C4 ainda deve
ser ligada ao wrapper Windows. Os testes usam apenas credenciais sintéticas.

## Build

No diretório raiz L2Killer:

```sh
python3 research/client-port/native/build.py
research/client-port/venv/bin/python research/client-port/native/inspect_profile.py
research/client-port/venv/bin/python -m unittest discover -s research/client-port -p 'test_*.py' -v
```

Requer clang++ para a biblioteca de testes macOS e i686-w64-mingw32-g++ para
a DLL Windows x86. `constants.inc` é gerado das tabelas matemáticas Blowfish
do backend e do bloco de protocolo previamente conferido.

Saídas em `../build/`:

- `L2KProtocolCore.dll`: PE32 x86, funções exportadas, sem hooks automáticos.
- `libl2k_protocol.dylib`: mesmo código compilado para testes do host.
- `manifest.json`: hashes e indicação explícita de biblioteca experimental.

## Testes executados

21 testes passaram. Entre eles:

- sequência completa de login **sintética**, com chaves cujo byte alto não é zero;
- vetor Blowfish conhecido do backend;
- 81 tamanhos comparando o checksum C++ com a rotina x86 original do C4;
- 110 transformações da cifra Python comparadas com a DLL C4 original e seis seeds;
- 80 transformações do código C++ host comparadas com o modelo validado;
- 18 transformações executando o export **da DLL Windows recém-compilada** em
  Unicorn, conferindo payload, chave, valor de retorno e convenção cdecl.

A emulação exigiu execução fora do sandbox macOS nesta máquina. Não houve
login real nem inicialização desta DLL dentro do jogo.

## Descobertas para os hooks

O dispatch de login Interlude está em `0x104218b0`, com chamada da tabela em
`0x10421b49`. Usa `UNetworkHandler+0x50 == 1` para a fase login. A tabela começa
em `0x10a572c0`, tem 13 entradas; valores >= 0x0c caem no handler de fallback.
O handler 0 é `0x1040be50`, que espera o Init estendido do Interlude.

Socket login: vtable `0x1088b69c`, envio slot `+0x68`, seal `+0x80`, decrypt
`+0x84`. Os slots `+0x78/+0x7c` herdados **não** são o caminho Blowfish de login.
Socket game: vtable `0x1088b52c`, envio `+0x68`, encrypt `+0x78`, decrypt `+0x7c`.
`../native-integration-profile.json` registra RVAs e bytes/pointers esperados.

Próximo passo: wrapper Windows que liga o núcleo aos sockets, preserva o ciclo
de vida e adapta os callbacks/estado do cliente, com instalação por hash e
validação de instruções. Só depois haverá um patch instalável para teste no jogo.

Atualização: `bootstrap.cpp` exporta `l2k_bootstrap`, chamado pelo entrypoint
instrumentado de l2.exe na cópia gerada por `../make_autoload_package.py`.
O carregamento automático é diagnóstico: escreve `L2KProtocol.log`, mas não
instala hooks de rede. Testes emulados não substituem teste real no Windows.

## Build login-hooks-1 (atual)

A DLL agora instala os hooks de LOGIN: Init curto C4, Blowfish, validação de
respostas, LoginOk e integração da ServerList com a UI nativa. A instalação
recusa engine de hash diferente ou ponteiros já alterados. São 27 testes,
quatro deles emulando os hooks efetivos da DLL. O pacote atual é
`../dist/L2Killer-Interlude-LoginTest`; transporte de GAME e personagens ainda
não integrado. As seções anteriores documentam as etapas anteriores.
