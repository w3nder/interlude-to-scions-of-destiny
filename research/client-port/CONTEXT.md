# Port do cliente L2Killer

## Objetivo confirmado pelo usuário

Adaptar o cliente de destino `/Users/wenderteixeira/Desktop/system-1` para falar
com o servidor atual do L2Killer C4 e aproveitar sua interface/visual.
O trabalho é apenas no cliente; não depende de acesso ao código do servidor.

## Evidências recuperadas em 2026-09-17

- Origem: `/Users/wenderteixeira/Documents/L2Killer/system`.
- Destino: `/Users/wenderteixeira/Desktop/system-1`.
- Patch anterior: https://github.com/w3nder/l2killer-interface.
- Catálogo: https://interface.unkbot.com/packets/L2Killer-opcodes.json.
- Cópia local do catálogo: `L2Killer-opcodes.json`.
- O SHA-256 da engine.dll de origem coincide exatamente com o catálogo.
- Catálogo contém 213 pontos de envio e 304 registros de recepção, não
  necessariamente opcodes únicos. Extração estática; não é uma especificação
  completa. Fases de sessão e subopcodes estendidos de saída não resolvidos.
- Identidade dos seis binários principais registrada em `inventory.json`.
- Destino tem interface.u e interface.xdat, com binários datados de 2007;
  identificação exata do protocolo ainda precisa ser feita.
- Ghidra headless disponível em
  `/opt/homebrew/opt/ghidra/libexec/support/analyzeHeadless`.
- Compilador disponível: `/opt/homebrew/bin/i686-w64-mingw32-g++`.

## Extração e comparação realizadas

- Scripts reproduzíveis: `extract_protocol.py`, `compare_protocols.py`.
- Destino: `system-1-opcodes.json`, 237 pontos de envio e 341 registros de
  recepção (255 primários e 86 estendidos).
- Reextração C4 reproduziu todos os 304 registros e 211 dos 213 envios do
  catálogo original, sem diferenças de opcode/formato nesses 211 envios.
  O percurso dos exports não recuperou ValidatePosition e VoteSociality.
- Há sete divergências de segmentos de leitura no catálogo antigo; por
  exemplo, MoveToLocation incluía uma chamada da função seguinte.
- Comparação e limitações: `COMPARISON.md` e `comparison.json`.
- Ghidra decompilou UIPacket/CIPacket do destino em `decompiled/`.
- Decoder do destino: thunk 0x103034e5 -> 0x104026b0. Q copia 8 bytes;
  evidência em `decoder-Q-evidence.txt`.
- RequestEnterWorldPacket mantém opcode 0x03, mas muda de `cbdddd` no C4
  para `cbddddbdcccccccccccccccccccc` no destino. Requer análise dos campos.

## Referência Interlude adicional

Usuário forneceu `/Users/wenderteixeira/Desktop/C6_System_Win10Supported`
como system original do Interlude. Engine.dll é idêntica à system-1, assim
como os catálogos extraídos. L2.exe, Core.dll, IpDrv.dll, interface.u e
interface.xdat também são idênticos. Nwindow.dll difere em dois bytes e
Fire.dll difere em tamanho/conteúdo. Não foi verificada autenticidade de
distribuição oficial. Inventário em `interlude-reference-inventory.json`.

## Próxima etapa técnica

Atualização: usuário forneceu o backend Go em
`/Users/wenderteixeira/l2g-client/l2g-backend` para protocolo/autenticação e
confirmou que assets/IDs são outra tarefa. Ver `AUTHENTICATION.md`.
Backend limpo, commit `9e5ff22cc8dcd4f458dd4569ac303f2983622db1`.
ProtocolVersion: C4 656/cdb; Interlude 746/cdbd. Bloco de 256 bytes foi
reconstruído por XOR nas duas DLLs e coincide com o backend.
Primeiro conversor offline em `handshake_codec.py`, quatro testes passando.
Cifra de jogo exige adaptação: 8 bytes no C4/bot, 16 no Interlude, com
atualização de chave em posições diferentes. Pontos de entrada mapeados no
documento. Blowfish de login do bot validado pelos testes existentes; Init
e caminho de login nativo Interlude ainda não totalmente resolvidos.

Resolver handshake e campos de entrada no mundo/seleção de personagem.
Definir hooks com base nos endereços do destino, incluindo conversão de
payload quando necessária. Formatos iguais não provam semântica igual.
Primeiro marco: conexão, seleção de personagem, entrada no mundo e movimento.
Não assumir que endereços ou hooks do patch C4 servem no destino.

Nenhum binário foi alterado e nenhuma compatibilidade em execução foi validada.

## Etapa de transporte concluída (offline)

Ver `TRANSPORT.md`. `game_transport.py` implementa framing incremental,
negociação C4 restrita e cifra com estado por socket/direção. 11 testes Python
e 2 testes nativos passaram; os nativos incluem 110 transformações e seis seeds.
Unicorn precisou executar fora do sandbox macOS por falha de inicialização de cache.
Nova evidência: DLL C4 soma o tamanho à chave inteira uint64 (ADD/ADC), enquanto
o bot só soma ao primeiro uint32. Modelo segue DLL. Cifra em 0x103f2aa0/0x103f2b10.

Login Interlude: 0x1040be50 lê Init estendido, além dos dois dwords do C4;
flags +0x50B8 e +0x50BC selecionam o caminho da cifra. Mais detalhes em
AUTHENTICATION.md. Dispatch/alternativas de login ainda pendentes.

Usuário perguntou pelo produto final: gerador de patch por perfil de builds,
com hashes e pré-condições, saída em nova system e DLL adaptadora. Não é
conversor universal entre quaisquer duas systems. Esse gerador ainda não foi
implementado; primeiro é necessário fechar o caminho de compatibilidade.

