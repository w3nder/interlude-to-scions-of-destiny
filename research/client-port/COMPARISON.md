# Comparação estática: L2Killer → system-1

Objetivo: adaptar somente o cliente de destino para o servidor atual do Killer.
Este relatório descreve somente a extração estática, não o estado do patch. Login e entrada no mundo já foram confirmados pelo usuário; consulte o README e reports/coverage.md para implementação e evidências atuais.

## Cobertura e conferência

- Origem: SHA-256 confirmado; 213 pontos de envio no catálogo original.
- Reextração: 213 envios reproduzidos com opcode/formato idênticos; métodos privados recuperados pela vtable instalada no construtor UNetworkHandler.
- Os 304 registros de recepção do catálogo foram reproduzidos, com os mesmos nomes e slots.
- Destino: 240 pontos de envio e 348 registros de recepção (255 primários, 93 estendidos).
- 31 handlers da origem têm divergências de segmentos em relação ao catálogo antigo; evidência detalhada em comparison.json.
- Exemplo confirmado: o segmento antigo de MoveToLocation em 0x104132ba fica numa rotina posterior, iniciada em 0x10413280 e separada por padding INT3. Não deve ser concatenado ao handler 0x10413120.
- Os limites de função são heurísticos (exports e padding); helpers e formatos construídos dinamicamente podem ficar fora da extração.
- Q lê 8 bytes no decoder do destino: caso 0x1040279b, duas cópias de dword e avanço do cursor por 8. Evidência em decoder-Q-evidence.txt; o significado do campo ainda precisa ser resolvido.
- Ghidra decompilou os handlers UIPacket (0x104342f0) e CIPacket (0x104366f0); arquivos em decompiled/. A inferência de tipos/assinaturas ainda é incompleta.

## Referência Interlude fornecida depois

`/Users/wenderteixeira/Desktop/C6_System_Win10Supported` foi fornecida pelo usuário como referência original do Interlude.
A engine.dll é idêntica byte por byte à system-1 (SHA-256 508974c711f207402719e92737e211a2f029c95c2f68fc0e1c31fcbb9dbb232d). Os dois catálogos extraídos são idênticos, desconsiderando o caminho de origem.
L2.exe, Core.dll, IpDrv.dll, interface.u e interface.xdat também são idênticos. nwindow.dll difere em dois bytes; Fire.dll tem tamanho e conteúdo diferentes. Isso não autentica nenhuma pasta como distribuição oficial sem alterações.
Inventário detalhado: interlude-reference-inventory.json. Nenhuma das duas pastas foi modificada.

## Envios prioritários

| Método | Killer (opcode: formato) | system-1 (opcode: formato) |
|---|---|---|
| RequestServerList | 0x05: `cddc` | 0x05: `cddc` |
| RequestServerLogin | 0x02: `cddc` | 0x02: `cddc` |
| RequestGameStart | 0x0D: `cdhddd` | 0x0D: `cdhddd` |
| RequestEnterWorldPacket | 0x03: `cbdddd` | 0x03: `cbddddbdcccccccccccccccccccc` |
| MoveBackwardToLocation | 0x01: `cdddddd` | 0x01: `cdddddd` |
| Action | 0x04: `cddddc` | 0x04: `cddddc` |
| Attack | 0x0A: `cddddc` | 0x0A: `cddddc` |
| RequestUseItem | 0x14: `cdd` | 0x14: `cdd` |
| Say2 | 0x38: `cSd`<br>0x38: `cSdS` | 0x38: `cSd`<br>0x38: `cSdS` |
| ValidatePosition | 0x48: `cddddd` | 0x48: `cddddd` |

Igualdade de opcode e formato é um candidato a reutilização; ainda faltam fase da sessão e significado dos campos.

Métodos agrupados por nome e aliases nativos revisados: same_observed_opcode_and_format=179, target_only_in_extraction=28, different_observed_opcode_or_format=6, extended_subopcode_unresolved=19. Esses números descrevem a extração, não funcionalidades quebradas.

Os seis métodos com formatos diferentes são ConfirmDlg, RequestEnterWorldPacket, RequestJoinPartyRoom, RequestJoinPledge, RequestMultiSellChoose e RequestPledgePower.

## Recepção prioritária

| Slot primário | Origem → destino | Formatos observados |
|---|---|---|
| 0x01 | MoveToLocationPacket → MTLPacket | iguais |
| 0x03 | CharInfoPacket → CIPacket | diferentes |
| 0x04 | UserInfoPacket → UIPacket | diferentes |
| 0x13 | CharacterSelectionInfoPacket → CharacterSelectionInfoPacket | diferentes |
| 0x15 | CharacterSelectedPacket → CharacterSelectedPacket | diferentes |
| 0x16 | NpcInfoPacket → NpcInfoPacket | diferentes |
| 0x1B | ItemListPacket → ItemListPacket | diferentes |
| 0x21 | TradeOtherAddPacket → TradeOtherAddPacket | iguais |
| 0x27 | InventoryUpdatePacket → InventoryUpdatePacket | diferentes |

MTLPacket, NSPacket, CIPacket e UIPacket são nomes abreviados do destino. A associação pelo slot é uma hipótese de correspondência, não validação de equivalência.

## Como usar esta comparação

Diferenças de nomes ou formatos orientam a investigação; não demonstram que uma ação esteja quebrada. A comparação não desconta conversores já implementados nem substitui os testes de execução das rotinas originais.
Login, entrada no mundo, movimento, skills, chat, informações de clã e warehouse já têm confirmação do usuário. Preserve esses fluxos e confronte as diferenças com os conversores e relatórios atuais antes de classificá-las como trabalho faltante.

Não copiar endereços, vtables ou estruturas de memória do patch C4 para a engine de destino.
