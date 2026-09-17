# Migração automática — perfil Killer C4 → Interlude

O gerador aplica somente regras explícitas deste par de builds. Sem teste individual por pacote, sem afirmar compatibilidade total.

Verificação desta execução: passed
Unidades inventariadas: 580 (métodos de envio + slots de recepção; não é contagem de schemas únicos).

## Regras implementadas

- Login C4 integrado; já validado em jogo na build anterior.
- StatusUpdate 0x0E: experiência C4 de 32 bits encaminhada à função nativa Interlude de 64 bits; demais tags preservadas; contagem validada.
- Dez comandos de summons exclusivos do Interlude (RequestActionUse, IDs 1031–1040) bloqueados. Elegibilidade das ações do C4 restaurada no actionname-e.dat.
- Recepção 0x53, 0x54 e 0x55: listas/membros de clã C4 convertidos ao layout Interlude.
- Pacotes de clã que já têm o layout Interlude são preservados.
- 26 solicitações exclusivas do Interlude bloqueadas antes da cifra/envio; outras duas são atendidas pela interface local de permissões por membro.
- 41 conversores S2C, 6 conversores C2S e 2 validador estrutural. Detalhes e variantes em schema-inbound.json, structured-inbound.json e outbound-schemas.json.
- Testes estruturais não validam por si só significado de campos nem comportamento de todas as telas.
- Permissões de clã: C0/D0:1A/D0:1B abrem consulta/edição por membro; o envio usa C0 C4 e preserva o bitset de 32 bytes. Resposta 30 legada alimenta a interface local. Veja pledge-members-build12.md.
- Cifra nativa de game preservada; trace registra apenas opcode, tamanho e decisão.
- Demais pacotes continuam no caminho original. Nenhuma conversão baseada apenas no tamanho.
- Auditoria dos argumentos C2S: 145 métodos equivalentes no serializador; não precisam de conversão nesse limite.
- Listas C2S: 13 métodos comparados nos dois binários em 195 pares de vetores; bytes iguais nos casos testados, sem nova conversão. Evidência: native-list-requests.json.
- Catálogo C4: 204 métodos, 213 pontos de envio; sem par no destino: 0; sem classificação de evidência: 0.
- Ramos adicionais: 24 métodos/154 pares; macros: 9; movimento/barcos: 30. Três peculiaridades de varargs herdadas documentadas separadamente, sem afirmar equivalência semântica.
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
| same_observed_opcode_and_format | 179 |
| target_only_in_extraction | 28 |
| target_only_slot | 44 |

Detalhamento por pacote em coverage.json. Tráfego observado prova ocorrência, não correção semântica.
Funções novas sem regra confirmada permanecem pendentes; o catálogo estático não é prova de ausência no C4.