## Núcleo C++ e login — etapa mais recente

Código em `native/`, compilação `python3 research/client-port/native/build.py`.
Gerou `build/L2KProtocolCore.dll` (Windows x86) e dylib de testes. Não instala
hooks e não deve ser copiada na system como patch pronto. API implementa
Blowfish C4, checksum, estados do login sintético até PlayOk, cifra de jogo
e ProtocolVersion. 21 testes passaram, inclusive export da DLL gerada em x86.

Diferença adicional do bot: checksum pode sobrescrever cauda de payloads
curtos. A DLL nativa alinha payload8 e soma8; fonte `0x103f3d00`. C++ segue DLL,
conferido em 81 comprimentos emulados. Backend original não foi modificado.

Dispatch login Interlude confirmado em `0x104218b0`, tabela `0x10a572c0`
(13 slots, fallback 0x0c), chamada cdecl em `0x10421b49`, payload sem opcode.
Login vtable `0x1088b69c`: send +0x68, seal +0x80, decrypt +0x84.
Não usar os slots de game herdados +0x78/+0x7c para Blowfish login.
Perfil em `native-integration-profile.json`; detalhes em `native/README.md`.

Próximo: wrapper Windows, instalação por build/hash, ciclo de vida de socket
e ligação dos callbacks/estado do Interlude ao login C4. Depois pacotes de
personagem e teste real. Assets continuam fora de escopo.

## Carregamento automático e l2.ini — 17/09/2026

`make_autoload_package.py` produz `dist/L2Killer-Interlude-Test.zip`, cópia
completa de Desktop/system-1, sem alterar originais. l2.exe recebe seção .l2k,
import estático de L2KProtocolCore.dll!l2k_bootstrap e stub de entrada PIC.
Hash exato obrigatório, imports anteriores preservados, backup exe/ini incluído.
Bootstrap executa fora de DllMain e escreve L2KProtocol.log ao lado do exe;
retorna ao entrypoint original preservando registradores/flags. Ainda sem hooks.
Sem teste real de abertura Windows; stub validado em Unicorn em duas bases.
23 testes passaram. Próximo: ligar callbacks e estados do login C4.

`ini_codec.py`: Ver413, RSA blocos alinhados à direita em múltiplos de4,
zlib estrito e cauda CRC32. Todas as três INIs fizeram roundtrip completo.
Killer ServerAddr=server.l2killer.org; system-1=L2Doll.mooo.com;
referência Interlude=127.0.0.1. Port=7777 em todos, preservado (não inferir
que seja porta de autenticação). Pacote muda somente ServerAddr no plaintext.
Formato consultado em https://github.com/ritsuwastaken/open-l2encdec/src/rsa.cpp

## Login com hooks reais — versão login-hooks-1

Implementação `native/login_hooks.cpp`: modifica 5 slots após conferir SHA256
da engine e os ponteiros relocados. Substitui receive completo de login,
seal/decrypt Blowfish, dispatch Init e LoginOk. Intercepta frames completos
via vtable +0x74; valida formato, checksum e limites antes da fila nativa.
Init curto envia credenciais da UI (UTF16->ACP, sem substituição) no layout C4.
LoginOk preserva as duas chaves e chama RequestServerList nativo; ServerList
com entradas21bytes segue para o handler/GUI Interlude. Sem log de credenciais.
Receive evita decriptação dupla durante a cópia para a fila de UI.

27 testes passaram, incluindo quatro testes que executam as funções dos hooks
na DLL x86 compilada com bordas OS/UI simuladas. Não equivale a login real.
Hooks de jogo AINDA PENDENTES: objetivo de validação desta build é ServerList.
Não afirmar que login/seleção/entrada no mundo funcionaram antes de testar.

Pacote `dist/L2Killer-Interlude-LoginTest` usa a referência limpa C6 porque
leituras de Desktop/system-1 travaram repetidamente. Engine/l2.exe têm hashes
iguais ao alvo validado. `install_test_system.py` instala no cliente completo
Downloads/Lineage2_Interlude_Client, com backup e staging verificados.
Usuário autorizou abrir pelo Wine e baixar Wine se ausente. Whisky instalado
sem runtime, endpoint antigo404. Wine11.0_1 baixado do Gcenx/macOS_Wine_builds,
URL/checksum conferidos no cask oficial Homebrew (sha256 b50dc50ec7f41d58b115a6b685d4d1315ba3c797bd3aa0f49213f2703cb82388).

Instalação e abertura concluídas: system instalada em
/Users/wenderteixeira/Downloads/Lineage2_Interlude_Client/system;
backup system.before-l2k-20260917-020505. Wine11.0_1 runtime extraído e hash
verificado em build/wine-runtime, prefix independente build/wine-prefix.
Executável aberto pelo Wine (sessão85803). Log real do cliente confirmou:
DLL loaded; build=login-hooks-1; ABI=1
hooks=login_active; C4 Init/Blowfish/LoginOk integrated; game hooks pending
Ainda sem tentativa de autenticação; depende de usuário inserir sua conta.
Wine log contém warnings OpenGL e GL_INVALID_FRAMEBUFFER_OPERATION na abertura;
não houve ainda confirmação visual pela ferramenta (CUA surfaces indisponível).
Atalho reutilizável Abrir-Interlude.command no diretório client-port.

## Validação real reportada pelo usuário

