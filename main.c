#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int codigo;
  char nome[30];
  float preco;
} Produto;

typedef struct {
  Produto produto;
  int quantidade;
} Carrinho;

/*Responsavel por todo o fluxo do programa.*/
void menu();

/*Cadastra o produto na lista de produtos.*/
void cadastrarProduto(Produto produtos[], int posicao);

/*Lista todos os produtos da lista de produtos.*/
void listarProdutos(Produto produtos[], int pos_atual);

/*Adiciona o produto ao carrinho e retorna 1, caso deva incrementar a posicao,
e 0, caso nao.*/
int comprarProduto(Produto produtos[], Carrinho carrinho[], int pos_pro, int pos_car);

/*Retorna um produto da lista pelo codigo especificado.*/
Produto pegarProdutoPorCodigo(int codigo, Produto produtos[]);

/*Imprime as informacoes detalhadas do produto*/
void infoProduto(Produto produto);

/*Confere se aquele produto com o codigo especificado ja foi adicionado
ao carrinho.*/
int temNoCarrinho(int codigo, Carrinho carrinho[], int pos_atual);

/*Lista todos os produtos ja adicionados ao carrinho de maneira detalhada.*/
void visualizarCarrinho(Carrinho carrinho[], int pos_atual);

/*Fecha o pedido gerando uma fatura detalhada ao usuario e reiniciando
o carrinho.*/
void fecharPedido(Carrinho carrinho[], int pos_atual);

int main() {
  menu();

  printf("SISTEMA FINALIZADO COM SUCESSO!\n");

  return 0;
}

void menu() {
  Produto produtos[50];
  Carrinho carrinho[50];
  int entrada, pos_pro = 0, pos_car = 0;
  // As variaveis acompanham a posicao atual dos elementos da array

  printf("MERCADINHO BOA VISTA\n");
  printf("Vendemos com honestidade e confianca\n");

  do {
    printf("\nDigite o que deseja fazer no sistema:\n");
    printf("[1] Cadastrar produtos\n");
    printf("[2] Listar produtos\n");
    printf("[3] Comprar produto\n");
    printf("[4] Visualizar carrinho\n");
    printf("[5] Finalizar pedido\n");
    printf("[6] Sair do Programa\n");
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
        if (comprarProduto(produtos, carrinho, pos_pro, pos_car)) {
          pos_car++;
        }
        break;

      case 4:
        visualizarCarrinho(carrinho, pos_car);
        break;

      case 5:
        fecharPedido(carrinho, pos_car);
        pos_car = 0; // Reinicia o carrinho
        break;

      case 6:
        printf("Encerrando programa...\n");
        break;

      default:
        printf("\nOpção invalida!\n");
    }
    system("clear");
  } while (entrada != 6);
}

void cadastrarProduto(Produto produtos[], int posicao) {
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

  if (temNoCarrinho(codigo, carrinho, pos_car)) {
    for (int i = 0; i < pos_car; i++) {
      if (carrinho[i].produto.codigo == codigo) {
        carrinho[i].quantidade++;
      }
    }

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
