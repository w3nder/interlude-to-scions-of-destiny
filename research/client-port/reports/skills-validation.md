# Migração de skills C4 → Interlude

Instaladas quatro tabelas, com prioridade para a origem pela chave composta e preservação das entradas exclusivas do Interlude. IDs, níveis, campos e duplicatas da origem foram preservados. Os esquemas dos quatro DDFs são iguais entre as versões; os arquivos foram recompilados com as definições Interlude.

| Tabela | Origem | Interlude original | Resultado |
|---|---:|---:|---:|
| skillname-e | 25461 | 29812 | 29982 |
| skillgrp | 26351 | 29812 | 30065 |
| skillsoundgrp | 962 | 1398 | 1398 |
| mobskillanimgrp | 4899 | 5463 | 10341 |

Validação: todas as linhas e colunas coincidem após assembler/disassembler; contagem binária e encode/decode RSA413 conferidos. Patch instalado conferido por SHA-256. Anti Buff 9709, 50012 e 50050, nível 1, têm nomes e ícones encontrados no Icon.utx instalado. Isso não identifica por si só qual ID está no slot 9, nem prova a causa do critical.

Três pacotes adicionais: Tony.utx, TonyC6.utx e kaaliv2.utx. Os dois primeiros receberam container Ver121, mantendo payload idêntico; tabelas de nomes/imports/exports conferidas. Dependências importadas limitadas a Core e Engine.

Auditoria de ícones/sons: 1270 referências distintas, 1199 já presentes e 8 resolvidas pelos três pacotes adicionados; 63 não encontradas nem nos pacotes de origem pesquisados. As pendências incluem ícones de skills de NPC, um ícone customizado e quatro sons. Não substituímos arbitrariamente referências por ícones de outras skills. Descritores de efeitos em skillgrp e renderização de todas as animações ainda exigem validação em jogo.

Pipeline: extração com extract_asset_tables.extract para estas quatro tabelas → migrate_skill_tables.py → audit_skill_assets.py → install_skill_update.py. Scripts de instalação usam os caminhos locais históricos e validam a base antes da escrita. Backups e resultados de execução ficam fora do Git, em build/last-skills-update.json. Próxima abertura do cliente ativa os arquivos. DLL e protocolo não alterados.