Após abrir esta build pelo Wine, usuário confirmou: entrou no game e está
movimentando o personagem. Leitura do L2KProtocol.log confirmou, na execução:
Init9 -> AuthLogin32 -> LoginOk(op03,48 bytes cifrados) -> RequestServerList10
-> ServerList(op04,56 bytes cifrados) -> RequestServerLogin10 -> PlayOk(op07,
24 bytes cifrados). Uma tentativa anterior teve opcode01 (recusa de login).
Não registrar/solicitar credenciais. Log não contém credenciais/chaves.

A DLL instalada continua SOMENTE com hooks de login. Entrada no mundo e
movimento são observação do usuário, não captura do protocolo de game.
Isso invalida a suposição operacional de que necessariamente seria preciso
adaptar o transporte de jogo antes de qualquer entrada. Hipótese: o endpoint
aceita o caminho Interlude; ainda não comprovada. Preservar a build funcional
e investigar por observação antes de instalar conversões de game desnecessárias.
Não afirmar compatibilidade de todos os pacotes, inventário, skills ou combate.

## Automação, clã e filtro — build login-hooks-3-clan

Usuário confirmou login/entrada/movimento/skills/chat; clã não mostra informações.
Pediu automatizar a migração/testes para não testar manualmente todos os pacotes,
e bloquear funções exclusivas do Interlude que o servidor C4 não suporta.

`port_client.py package` gera seletores/política, compila, roda suíte e empacota;
`reports/coverage.json` enumera577 unidades, separando adaptação/bloqueio/passthrough
(evidência estática nunca é marcada como compatibilidade semântica provada).
39 testes passaram. Casos incluem100 listas geradas, truncamentos/Unicode/limites,
65.536 subopcodes contra política e execução dos wrappers x86 usando a cifra
nativa Interlude (bytes e evolução da chave iguais). Documentação AUTOMATION.md.

`native/clan_codec.cpp`: converte estritamente S2C53/54/55 C4→IL. 53 insere
main/sub=0 e pledgeType=0 em torno do clanID, mais sponsor0 em cada membro.
54 acrescenta pledgeType0+sponsor0;55 pledgeType0. Campos compartilhados mantidos.
Valida pacote completo e reconhece layout moderno para evitar conversão dupla.
Teste encontrou ambiguidade de header em lista vazia; corrigido com flags
main/sub e pledgeType do header Interlude. Layout inválido nos3opcodes é descartado
com diagnóstico antes do parser nativo. Demais opcodes seguem originais.

`native/game_trace.cpp`: hooks vtable game +68 sender, +74 receive, +78/+7c
cipher observadores. Sender serializa com rotina nativa e passa payload 'b'
ao sender original depois do filtro. Receive decifra uma vez pelo nativo,
converte clã se necessário e chama fila nativa com flag de cifra temporariamente0.
Cifra original (16bytes IL) e transporte de game preservados. Metadados de
trace L2KGameTrace-<PID>.tsv; sem payload/chat/credenciais/chaves; limite50k linhas.

`derive_outbound_policy.py` confirma hashes e resolve subopcode pelo push anterior
ao pushD0 nos callsites. Filtro `outbound_denied.inc` bloqueiaD0:0019–001E e0024:
academia master/pupil, grades/poderes/detalhes de membro, warlist e reorganização.
Bloqueio é antes da cifra/send. Todos os seletores C4 observados têm teste de
permissão. Outras novidades não resolvidas ficam no relatório, sem bloqueio por
simples ausência num catálogo parcial. NÃO afirmar filtro de todas as novidades.

Pacote dist/L2Killer-ClanPatch-834676a5.zip e pasta de mesmo nome.
DLL SHA256 834676a5f178374ef062b5592b472625ee153b53852b2bacf2061196965fd8a5.
Instalada atomicamente em Downloads/Lineage2_Interlude_Client/system (script
install_protocol_update.py), backup L2KProtocolCore.before-clan-20260917-023623.dll.
Baseline98dffa5... preservada também build/baseline-login-hooks-1.
Sem confirmação visual de clã corrigido ainda. Usuário autorizou abrirWine ao
final. Verificação ps não encontrou l2.exe; nova abertura sendo iniciada.
Nova abertura Wine concluída (sessão12713). Log real confirmou
DLL loaded; build=login-hooks-3-clan; ABI=1 e game_adapter=active.
Trace iniciado em system/L2KGameTrace-224.tsv. Usuário disse que vai abrir;
foi avisado que já iniciamos para não duplicar instâncias. Ainda aguardando
login e validação do clã nesta versão. Linha antiga de login menciona game
hooks pending, mas linha subsequente game_adapter=active é a situação atual.
A sessão nova já autenticou e gerou tráfego real de game: primeiro payload
plaintext opcode00 tem23bytes; AuthLogin game08 tem41bytes; lista personagens
13 tem344bytes; selected15 tem289bytes. Depois mais de1600 eventos, incluindo
movimento/NPC/CharInfo. Cipher original continuou funcional com os wrappers.
No snapshot inicial não havia53/54/55; havia34 ocorrências83 (PledgeInfo).
Não afirmar conversão real de clã validada: aguardando pacote/lista de membros.
Snapshot sem payload em reports/live-clan-observation.json.

## Atualização 2026-09-17 — autonomia, lote e incidente

