# Autenticação e transporte: C4 → Interlude

Escopo confirmado: protocolo primeiro; assets e associação de IDs ficam para outra tarefa.
Esta etapa só leu o backend e os clientes. Nenhuma conexão de login foi aberta.

## Referência recuperada

Backend: `/Users/wenderteixeira/l2g-client/l2g-backend`, commit
`9e5ff22cc8dcd4f458dd4569ac303f2983622db1`, árvore limpa no momento da leitura.
Hashes dos fontes usados em `handshake-evidence.json`.

- `internal/login/client.go`: sequência de login, Blowfish, checksum e padding.
- `internal/login/packets.go`: Init, LoginOk, ServerList, PlayOk e credenciais.
- `internal/netio/blowfish.go`: Blowfish com palavras externas em little endian.
- `internal/netio/crypt.go`: cifra de jogo com chave de oito bytes e estados separados por direção.
- `internal/protocol/packets/client/protocolversion.go`: bloco de 256 bytes.
- `internal/protocol/packets/client/handshake.go`: autenticação no game server e seleção.
- `internal/session/session.go`: versão 656, composição da chave e transições.
- `docs/protocol/deviations.md`: relata que o servidor fecha a conexão sem o bloco de 256 bytes.

O código e os testes foram inspecionados; relatos históricos de captura nos documentos
não equivalem a uma nova validação em rede nesta sessão.

## Fluxo implementado pelo bot

1. Login server envia Init (`0x00`) sem cifra: SessionID e Protocol como dwords.
2. Bot envia RequestAuthLogin (`0x00`) sob Blowfish: username em 14 bytes,
   password em 16 bytes, preenchimento com zeros, byte final `0x08`.
3. LoginOk (`0x03`) fornece LoginKey1 e LoginKey2.
4. RequestServerList (`0x05`), ServerList (`0x04`), RequestServerLogin (`0x02`).
5. PlayOk (`0x07`) fornece PlayKey1 e PlayKey2; a conexão de login é fechada.
6. Nova conexão TCP ao endereço de jogo: ProtocolVersion, ainda sem cifra.
7. Resposta `0x00`: bot lê um byte e quatro bytes de seed; ativa a cifra de jogo.
8. Bot envia `0x08 S(username) d(PlayKey2) d(PlayKey1) d(LoginKey1) d(LoginKey2)`.
9. Recebe lista de personagens (`0x13`), envia seleção (`0x0D`, `cdhddd`).
10. Ao receber CharacterSelected (`0x15`), envia EnterWorld (`0x03` sozinho).

Os opcodes são interpretados pela fase e direção. Os zeros vistos no código são
padding/campos específicos, não uma regra de substituir as chaves de sessão por zero.
LoginKey e PlayKey vêm das respostas do servidor.

## Blowfish de login

Chave estática do código, incluindo o byte NUL final (21 bytes):
`5f3b352e5d39342d33313d3d2d257854215e5b2400`.
Presente no C4 em `0x1092531c` e no Interlude em `0x10a572a8`.
A presença da constante não prova que ambos percorrem a mesma negociação de login.

O bot cifra blocos independentes de 8 bytes, com leitura/escrita de cada palavra
de 32 bits em little endian. Não trocar diretamente por uma biblioteca Blowfish
com representação externa padrão sem conferir o vetor:

`00 01 02 03 04 05 06 07` → `76 b8 d9 08 44 3a 6a 97`.

**Correção importante após conferir a DLL:** o empacotamento descrito abaixo
é o do bot, não o nativo. C4 `0x103f3d00` alinha o payload a 8 e só então soma
8 bytes de reserva. O checksum fica depois de todo o payload alinhado. A fórmula
do bot (`align8(payload+4)`, checksum em `len-8`) sobrescreve parte do payload
quando `len(payload)%8` fica entre 1 e 4, como no RequestServerList de 9 bytes.
A biblioteca C++ usa a fórmula da DLL, conferida por emulação em 81 tamanhos.
Também envia RequestServerList nativo `cddc`, com o byte final 4, confirmado
em `0x103f4672`; não reproduz esse pacote truncado do bot.

Seu empacotamento reserva quatro bytes e alinha o tamanho a oito. O XOR dos dwords
anteriores fica em `len(buffer)-8`; os quatro bytes finais ficam zerados. Reproduzir
o comportamento por pacote: alguns bytes extras dos builders coexistem com essa
reserva, e não convém tratar qualquer trailer como campo semântico.

O frame TCP começa por `uint16 LE(payload_length+2)`, fora da cifra. O bot recebe
Init sem Blowfish e passa a decriptar depois. A forma de Init esperada pelo Interlude
e qualquer caminho alternativo de login ainda precisam ser resolvidos.

## ProtocolVersion confirmado nas duas DLLs

| Evidência | Killer C4 | Interlude |
|---|---|---|
| Revisão embutida | 656 | 746 |
| Rotina de envio | `0x103f2880` | `0x10401dc0` |
| Formato | `cdb` | `cdbd` |
| Payload | 261 bytes | 265 bytes |
| Frame com comprimento | 263 bytes | 267 bytes |
| Opcode | `0x00` | `0x00` |

O bloco não aparece literalmente no arquivo porque a rotina o gera por XOR.
Foi reconstruído das duas engines e é idêntico ao array do backend:
SHA-256 `df28882658a7f6fedc9b8b8e70b41e8b02eae264fae0970b15def91cbfc3cd79`.

`handshake_codec.py` implementa a primeira conversão offline: valida opcode,
versão, comprimento e hash do bloco; troca 746 por 656 e remove o dword final
do layout Interlude. A semântica desse dword ainda não foi nomeada. O teste usa
um valor sintético não zero para garantir que ele não vaze para o payload C4.
`killer-protocol-version.frame.bin` é o frame de referência de 263 bytes.

