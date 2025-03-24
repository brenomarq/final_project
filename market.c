#include "market.h"

void menu() {
  printf("\nDigite o que deseja fazer no sistema:\n");
  printf("[1] Cadastrar produtos\n");
  printf("[2] Listar produtos\n");
  printf("[3] Comprar produto\n");
  printf("[4] Visualizar carrinho\n");
  printf("[5] Finalizar pedido\n");
  printf("Opcao: ");
}

void cadastrarProduto(Produto produtos[], int posicao) {
  if (posicao > 50) {
    printf("\nNumero maximo de produtos ja cadastrados!\n");
    return;
  }

  system("clear");
  produtos[posicao].codigo = posicao + 1;

  printf("Digite as informacoes do produto:\n");
  printf("Nome do produto: ");
  fgets(produtos[posicao].nome, sizeof(produtos[posicao].nome), stdin);

  printf("Preco do produto: R$");
  scanf("%f", &produtos[posicao].preco);
  getchar();
}

void listarProdutos(Produto produtos[], int pos_atual) {
  if (pos_atual == 0) {
    printf("\nNao ha produtos cadastrados ainda!\n");
    return;
  }

  printf("\nProdutos listados:");
  for (int i = 0; i < pos_atual; ++i) {
    infoProduto(produtos[i]);
  }
}

int comprarProduto(Produto produtos[], Carrinho carrinho[], int pos_pro, int pos_car) {
  int codigo;

  system("clear");
  printf("Digite o codigo do produto: ");
  scanf("%d", &codigo);

  if (codigo > pos_pro) {
    printf("\nProduto nao encontrado!\n");
    return 0;
  }

  if (pos_car > 50) {
    printf("\nNumero maximo de produtos ja adicionados ao carrinho!\n");
    return 0;
  }

  if (temNoCarrinho(codigo, carrinho, pos_car)) {
    for (int i = 0; i < pos_car; i++) {
      if (carrinho[i].produto.codigo == codigo) {
        carrinho[i].quantidade++;
      }
    }

    printf("\nProduto adicionado ao carrinho!\n");

    return 0;
  }

  Produto prod = pegarProdutoPorCodigo(codigo, produtos);
  carrinho[pos_car].produto.codigo = prod.codigo;
  strcpy(carrinho[pos_car].produto.nome, prod.nome);
  carrinho[pos_car].produto.preco = prod.preco;
  carrinho[pos_car].quantidade = 1;

  printf("\nProduto adicionado ao carrinho!\n");

  return 1;
}

Produto pegarProdutoPorCodigo(int codigo, Produto produtos[]) {
  return produtos[codigo - 1];
}

void infoProduto(Produto produto) {
  printf("\nCodigo do produto: %d\n", produto.codigo);
  printf("Nome do produto: %s", produto.nome);
  printf("Preco do produto: R$%.2f\n", produto.preco);
}

int temNoCarrinho(int codigo, Carrinho carrinho[], int pos_atual) {
  for (int i = 0; i < pos_atual; i++) {
    if (carrinho[i].produto.codigo == codigo) {
      return 1;
    }
  }

  return 0;
}

void visualizarCarrinho(Carrinho carrinho[], int pos_atual) {
  if (pos_atual == 0) {
    printf("\nO carrinho esta vazio!\n");
    return;
  }

  system("clear");
  printf("\nProdutos no carrinho:");
  for (int i = 0; i < pos_atual; i++) {
    printf("\nProduto: %s", carrinho[i].produto.nome);
    printf("Quantidade: %d\n", carrinho[i].quantidade);
  }
}

void fecharPedido(Carrinho carrinho[], int pos_atual) {
  float soma = 0;

  system("clear");
  printf("FATURA DETALHADA");
  for (int i = 0; i < pos_atual; ++i) {
    printf("\nProduto: %s Quantidade: %d\n",
    carrinho[i].produto.nome,
    carrinho[i].quantidade);
    printf("Valor: %.2f\n", carrinho[i].produto.preco * carrinho[i].quantidade);

    soma += carrinho[i].produto.preco * carrinho[i].quantidade;
  }

  printf("\nO valor total eh R$%.2f\n", soma);
}