- Usuário confirmou clã funcionando na build 834676a5; quer execução autônoma e teste manual somente ao final. Aprovações do sandbox continuam obrigatórias.
- Gerador resolveu os 19 seletores D0 compartilhados (mesmos valores), expandiu bloqueio de 7 para 28 solicitações Interlude e identificou 25 pares de handlers sem leitura de payload.
- Ghidra exportou 79 handlers de cada cliente em decompiled/batch; scriptPath isolado em ghidra-scripts evita seguir o symlink z: do Wine ao varrer scripts.
- schema_codec.cpp adiciona 10 conversores: ItemList/InventoryUpdate, SkillList/GMViewSkillInfo, PetStatusUpdate, ExEnchantSkillList/Info, FishingStart/StartCombat/HpRegen. Junto com clã são 13. Todos preservam layouts modernos reconhecidos.
- Inventário: C4 já possui type1 (h) e InventoryUpdate possui change/type1 (hh); chamadas estavam ausentes no catálogo, recuperadas por decompilação. Acrescenta augmentation=0 e shadow duration=-1. PetInventoryUpdate tem a mesma leitura completa: não precisa inserir h/hh.
- Usuário relatou crash na sessão real durante o trabalho. Build carregada era 834676a5; logs preservados em build/incidents/20260917-041001. Últimos C2S: 21 (bypass), último S2C: 2D; log mostra frame inválido sem tamanho, Wine mostra espera WINMM_cs. Causa ainda NÃO comprovada. Pergunta assíncrona sobre ação exata enviada, sem resposta até esta anotação.
- Corrigido defeito independente: hook rejeitava frames >8192 ANTES da cifra, perdendo sua sequência. Agora aceita frame válido até65535, converte com capacidade limitada a65533, registra tamanhos recebido/declarado em rejeições e trace suporta grandes frames. Teste x86 garante uma chamada de decrypt e entrega do frame9002 seguido de frame4.
- 47 testes passaram, artefato dist/L2Killer-ProtocolPatch-9bd942c5.zip, DLL SHA256 9bd942c569776bc94f756f41e7778a0db0c253f343ad50b16e60a715a09a250b. Build protocol-hooks-4-schemas.
- --require-complete recusa corretamente declarar migração total. Cobertura semântica de todos os demais pacotes ainda pendente; não confundir extração/decompilação com implementação validada.
- Ver build/last-update.json para confirmação da instalação e backup; a DLL substituída atomicamente vale na próxima abertura, sem alterar processo existente.

### Confirmação em jogo após atualização

- DLL 9bd942c5 instalada com backup before-protocol-20260917-041541.dll.
- Primeira reabertura encerrou antes de login com erro SEH Wine; segunda, com WINEDEBUG=+seh, entrou e usuário confirmou: "fiz a mesma acao e agora nao travou". Não interromper a sessão atual (trace PID272).
- Isso valida o cenário reproduzido, não comprova causa exclusiva nem cobertura total. Log +seh contém registros de exceções e pode ser mais verboso nesta sessão; launcher normal não mantém WINEDEBUG.
- pgrep com padrão wine.*l2.exe NÃO é teste confiável de processo encerrado: o processo pode mudar o título para l2.exe. Na segunda tentativa deu negativo apesar de jogo ativo.
- Trace por PID usa CREATE_ALWAYS: PID reutilizado sobrescreve trace antigo; preservar snapshots antes de relançar e trocar futuramente por nome PID+tick/CREATE_NEW. Trace224 antigo foi sobrescrito na primeira tentativa; trace296 do incidente preservado.

- Evidência adicional do cenário corrigido: trace272 sequência356 recebeu S2C0F (HTML de NPC) com13035 bytes; excedia o limite8192 da DLL anterior. O frame agora chega ao cliente e o usuário repetiu a ação sem crash. Forte evidência do defeito de framing/cifra como causa deste cenário. Snapshot no incidente.

## Atualização 2026-09-17 — catálogo completo por variante, build 5

- Usuário reforçou: não basta número do opcode, precisa do catálogo/estrutura. Considerar campos, ordem, tipos, tamanhos, listas, condições, blocos fora do decoder e semântica. Nunca promover similaridade estática a compatibilidade comprovada.
- Permissões atuais: danger-full-access, approval never. Anotações antigas sobre sandbox/solicitar aprovação estão obsoletas. Nenhum subagente autorizado.
- Implementado native/structured_codec.cpp: 23 conversores S2C adicionais + validador SystemMessage64. Inclui CharacterSelection13, CharacterSelected15, TargetSelected29/Unselected2A/MyTargetA6, Door4C, FlyC5, CameraC7, PledgeStatusCD, EtcF3, Warehouse41/42, GMitems94/95, Shortcuts44/45, MultiSellD0, GMclan90, AskJoinPledge32, Npc16, PetB1, ExAskJoinMPCC FE27, ConfirmDlgED. Detalhes/limites em structured-inbound.json. Total 36 conversores S2C com os 13 anteriores.
- IMPORTANTES: GMwarehouse95 tem linha condicional type1<4, recuperada por assembly pois Ghidra eliminou ramo. CharacterSelected15 tem blob e grupos condicionais; preservar ambos. Campos novos sem equivalente C4 recebem defaults explícitos, mas parte da semântica ainda requer validação; testes de layout não provam todas as telas.
- C2S: RequestJoinPledge24 remove pledgeType=0 e bloqueia subunidades; MultiSellA7 preserva list/entry/amount e remove duas extensões zeradas (bloqueia não-zero); ConfirmDlgC5 remove requestorID extra. outbound-schemas.json contém regras. Hook aplica antes de cifra/envio.
- Trace agora PID+tick com CREATE_NEW para não sobrescrever sessão anterior.
- 60 testes passaram usando research/client-port/venv/bin/python. Python global não tem pefile/unicorn; usar venv. Novos testes incluem arrays de equipamento/XP, blobs/listas condicionais, parâmetros tipados, truncamentos, capacidade, Unicode, 1000 entradas aleatórias e sequência receive/decrypt/rejeição/receive na DLL x86, além dos C2S antes do sender.
- Pacote dist/L2Killer-ProtocolPatch-6f710c50.zip. DLL 6f710c50cac23556bc6a8212718be31ab01705dc69851b7fd50f369e953e25dc, build protocol-hooks-5-structured. Instalado atomicamente em Downloads/Lineage2_Interlude_Client/system com backup L2KProtocolCore.before-protocol-20260917-044016.dll (9bd942c5).
- Jogo ATIVO PID host10385; não reiniciado nem interrompido. Nova DLL vale na próxima abertura. `ps -axo pid=,comm=` encontra l2.exe mesmo quando não aparece wine no nome.
- Relatório continua release_complete=false; próximos alvos críticos: CharInfo03, UserInfo04, GMUser8F, Quest80 (C4 lista de quest items vs IL bitmap128), Ride86 (coords), ManagePledgePower30 (array32 vs máscara + semântica de ações), FE30 commandchannel. C2S EnterWorld03, JoinPartyRoom71 e PledgePowerC0 continuam com diferenças pendentes; não modificar às cegas.
- Backend existente fornece campo a campo em /Users/wenderteixeira/l2g-client/l2g-backend/internal/protocol/packets/server/{charinfo.go,userinfo.go}. Ler como evidência complementar, engine exato prevalece. CharInfo C4 11 slots visíveis; IL 12 +24h augmentation. UserInfo C4 16 slots por array, IL17 +34h; C4 tem bloco32bytes de privilégios fora das chamadas decoder, IL máscara d. Catálogo original omite essas leituras.
- Decompilados 79 handlers S2C por lado em decompiled/batch; 6 métodos C2S por lado em decompiled/outbound. Caminho Ghidra scripts isolado evita varredura recursiva do Wine z:.

