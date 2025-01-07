#include <stdio.h>

#define MAX_PRODUTOS 60

typedef struct {
    char nome[30];
    float preco;
} Produto;

void exibirProdutos(Produto produtos[], int totalProdutos) {
    printf("Produtos disponiveis:\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("%d - %s: R$ %.2f\n", i + 1, produtos[i].nome, produtos[i].preco);
    }
}

float calcularTotal(Produto produtos[], int indices[], int quantidades[], int quantidade) {
    float total = 0.0;
    for (int i = 0; i < quantidade; i++) {
        total += produtos[indices[i]].preco * quantidades[i];
    }
    return total;
}

int main() {
    Produto produtos[MAX_PRODUTOS] = {
        // Frutas
        {"Maca", 2.50}, {"Banana", 1.20}, {"Laranja", 1.50}, {"Pera", 3.50}, {"Uva", 5.00},
        {"Abacaxi", 4.00}, {"Kiwi", 6.50}, {"Morango", 8.00}, {"Manga", 4.00}, {"Mamao", 3.00},
        {"Melancia", 1.00}, {"Caju", 6.50}, {"Melao", 5.00}, {"Ameixa", 3.50}, {"Pessego", 4.50},
        {"Figo", 8.00}, {"Goiaba", 3.00}, {"Abacate", 7.00}, {"Framboesa", 10.00}, {"Jabuticaba", 12.00},

        // Legumes
        {"Cenoura", 2.00}, {"Batata", 3.00}, {"Batata-doce", 3.50}, {"Abobrinha", 4.00},
        {"Beterraba", 3.00}, {"Chuchu", 2.50}, {"Berinjela", 4.50}, {"Vagem", 7.00},
        {"Nabo", 5.00}, {"Rabanete", 4.00}, {"Inhame", 6.00}, {"Ervilha", 5.00}, {"Milho", 2.50},
        {"Pepino", 3.00}, {"Pimentao", 4.00}, {"Abobora", 3.50}, {"Quiabo", 6.00}, {"Tomate", 4.00},
        {"Jilo", 5.50}, {"Alho-poro", 6.00},

        // Verduras
        {"Alface", 1.50}, {"Espinafre", 3.50}, {"Couve", 2.80}, {"Agarico", 3.00},
        {"Acelga", 3.50}, {"Rucula", 2.30}, {"Escarola", 2.50}, {"Repolho", 3.00}, 
        {"Almeirao", 2.20}, {"Brocolis", 5.00}, {"Couve-flor", 4.50}, {"Chicoria", 2.50},
        {"Mostarda", 3.50}, {"Dente-de-leao", 6.00}, {"Cebola", 1.70}, {"Salsa", 1.80},
        {"Endivia", 8.00}, {"Nabo verde", 5.00}, {"Couve-manteiga", 3.00}, {"Alface americana", 2.50}
    };

    int indices[MAX_PRODUTOS];
    int quantidades[MAX_PRODUTOS];
    int quantidade = 0;
    int opcao, qtd;

    while (quantidade < MAX_PRODUTOS) {
        exibirProdutos(produtos, MAX_PRODUTOS);
        printf("\nEscolha o produto (1-%d) ou 0 para finalizar: ", MAX_PRODUTOS);
        scanf("%d", &opcao);

        if (opcao == 0) {
            break;
        } else if (opcao < 1 || opcao > MAX_PRODUTOS) {
            printf("Opiçao invalida. Tente novamente.\n");
            continue;
        }

        printf("Quantidade para %s: ", produtos[opcao - 1].nome);
        scanf("%d", &qtd);

        indices[quantidade] = opcao - 1;
        quantidades[quantidade] = qtd;
        quantidade++;

        printf("Produto adicionado: %s (Quantidade: %d)\n", produtos[opcao - 1].nome, qtd);
    }

    float total = calcularTotal(produtos, indices, quantidades, quantidade);
    printf("\nTotal da compra: R$ %.2f\n", total);

    return 0;
}