#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int codigo;
  char nome[30];
  float preco;
} Produto;

typedef struct {
  Produto produto;
  int quantidade;
} Carrinho;

void cadastrarProduto(Produto produtos[], int posicao);

void listarProdutos(Produto produtos[], int pos_atual);

void infoProduto(Produto produto);

void visualizarCarrinho(Carrinho carrinho[], int pos_atual);

int main() {
  Produto produtos[50];
  Carrinho carrinho[50];
  int entrada, pos_pro = 0, pos_car = 0;

  printf("MERCADINHO BOA VISTA\n");
  printf("Vendemos com honestidade e confianca\n");

  do {
    printf("\nDigite o que deseja fazer no sistema:\n");
    printf("[1] Cadastrar produtos\n");
    printf("[2] Listar produtos\n");
    printf("[3] Comprar produto\n");
    printf("[4] Visualizar carrinho\n");
    printf("[5] Finalizar pedido\n");
    printf("Opcao: ");

    scanf("%d", &entrada);
    getchar();

    switch (entrada) {
      case 1:
        do {
          cadastrarProduto(produtos, pos_pro);
          pos_pro++;

          printf("\nProduto cadastrado com sucesso!\n");
          printf("\nDeseja cadastrar mais?\n[1] Sim [0] Nao: ");
          scanf("%d", &entrada);
          getchar();
        } while (entrada != 0);
        break;

      case 2:
        listarProdutos(produtos, pos_pro);
        break;

      case 3:
        /*Comprar produto*/
        break;

      case 4:
        visualizarCarrinho(carrinho, pos_car);
        break;

      case 5:
        /*Fechar pedido*/
        break;

      default:
        printf("\nOpção inválida!\n");
    }

    printf("\nDeseja finalizar o sistema?\n[0] Sim [1] Nao: ");
    scanf("%d", &entrada);
    system("clear");
  } while (entrada != 0);

  return 0;
}

void cadastrarProduto(Produto produtos[], int posicao) {
  system("clear");
  produtos[posicao].codigo = posicao;

  printf("Digite as informacoes do produto:\n");
  printf("Nome do produto: ");
  fgets(produtos[posicao].nome, sizeof(produtos[posicao].nome), stdin);

  printf("Preco do produto: ");
  scanf("%f", &produtos[posicao].preco);
  getchar();
}

void listarProdutos(Produto produtos[], int pos_atual) {
  system("clear");
  printf("Produtos listados:");
  for (int i = 0; i < pos_atual; ++i) {
    infoProduto(produtos[i]);
  }
}

void infoProduto(Produto produto) {
  printf("\nCodigo do produto: %d\n", produto.codigo);
  printf("Nome do produto: %s", produto.nome);
  printf("Preco do produto: %.2f\n", produto.preco);
}

void visualizarCarrinho(Carrinho carrinho[], int pos_atual) {
  if (pos_atual == 0) {
    printf("\nO carrinho esta vazio!\n");
    return;
  }

  printf("Produtos no carrinho:");
  for (int i = 0; i < pos_atual; i++) {
    printf("\nProduto: %s", carrinho[i].produto.nome);
    printf("Quantidade: %d\n", carrinho[i].quantidade);
  }
}