## ATENÇÃO — regressão de entrada e rollback, 2026-09-17 04:45

- Usuário: "agora parou de entrar no mundo". Causa confirmada no trace da build5: `S2C15 after_decrypt` de281/289bytes seguido de `rejected_schema_layout`; pacote nunca chegava à fila nativa. Fixtures do parser CharacterSelected não representavam a variante do servidor. Não repetir a alegação de catálogo totalmente validado por testes sintéticos.
- Rollback ATÔMICO feito para DLL9bd942c5 (protocol-hooks-4-schemas). Incidente preservado em build/incidents/20260917-044534-world-entry, com DLL rejeitada e traces só de metadados.
- Usuário reabriu o jogo durante o trabalho. Não foi necessário matar nenhum processo: PID27971 já havia saído quando conferido; novo PID28645 estava aberto. Log confirmou build4 carregada. Trace L2KGameTrace-308.tsv posteriormente contém S2C15, C2S03 EnterWorld, S2C04 UserInfo e milhares de S2C03; fluxo de mundo voltou. Não afirmar teste visual pelo agente.
- Build6f710c50 foi marcada withdrawn_live_regression no manifest e ZIP refeito; install_protocol_update.py também recusa explicitamente esse hash. Converter15 candidato está desativado, retornando0/passthrough; draft parser mantido [[maybe_unused]] para pesquisa. structured-inbound.json marca kind=quarantined. Não reinstalar candidato automaticamente.
- INSTALADO AGORA: 13 conversores S2C da build4, zero novos C2S. CÓDIGO CANDIDATO:35 S2C +3 C2S +1 validador, NÃO instalado. build/current-runtime.json e last-update.json registram distinção. Atualizações anteriores desta nota que dizem build5 instalada estão obsoletas.

## Auditoria automática solicitada — concluída primeira comparação conservadora

- Novo audit_wire_equivalence.py compara argumentos reais que chegam ao serializer, não apenas tipos. Intérprete simbólico de prefixes sem desvios com expressões de argumentos, constantes, ordem dos Top(), socket e slot do sender conferidos. Recusa helpers/instruções/buffers/controle de fluxo desconhecidos em vez de usar curingas.
- 137 métodos C2S com mesmos argumentos de serialização; 5 com diferenças;55 precisam de modelo mais profundo. Essa prova trata o limite serializer, não semântica dos callers/UI. 137 saíram de passthrough genérico para native_same_serializer_contract no relatório.
- Novo defeito de catálogo encontrado: RequestExAcceptJoinMPCC mantém D0:0E mas muda chd->chdd. Ainda SEM conversão. Não repetir que todos19 D0 compartilhados são compatíveis só porque seletores coincidem.
- Source L2ParamStack.Top resolve10303a12->1046c7a0 (cursor+8/count+12); target é import Top@L2ParamStack deCore.dll, função1015b5c0 (cursor+4/count+8). teste x86 executa ambas para comprimentos0/1/7, verifica sequência, avanço e lista vazia; hashes/VA em reports/parameter-stack-evidence.json. Slots internos mudam mas API de extração sequencial coincide nos casos testados.
- CFG percorre saltos e termina em RET, sem pegar função seguinte por padding heurístico. Reextrai formatos do terceiro argumento empilhado em cada decoder efetivamente alcançável. Recuperou46 formatos antes ausentes, descartou37 callsites inalcançáveis do catálogo.
- Recepção304slots compartilhados:216 mesmos sites/formatos de decoder (NÃO prova de loops, condições, leituras diretas ou semântica),40 diferentes,40 sem recuperar diretamente argumento do pacote sob critério conservador (incluem25noops já provados),8 com CFG/endereço pendente. Nenhum dos15 demais sem argumento foi automaticamente promovido a no-op: callbacks ainda fora da prova.
- 65 testes passaram:60 do candidato (incluindo regressão15 passthrough281/289 e sequência de hook) +5 auditoria/CFG/argumentos/nativeTop. Binário candidato recompilado, NÃO instalado.
- reports/wire-equivalence.{json,md} têm dados legíveis, hashes, razões de pendência, expressões e formatos recuperados. port_client.py check/package roda auditoria após testes; report agrega categorias e distingue instalação atual de código candidato.
- Continuar trabalho priorizando diferenças reais. Para fechar os casos complexos, ampliar modelo de branches/buffers e rastrear leituras diretas/condicionais. Sem modificar cliente enquanto este estiver jogando.

