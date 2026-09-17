# System Interlude de referência

`C6_System_Win10Supported/` contém os arquivos originais da base usada no desenvolvimento, sem a DLL e sem as mudanças do porte. Não é o cliente completo.

Copie seu conteúdo para uma nova pasta `system` dentro do cliente Interlude completo. Depois aplique `patch/` na raiz do cliente, por último. Consulte o README principal.

`manifest.json` registra os hashes dos arquivos originais. Essa inclusão resolve a ausência da base na distribuição; o carregamento no Windows do usuário ainda precisa ser confirmado.
