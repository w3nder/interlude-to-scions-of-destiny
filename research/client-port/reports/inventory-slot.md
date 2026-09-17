> Histórico: ajuste retirado após o usuário reproduzir a falha. Não corrigia o caminho de InventoryWnd em Interface.u. Substituído por [inventory-script-2](inventory-script.md).

# Tattoo AIO: slot do inventário

O ajuste `inventory-slot-1` acrescenta `patch/system/NWindow.dll`. A DLL de
protocolo continua na build 13; este ajuste não altera pacotes nem DATs.

Nos dados C4, a AIO Tattoo (27307) usa `body_part=13` e máscara de equipamento
`0x2000`. Tattoos comuns verificadas, como 27602 e 27622, usam `body_part=0` e
máscara `1`. Os DATs migrados preservam esses campos.

O mapeador nativo C4 resolve `0x2000` para a célula visual 2. O Interlude resolve
essa máscara para 19, mas seu `NCEquipItemWnd::OnPaint` não desenha a célula 19
e seu teste de coordenadas não encontra essa célula. A correção muda apenas o
imediato desse retorno de 19 para 2. A tattoo comum permanece na célula 3 do
Interlude; são células e regiões de clique separadas.

O caminho nativo de clique duplo seleciona o item pelo mesmo mapeador e passa
a máscara original do item (`item+0x1e6c`) para a operação de desequipar. A
correção não troca essa máscara por um índice visual.

Foram aprovados quatro testes em `test_native_inventory_slot.py`:

- Execução das funções x86 originais C4 e Interlude para reproduzir a diferença.
- Execução da função corrigida, com a AIO e a tattoo comum em células distintas.
- Comparação dos demais valores de máscara e identidades de brincos/anéis com
  o Interlude original; execução do teste nativo de coordenadas, incluindo sua
  função geométrica e conversão x87, em sete pontos.
- Exatamente um byte alterado; arquivos desconhecidos são rejeitados.

A validação visual no jogo permanece pendente. Este é um perfil para o
servidor C4: a célula 2 é reservada para a máscara C4 `0x2000`. A máscara de
segundo acessório de cabelo `0x40000`, exclusiva do mapeador Interlude, também
usaria essa célula e não é suportada simultaneamente por esta reserva. O
mapeador original C4 não reconhece essa máscara.

Evidências de desenho, seleção e clique:
`../evidence/inventory-slot/`. Hashes, instalação e backup:
`inventory-slot.json`. A base original em `base/` não foi alterada.

Para reproduzir neste ambiente, com os dois binários de pesquisa originais:

```sh
PYTHONPATH=/tmp/l2k-port-test-deps:research/client-port python3 -m unittest discover -s research/client-port -p test_native_inventory_slot.py -v
PYTHONPATH=/tmp/l2k-port-test-deps python3 research/client-port/patch_inventory_slot.py --install /caminho/do/cliente/system
python3 patch/verify.py /caminho/do/cliente
```

A instalação verifica o hash completo, salva backup e substitui o arquivo
atomicamente. O processo de jogo que já está aberto permanece na versão que
carregou; o ajuste entra na próxima abertura.