## Estado atual — build 6 e assets instalados, 2026-09-17

- Substitui o estado histórico de rollback acima: instalado protocol-hooks-6-assets-audit, SHA256 c9c3bd7dd27b947e2859d8ca1c0054ecccd003e9ad1c5940cb0b11fdbfd32920; 35 conversores S2C + 3 C2S. CharacterSelected15 continua em passthrough/quarentena. CharInfo/UserInfo apenas diagnóstico, sem reescrita.
- 69 testes passaram. Seis DATs migrados de Documents/L2Killer para formato Interlude com roundtrip de todas as colunas/linhas e RSA413; 55 pacotes ausentes adicionados, sem substituir pacotes nativos. Todos os 62 hashes instalados conferidos.
- Backup: Downloads/Lineage2_Interlude_Client/system.before-assets-20260917-052113. Manifestos build/last-assets-update.json e build/current-runtime.json. Pacote DLL dist/L2Killer-ProtocolPatch-c9c3bd7d.zip não inclui assets; assets ficam em build/assets-interlude.
- PID28690 ainda usa sessão anterior: não interrompido. Nova DLL e DATs ativam na próxima abertura. Validação visual pendente.
- L2Killer_Assassin_light.ukx e L2killer_HeadGear.ukx têm cabeçalho desconhecido CAFE F0 0D; não instalados. 139 referências ainda sem export confirmado, das quais 115 nesses dois pacotes. Não declarar migração visual completa.
- Ferramentas e limitações em reports/assets-validation.md. inspect_asset_audit.py cruza IDs permitidos do log novo com tabelas; nenhum payload/chat/nome de personagem é registrado.


Atualização após erro c5icon.utx corrupted: 20 texturas UTX adicionadas estavam sem container Lineage2. wrap_asset_textures.py aplicou Ver121, preservando integralmente o payload e conferindo tabelas names/imports/exports e ida/volta XOR. Originais em /Users/wenderteixeira/Downloads/Lineage2_Interlude_Client/textures.before-ver121-20260917-052804. Formatos internos não alterados. Aceitação pelo loader e visual em jogo ainda pendentes; não confundir índice legível com compatibilidade total. Manifesto de assets atualizado.


## Skills migradas — 2026-09-17
Quatro DATs e três pacotes de ícones instalados, com backup system.before-skills-20260917-055311. Patch agora 71 arquivos. Anti Buff IDs9709/50012/50050 têm nomes e ícones resolvidos. Validação estrutural completa, visual pendente de reinício; 63 referências de ícones/sons ainda ausentes na origem/destino. Relatório reports/skills-validation.md. Não afirmar que o critical foi comprovadamente corrigido. DLL inalterada.


## Build 7 — contratos C2S
Instalada protocol-hooks-7-outbound, SHA256 f88387f99dc84d3c5e5ad4a83af3546afaaddd7de97c0c8688c8feaeef222f9c. 35 S2C +6 C2S, 74 testes passaram. Três novas correções: EnterWorld por reserialização do formato C4 (88 bytes exclusivos removidos), RequestJoinPartyRoom71 (17→9) e AcceptJoinMPCCD0:0E (11→7). Teste executa serializer real104021f0; preserva blob variável. RequestPledgePowerC0 exige semântica de callers/ações, ainda pendente. Relatório reports/outbound-build7.md. Usuário confirmou Windows abre com base fornecida e relatou desconexões por pacotes incompatíveis; não temos trace dessas sessões Windows. Não afirmar causa confirmada ou conclusão de todos os pacotes.


## Build 8 — personagens, 2026-09-17 08:03
Instalada protocol-hooks-8-characters SHA256 3fcef81e7f3d07f97f94a7f02b9fc29f558339f8df0e1f27c5ccd8097a30b706; backup system/L2KProtocolCore.before-protocol-20260917-080333.dll. 37 S2C +6 C2S; 82 testes passaram. CharInfo03/UserInfo04 agora convertem somente layout C4 completo e inequívoco; moderno/desconhecido preservado. CharacterSelected15 continua em quarentena. new native/character_codec.cpp + tests.
CRÍTICO: bloco32 de permissões UserInfo C4 é bitset, NÃO32booleanos! Nem copiar primeiros4bytes mantém a semântica. Source User::SetPledgePower10353010 usa bits0,1,3,10 para quatro indicadores; target10358a80 usa1,2,7,5. Conversor mapeia esses4, zera extras sem equivalente. Teste executa asduasfunçõesx86 para cada256bits e vetoreszero/um. Não resolve C0/30ações/membro/rank. Rascunhos com mapeamento errado foram corrigidos antes da instalação; não foram distribuídos.
Auditoria142contratosC2Sequivalentes/50foraModelo/5diferentes. low/extend registraAL/AH/AX, movsx e movzx; writesparciais ainda recusadas. Novos2testes, cinco métodos promovidos. Ver reports/characters-build8.md para limites concretos Quest80/Ride86/GM8F/FE30/CharacterSelected e assets. Porte NÃO completo; não pedir ao usuário para adivinhar quais estão pendentes.
Para evitar stalls mmap/pycache no Documents: pefile.PE(data=path.read_bytes()); PYTHONPATH=/tmp/l2k-port-test-deps PYTHONPYCACHEPREFIX=/tmp/l2k-port-pycache python3. 602arquivosgit hidratados por ThreadPool24. gitcommit-q evita travar resumo apóscommit. Log82testes /tmp/l2k-build8-validation.log. Nenhuma sessão l2.exe ativa ao instalar.


