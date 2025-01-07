#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nomeUsuario[50];
    char email[50];
    char rua[100];
    char telefone[20];
    char cep[10];
} Usuario;

void armazenarDadosUsuario(Usuario *usuario) {
    FILE *arquivo;

    // Abre o arquivo 
    arquivo = fopen("DADOS_USUARIO.TXT", "a");
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo!\n");
        exit(1);
    }

    // Escreve os dados do usuário no arquivo
    fprintf(arquivo, "Nome de usuario: %s\n", usuario->nomeUsuario);
    fprintf(arquivo, "Email: %s\n", usuario->email);
    fprintf(arquivo, "Rua: %s\n", usuario->rua);
    fprintf(arquivo, "Telefone: %s\n", usuario->telefone);
    fprintf(arquivo, "CEP: %s\n\n", usuario->cep); 

    fclose(arquivo);
}

void coletarDadosUsuario(Usuario *usuario) {
    printf("\nDigite o nome de usuario: ");
    fgets(usuario->nomeUsuario, sizeof(usuario->nomeUsuario), stdin);
    usuario->nomeUsuario[strcspn(usuario->nomeUsuario, "\n")] = 0; 

    printf("Digite o email: ");
    fgets(usuario->email, sizeof(usuario->email), stdin);
    usuario->email[strcspn(usuario->email, "\n")] = 0;

    printf("Digite a rua: ");
    fgets(usuario->rua, sizeof(usuario->rua), stdin);
    usuario->rua[strcspn(usuario->rua, "\n")] = 0;

    printf("Digite o telefone: ");
    fgets(usuario->telefone, sizeof(usuario->telefone), stdin);
    usuario->telefone[strcspn(usuario->telefone, "\n")] = 0;

    printf("Digite o CEP: ");
    fgets(usuario->cep, sizeof(usuario->cep), stdin);
    usuario->cep[strcspn(usuario->cep, "\n")] = 0;
}

int main(void) {
    Usuario usuario;
    char resp = 'S';

    while (resp == 'S' || resp== 's') {
        // Coleta os dados do usuário
        coletarDadosUsuario(&usuario);
        // Armazena os dados do usuário em um arquivo
        armazenarDadosUsuario(&usuario);
        printf("\nCadastro realizado com sucesso!\n");
        printf("Deseja cadastrar outro usuario? (S/N): ");
        scanf(" %c", &resp); 
        while (getchar() != '\n'); 
    }
    system("pause");
    return 0;
}
