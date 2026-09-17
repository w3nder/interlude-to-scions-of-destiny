# Envios com listas — comparação nativa C4/Interlude

As rotinas originais de 13 métodos produziram os mesmos bytes em 195 pares de vetores sintéticos. Cada caso também exige que o adaptador C++ preserve os bytes Interlude já iguais aos do C4. Não foi adicionada conversão nem alterada a DLL instalada.

| Métodos | Opcode | Campos por entrada |
|---|---|---|
| RequestBuyItem / RequestBuySeed / RequestPackageSend | 1F / C4 / 9F | dd |
| RequestPreviewItem | C6 | d |
| RequestProcureCrop / RequestSellItem | C3 / 1E | ddd |
| RequestRecipeShopListSet | B2 | dd |
| SendPrivateStoreBuyBuyList | 96 | ddhhdd |
| SendPrivateStoreBuyList | 79 | ddd |
| SendWareHouseDepositList / SendWareHouseWithdrawList | 31 / 32 | dd |
| SetPrivateStoreBuyList | 91 | dhhdd |
| SetPrivateStoreList | 74 | ddd |

São cinco contagens (0, 1, 2, 17 e 100), três padrões de valores e ambas as engines. Os padrões distinguem a ordem dos campos, truncagem para 16 bits e preservação dos 32 bits. Asserções conferem opcode, cabeçalho, contagem, todos os bytes, consumo do L2ParamStack e cada formato usado nas linhas.

Também há nove pares de casos para RequestMakeMacro C1: 0/1/12 linhas e texto vazio, ASCII ou Unicode (incluindo par substituto UTF-16). O formato de linha nativo é ccdcS. Strings válidas são fornecidas em memória sintética; não há captura de macros do usuário.

A VM executa os helpers nativos de pilha, Top, montagem das listas e os serializadores dos dois binários. Core.dll e MSVCR70.dll usados nos helpers têm hashes conferidos. Apenas o callback de diagnóstico da UI C4 é substituído por retorno vazio. A execução para antes do sender de rede. O retorno do adaptador C++ também é conferido para evitar futuras alterações indevidas desses pacotes.

## Limites

Estes testes finitos não demonstram todos os valores possíveis, limites de UI, regras do servidor nem equivalência semântica de todos os callers. Não certificam contagens inválidas ou estouros dos buffers nativos. Os 13 métodos continuam separados da prova simbólica de 142 contratos; os 50 métodos fora do modelo simbólico não são automaticamente promovidos.

O usuário confirmou warehouse funcionando em jogo. Esse relato e a igualdade dos bytes nos vetores sustentam preservar o caminho atual. QuestList, Ride, permissões de clã, GMViewCharacterInfo e command channel permanecem pendências próprias, sem conversão por suposição.

## Reproduzir

```sh
python3 -m unittest discover -s research/client-port -p test_native_list_requests.py -v
```

Requer as dependências em requirements.txt, engines fingerprintadas e build/libl2k_protocol.dylib compilada. Evidência detalhada dos 195 pares: native-list-requests.json. A suíte completa inclui automaticamente estes testes.
