# Status, catálogo completo de envios e conteúdo — build 13

O C4 recebe experiência pelo campo 2 de `StatusUpdate` (0E). O Interlude lê o par de dwords, mas seu switch ignora esse campo. A adaptação restaura somente esse ramo: chama `OnExpUpdate(User*, int64)` com extensão por zero do valor C4 e volta ao laço original. Os outros campos e o caminho de entrada no mundo permanecem nativos.

O instalador verifica o hash integral da engine, a instrução de despacho e o destino original do slot antes de publicar o pequeno trecho x86. A memória fica gravável durante a construção e executável após a proteção; falhas anteriores à publicação deixam o slot intacto. O validador de recepção exige exatamente `9 + 8 × count` bytes antes de encaminhar `StatusUpdate`.

`native-status-update.json` registra 183 pares de casos nos dois binários: tags legadas, campos ignorados, valores de 32 bits, repetição e mistura de atualizações. O teste executa o decoder, o switch e os dois setters de experiência originais; os demais callbacks são observados no limite da ABI. `test_status_installer.py` executa o instalador Windows compilado, incluindo falhas de alocação, proteção e publicação.

## Envios C4

Os 213 pontos de envio identificados no binário C4 pertencem a 204 métodos compartilhados com o Interlude. Foram recuperados os métodos privados das vtables e identificados os aliases Atk/Attack, MTL/MoveToLocation, SAP/SendAppearingPacket e EW/EnterWorld.

Todos os métodos têm uma classificação de evidência: 145 contratos simbólicos de argumentos iguais, 48 métodos cobertos por comparações nativas de casos, seis conversores, uma ponte contextual de permissões, um sufixo fixo de entrada no mundo e três peculiaridades de varargs herdadas. Isso fecha a enumeração; não transforma vetores finitos em prova de todas as ações possíveis.

As três peculiaridades são `RequestHennaItemList`, `RequestHennaUnequipList` e `RequestPetitionCancel`. Ambos os clientes originais leem um argumento implícito da pilha. O relatório as mantém separadas de equivalência semântica; não fabrica um campo de usuário para substituir o comportamento sem evidência do servidor.

Há 90 formatos compartilhados de recepção verificados em 270 pares de entradas nos decodificadores originais. Esse teste confirma tamanhos, conteúdo dos campos e avanço do cursor; condições e callbacks completos de cada handler têm escopo diferente. As diferenças dos switches de 0E, 64 e 8C estão em `evidence/receiver-switches`.

## Sete DATs adicionais

| Tabela | Tratamento |
|---|---|
| systemmsg-e | Templates e parâmetros C4; RGB/alpha e referências convertidos ao formato Interlude |
| questname-e | Etapas e IDs C4; campos de NPC, itens e coordenadas convertidos |
| entereventgrp | 1.111 IDs de eventos C4 acrescentados ao catálogo Interlude |
| actionname-e | Elegibilidade das ações restaurada para IDs de pets/summons C4 |
| staticobject-e | Nomes dos objetos estáticos C4 |
| servername-e | Nomes de servidor C4 |
| castlename-e | Nomes de castelos e propriedades C4 |

Cada tabela passou por montagem/desmontagem no schema Interlude, comparação de todas as colunas/linhas e ida/volta RSA413. Referências de itens de quests e de NPCs dos eventos/ações foram cruzadas com os catálogos migrados. O ID especial 1008740 em três etapas da quest 246 já existe assim no arquivo C4; não foi inventado pelo porte.

Os dez IDs de ações de summons 1031–1040 existem somente no DAT Interlude e são bloqueados antes de cifrar/enviar `RequestActionUse` (45). Ações C4 e IDs customizados desconhecidos mantêm o caminho nativo. A busca local de lojas é preservada; solicitações de duelo já são bloqueadas por seus seletores próprios.

Os 33 DATs C4 têm uma decisão explícita em `content-disposition.json`: 17 migrados, cinco cujas linhas da origem já existem no destino, e 11 configurações nativas de UI/geometria/câmera/mapa preservadas.

## Limite dos arquivos disponíveis

Dois arquivos de animação customizados têm cabeçalho `CA FE F0 0D` (`cafef00d`): `L2Killer_Assassin_light.ukx` e `L2killer_HeadGear.ukx`. Não contêm um índice Unreal legível, nem o wrapper Lineage2Ver reconhecido pelo leitor do executável fornecido. A análise desse leitor está em `evidence/file-loader`; ela não prova que nunca existiu um carregador externo.

O suporte a arquivos `.usk` foi incluído no indexador, e o pacote da skill 10615 foi recuperado com o export exato `virus_icon.l2_11023_skill_i00`. A lista oficial do updater foi consultada; as cópias dos dois containers customizados são idênticas às locais e conferem com os hashes publicados. Consulte `updater-asset-verification.json`.

O relatório enumera 139 referências de itens/NPCs e 62 de skills ainda sem export disponível, incluindo 115 referências dependentes dos dois containers. Esses números não são quantidades de itens quebrados em uso. Recuperar os visuais exatos exige os exports/pacotes legíveis ou o decoder compatível e sua chave; IDs e textos dos DATs não contêm as malhas, texturas e sons ausentes.

Login, entrada no mundo, movimento, skills, chat, informações de clã e warehouse já foram confirmados pelo usuário. As novas correções têm validação offline; não houve automação de ações no servidor nem interrupção do cliente aberto.
