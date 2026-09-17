# Interlude → Scions of Destiny (L2Killer)

Porte experimental do cliente Interlude para o protocolo C4 do L2Killer. Inclui hooks de autenticação e pacotes, conversores de estruturas, auditorias e migração de catálogos de itens/NPCs.

- `research/client-port/`: código C++/Python, testes, catálogos, evidências e ferramentas de migração.
- `patch/`: somente os arquivos adicionados ou modificados pelo porte, com estrutura de pastas pronta para o cliente Interlude. Não contém o cliente completo.

## Instalar o patch

Feche o jogo e faça backup da sua pasta `system`.

1. Renomeie a system antiga e crie uma nova pasta `system` no cliente Interlude completo.
2. Copie todo o conteúdo de `base/C6_System_Win10Supported/` para essa nova `system/`.
3. Copie as pastas de `patch/` para a raiz do cliente, aceitando substituir os arquivos correspondentes.
4. Abra `system/l2.exe`: a DLL do porte carrega automaticamente.

A base vem primeiro e o patch por último. Aplicar a base depois do patch desfaz o carregamento automático e as tabelas migradas. O `l2.ini` final aponta para `server.l2killer.org`.

O erro de ponto de entrada `?GL2ShowCMViewer@@3HA` é compatível com mistura de versões: o executável do porte importa esse símbolo da `Core.dll`, presente na base fornecida. Não misture DLLs de outra system.

Base validada: C6_System_Win10Supported / engine.dll SHA-256 `508974c711f207402719e92737e211a2f029c95c2f68fc0e1c31fcbb9dbb232d`. Não é um patch universal para qualquer system. `patch/manifest.json` contém os hashes dos 80 arquivos do porte. Confira com `python3 patch/verify.py`; para conferir a instalação, use `python3 patch/verify.py /caminho/do/cliente`.

## Fonte e compilação

Requer Python 3, Clang e MinGW-w64 i686. No macOS, a compilação gera uma biblioteca nativa para testes e a DLL Windows x86.

```sh
python3 -m venv .venv
. .venv/bin/activate
pip install -r research/client-port/requirements.txt
python research/client-port/native/build.py
```

As ferramentas de extração, auditoria binária, DAT e Wine dependem dos clientes originais e de ferramentas externas; scripts históricos ainda contêm caminhos absolutos do ambiente de desenvolvimento. Consulte `research/client-port/AUTOMATION.md`, `native/README.md` e `reports/assets-validation.md` antes de executar a pipeline completa. A system Interlude de referência está em `base/`; o cliente completo, Wine, ambientes virtuais, caches, backups e logs de sessões não estão versionados.

## Estado

Ajuste adicional `inventory-slot-1`: o `NWindow.dll` do patch restaura um slot visível e clicável para a AIO Tattoo (máscara `0x2000`), separado da tattoo comum. Quatro testes nativos passaram; a confirmação visual em jogo ainda está pendente. Veja [evidência e reprodução](research/client-port/reports/inventory-slot.md).

Build `protocol-hooks-13-status-content`: restaura a atualização de experiência C4 em `StatusUpdate`, corrige templates de mensagens/quests/eventos e liga as ações de pets aos IDs C4. São 17 DATs migrados e 126 testes automatizados aprovados; dez comandos de summons exclusivos do Interlude são bloqueados antes do envio.

O catálogo inclui os 213 pontos de envio C4 (204 métodos), todos com uma classificação de evidência, além dos 304 slots de recepção. Enumeração completa não é prova de todos os comportamentos em jogo. Veja [mudanças e evidências da build 13](research/client-port/reports/status-content-build13.md), [cobertura dos protocolos](research/client-port/reports/coverage.md) e [destino dos 33 DATs e assets indisponíveis](research/client-port/reports/content-disposition.json).

O usuário confirmou login, entrada no mundo, movimento, uso de skills, chat, informações de clã e warehouse funcionando. A entrada no mundo usa o caminho preservado de CharacterSelected; ausência de conversão desse pacote não significa falha de entrada. Dois pacotes customizados de formato desconhecido e referências visuais ainda estão pendentes. O relatório de assets e os relatórios de cobertura documentam os limites. Arquivos do jogo e ferramentas de terceiros mantêm os direitos/licenças de seus respectivos autores.

## Atualização de skills

Incluídos `skillname-e.dat`, `skillgrp.dat`, `skillsoundgrp.dat` e `mobskillanimgrp.dat`, mais três pacotes de ícones customizados. A pasta `patch/` já contém a atualização. Reinicie o cliente após copiar. Consulte [validação de skills](research/client-port/reports/skills-validation.md) para resultados e pendências.

## Contratos de envio — build 7

Corrigidos EnterWorld, RequestJoinPartyRoom e RequestExAcceptJoinMPCC. A atualização está em `patch/system/L2KProtocolCore.dll`; feche o jogo antes de substituir. Consulte [evidências e limites](research/client-port/reports/outbound-build7.md). A build passou por testes automatizados; isso não confirma que todas as desconexões observadas no Windows estejam resolvidas.

## Personagens — build 8

Conversão dos layouts C4 completos de CharInfo e UserInfo, incluindo equipamentos, experiência e os quatro indicadores legados de permissão. Pacotes já Interlude e variantes desconhecidas são preservados. A equivalência dos indicadores foi testada nas funções x86 originais para cada um dos 256 bits C4. A adaptação das operações por membro foi acrescentada na build 12 descrita abaixo. Consulte [evidências e pendências](research/client-port/reports/characters-build8.md).

## Proteção de privilégios — build 9

RequestPledgePower C0 agora recusa tamanhos incompatíveis com a ação C4 antes de cifrar/enviar. O pedido Interlude de alteração por rank (13 bytes) fica bloqueado; não foi convertido em uma operação C4 diferente. [Evidência nos emissores originais e limites](research/client-port/reports/pledge-guard-build9.md).

## Quests, grupos de comando e catálogo — build 11

QuestList 80 e command channel FE30 convertidos com evidências nos binários originais e testes dos hooks. A extração cobre os 304 slots registrados do C4 e 348 do Interlude, incluindo sete registros que o filtro por nome omitia. Nove métodos de movimento/descarte e o inventário do pet receberam comparações nativas; os casos equivalentes preservam os bytes. [Evidências e limites](research/client-port/reports/quest-channel-build11.md).

A auditoria restante deve distinguir funcionalidades comprovadamente ausentes, contratos ainda sem evidência suficiente e referências de assets não resolvidas. A entrada no mundo está confirmada e deve ser preservada. Contagens da extração estática não representam uma lista de funcionalidades quebradas; passar nos testes automatizados também não comprova funcionamento de todas as telas em jogo.

## Permissões por membro — build 12

Os comandos de permissões de cargos do Interlude abrem uma janela local de membros online. O líder consulta e altera direitos no formato C4; outros membros consultam os próprios direitos. Apenas o clique em Aplicar envia uma alteração. IDs de cargos não são enviados como IDs de personagens, e todos os 32 bytes de permissões são preservados. A implementação passou pelos testes dos emissores e da fila nativa; a apresentação da nova janela em jogo ainda não foi confirmada. [Contrato, testes e limites](research/client-port/reports/pledge-members-build12.md).
