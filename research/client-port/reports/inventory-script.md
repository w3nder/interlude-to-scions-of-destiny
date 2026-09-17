# Left Tattoo e AIO Tattoo — inventory-script-2

O usuário confirmou que o ajuste anterior em `NWindow.dll` não resolveu a
sobreposição. Após restaurar a base Win10Supported, a imagem mostrou que a
Left Tattoo deveria ocupar o terceiro espaço da primeira linha, com desenho
de orelhas. Esse caminho usa o script `InventoryWnd`, e não a função nativa
`NCEquipItemWnd` auditada anteriormente.

O `Interface.u` original foi identificado pelo hash
`4ca40e2936138d9551412767c695b6e54e8f2843daf437536811705704b91019`.
Seu export 3176, `InventoryWnd.EquipItemUpdate`, encaminhava tanto máscara 1
quanto 8192 para `m_equipItem[0]`. O trecho comum chama `Clear()` e `AddItem()`:
a segunda atualização substituía a primeira tattoo no mesmo controle.

| Máscara original | Antes | Agora | Posição no XDAT original |
|---|---|---|---|
| 1 — Left Tattoo, incluindo 27622/27602 | `m_equipItem[0]` | `m_equipItem[3]` / `EquipItem_Hair2` | x=92, y=36; terceiro espaço |
| 8192 — AIO Tattoo 27307 | `m_equipItem[0]` | Mesmo controle / `EquipItem_Underwear` | x=137, y=36; quarto espaço |

Ambos os controles têm 34×34 pixels e não se intersectam. `OnLoad` chama
`InitHandle`, que vincula efetivamente o índice 3 ao controle `EquipItem_Hair2`.
O DAT e as máscaras enviadas ao servidor não mudam. Os caminhos de clique,
arraste, desequipar e remoção de itens permanecem byte a byte originais.

A correção substitui apenas o literal do índice no primeiro caso. O token
`IntZero` ocupa um byte, enquanto `IntConstByte(3)` ocupa dois. O gerador
recalcula os destinos de saltos na representação da VM, preservando a
distinção entre referências compactadas no arquivo e referências de quatro
bytes em memória. A função corrigida e uma nova tabela de exports são
acrescentadas ao pacote. Todos os outros objetos, imports, nomes, flags e GUID
permanecem originais. Não há reconstrução aproximada dos demais scripts.

O `NWindow.dll` original foi restaurado. Ele continua incluído em `patch/`
para desfazer a alteração nativa em instalações que receberam a primeira
tentativa. O script antigo de instalação está desativado e sua evidência foi
marcada como histórica.

Seis testes em `test_inventory_script.py` passaram. Eles verificam a edição
exata da árvore de tokens, todos os destinos de controle, a preservação dos
demais exports, a vinculação dos controles e as coordenadas do XDAT. Um
interpretador restrito aos dois casos e ao trecho comum de `Clear/AddItem`
reproduz a sobreposição antes da alteração e mantém os dois itens depois,
nas duas ordens de chegada e após substituir a Left Tattoo por outra do mesmo
slot. Esse teste simula os métodos dos controles; não é uma execução completa
da VM/interface em jogo. A confirmação visual pelo usuário continua pendente.

Este pacote é para a interface original Interlude cujo XDAT tem hash
`ee755d9865e548398d822493b9536a40b3f7483108b582723d89b03eeb803c55`.
A interface Classic usa arquivos diferentes e não foi substituída por este
instalador. O segundo slot de cabelo é reservado à Left Tattoo no perfil C4;
um acessório exclusivo Interlude de máscara 262144 também usaria esse controle
e não deve ser considerado compatível simultaneamente com essa reserva.

Reprodução, com a base original versionada:

```sh
PYTHONPATH=research/client-port python3 -m unittest discover -s research/client-port -p test_inventory_script.py -v
PYTHONPATH=research/client-port python3 research/client-port/patch_inventory_interface.py --install /caminho/do/cliente/system
python3 patch/verify.py /caminho/do/cliente
```

O instalador confere os hashes de entrada, salva backup, substitui os arquivos
atomicamente e restaura os anteriores em caso de falha na atualização. A
ativação ocorre na próxima abertura do cliente. Hash instalado e backup em
`inventory-script.json`.

Referências primárias do formato, consultadas para a leitura dos arquivos:

- [acmi/L2unreal — tokens e tamanhos de bytecode, commit 811bec0](https://github.com/acmi/L2unreal/tree/811bec0f0990ff725019dbd7fc8edf6b1928f809/src/main/java/acmi/l2/clientmod/unreal/bytecode).
- [acmi/xdat_editor_schema — propriedades Interlude, commit 26c010a](https://github.com/acmi/xdat_editor_schema/blob/26c010ab5b5fc8fec505aee910ccf64aac4a3731/src/main/groovy/ct0/DefaultProperty.groovy).

O código da interface Classic publicado por L2jBrasil ajudou a localizar o
fluxo; a alteração final foi derivada e testada no bytecode do arquivo local
original, sem compilar ou instalar aquela fonte externa.
