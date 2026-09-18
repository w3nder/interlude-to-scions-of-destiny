# Próprio personagem na lista do clan — build 14

**Superada pela build 15.** O teste real falhou: o ID de seleção difere do ID de
mundo nesta sessão. A igualdade exigida nesta versão impedia a inclusão.
Consulte `clan-world-id-build15.md`; os testes abaixo não cobriam essa diferença.

O conversor 53 anterior expandia os campos C4 para Interlude, mas preservava
somente os membros presentes no pacote. O cliente Interlude constrói sua lista
pelas entradas recebidas; uma atualização 54 não cria uma entrada ausente.
A referência C4 fornecida pelo usuário, `pmbstyle/L2Solo`, exclui explicitamente
`activeActor` em `Response/PledgeShowMemberListAll.js`. Isso explica a diferença
de contrato; não pressupõe que L2Killer execute esse servidor.

O trace local confirma a ordem 15 → 53 C4 → 04, com 53 de 603 bytes expandido
para 667 bytes. O conteúdo dos pacotes não foi gravado. Portanto o trace sozinho
não prova quais nomes vieram na lista; a reprodução usa membros sintéticos e
corresponde ao sintoma informado pelo usuário.

## Correção

`native/clan_self.cpp` guarda a identidade de CharacterSelected apenas em memória
sem alterar esse pacote. Lê de UserInfo o prefixo comum aos dois engines:
`x,y,z,heading,objectId,S(name),race,sex,class,level`. Confere ID/nome com a
identidade da sessão. Não depende dos campos posteriores de experiência,
equipamentos ou permissões, que podem ter variantes neste servidor.

Somente uma lista principal validada e expandida de C4 habilita a complementação.
Se o próprio ID ou nome já constar nela, nada é acrescentado. Quando omitido,
a DLL encaminha um 55 Interlude local após o pacote original na mesma fila
nativa. Se UserInfo chegar depois da lista, a inserção espera esse prefixo;
se chegar antes, ocorre após a lista. O registro também entra no contexto local
de permissões por membro. Os dados não são enviados ao servidor.

Novos UserInfo idênticos não repetem a inserção. Mudanças de nível/classe do
registro local geram 54, e uma entrada posterior fornecida pelo servidor passa
a prevalecer. Uma lista completa substitui o contexto anterior. Remoção do
próprio membro, saída do clan, nova seleção de personagem e troca de socket
impedem reutilizar a entrada antiga.

A observação é limitada ao prefixo de UserInfo; ela não certifica o restante do
pacote híbrido nem a semântica de todos os dados de personagem. O campo de classe
usado é o do prefixo recebido, sem inferir uma classe diferente pelos DATs.

## Título

A extração dos emissores registra `RequestGiveNickName` como opcode 55 C2S,
formato `cSS`, em ambos os binários: chamada C4 `103f68c8`, Interlude `1040557c`.
A ausência da linha impede selecionar o próprio personagem na interface.
A correção disponibiliza a linha; não concede permissões nem altera as regras
do servidor. O teste dos hooks verifica que o pedido `55 + nome + título`
atravessa o adaptador sem alteração. Não foi feita alteração real de título.

## Verificação

`test_clan_self.py` cobre ambas as ordens de chegada, lista vazia/repetida,
duplicação por nome ou ID, lista já Interlude, atualizações, remoção, troca de
personagem, identidade divergente, truncamentos e capacidade insuficiente.
`test_game_trace.py` executa a DLL Windows x86 emulada, reproduz a ordem observada,
confere os frames original e local na fila, ausência de segunda descriptografia,
preservação do estado de cifra e envio intacto do pedido de título.

Os testes de codecs de clan/personagem, permissões por membro e política de
envio são executados junto da regressão. O manifesto de instalação registra o
resultado e o hash da DLL testada. A confirmação visual da linha e a alteração
de título no servidor permanecem para o teste manual após reiniciar o cliente.
A correção de tattoos `inventory-script-2` é preservada.
