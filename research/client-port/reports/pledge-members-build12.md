# Permissões de clã por membro — build 12

A adaptação troca o pedido de permissões por cargo do Interlude por uma janela
local de membros online. O líder consulta e altera os onze direitos expostos
pelo C4; outros membros podem consultar os próprios direitos. Alterações só
são enviadas ao clicar em Aplicar. Cargos, academias e subunidades não são
inventados no servidor C4.

## Contrato dos binários

Referências primárias: engine C4 SHA256
`17a8bcacd57d071a3420d278a7570ddf2a13abba2f6d4336bb4eb48afd4e244b`
e Interlude SHA256
`508974c711f207402719e92737e211a2f029c95c2f68fc0e1c31fcbb9dbb232d`.

- C4 `103fb950`: C0, ID do membro, ação. Ações 1/2 usam `cdd`
  (9 bytes); ação 3 usa `cddb`, com 32 bytes de permissões (41 bytes).
- Interlude `104058d0`: D0:1B, tipo de clã e nome (`chdS`). O nome é
  resolvido para o ID online da lista de clã já convertida.
- C4 NWindow `1004e866` consulta os próprios direitos (ação 1), `1004e97a`
  consulta o membro selecionado (ação 2), `10087183` aplica (ação 3).
- Resposta C4 30 em `10409680`: dois dwords e bloco de 32 bytes.
  NWindow `10088250` usa o contexto da consulta, ignorando esses dois dwords.
  Por isso só pode existir uma consulta pendente, inclusive após timeout.
- NWindow `10086ee0`: bits 0–10 representam convite, título, warehouse,
  crest, três direitos de clan hall, três de castelo e guerra. Os demais
  bits são preservados integralmente em uma alteração.
- Pedidos C0 de cargos e D0:1A abrem a lista local; não enviam um ID de
  cargo como se fosse ID de personagem. D0:1C continua bloqueado.
- A resposta legada de 41 bytes é consumida pelo adaptador; uma resposta
  moderna de 13 bytes mantém o caminho original.

O repositório L2Solo fornecido pelo usuário foi usado como referência
secundária. Seu `ManagePledgePower` escreve apenas 13 bytes, portanto não
substitui o contrato de 41 bytes lido pela system C4 deste perfil.

## Interface e transporte

`native/pledge_bridge.cpp` mantém nomes e direitos somente em memória.
A interface usa NPCHtmlMessage 0F local. Links são interceptados antes do
envio; incluem um identificador da tela para rejeitar cliques antigos.
Nomes são escapados e a lista é paginada dentro do limite de tamanho.

`native/local_ui.cpp` aloca o mesmo descritor de pacote que ReceivePacket
Interlude `10420e60` e chama AddNetworkQueue `1042b7d0`, com a seção crítica
nativa. Não muda o estado de cifra. Os pedidos gerados passam pelo emissor
original, que mantém framing, cifra e sincronização de envio.

Saída do membro, remoção, nova lista e troca de personagem invalidam a tela.
Uma resposta atrasada não pode ser aplicada ao membro seguinte. Sem resposta,
a consulta continua pendente até receber a resposta ou mudar de sessão;
não há reenvio automático nem atribuição especulativa de direitos.

## Verificação e limites

`test_pledge_bridge.py` cobre os estados, permissões de líder, alterações
explícitas, bits desconhecidos, nomes escapados, truncamentos e respostas
atrasadas. `test_native_pledge_requests.py` compara os bytes com a execução
dos emissores originais. `test_native_local_ui.py` executa a fila original
e confere descritor, alocação e preservação da cifra.
`test_game_trace.py` exercita consulta, resposta, edição e envio pelo hook.

A suíte completa passou com 111 testes antes do empacotamento. O manifesto
do pacote registra a verificação da DLL final. Isso valida o código e os
contratos offline; a nova janela ainda não foi confirmada visualmente no jogo.
Nenhuma permissão real foi alterada durante os testes.

Login, entrada no mundo, movimento, skills, chat, informações de clã e
warehouse já foram confirmados pelo usuário. O fluxo de entrada no mundo
foi preservado. Ler identidade em CharacterSelected para manter o contexto
local não reescreve esse pacote nem reabre sua validação como impedimento.
