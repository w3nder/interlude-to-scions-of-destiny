# Automação do port por perfil

A esteira atual atende às hashes exatas das duas engines já analisadas. Ela
não promete converter automaticamente builds desconhecidas ou todos os campos.

Na raiz L2Killer:

```
research/client-port/venv/bin/python research/client-port/port_client.py package
```

Esse comando extrai subopcodes dos callsites, gera o filtro de solicitações,
compila a DLL, executa toda a suíte, produz cobertura por pacote e empacota uma
atualização. Qualquer divergência de hash, seletor não resolvido ou teste falho
interrompe o pacote. Os testes x86 exigem execução fora do sandbox macOS.

O relatório `reports/coverage.json` enumera métodos de envio e slots de recepção, sem confundir inventário com schemas completos ou cobertura
semântica. `coverage.md` resume as categorias e o que já está implementado.

## Clã

Conversores 0x53/0x54/0x55 recebem payload decifrado, conferem layout completo,
strings UTF-16 terminadas, contagem e capacidade. A lista C4 ganha os campos de
clã principal/tipo de unidade e o campo sponsor de cada membro. Atualização e
adição de membro ganham os campos ausentes. Campos existentes são preservados.
Pacotes que já são Interlude passam sem expansão. Layout reconhecido mas inválido
é registrado e descartado antes do parser nativo. Isso não cria academias no C4.

O envio passa pelo serializador original, consulta uma política explícita, e só
então alcança o sender/cifra originais. Bloqueios atuais: D0:0019–001E e D0:0024.
Todos os seletores C4 observados continuam permitidos; cada um dos 65.536
subopcodes possíveis é testado contra a política. Ausência em extração parcial
não vira bloqueio global: as demais funções novas aparecem como pendência.

A suíte também gera 100 listas com 0,1,2,30,100 membros e campos variados,
verifica truncamentos/capacidades, nomes Unicode, preservação de pacotes modernos,
e executa os wrappers x86 contra a cifra original Interlude, comparando bytes e
chaves evolutivas. Esses testes não substituem confirmação visual do clã no jogo.

## Evidência de protocolo

- Engines locais: handlers 0x53,0x54,0x55 em clan-inbound.json.
- Layout Interlude e significado dos campos adicionais conferidos na implementação:
  https://github.com/VytautasBoznis/l2.skilas.lt/blob/master/aCis_gameserver/java/net/sf/l2j/gameserver/network/serverpackets/PledgeShowMemberListAll.java
- Registros e subopcodes exatos: outbound-policy.json.

## Diagnóstico passivo

Cada processo novo grava `system/L2KGameTrace-<PID>.tsv` com direção, opcode,
subopcode, tamanho e decisão. Nenhum payload, texto de chat, conta ou chave é
persistido. Há limite de 50.000 eventos; jogo continua quando o limite é atingido.

```
research/client-port/venv/bin/python research/client-port/port_client.py report --trace /caminho/L2KGameTrace-123.tsv
```

O leitor tolera uma linha incompleta no arquivo ativo e agrega decisões/tamanhos.
Tráfego observado prova ocorrência, não comportamento correto de uma função.

## Instalação e retorno

`install_protocol_update.py` confere engine, import de bootstrap e DLL anterior,
salva backup e troca a DLL por rename atômico. O processo de jogo aberto mantém
sua DLL antiga; a atualização vale na próxima abertura. Não encerra o jogo.
Para retornar, com o jogo fechado, restaure a DLL `before-clan` ao nome original.

## Catálogo e variantes — build 5

O pacote inclui `structured-inbound.json` e `outbound-schemas.json`, além do catálogo
anterior. As regras descrevem estruturas completas reconhecidas, condições e limites,
não apenas números de opcode. Há 36 conversores S2C, 3 C2S e um validador de
parâmetros de mensagens. O teste automático cobre estrutura, limites e integração
representativa com o hook x86; não constitui validação de todas as telas do jogo.

A geração permanece incompleta (`release_complete=false`). Diferenças ainda sem
regra confirmada permanecem indicadas no relatório. O trace usa agora
`L2KGameTrace-<PID>-<tick>.tsv`, preservando arquivos de sessões anteriores.

## Auditoria dos iguais e regressão de entrada

A build `6f710c50` foi retirada por rejeitar a variante real de `CharacterSelected`.
O cliente foi restaurado para `9bd942c5`; `build/current-runtime.json` distingue a
instalação real do código candidato. O pacote retirado é recusado pelo instalador.

`check` e `package` agora executam `audit_wire_equivalence.py` depois dos testes.
A auditoria compara argumentos efetivos do serializer, segue controle de fluxo até
RET e recupera formatos ausentes. Consulte `reports/wire-equivalence.md` e o JSON
correspondente: igualdade no serializer, igualdade de chamadas de decoder e
compatibilidade semântica completa são classificações diferentes.

## Migração de assets (build 6)

Pipeline: `extract_asset_tables.py` → `audit_asset_dependencies.py` → `migrate_asset_tables.py` → `install_assets_update.py <pacote DLL>`. Saída em `build/assets-interlude`, com hashes, referências pendentes e seis DATs Interlude recompilados e validados por roundtrip. Instalação verifica engine/base, mantém backup e recusa substituir pacotes nativos diferentes.

`inspect_asset_audit.py` relaciona o log da próxima sessão com as tabelas migradas. Diagnóstico é somente leitura: layout desconhecido não bloqueia pacote. Registra IDs de catálogo e campos de itens, nunca payload bruto, chat, credenciais ou nomes de personagens. Build 6 passou em 69 testes; detalhes e limites em `reports/assets-validation.md`.


## Build 13: conteúdo e status

`audit_content_tables.py` extrai as tabelas adicionais com os DDFs versionados. Use `L2K_DAT_WINEPREFIX=/caminho/do/prefixo` para isolar o Wine das ferramentas do cliente aberto. `migrate_content_tables.py` reconstrói sete DATs, valida cada linha/coluna e a codificação RSA413; `install_content_update.py` confere a baseline e instala com backup. `report_content_disposition.py` cobre os 33 DATs e lista os recursos ausentes.

`install_usk_update.py` instala somente o pacote verificado da skill 10615. Não substitui pacotes nativos. A DLL da build 13 restaura o campo de experiência de StatusUpdate e bloqueia IDs de ações de summons exclusivos do Interlude. `reports/status-content-build13.md` documenta endereços, testes e limites.

O catálogo tem 213 pontos de envio C4, 204 métodos compartilhados e nenhuma função de envio sem classificação de evidência. Igualdade de bytes nos casos testados não certifica todas as telas ou qualquer build de servidor. Os resultados instalados ficam em `build/current-runtime.json`; a versão distribuída e os hashes ficam em `patch/manifest.json`.
