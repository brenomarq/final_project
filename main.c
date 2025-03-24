#include "market.h"

int main() {
  Produto produtos[50];
  Carrinho carrinho[50];
  int entrada, pos_pro = 0, pos_car = 0;
  // As variaveis acompanham a posicao atual dos elementos da array

  printf("MERCADINHO BOA VISTA\n");
  printf("Vendemos com honestidade e confianca\n");

  do {
    menu(); // Apresenta o menu ao usuario

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

      default:
        printf("\nOpção invalida!\n");
    }

    printf("\nDeseja continuar no sistema?\n[1] Sim [0] Nao: ");
    scanf("%d", &entrada);
    system("clear");
  } while (entrada != 0);

  printf("SISTEMA FINALIZADO COM SUCESSO!\n");

  return 0;
}
