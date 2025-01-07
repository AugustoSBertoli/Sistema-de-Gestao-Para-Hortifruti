#include <stdio.h>
#include <stdlib.h>

void readUserData() {
    FILE *PTRARQ;
    char line[150];

    // Abre o arquivo no modo de leitura
    PTRARQ = fopen("DADOS_USUARIO.TXT", "r");
    if (PTRARQ == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo! Verifique se o arquivo USER_DATA.TXT existe.\n");
        exit(1);
    }

    printf("Dados do usuário armazenados no arquivo:\n");

    // Lê e imprime cada linha até o final do arquivo (EOF)
    while (fgets(line, sizeof(line), PTRARQ) != NULL) {
        printf("%s", line);
    }

    fclose(PTRARQ);
}

int main(void) {
    readUserData();
    system("pause");
    return 0;
}
