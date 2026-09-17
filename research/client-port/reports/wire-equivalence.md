# Auditoria de equivalência — 2026-09-17

A auditoria é somente leitura e não ativa conversões. As contagens descrevem diferenças nos binários originais; as traduções implementadas estão em outbound-schemas.json. O estado de instalação é registrado separadamente em build/current-runtime.json.

## Envio: argumentos reais do serializador

| Classificação | Métodos |
|---|---:|
| Controle de fluxo, helpers ou buffers fora do modelo conservador | 50 |
| Mesmos argumentos, ordem e constantes; nenhuma conversão necessária nesse limite | 142 |
| Argumentos ou formato diferentes | 5 |

Comparação limitada a prefixes sem desvios até o envio. O interpretador recusa instruções desconhecidas, registradores não modelados, buffers variáveis e helpers desconhecidos. Não substitui essas informações por curingas. A abstração de L2ParamStack.Top foi conferida em x86 nos dois binários para sequência, cursor e fim da lista.

Diferença adicional identificada: `RequestExAcceptJoinMPCC` conserva D0:0E, mas C4 envia `chd` e Interlude `chdd`. A build 7 traduz a resposta mantendo o primeiro argumento serializado; os demais limites de semântica de UI continuam documentados.

## Recepção: fluxo realmente alcançável

| Classificação | Slots compartilhados |
|---|---:|
| control_flow_or_handler_unresolved | 8 |
| same_reachable_decoder_sites_not_semantic_proof | 216 |
| neither_entry_retrieves_packet_argument | 40 |
| different_reachable_decoder_sites | 40 |

- 46 chamadas de decoder tinham formato ausente no catálogo; recuperado pelos argumentos efetivos da chamada.
- 37 referências do catálogo não pertenciam ao fluxo alcançável do handler e foram descartadas nesta auditoria.
- 216 pares têm a mesma sequência observada de chamadas após correção. Isso ainda não prova mesmas condições, repetições, leituras diretas ou semântica.
- 40 pares não recuperam diretamente o argumento do pacote no critério conservador. Destes, os 25 no-ops anteriormente comprovados continuam dispensados; callbacks dos demais não são promovidos automaticamente a equivalentes.
- Endereços, formatos recuperados, argumentos simbólicos, motivos de pendência e hashes estão em `wire-equivalence.json`.

## Histórico da regressão (não descreve a instalação atual)

- Build 5 `6f710c50` retirada: rejeitou CharacterSelected15 de 281/289 bytes observado no servidor.
- DLL instalada: `9bd942c5` (build 4, 13 conversores S2C). O trace da sessão restaurada contém EnterWorld e atualizações do mundo.
- Código candidato: conversão 15 em quarentena, passthrough restaurado. 65 testes passaram; o candidato não foi reinstalado.
- Os arquivos de evidência não contêm payloads capturados, contas, chat ou chaves.

Build 8: modeladas leituras de AL/AH/AX e registradores equivalentes e extensões de sinal/zero. Escritas parciais continuam recusadas. Cinco contratos adicionais foram reconhecidos sem mudar pacotes; testes distinguem extensão com e sem sinal e partes altas/baixas.
