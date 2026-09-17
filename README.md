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

Base validada: C6_System_Win10Supported / engine.dll SHA-256 `508974c711f207402719e92737e211a2f029c95c2f68fc0e1c31fcbb9dbb232d`. Não é um patch universal para qualquer system. `patch/manifest.json` contém os hashes dos 71 arquivos do porte. Confira com `python3 patch/verify.py`; para conferir a instalação, use `python3 patch/verify.py /caminho/do/cliente`.

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

Build `protocol-hooks-8-characters`: 37 conversores S2C e 6 C2S, dez DATs migrados e 58 pacotes adicionais. Vinte texturas receberam container Ver121 sem alterar seu conteúdo. 82 testes automatizados passaram; o usuário confirmou equipamentos no seletor e resolução do erro de textura. Isso não equivale a validação de todas as funcionalidades.

CharacterSelected permanece sem conversão após uma regressão corrigida. Dois pacotes customizados de formato desconhecido e referências visuais ainda estão pendentes. O relatório de assets e os relatórios de cobertura documentam os limites. Arquivos do jogo e ferramentas de terceiros mantêm os direitos/licenças de seus respectivos autores.

## Atualização de skills

Incluídos `skillname-e.dat`, `skillgrp.dat`, `skillsoundgrp.dat` e `mobskillanimgrp.dat`, mais três pacotes de ícones customizados. A pasta `patch/` já contém a atualização. Reinicie o cliente após copiar. Consulte [validação de skills](research/client-port/reports/skills-validation.md) para resultados e pendências.

## Contratos de envio — build 7

Corrigidos EnterWorld, RequestJoinPartyRoom e RequestExAcceptJoinMPCC. A atualização está em `patch/system/L2KProtocolCore.dll`; feche o jogo antes de substituir. Consulte [evidências e limites](research/client-port/reports/outbound-build7.md). A build passou por testes automatizados; isso não confirma que todas as desconexões observadas no Windows estejam resolvidas.

## Personagens — build 8

Conversão dos layouts C4 completos de CharInfo e UserInfo, incluindo equipamentos, experiência e os quatro indicadores legados de permissão. Pacotes já Interlude e variantes desconhecidas são preservados. A equivalência dos indicadores foi testada nas funções x86 originais para cada um dos 256 bits C4. Isso não conclui a adaptação das operações de alteração de privilégios de clã. Consulte [evidências e pendências](research/client-port/reports/characters-build8.md).
