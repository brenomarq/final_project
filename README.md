## Sistema de Gerenciamento de Mercado em C

### Descrição Geral

Este código em C implementa um sistema básico de gerenciamento para um mercadinho. O programa permite ao usuário cadastrar produtos, listar produtos disponíveis, adicionar itens ao carrinho de compras, visualizar o carrinho e finalizar o pedido, gerando uma fatura detalhada. Este projeto é um trabalho da disciplina de programação estruturada, sendo a última atividade
da disciplina do primeiro semestre de Ciência da Computação na Universidade Católica de Brasília.

### Estrutura do Código

- **Estruturas:**
  - `Produto`: Armazena informações sobre um produto, como código, nome e preço.
  - `Carrinho`: Representa um item no carrinho, contendo um produto e a quantidade.
- **Funções:**
  - `menu()`: Apresenta o menu principal para o usuário.
  - `cadastrarProduto()`: Permite cadastrar um novo produto no sistema.
  - `listarProdutos()`: Exibe a lista completa de produtos cadastrados.
  - `comprarProduto()`: Adiciona um produto ao carrinho de compras.
  - `pegarProdutoPorCodigo()`: Retorna um produto específico com base em seu código.
  - `infoProduto()`: Exibe as informações detalhadas de um produto.
  - `temNoCarrinho()`: Verifica se um produto já está no carrinho.
  - `visualizarCarrinho()`: Mostra os itens presentes no carrinho.
  - `fecharPedido()`: Finaliza o pedido, gerando uma fatura detalhada e zerando o carrinho.

### Funcionamento

1. **Menu Principal:** O programa inicia apresentando um menu com as opções disponíveis para o usuário.
2. **Cadastro de Produtos:** O usuário pode cadastrar novos produtos, informando o nome e o preço.
3. **Listagem de Produtos:** A lista de produtos cadastrados pode ser visualizada a qualquer momento.
4. **Compra de Produtos:** O usuário escolhe um produto pelo código e ele é adicionado ao carrinho sem duplicação.
5. **Visualização do Carrinho:** O carrinho de compras pode ser visualizado para verificar os itens adicionados.
6. **Finalização do Pedido:** Ao finalizar o pedido, o sistema gera uma fatura detalhada com o valor total da compra e
   reinicia o carrinho.

### Observações sobre o Código

- **Arrays Fixas:** O código utiliza arrays de tamanho fixo para armazenar os produtos e o carrinho. Isso limita a quantidade de produtos e itens que podem ser cadastrados.
- **Duplicação de Produtos no Carrinho:** O código original tinha um bug que permitia a duplicação de produtos no carrinho. Essa falha foi corrigida na versão apresentada.

### Como Usar

1. **Compilação:** Compile o código usando um compilador C, como GCC.
   ```bash
   gcc main.c market.c -o main
   ```
2. **Execução:** Execute o programa gerado.

  ```bash
  ./main
  ```

3. **Interação:** Siga as instruções do menu para realizar as operações desejadas.
