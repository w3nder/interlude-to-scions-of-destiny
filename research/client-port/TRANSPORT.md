# Transporte por socket e formato do futuro gerador

## Implementado nesta etapa

`game_transport.py` é um modelo offline com uma instância por conexão de jogo:

1. `new`: aceita apenas ProtocolVersion Interlude válido para este perfil.
2. `waiting_key`: recebe frames TCP, inclusive fragmentados, e espera o pacote
   C4 completo (opcode + `cddd`, 14 bytes).
3. `ready`: mantém chaves independentes de envio e recepção, cifra/decifra
   payloads e conserva o cabeçalho de comprimento fora da cifra.
4. `failed`/`closed`: invalida as chaves e não aceita continuar a sessão.

O perfil experimental só aceita status=1 e cipher_enabled=1 no pacote de chave.
Esses valores são uma restrição conservadora do modelo, não uma afirmação de
que todos os modos do servidor foram capturados. O dword extra é preservado
na estrutura, com semântica ainda não resolvida. Um pacote reduzido aceito pelo
bot não é tratado como pacote completo do cliente gráfico.

`send()` recebe payload já no formato C4. `receive()` devolve payload C4 em
claro e um evento específico de chave. Não aplica por conta própria conversão
de UserInfo/CharInfo, não repassa a chave de oito bytes ao handler Interlude
de 16 bytes e não envia credenciais. A integração nativa terá que ligar esses
eventos aos handlers corretos e serializar o acesso por socket.

## Validação concluída

- 4 testes de ProtocolVersion/frame.
- 7 testes de estado, fragmentação TCP, frames agrupados, isolamento de
  conexões/direções, overflow, rejeição e EOF truncado.
- 2 testes com a DLL C4 em emulação x86, cobrindo 110 transformações
  de criptografia e seis seeds. Comparam payload **e estado da chave**.
- Payloads da emulação têm de 1 a 8190 bytes, incluindo fronteiras de 8 bytes.
- Incluídos carry do primeiro dword para o segundo, wrap de 64 bits e seed
  com bit de sinal. Foi confirmada uma diferença em relação ao backend Go:
  a DLL evolui a chave como uint64; o bot evolui apenas o primeiro uint32.

O Unicorn abortou durante inicialização de cache sob o sandbox macOS.
Os dois testes nativos passaram executados fora dele, com autorização da
ferramenta. A DLL não foi carregada como programa: só trechos de instruções
foram emulados em memória, sem imports do Windows ou acesso à rede.

## Como será o gerador

O resultado pretendido é um gerador orientado por **perfil de builds**, não
uma conversão universal deduzida automaticamente de quaisquer duas pastas.

```text
system C4 de referência + system Interlude de destino
                + perfil de compatibilidade validado
                              |
                  conferir hashes e pré-condições
                              |
                  compilar/integrar DLL adaptadora
                              |
                  produzir nova pasta de saída
                  + manifesto + hashes + instruções
```

A engenharia reversa das duas systems serve para construir o perfil. Depois
de pronto, o gerador pode precisar só da system Interlude e do perfil: o jogador
não precisa ter Ghidra nem as ferramentas de desenvolvimento. A forma exata de
carregar a DLL e os arquivos alterados ainda dependem da integração nativa.

O perfil registra:

- hashes exatos das engines e demais arquivos realmente modificados;
- RVAs, bytes esperados e convenções de chamada dos hooks;
- estados de login e game, framing e algoritmos de cifra;
- conversões por fase/direção/opcode e subopcode;
- campos adicionais, contadores, limites e recursos ainda não suportados;
- testes executados e versão do patch gerado.

Uma build desconhecida deve ser recusada até ter perfil validado. Mesmo uma
build reconhecida só pode ser anunciada compatível depois dos testes no jogo.
Um PE/DLL estruturalmente válido não prova compatibilidade de protocolo.
Assets e mapeamento de IDs continuam fora desta tarefa.

## Ainda falta antes de gerar um patch jogável

1. Resolver e adaptar o login Interlude estendido para o fluxo C4.
2. Portar o modelo testado para C++ x86 e integrar hooks por tipo de socket.
3. Converter seleção/entrada, UserInfo, CharInfo e demais pacotes necessários.
4. Validar no Windows/Wine e depois empacotar o resultado.

Não há conversor universal, DLL instalável nem autenticação real validada
nesta etapa. Os módulos Python são referência executável para a integração.
