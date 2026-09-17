# Migração de itens e NPCs — build 6

## Evidência de protocolo

- Tráfego observado: ItemList1B de2057bytes equivale a57linhas de36bytes; InventoryUpdate27 de41bytes equivale a1linha de38bytes. O conversor preserva esses layouts modernos.
- Conversores preservam item ID, object ID, quantidade, estado equipado, body part e enchant. A extensão de C4 adiciona somente augmentation=0/mana=-1.
- CharInfo03 e UserInfo04 permanecem sem reescrita. Diagnóstico valida uma variante completa antes de extrair IDs de equipamentos, mantendo nomes de personagens e payloads fora dos logs.
- CharacterSelected15 permanece em passthrough para evitar a regressão de entrada.

## Tabelas convertidas

| Tabela | Origem | Destino anterior | Mesclada | IDs da origem ausentes no destino |
|---|---:|---:|---:|---:|
| itemname-e | 8729 | 9208 | 9994 | 768 |
| weapongrp | 1102 | 1313 | 1349 | 77 |
| armorgrp | 1652 | 1014 | 1728 | 709 |
| etcitemgrp | 6372 | 6881 | 7128 | 369 |
| npcgrp | 6346 | 6519 | 12817 | 6292 |
| npcname-e | 6361 | 6519 | 12832 | 6302 |

Cada arquivo foi recompilado e reextraído com o DDF Interlude; todas as colunas e linhas coincidiram. A codificação RSA413 também passou por ida/volta. IDs, ordem e duplicatas da origem preservados. Registros exclusivos do destino mantidos, exceto conflitos de ID com categorias de itens da origem.

## Arquivos visuais

- 55 pacotes adicionais, 191454323bytes; nenhum pacote nativo substituído.
- Cinco referências quebradas na origem foram redirecionadas a exports de mesmo nome verificados no cliente. O material customizado ausente de Zariche usa o material padrão Dragon Slayer correspondente à sua malha.
- Dois arquivos da origem não são Unreal/Lineage2Ver111/121 reconhecidos: L2Killer_Assassin_light.ukx e L2killer_HeadGear.ukx (cabeçalho CAFE F0 0D). Não foram instalados como se fossem compatíveis; seus modelos/ícones internos continuam pendentes.
- 139 referências distintas da origem continuam sem export confirmado (incluem115 referências internas nesses2arquivos); lista completa no assets-manifest.json. Isso não significa esse número de itens em uso no inventário.
- Metadados de faixa de nível/flag de NPC exclusivos do C4 não são campos do arquivo Interlude; novo efeito de raid permanece desativado nas linhas migradas.

## Ferramentas e reprodução

Definições e assembler/disassembler de M.Soltys/DStuff obtidos do [L2FileEdit](https://github.com/L2Miko/L2FileEdit/tree/master/data/l2asm-disasm). Originais preservados.

`extract_asset_tables.py` → `audit_asset_dependencies.py` → `migrate_asset_tables.py` → `install_assets_update.py <pacote>`.

`inspect_asset_audit.py` cruza os IDs do novo L2KAssetAudit-PID-tick.tsv com as tabelas. O log contém somente campos de itens, slots e IDs de catálogo de NPCs, sem nomes de personagens, chat, credenciais ou dump de pacotes.

Validação visual em jogo ainda depende da próxima abertura.


Atualização após erro c5icon.utx corrupted: 20 texturas UTX adicionadas estavam sem container Lineage2. wrap_asset_textures.py aplicou Ver121, preservando integralmente o payload e conferindo tabelas names/imports/exports e ida/volta XOR. Originais em /Users/wenderteixeira/Downloads/Lineage2_Interlude_Client/textures.before-ver121-20260917-052804. Formatos internos não alterados. Aceitação pelo loader e visual em jogo ainda pendentes; não confundir índice legível com compatibilidade total. Manifesto de assets atualizado.
