# Personagens — build 8

Instalada e distribuída: `protocol-hooks-8-characters`, SHA256 `3fcef81e7f3d07f97f94a7f02b9fc29f558339f8df0e1f27c5ccd8097a30b706`.

## Conversões

- CharInfo 03: preserva campos C4, insere slot facial vazio, 48 bytes de augmentation e seis dwords finais Interlude. Título branco; recursos novos sem equivalente ficam zerados.
- UserInfo 04: experiência de 32 para 64 bits sem sinal; slot facial nos dois arrays de equipamento; 68 bytes de augmentation; tradução dos quatro indicadores legados de permissão e campos finais Interlude.
- O reconhecedor exige consumo completo e inequívoco do layout. Pacotes já Interlude, ambíguos ou desconhecidos continuam sem reescrita. CharInfo reconhece o ramo de protocolo maior que 420; outros ramos não são considerados concluídos.
- CharacterSelected 15 permanece em quarentena, com passthrough das variantes de entrada que já funcionavam.

## Evidência de permissões

O C4 não usa um booleano por byte no bloco de UserInfo: o handler 10423a00 lê bits dos dois primeiros bytes e avança 32 bytes. A função exportada `User::SetPledgePower` em 10353010 lê bits 0, 1, 3 e 10. A correspondente Interlude em 10358a80 lê bits 1, 2, 7 e 5 para os quatro indicadores correspondentes.

`test_native_character_permissions.py` executa ambas as funções x86 reais para cada um dos 256 bits C4, mais os vetores todo zero e todo um. Compara os quatro indicadores de saída e verifica que os três indicadores adicionais Interlude não são concedidos pela conversão. Isso prova esse comportamento de User, não a equivalência de todas as permissões ou operações de clã.

Hashes dos engines: C4 `17a8bcacd57d071a3420d278a7570ddf2a13abba2f6d4336bb4eb48afd4e244b`; Interlude `508974c711f207402719e92737e211a2f029c95c2f68fc0e1c31fcbb9dbb232d`.

## Validação

82 testes passaram. Novos casos cobrem campos completos, experiência acima de 2^31, nomes/títulos UTF16, listas de cubics, todas as truncagens dos exemplos, capacidade sem escrita parcial, preservação dos pacotes modernos e passagem pela fila nativa na DLL x86. A auditoria também reconhece leituras parciais de registradores e extensão de sinal: 142 métodos C2S têm contratos de argumentos equivalentes, 50 permanecem fora do modelo conservador e 5 têm diferenças de contrato já tratadas por regras explícitas.

Não houve validação desta build dentro do mundo pelo agente nem reprodução das desconexões do Windows.

## Pendências que impedem declarar o porte completo

| Família | Evidência que falta ou diferença real |
|---|---|
| RequestPledgePower C0 / ManagePledgePower 30 | Operações C4 e Interlude diferem: ação 2 C4 não carrega máscara; ação 2 Interlude carrega. É necessário rastrear callers e identidade de membro versus rank. A correção de UserInfo não resolve isso. |
| QuestList 80 | C4 contém uma segunda lista de itens de quest; Interlude lê bitmap de 128 bytes. Preencher zeros ou descartar a lista não prova equivalência da tela. |
| Ride 86 | C4 fornece quatro dwords; Interlude exige sete e usa os três extras como coordenadas. Coordenadas inventadas podem reposicionar personagens incorretamente. |
| GMUserInfo 8F, FE30 e variantes de CharacterSelected | Leituras e contexto ainda não modelados integralmente. |
| 50 métodos C2S fora do modelo | Há controle de fluxo, listas, buffers e helpers a analisar. São pendências de prova, não 50 pacotes comprovadamente incompatíveis. |
| Assets | Dois UKX com cabeçalho CAFE F0 0D ainda não decodificados; referências de ícones/sons restantes documentadas nos relatórios de assets/skills. |

O catálogo de cobertura mantém `release_complete=false`. O comando `port_client.py package --require-complete` recusa declarar uma distribuição completa enquanto essas lacunas existirem.
