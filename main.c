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



int main() {
  Produto produtos[50];
  Carrinho carrinho[50];
  int entrada;

  do {
    switch (entrada) {
      case 1:
        /*Cadastrar produtos*/
        break;

      case 2:
        /*Listar produtos*/
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
  } while (entrada != 0);

  return 0;
}
