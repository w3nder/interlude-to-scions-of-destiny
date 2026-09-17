# Migração automática — perfil Killer C4 → Interlude

O gerador aplica somente regras explícitas deste par de builds. Sem teste individual por pacote, sem afirmar compatibilidade total.

Verificação desta execução: passed
Unidades inventariadas: 577 (métodos de envio + slots de recepção; não é contagem de schemas únicos).

## Regras implementadas

- Login C4 integrado; já validado em jogo na build anterior.
- Recepção 0x53, 0x54 e 0x55: listas/membros de clã C4 convertidos ao layout Interlude.
- Pacotes de clã que já têm o layout Interlude são preservados.
- 28 solicitações exclusivas do Interlude bloqueadas antes da cifra/envio.
- 39 conversores S2C, 6 conversores C2S e 1 validador estrutural. Detalhes e variantes em schema-inbound.json, structured-inbound.json e outbound-schemas.json.
- Testes estruturais não validam por si só significado de campos nem comportamento de todas as telas.
- RequestPledgePower C0: tamanhos incompatíveis com a ação C4 são bloqueados antes do envio; alteração de privilégios por rank continua sem adaptação.
- Cifra nativa de game preservada; trace registra apenas opcode, tamanho e decisão.
- Demais pacotes continuam no caminho original. Nenhuma conversão baseada apenas no tamanho.
- Auditoria dos argumentos C2S: 142 métodos equivalentes no serializador; não precisam de conversão nesse limite.
- Listas C2S: 13 métodos comparados nos dois binários em 195 pares de vetores; bytes iguais nos casos testados, sem nova conversão. Evidência: native-list-requests.json.
- Evidências completas em wire-equivalence.json. Mesmos decoders S2C não provam condições, repetições ou semântica iguais.
- Contagem de conversores descreve o código candidato; consulte runtime_installation para a DLL realmente instalada.

## Pendências automáticas por categoria

| Categoria estática | Quantidade |
|---|---|
| decode_layout_unresolved | 61 |
| different_observed_decode_segments | 43 |
| different_observed_opcode_or_format | 6 |
| extended_subopcode_unresolved | 19 |
| renamed_slot_requires_review | 4 |
| same_observed_decode_segments | 196 |
| same_observed_opcode_and_format | 172 |
| source_only_in_extraction | 7 |
| target_only_in_extraction | 32 |
| target_only_slot | 37 |

Detalhamento por pacote em coverage.json. Tráfego observado prova ocorrência, não correção semântica.
Funções novas sem regra confirmada permanecem pendentes; o catálogo estático não é prova de ausência no C4.
