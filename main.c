#include <stdio.h>

typedef struct {
  int codigo;
  char nome[30];
  float preco;
} Produto;

typedef struct {
  Produto produto;
  int quantidade;
} Carrinho;

void listarProdutos(Produto produtos[]);

void infoProduto(Produto produto);

int main() {
  Produto produtos[50];
  Carrinho carrinho[50];
  int entrada;

  do {
    scanf("%d", &entrada);

    switch (entrada) {
      case 1:
        /*Cadastrar produtos*/
        break;

      case 2:
        listarProdutos(produtos);
        break;

      case 3:
        /*Comprar produto*/
        break;

      case 4:
        /*Visualizar carrinho*/
        break;

      case 5:
        /*Fechar pedido*/
        break;

      default:
        printf("\nOpção inválida!\n");
    }

    scanf("%d", &entrada);
  } while (entrada != 0);

  return 0;
}

void listarProdutos(Produto produtos[]) {
  for (int i = 0; i <= 50; ++i) {
    if (produtos[i].codigo == i) {
      infoProduto(produtos[i]);
    }
  }
}

void infoProduto(Produto produto) {
  printf("\nCodigo do produto: %d\n", produto.codigo);
  printf("Nome do produto: %s\n", produto.nome);
  printf("Preco do produto: %.2f\n", produto.preco);
}