## Build 9 — guarda C0, 2026-09-17 08:12
Instalada protocol-hooks-9-pledge-guard SHA256 41f8f3308f86009c06209c2f4f582612e48f6a6f72cbe62d0ba65db2710a47ac; backup /Users/wenderteixeira/Downloads/Lineage2_Interlude_Client/system/L2KProtocolCore.before-protocol-20260917-081233.dll. 84 testes passaram. Mantém37 S2C+6C2S, adiciona validador C0: ações1/2 exigem9bytes; outras41. Bloqueia pedido ILação2de13bytes antescipher/send, NÃO traduz operação/rank/membro. Teste novo executa funções originais103fb950/10409980 atévirtualsender, validaargumentosformatosbuf32. test_game_traceconfirmaausênciadeenvio13. Catálogo outbound-schemas.validators ecoverage refletemproteção, não conversor7. docs reports/pledge-guard-build9.md. Porte segueincompleto. BackendGo consultado somenteleitura:quests.goQuestList sóH+dd[], Ride4D; não resolvebitmap128/coords. Nenhuml2.exe aberto para validar8/9; usuárioquer testeao finalportecompleto. Logs /tmp/l2k-build9-validation.log.


## Retomada das pendências e recuperação Wine — 2026-09-17

- Usuário confirmou que o jogo voltou a abrir corretamente após falhas de inicialização e tela preta. Configuração confirmada: Wine 11.0 existente, prefix separado `/Users/wenderteixeira/Library/Application Support/L2Killer/WineRecovery-20260917`, OpenGL padrão, `WINEDLLOVERRIDES=winemenubuilder.exe=d`, `WINEDEBUG=+seh,+loaddll`. Atalho atualizado. Vulkan e Wine 11.17 foram tentativas sem sucesso; não usar como configuração validada. `l2.ini` foi restaurado integralmente. Não confundir janela visível com renderização correta; a confirmação visual veio do usuário. Causa raiz das falhas intermitentes ainda não estabelecida.
- Usuário pediu retomar pendências e confirmou warehouse funcionando. Orientação: manter o contrato C4 e traduzir somente diferenças confirmadas, sem alterar gratuitamente pacotes iguais.
- Adicionada execução diferencial offline em `native_emitter_audit.py` e `test_native_list_requests.py`: 13 métodos com listas, 195 pares de vetores, bytes C4/Interlude iguais; nove pares adicionais de macros com Unicode e 0/1/12 linhas. Executa rotinas originais, Top, montagem de buffers e serializadores; para antes de enviar à rede. Callback de diagnóstico UI C4 é no-op, dependências Core/CRT verificadas por hash.
- Testes também exigem que `l2k_outbound_convert` preserve os bytes já iguais ao C4. Suíte completa: 87 testes passaram; após adicionar essas asserções, os três testes nativos de listas/macros passaram novamente. Logs `/tmp/l2k-pending-audit-validation.log` e `/tmp/l2k-native-list-final.log`.
- Cobertura registra evidência finita em `native_vector_audit`, sem promover para prova simbólica nem declarar porte completo. 142 contratos simbólicos permanecem; os 50 fora do modelo não são automaticamente removidos. Detalhes em reports/native-list-requests.{json,md}. Nenhum pacote da sessão real foi capturado como payload.
- Nenhuma DLL, DAT ou arquivo de patch alterado nesta retomada; build 9 continua instalada e o jogo não foi interrompido. Pendências reais ainda incluem C0/30 (clã), Quest80, Ride86, GM8F, FE30 e CharacterSelected15 em quarentena. Não reativar conversão15 baseada nas antigas fixtures que quebraram entrada no mundo.


## Build 10 — GM e montaria
Instalada protocol-hooks-10-gm-ride, SHA256 d7e10bcc6392f0d0a0d9586c3f6ab9f31f790458403bdcb14302194d95f5a52e. 90 testes passaram; 39 S2C e 6 C2S. GM8F: conversão completa reconhecida (+100B), campos/CP conferidos nos decoders nativos. Ride86: +12B zeros; execução das funções reais RiderEnter/RiderEnd e igualdade FVector do Core confirmou sentinel de posição atual, inclusive coordenadas fracionárias. Ver reports/gm-ride-build10.md. Jogo não interrompido; ativa no próximo processo. Porte ainda incompleto: C0/30, Quest80, FE30, CharacterSelected15 em quarentena, demais contratos e assets. Não declarar conclusão com base em contagem de testes.

## 2026-09-17 — build 11 quests/channel + complete registered-slot extraction

Installed protocol-hooks-11-quest-channel SHA256 055de034de5d394040f50866ea5c5d544922dd41d37c4360c011fe3947b71f02. 98 tests passed; 41 S2C, 6 C2S, 28 unsupported requests blocked. Quest80 preserves quests/states and supplies empty IL completion bitmap; exact source NWindow AddQuestItem callback is a no-op. FE30 preserves names/counts; native invite/kick use names; ID-only new details stay blocked. Movement9methods/45pairs and petB3 native decoders matched. Extractor now inventories304source/348target slots, includes7previously omitted target names and static slot-zero handlers, and no longer truncates format-to-call scan at11instructions. See reports/quest-channel-build11.md. No live game interrupted; next process loads new DLL. Clan C0/30 per-member/rank semantics, CharacterSelected15 quarantine, other contracts and missing/protected assets still open. Do not claim port complete.

## User clarification after build 11

