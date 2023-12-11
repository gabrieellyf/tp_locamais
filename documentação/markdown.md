# Evolução do Backlog do Produto

## Sprint 1 (3 a 4 dias):

### 1. Definir a Estrutura Básica do Projeto
   - Criar arquivos principais (main.c, funcoes.h, funcoes.c).
   - Estabelecer estrutura inicial das funções e procedimentos.
   - **Responsável:** Arthur.

### 2. Cadastrar Cliente (Função 1)
   - Criar função de cadastro de cliente.
   - Implementar verificação de duplicidade de código.
   - Implementar persistência em arquivo.
   - **Responsável:** Gabrielly.

### 3. Cadastrar Veículo (Função 2)
   - Criar função de cadastro de veículo.
   - Implementar verificação de duplicidade de código.
   - Implementar persistência em arquivo.
   - **Responsável:** Raul.

**Entrega da Sprint 1:** Documentação inicial, estrutura básica e funcionalidades de cadastro.

## Sprint 2 (3 a 4 dias):

### 1. Cadastrar Locação (Função 3)
   - Criar função de cadastro de locação.
   - Validar disponibilidade de veículo.
   - Calcular quantidade de diárias e valor total.
   - **Responsável:** Arthur.

### 2. Baixa em Locação e Cálculo de Valor (Função 4)
   - Criar função de baixa em locação.
   - Calcular valor total considerando seguro.
   - Atualizar status do veículo para disponível.
   - **Responsável:** Gabrielly.

### 3. Pesquisas por Clientes e Veículos (Funções 5 e 6)
   - Criar funções de pesquisa por clientes e veículos.
   - Apresentar informações na tela.
   - **Responsável:** Raul.

**Entrega da Sprint 2:** Funcionalidades de locação, baixa, pesquisa e apresentação.

## Sprint 3 (3 a 4 dias):

### 1. Pesquisa de Locações por Cliente (Função 7)
   - Criar função de pesquisa de locações por cliente.
   - Apresentar informações na tela.
   - **Responsável:** Arthur.

### 2. Pontuação de Fidelidade (Função 8)
   - Criar função de cálculo de pontos de fidelidade.
   - Armazenar pontos no arquivo de clientes.
   - **Responsável:** Gabrielly.

### 3. Premiação de Clientes Fidelizados (Função 9)
   - Criar função de premiação para clientes com 500 pontos.
   - Notificar e armazenar informações.
   - **Responsável:** Raul.

**Entrega da Sprint 3:** Funcionalidades de pesquisa, pontuação e premiação.

# Issues no GitHub:

1. **Issue #1: Estrutura Básica do Projeto**
   - Criar arquivos principais e estrutura inicial.
   - **Responsável:** Arthur.

2. **Issue #2: Cadastro de Cliente**
   - Implementar função de cadastro.
   - Verificar duplicidade de código.
   - Implementar persistência.
   - **Responsável:** Gabrielly.

3. **Issue #3: Cadastro de Veículo**
   - Implementar função de cadastro.
   - Verificar duplicidade de código.
   - Implementar persistência.
   - **Responsável:** Raul.

4. **Issue #4: Cadastro de Locação**
   - Implementar função de cadastro.
   - Validar disponibilidade de veículo.
   - Calcular quantidade de diárias e valor total.
   - **Responsável:** Arthur.

5. **Issue #5: Baixa em Locação e Cálculo de Valor**
   - Implementar função de baixa.
   - Calcular valor total considerando seguro.
   - Atualizar status do veículo.
   - **Responsável:** Gabrielly.

6. **Issue #6: Pesquisas por Clientes e Veículos**
   - Implementar funções de pesquisa.
   - Apresentar informações na tela.
   - **Responsável:** Raul.

7. **Issue #7: Pesquisa de Locações por Cliente**
   - Implementar função de pesquisa.
   - Apresentar informações na tela.
   - **Responsável:** Arthur.

8. **Issue #8: Pontuação de Fidelidade**
   - Implementar função de cálculo de pontos.
   - Armazenar pontos no arquivo de clientes.
   - **Responsável:** Gabrielly.

9. **Issue #9: Premiação de Clientes Fidelizados**
   - Implementar função de premiação.
   - Notificar e armazenar informações.
   - **Responsável:** Raul.

10. **Issue #10: Função Extra Criada pelo Grupo**
    - Desenvolver uma função extra criativa.
    - **Responsável:** Equipe de Desenvolvimento.

# Documentação das Funcionalidades do Software

## Estrutura do Projeto

O projeto consiste em um conjunto de arquivos, sendo o principal denominado `main.c` e os demais responsáveis por armazenar informações específicas. O arquivo `main.c` desempenha um papel central, contendo a função principal e o menu interativo para a interação com o usuário. Além disso, temos o arquivo `funcoes.h`, que declara os protótipos das funções utilizadas no projeto, e o arquivo `funcoes.c`, responsável por implementar as funções definidas em `funcoes.h`.

## Cadastro de Cliente (Função 1)

- A função permite cadastrar um cliente, verificando a duplicidade de código.
- Os dados do cliente são armazenados no arquivo `clientes.dat`.
- Caso o código do cliente já exista, o sistema exibe uma mensagem de erro.

### Casos de Teste:

1. **Teste de Cadastro com Dados Válidos**
   - **Entrada:** Dados válidos de um novo cliente.
   - **Procedimento:** Executar a função de cadastro.
   - **Saída Esperada:** Cliente cadastrado com sucesso.

2. **Teste de Duplicidade de Código**
   - **Entrada:** Dados de um cliente com código já existente.
   - **Procedimento:** Executar a função de cadastro.
   - **Saída Esperada:** Exibição de mensagem de erro.

