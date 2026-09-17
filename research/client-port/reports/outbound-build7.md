# Build 7 — completar contratos de envio confirmados

O usuário confirmou que o cliente abre no Windows com a system de referência e relatou desconexões ao enviar pacotes incompatíveis. Não recebemos o trace dessas sessões Windows; as correções abaixo vêm da comparação dos binários exatos e não identificam, por si só, qual ação causou a desconexão observada.

| Pedido | Interlude | C4 | Correção |
|---|---|---|---|
| RequestEnterWorldPacket (03) | cbddddbd + 20c | cbdddd | Reutiliza os argumentos originais com o formato C4; elimina a extensão final de 88 bytes sem adivinhar o limite do primeiro bloco variável. |
| RequestJoinPartyRoom (71) | cdddd | cdd | Mantém os dois primeiros argumentos Top(), na ordem original. |
| RequestExAcceptJoinMPCC (D0:0E) | chdd | chd | Mantém a resposta do primeiro Top(), removendo o segundo dword exclusivo do Interlude. |

EnterWorld foi comparado em decompiled/outbound/{source/103f5510.c,target/10404550.c}. O decompilador não exibiu todos os argumentos finais da chamada variádica; o formato e o serializador real incluem b[64], d e vinte bytes, totalizando 88. Por isso a conversão é feita no limite da serialização, condicionada ao formato exato, em vez de cortar um pacote apenas pelo tamanho. `test_native_serializer.py` executa as instruções reais de 104021f0 com cinco tamanhos do primeiro bloco, comprovando prefixo e extensão byte a byte. O memcpy é substituído por cópia limitada na emulação; nenhuma conexão de rede é feita.

Os dois outros contratos têm a ordem dos argumentos recuperada em reports/wire-equivalence.json. Testes cobrem variantes antigas já corretas, truncamentos, isolamento de subopcodes, valores não nulos nas extensões e chamada do sender nativo somente após a conversão. A cifra e o enquadramento continuam a cargo do cliente original.

Pendente: RequestPledgePower não pode ser tratado simplesmente removendo ou expandindo campos. O C4 manda 32 bytes em determinadas ações; o Interlude transforma o vetor em máscara e usa ações diferentes. É necessário relacionar os callers e as regras de privilégios antes de alterar permissões. Demais métodos com ramos/helpers/buffers fora do modelo de equivalência permanecem em análise. Nenhuma alegação de migração completa.

Resultado: 74 testes passaram. DLL `f88387f99dc84d3c5e5ad4a83af3546afaaddd7de97c0c8688c8feaeef222f9c`, build protocol-hooks-7-outbound. Instalada localmente com backup e distribuída em patch/system. Validação das novas regras em jogo pendente.