The user explicitly reconfirmed world entry and many gameplay actions work. CharacterSelected investigation is NOT an active reported world-entry failure and must not be treated as a release blocker requiring another login test. Preserve the working path. Focus on actual missing C4 features and evidence-backed gaps. User provided pmbstyle/L2Solo as secondary reference; source and target systems remain authoritative. Its ManagePledgePower writes13bytes vs pinned C4 handler reading41, so do not copy its clan protocol blindly.

## Build 12 — member permission bridge

Installed protocol-hooks-12-clan-members, SHA256 ec355d32587c3b516d228011d76ead08a0592e0a018e46aedf63c03dd6a079d0. Backup /Users/wenderteixeira/Downloads/Lineage2_Interlude_Client/system/L2KProtocolCore.before-protocol-20260917-125038.dll. 111 tests passed in final packaging. C0/D0:1A/D0:1B now use local per-member HTML editor and exact C4 queries/32-byte updates; legacy S2C30 handled contextually. Native sender, native locked queue and hook integration tested; live editor appearance not yet confirmed. 41 S2C +6 C2S generic converters retained; contextual bridge additional; 26 unsupported selectors remain blocked and 2 are serviced before fallback policy. No game interrupted. User confirmed world entry/movement/skills/chat/clan/warehouse; preserve working world-entry path. See reports/pledge-members-build12.md. Static categories are not counts of broken features.

## Build 15 — ID de mundo do clan, 2026-09-17 21:47

Instalada protocol-hooks-15-clan-world-id, SHA256 336b6f83897b0296f816e47a13fc384f5dea3260b10cfd0a1360f0b846ed78c1; backup /Users/wenderteixeira/Downloads/Lineage2_Interlude_Client/system/L2KProtocolCore.before-protocol-20260917-214750.dll (build 14, 2770548a). Nenhum l2.exe aberto na instalação; vale na próxima abertura.
Causa da falha da 14: ID de CharacterSelected (15) difere do objectId de UserInfo (04) neste servidor, mesmo nome; a 14 exigia igualdade e nunca aceitava o UserInfo (ready=0). Agora UserInfo é autoritativo para o ID de mundo, tanto no membro local 55/54 quanto no contexto de permissões C0. Antes de conhecer o ID de mundo, duplicata na lista é detectada só por nome. Evento de trace local_C4_clan_world_id sem valores.
43 testes direcionados (test_clan_self, test_clan_codec, test_pledge_bridge, test_game_trace, test_character_codec, test_outbound_policy) + suíte completa 147 testes passaram; logs /tmp/l2k-build15-directed.log e /tmp/l2k-build15-full.log. Relatório reports/clan-world-id-build15.{md,json}; patch/ atualizado (DLL + manifest). Validação visual da linha do próprio personagem e da alteração de título pendente de teste manual. Porte segue incompleto.

## Build 16 — RequestPledgeMemberInfo local, 2026-09-17 22:29

Usuário confirmou na build 15 que o próprio personagem aparece na lista do clan, mas alterar título retornou "target not found". Trace (sem payloads): cada C2S 55 (15/17/25/27 bytes) vinha com C2S D0:1D (21 bytes) bloqueado e resposta S2C 64 de 9 bytes. Trace grava o subopcode estendido em DECIMAL (%d): 29 = 0x1D RequestPledgeMemberInfo, não 0x29.
Causa: interface.u Interlude, ClanDrawerWnd.OnClickButton → RequestClanChangeNickName(GetText('Clan1_CurrentSelectedMemberName'), editbox). Esse textbox só é preenchido por HandleClanMemberInfo (ClanType, Name, NickName, GradeID, OrderName, MasterName) = PledgeReceiveMemberInfo FE:3D dSSdSS (handler 0x10412a70, decompilado em decompiled/runtime). Com D0:1D bloqueado, o 55 ia com nome vazio. GetStringByGradeID só mapeia 1–9; outros valores → GetSystemString(-1) vazio.
Correção: l2k_pledge_send atende D0:1D (pledgeType 0 + nome próprio ou da lista) com FE:3D local d(0) S(nome) S("") d(0) S("") S(""); L2KPledgeResult ganhou local/local_size. local_ui: l2k_queue_local_packet genérico (FE: extended=word, length=n-1 como o nativo, corpo alocado n-3+1); l2k_queue_local_html vira wrapper. game_trace registra S2C local_C4_member_info. Nome desconhecido/subunidade/layout inválido segue para o bloqueio.
Ferramentas: ScriptText do interface.u não é texto legível por XOR simples; o tokenizador inventory_bytecode.py não cobre op 0x39 — a leitura foi por varredura linear de 0x1f (strings) e 0x1b (chamadas por nome compact). Ghidra headless falha com "OSGi bundle" quando o scriptPath está dentro de Documents ou quando o cwd tem ExportPacketEvidence.java na raiz; funcionou copiando o script para o scratchpad e rodando de lá.
Instalada protocol-hooks-16-clan-member-info SHA256 910e74bf0e52a9f183416b326039ece0bde43366edcfd6afa010748d06fd4590 com jogo ABERTO (PID host ativo; atômico, vale na próxima abertura); backup L2KProtocolCore.before-protocol-20260917-222922.dll (build 15). 31 testes direcionados + suíte completa 153 passaram (/tmp/l2k-build16-full.log). patch/ atualizado, verify OK 81 arquivos. Relatório reports/clan-member-info-build16.{md,json}. Alteração real de título pendente de teste manual; título mostrado no painel do membro fica vazio (C4 não envia).
Wine: crash intermitente de inicialização (AV em kernel32 7BF2123D após wined3d GL_VENDOR Apple) ocorreu de novo hoje antes e depois da build 15; reabrir resolve. Não é a DLL.
