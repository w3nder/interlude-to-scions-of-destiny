# Pesquisa de compatibilidade C4 → Interlude

Leia `CONTEXT.md` para o escopo confirmado e `COMPARISON.md` para os resultados.
A extração lê os binários; os testes nativos executam funções x86 isoladas no Unicorn, sem conexão ao servidor. O patch distribuído fica em `../../patch/`.

## Reproduzir no diretório L2Killer

```sh
python3 -m venv research/client-port/venv
research/client-port/venv/bin/pip install -r research/client-port/requirements.txt
research/client-port/venv/bin/python research/client-port/extract_protocol.py system/engine.dll research/client-port/killer-reextracted.json
research/client-port/venv/bin/python research/client-port/extract_protocol.py /Users/wenderteixeira/Desktop/system-1/engine.dll research/client-port/system-1-opcodes.json
research/client-port/venv/bin/python research/client-port/extract_protocol.py /Users/wenderteixeira/Desktop/C6_System_Win10Supported/engine.dll research/client-port/interlude-reference-opcodes.json
python3 research/client-port/compare_protocols.py
```

A comparação verifica por assertions o hash da origem, os nomes/slots de
recepção e os opcodes/formatos dos envios recuperados em relação ao catálogo
anterior. Não é um teste de protocolo em execução. Nomes de export, limites
por padding e tabela de descritores de 260 bytes são heurísticas específicas
destes binários. Segmentos condicionais e repetidos não formam um esquema
linear; igualdade de formatos não estabelece igualdade dos campos.

`ExportPacketEvidence.java` é o script Ghidra de decompilação dirigida.
`ghidra/` contém o projeto de análise; `decompiled/` contém a saída dos dois
handlers de personagem. Tipos e assinaturas da saída ainda são inferências.

O histórico abaixo descreve as etapas iniciais. Para o estado atual, consulte `reports/coverage.md` e o README da raiz.

## Evidência de autenticação e primeiro conversor

Veja `AUTHENTICATION.md` para o cruzamento com o backend Go e os pontos de
envio/recepção mapeados. Para reconstruir os blocos e executar os testes offline:

```sh
research/client-port/venv/bin/python research/client-port/recover_handshake_evidence.py
python3 -m unittest discover -s research/client-port -p 'test_handshake_codec.py' -v
```

`handshake_codec.py` converte apenas o payload ProtocolVersion de 746 para 656,
com validação estrita do bloco. Não executa login nem instala hooks.

`game_transport.py` acrescenta a referência de transporte por socket;
`TRANSPORT.md` descreve cobertura e o futuro gerador por perfil de builds.

```sh
research/client-port/venv/bin/python -m unittest discover -s research/client-port -p 'test_*.py' -v
```

Os testes `test_native_cipher.py` usam Unicorn para emular instruções da DLL
C4 fingerprintada. Sob o sandbox macOS desta sessão, Unicorn aborta antes da
emulação na inicialização de cache; esses testes passaram fora do sandbox.

## Biblioteca C++ experimental

Veja `native/README.md`. Antes da suíte completa, compile os artefatos:

```sh
python3 research/client-port/native/build.py
research/client-port/venv/bin/python research/client-port/native/inspect_profile.py
```

`build/L2KProtocolCore.dll` é a biblioteca Windows x86 compilada do código atual,
incluindo bootstrap e hooks. O artefato candidato pode diferir da versão
distribuída em `patch/system/`; consulte os manifestos antes de instalar.
