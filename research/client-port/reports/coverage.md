# Migração automática — perfil Killer C4 → Interlude

O gerador aplica somente regras explícitas deste par de builds. Sem teste individual por pacote, sem afirmar compatibilidade total.

Verificação desta execução: passed
Unidades inventariadas: 584 (métodos de envio + slots de recepção; não é contagem de schemas únicos).

## Regras implementadas

- Login C4 integrado; já validado em jogo na build anterior.
- Recepção 0x53, 0x54 e 0x55: listas/membros de clã C4 convertidos ao layout Interlude.
- Pacotes de clã que já têm o layout Interlude são preservados.
- 26 solicitações exclusivas do Interlude bloqueadas antes da cifra/envio; outras duas são atendidas pela interface local de permissões por membro.
- 41 conversores S2C, 6 conversores C2S e 1 validador estrutural. Detalhes e variantes em schema-inbound.json, structured-inbound.json e outbound-schemas.json.
- Testes estruturais não validam por si só significado de campos nem comportamento de todas as telas.
- Permissões de clã: C0/D0:1A/D0:1B abrem consulta/edição por membro; o envio usa C0 C4 e preserva o bitset de 32 bytes. Resposta 30 legada alimenta a interface local. Veja pledge-members-build12.md.
- Cifra nativa de game preservada; trace registra apenas opcode, tamanho e decisão.
- Demais pacotes continuam no caminho original. Nenhuma conversão baseada apenas no tamanho.
- Auditoria dos argumentos C2S: 142 métodos equivalentes no serializador; não precisam de conversão nesse limite.
- Listas C2S: 13 métodos comparados nos dois binários em 195 pares de vetores; bytes iguais nos casos testados, sem nova conversão. Evidência: native-list-requests.json.
- Evidências completas em wire-equivalence.json. Mesmos decoders S2C não provam condições, repetições ou semântica iguais.
- Contagem de conversores descreve o código candidato; consulte runtime_installation para a DLL realmente instalada.

## Categorias da extração estática (não são contagens de falhas)

| Categoria estática | Quantidade |
|---|---|
| decode_layout_unresolved | 60 |
| different_observed_decode_segments | 43 |
| different_observed_opcode_or_format | 6 |
| extended_subopcode_unresolved | 19 |
| renamed_slot_requires_review | 4 |
| same_observed_decode_segments | 197 |
| same_observed_opcode_and_format | 172 |
| source_only_in_extraction | 7 |
| target_only_in_extraction | 32 |
| target_only_slot | 44 |

Detalhamento por pacote em coverage.json. Tráfego observado prova ocorrência, não correção semântica.
Funções novas sem regra confirmada permanecem pendentes; o catálogo estático não é prova de ausência no C4.
