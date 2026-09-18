# Título de membro e RequestPledgeMemberInfo — build 16

Após a build 15, o próprio personagem apareceu na lista do clan, mas alterar o
título retornou "target not found" do servidor. O trace da sessão (sem payloads)
mostrou, a cada tentativa, um `C2S 55` de 15/17/25/27 bytes seguido de um
`C2S D0:1D` de 21 bytes bloqueado como não suportado, e a resposta `S2C 64`
de 9 bytes (SystemMessage sem parâmetros).

## Causa

`RequestGiveNickName` (55, `cSS`) tem o mesmo formato nos dois clientes. Os
tamanhos observados só fecham com **nome vazio** mais um título de 5/6/10/11
caracteres; um nome de 6 caracteres (o que o `D0:1D` de 21 bytes carrega em
`chdS`) não cabe.

O script `ClanDrawerWnd.OnClickButton` do `interface.u` Interlude confirma:
`Clan1_ChangeNameAssignBtn` chama
`RequestClanChangeNickName(GetText('Clan1_CurrentSelectedMemberName'), GetString('Clan1_ChangeNameTextEditbox'))`.
Esse textbox é preenchido apenas por `ClanDrawerWnd.HandleClanMemberInfo`, que
lê `ClanType, Name, NickName, GradeID, OrderName, MasterName` — a resposta
`PledgeReceiveMemberInfo` (FE:3D, `dSSdSS`, handler `0x10412a70`) ao
`RequestPledgeMemberInfo` (D0:1D). O C4 não tem esse par de pacotes; com o
pedido bloqueado, o nome ficava vazio e o servidor não encontrava o membro `""`.

`GetStringByGradeID` mapeia apenas 1–9 para strings do sistema; qualquer outro
valor resolve `GetSystemString(-1)` e a UI mostra o grau vazio.

## Correção

`l2k_pledge_send` atende `D0:1D` com `pledgeType == 0` e nome igual ao próprio
personagem ou a um membro da lista convertida, sem enviar nada ao servidor.
A DLL enfileira localmente `FE:3D` com `d(0) S(nome) S("") d(0) S("") S("")`.
O C4 não fornece título, grau, subunidade nem patrocinador dos membros; esses
campos ficam vazios de forma explícita. Nomes desconhecidos, subunidades,
layout inválido ou lista ausente seguem para a política de bloqueio anterior.

`l2k_queue_local_packet` generaliza a fila local para opcodes estendidos. O
teste executa o `ReceivePacket` original (`0x10420e60`) em Unicorn com o mesmo
frame e exige descritor idêntico: opcode, word estendida, `length = n-1` (o
nativo declara o comprimento após o opcode mesmo em FE), corpo alocado com
`corpo+1` bytes, mesma sequência de lock/append/unlock e cifra do socket intacta.

O pedido 55 continua com os bytes nativos. O trace registra
`local_C4_member_info` (S2C, FE:3D) sem nomes.

## Verificação e limites

`test_pledge_bridge` cobre nomes conhecidos, adição/remoção via 54/56, próprio
personagem sem lista, nome de 63 caracteres, subunidades, caixa diferente,
truncamentos e isolamento do estado de permissões. `test_native_local_ui` prova
o descritor contra o receive original. `test_game_trace` executa o hook de
envio real da DLL x86: nada é enviado, o FE:3D é enfileirado, o nome
desconhecido cai no bloqueio e o 55 atravessa intacto.

Não é validação em jogo: a atualização real do título e a exibição do painel de
membro dependem do teste manual após reabrir o cliente. O título mostrado no
painel do membro fica vazio porque o C4 não o envia nesse fluxo; isso não é o
título real do personagem.