## Cadastro de Veículo (Função 2)

- A função possibilita cadastrar um veículo, verificando a duplicidade de código.
- Os dados do veículo são armazenados no arquivo `veiculos.dat`.
- Se o código do veículo já estiver em uso, o sistema informa um erro.

### Casos de Teste:

1. **Teste de Cadastro com Dados Válidos**
   - **Entrada:** Dados válidos de um novo veículo.
   - **Procedimento:** Executar a função de cadastro.
   - **Saída Esperada:** Veículo cadastrado com sucesso.

2. **Teste de Duplicidade de Código**
   - **Entrada:** Dados de um veículo com código já existente.
   - **Procedimento:** Executar a função de cadastro.
   - **Saída Esperada:** Exibição de mensagem de erro.

## Cadastrar Locação (Função 3)

- A função realiza o cadastro de uma locação, considerando a disponibilidade do veículo.
- Calcula a quantidade de diárias e o valor total da locação.
- Atualiza o status do veículo para indisponível.

### Casos de Teste:

1. **Teste de Cadastro de Locação com Veículo Disponível**
   - **Entrada:** Dados válidos para uma nova locação.
   - **Procedimento:** Executar a função de cadastro.
   - **Saída Esperada:** Locação cadastrada com sucesso.

2. **Teste de Cadastro de Locação com Veículo Indisponível**
   - **Entrada:** Dados de uma locação com veículo já locado.
   - **Procedimento:** Executar a função de cadastro.
   - **Saída Esperada:** Exibição de mensagem de veículo indisponível.

## Baixa em Locação e Cálculo de Valor (Função 4)

- A função realiza a baixa em uma locação, calculando o valor total considerando seguro.
- Atualiza o status do veículo para disponível.

### Casos de Teste:

1. **Teste de Baixa em Locação com Valor Calculado Corretamente**
   - **Entrada:** Locação com dias e valor previamente calculados.
   - **Procedimento:** Executar a função de baixa em locação.
   - **Saída Esperada:** Baixa realizada com sucesso e valor total correto.

2. **Teste de Baixa em Locação com Atualização de Status do Veículo**
   - **Entrada:** Locação com baixa realizada.
   - **Procedimento:** Verificar o status do veículo.
   - **Saída Esperada:** Status do veículo atualizado para disponível.

## Pesquisas por Clientes e Veículos (Funções 5 e 6)

- As funções permitem pesquisar informações sobre clientes e veículos.

### Casos de Teste:

1. **Teste de Pesquisa por Cliente Existente**
   - **Entrada:** Código de um cliente existente.
   - **Procedimento:** Executar a função de pesquisa por cliente.
   - **Saída Esperada:** Exibição das informações do cliente.

2. **Teste de Pesquisa por Cliente Inexistente**
   - **Entrada:** Código de um cliente não existente.
   - **Procedimento:** Executar a função de pesquisa por cliente.
   - **Saída Esperada:** Exibição de mensagem de cliente não encontrado.

3. **Teste de Pesquisa por Veículo Existente**
   - **Entrada:** Código de um veículo existente.
   - **Procedimento:** Executar a função de pesquisa por veículo.
   - **Saída Esperada:** Exibição das informações do veículo.

4. **Teste de Pesquisa por Veículo Inexistente**
   - **Entrada:** Código de um veículo não existente.
   - **Procedimento:** Executar a função de pesquisa por veículo.
   - **Saída Esperada:** Exibição de mensagem de veículo não encontrado.

## Pesquisa de Locações por Cliente (Função 7)

- Permite pesquisar locações por cliente, apresentando as informações na tela.

### Casos de Teste:

1. **Teste de Pesquisa de Locações para Cliente com Locações**
   - **Entrada:** Código de um cliente com locações.
   - **Procedimento:** Executar a função de pesquisa por locações.
   - **Saída Esperada:** Exibição das informações das locações do cliente.

2. **Teste de Pesquisa de Locações para Cliente sem Locações**
   - **Entrada:** Código de um cliente sem locações.
   - **Procedimento:** Executar a função de pesquisa por locações.
   - **Saída Esperada:** Exibição de mensagem de cliente sem locações.

## Pontuação de Fidelidade (Função 8)

- Calcula os pontos de fidelidade de um cliente com base nas locações.
- Armazena os pontos no arquivo `clientes.dat`.

### Casos de Teste:

1. **Teste de Cálculo de Pontos com Locações Suficientes**
   - **Entrada:** Cliente com locações suficientes para pontos.
   - **Procedimento:** Executar a função de cálculo de pontos.
   - **Saída Esperada:** Pontos calculados e armazenados corretamente.

2. **Teste de Cálculo de Pontos com Locações Insuficientes**
   - **Entrada:** Cliente com locações insuficientes para pontos.
   - **Procedimento:** Executar a função de cálculo de pontos.
   - **Saída Esperada:** Pontuação não alterada.

## Premiação de Clientes Fidelizados (Função 9)

- Premia clientes que acumularam 500 pontos de fidelidade.
- Notifica os clientes premiados e armazena informações no sistema.

### Casos de Teste:

1. **Teste de Premiação com Cliente Elegível**
   - **Entrada:** Cliente com 500 pontos de fidelidade.
   - **Procedimento:** Executar a função de premiação.
   - **Saída Esperada:** Cliente premiado e informações armazenadas corretamente.

2. **Teste de Premiação com Cliente Não Elegível**
   - **Entrada:** Cliente com menos de 500 pontos de fidelidade.
   - **Procedimento:** Executar a função de premiação.
   - **Saída Esperada:** Cliente não premiado e sem alterações.

