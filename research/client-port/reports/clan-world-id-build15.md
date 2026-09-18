# ID de seleção versus ID de mundo — build 15

A build 14 não corrigiu o caso real. Sua validação exigia igualdade entre o ID
lido de CharacterSelected (15) e o ID de UserInfo (04). Os testes sintéticos
anteriores usavam o mesmo número nos dois pacotes e não detectavam o problema.

## Evidência da sessão, sem payloads

O novo trace confirmou 15 → 53 C4 → 04, sem `local_C4_clan_self`. Uma ferramenta
Windows temporária leu o processo aberto usando apenas `PROCESS_VM_READ` e
`PROCESS_QUERY_INFORMATION`, sem pausar, escrever ou executar código no jogo.
A consulta ao estado da DLL mostrou:

- identidade presente, lista C4 habilitada, 14 membros;
- próprio membro ausente, nenhum membro local inserido;
- `ready=0`, isto é, UserInfo nunca aceito pela build 14.

A leitura do estado nativo do engine confirmou **ID de mundo diferente do ID de
seleção**, **nome igual**, raça/sexo/nível válidos. Foram registrados somente
booleans e contagens, sem nomes, IDs, credenciais, chat ou bytes de pacotes.

O contrato nativo está em `decompiled/batch/target/104342f0.c`: UserInfo armazena
seu objectId no global `10b1f530`; o mapa do handler `10b1f538` resolve esse ID
para o User. Os campos iniciais do User estão nos offsets 18h (ID), 1Ch (nome),
4Ch (raça), 50h (sexo), 54h (classe) e 58h (nível). O engine de referência tem
SHA256 `508974c711f207402719e92737e211a2f029c95c2f68fc0e1c31fcbb9dbb232d`.
Essa inspeção confirmou o motivo da rejeição sem depender de um novo login.

## Correção

UserInfo fornece o ID de mundo autoritativo após validar o nome da sessão,
ID não nulo e os campos iniciais. CharacterSelected continua inalterado.
Antes de conhecer o ID de mundo, a detecção de duplicatas na lista usa o nome,
evita confundir o ID de seleção com o objectId de outro membro. Depois, usa
nome ou ID de mundo. A inserção local 55 e as atualizações 54 usam esse ID.

O contexto de permissões por membro também é sincronizado. Uma mudança de ID
fecha uma seleção anterior; uma consulta já pendente continua protegida contra
atribuição indevida de resposta atrasada. O emissor de título 55/cSS permanece
inalterado. A DLL registra apenas o evento `local_C4_clan_world_id`, sem valores.
O identificador de versão do log de inicialização também foi atualizado; na
build 14 ele ainda mostrava o rótulo antigo da build 13.

## Regressão e limites

O mesmo cenário sintético (seleção com ID A, lista sem o próprio nome, UserInfo
com o mesmo nome e ID B) foi executado com o código anterior e o novo: build 14
gerou zero bytes locais; build 15 gerou o membro Interlude esperado de 35 bytes.
A regressão inclui a hipótese de outro membro ter o ID A, atualizações do ID B,
permissões usando o ID de mundo e descarte de uma resposta de seleção antiga.

O teste da DLL Windows emulada agora também usa IDs diferentes na seleção e no
UserInfo. A suíte direcionada cobre clan, permissões, hooks, personagens e
política de envio; seu resultado e o hash da DLL estão no manifesto da build 15.
A evidência em memória confirma a causa da falha anterior, não a renderização da
nova versão. A linha na interface e a alteração efetiva de título ainda precisam
de confirmação após reabrir o jogo. A DLL é instalada atomicamente para o próximo
processo; a sessão aberta não é modificada.
