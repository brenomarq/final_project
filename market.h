#ifndef MARKET_H
#define MARKET_H

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

/*Apresenta as opcoes para o usuario.*/
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

#endif