## Cifra de jogo: incompatibilidade confirmada

| Item | C4/bot | Interlude nativo |
|---|---|---|
| Handler de chave na engine | `0x103fdfe0` | `0x1040d000` |
| Segmento lido na engine | `cddd` | `cQdd` |
| Tamanho da chave | 8 bytes | 16 bytes |
| Índice cíclico | `i & 7` no bot | `i & 15` em `0x10401fd0`/`0x10402070` |
| Estado evolutivo | DLL: soma aos 8 bytes, LE; bot: só aos 4 primeiros | soma tamanho aos 8 últimos bytes, LE |

No bot a chave é `seed[0:4] + A1 6C 54 87`. Na engine C4, o seed passa por
`cdq` antes de `or edx, 0x87546ca1`: um seed com bit de sinal ligado produziria
uma metade alta diferente da constante do bot. O intervalo de seeds do servidor
não foi medido aqui; essa diferença deve ser preservada como questão de teste.

O handler Interlude lê uma região de oito bytes e junta outra região inicializada
com `C8 27 93 01 A1 6C 31 97`. Copia 16 bytes para cada estado de direção.
Transformar somente `cddd` em `cQdd` não torna as cifras equivalentes.
O cabeçalho de comprimento de dois bytes fica fora da cifra nos dois clientes.

Atualização da análise: C4 encrypt `0x103f2aa0` e decrypt `0x103f2b10`
executam ADD/ADC sobre os dois dwords da chave. O bot não propaga esse carry.
`test_native_cipher.py` comparou bytes e chave final em 110 casos contra essas
instruções x86 em Unicorn, além de seis seeds na inicialização real. Todos passaram.
O modelo segue a DLL, inclusive o sinal do seed e o carry de 64 bits.

### Avanço no login Interlude

O caminho encontrado em `0x1040be50` (identificado pela string de diagnóstico
`ProtocolVersionPacket`) lê `dd`, acessa dados 128 bytes depois, lê mais `dddd`
e depois lê uma string limitada em buffer de 17 bytes; passa 16 bytes desse
buffer a `0x10313165` para configurar a cifra. Também muda `socket+0x50B8` para
zero. Evidência em `interlude-1040be50.asm`.

As rotinas `0x10403140` e `0x104031c0` selecionam funções de cifra pelo flag
`+0x50B8`. O RequestAuthLogin Interlude inicializa esse flag e `+0x50BC` com 1.
O caminho C4/bot de Init com só dois dwords não satisfaz diretamente esse caminho
Interlude estendido. Ainda é necessário identificar o dispatch de login e confirmar
eventuais caminhos alternativos; não basta mudar a chave estática existente no arquivo.

### Pontos concretos para integração

- Vtable observada no Interlude: `0x1088b52c`.
- Envio serializado: slot `+0x68` → thunk `0x1030d184` → `0x104029b0`.
- Cifra de envio: slot `+0x78` → thunk `0x1030e408` → `0x10401fd0`.
- Decifra de recepção: slot `+0x7C` → thunk `0x10303116` → `0x10402070`.
- Recepção/encaminhamento: `0x10420e60`, decripta antes de separar opcode e payload.
- Estado de envio no objeto: `+0x50C0`; recepção: `+0x50D1`, cada um com
  byte de estado seguido dos 16 bytes de chave. Flag adicional em `+0x50BC`.

Estes endereços são evidência para planejar hooks, não offsets já seguros para
aplicar um patch. É preciso conferir todos os tipos de socket, convenções de
chamada, limites dos buffers e o momento da troca de estados.

## Diferenças entre bot e cliente que não devem ser apagadas

- AuthLogin de jogo nas duas engines usa `cSddddd`; o bot envia `cSdddd`.
  O dword adicional nativo ainda precisa ser interpretado.
- EnterWorld do bot só tem opcode; as engines enviam blocos adicionais.
  O bot é evidência de um caminho aceito segundo o projeto, não prova de que
  todas as diferenças podem ser truncadas sem efeitos no cliente gráfico.
- Bot aceita ao menos seis bytes no pacote de chave incluindo opcode; o handler
  C4 lê outros dwords. Falta classificar os campos adicionais e o byte de status.
- O catálogo estático não cobre o handshake inteiro: o envio de ProtocolVersion
  e o handler inicial estavam fora da lista de métodos exportados catalogados.

## Validação e próximo passo

Passaram `go test ./internal/netio ./internal/login ./internal/protocol/packets/client`
no backend e os quatro testes offline de `test_handshake_codec.py`.
O backend permaneceu sem alterações.

Próxima implementação: resolver Init/login do Interlude, definir estado por
socket e adaptar o caminho de chave/cifra C4 junto com ProtocolVersion. Só então
testar autenticação e seleção antes de prosseguir com UserInfo/CharInfo.
Não há DLL de migração nem conexão ao servidor validada nesta etapa.

## Atualização: núcleo C++ compilado

Existe agora `build/L2KProtocolCore.dll`, uma biblioteca x86 experimental,
sem hooks nem loader de jogo. Ver `native/README.md`: login sintético completo,
cifra C4, Blowfish e checksum estão implementados. A suíte passou 21 testes,
incluindo execução emulada de um export da DLL gerada. Ainda não é uma DLL de
migração instalável e não houve autenticação real.

Dispatch de login confirmado: função `0x104218b0`, tabela `0x10a572c0`, chamada
`0x10421b49`; handler recebe dois argumentos cdecl, o segundo sem opcode.
Tabela com 13 slots, selecionada por `UNetworkHandler+0x50 == 1`.
Seal/decrypt do socket login estão nos slots `+0x80/+0x84`, não nos slots
da cifra de jogo. Perfil e evidência em `native-integration-profile.json`.
