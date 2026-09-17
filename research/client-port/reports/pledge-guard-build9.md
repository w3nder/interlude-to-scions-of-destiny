# Proteção de envio — build 9

`protocol-hooks-9-pledge-guard` mantém as conversões de personagem da build 8 e acrescenta validação de RequestPledgePower C0 antes da cifra e do envio.

## Contrato confirmado no código executável

| Cliente | Ação | Formato | Tamanho com opcode |
|---|---:|---|---:|
| C4, função 103fb950 | 1 ou 2 | cdd | 9 |
| C4, função 103fb950 | demais | cddb, bloco de 32 bytes | 41 |
| Interlude, função 10409980 | 1 | cdd | 9 |
| Interlude, função 10409980 | 2 | cddd | 13 |

`test_native_pledge_requests.py` executa as duas funções x86 originais até a chamada virtual de envio. Confere formato, opcode, identificador, ação e comprimento do bloco bruto. O teste de integração do hook garante que o pedido Interlude de 13 bytes não chega ao sender nativo; pedidos de consulta de 9 bytes continuam no caminho existente.

A atualização não muda ação 2 para outra ação nem trunca a máscara para fabricar um pedido C4. A alteração de privilégios por rank permanece indisponível. Consultas com tamanho aceito ainda não têm equivalência semântica de rank/membro comprovada.

## Limites

Esta é a correção de um envio comprovadamente incompatível com o emissor C4, não a comprovação da causa de todas as desconexões relatadas. As sessões Windows não foram reproduzidas aqui. O porte completo continua pendente nas famílias listadas em [characters-build8.md](characters-build8.md) e no catálogo [coverage.json](coverage.json).

## Distribuição

84 testes passaram. SHA256 da DLL: `41f8f3308f86009c06209c2f4f582612e48f6a6f72cbe62d0ba65db2710a47ac`. Instalada no cliente Downloads/Lineage2_Interlude_Client, com backup da build 8. Validação dos 71 arquivos do patch e hashes do engine realizada após a instalação. Validação dentro do mundo ainda pendente.
