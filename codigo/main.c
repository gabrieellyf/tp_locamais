#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define MAX_CLIENTES 100
#define MAX_VEICULOS 100
#define MAX_LOCACOES 100

struct Cliente {
  char codigo[20];
  char nome[50];
  char endereco[100];
  char telefone[20];
};

struct Veiculo {
  char codigo[20];
  char descricao[50];
  char modelo[50];
  char cor[20];
  char placa[20];
  float valor_diaria;
  int ocupantes;
  char status[20];
};

struct Locacao {
  char codigo_locacao[20];
  char data_retirada[20];
  char data_devolucao[20];
  char seguro[5];
  int quantidade_dias;
  char codigo_cliente[20];
  char codigo_veiculo[20];
};

struct Cliente clientes[MAX_CLIENTES];
struct Veiculo veiculos[MAX_VEICULOS];
struct Locacao locacoes[MAX_LOCACOES];

int num_clientes = 0;
int num_veiculos = 0;
int num_locacoes = 0;

// Funções para manipulação de arquivos (continuação)
void salvar_veiculos_em_arquivo() {
  FILE * arquivo = fopen("veiculos.dat", "wb");
  if (arquivo == NULL) {
    perror("Erro ao abrir o arquivo de veículos");
    exit(EXIT_FAILURE);
  }

  fwrite(veiculos, sizeof(struct Veiculo), num_veiculos, arquivo);

  fclose(arquivo);
}

void carregar_veiculos_de_arquivo() {
  FILE * arquivo = fopen("veiculos.dat", "rb");
  if (arquivo == NULL) {
    // Se o arquivo não existir, não é um erro
    return;
  }

  fread(veiculos, sizeof(struct Veiculo), MAX_VEICULOS, arquivo);

  fclose(arquivo);
}

void salvar_locacoes_em_arquivo() {
  FILE * arquivo = fopen("locacoes.dat", "wb");
  if (arquivo == NULL) {
    perror("Erro ao abrir o arquivo de locações");
    exit(EXIT_FAILURE);
  }

  fwrite(locacoes, sizeof(struct Locacao), num_locacoes, arquivo);

  fclose(arquivo);
}

void carregar_locacoes_de_arquivo() {
  FILE * arquivo = fopen("locacoes.dat", "rb");
  if (arquivo == NULL) {
    // Se o arquivo não existir, não é um erro
    return;
  }

  fread(locacoes, sizeof(struct Locacao), MAX_LOCACOES, arquivo);

  fclose(arquivo);
}

void salvar_clientes_em_arquivo() {
  FILE * arquivo = fopen("clientes.dat", "wb");
  if (arquivo == NULL) {
    perror("Erro ao abrir o arquivo de clientes");
    exit(EXIT_FAILURE);
  }

  fwrite(clientes, sizeof(struct Cliente), num_clientes, arquivo);

  fclose(arquivo);
}

void carregar_clientes_de_arquivo() {
  FILE * arquivo = fopen("clientes.dat", "rb");
  if (arquivo == NULL) {
    // Se o arquivo não existir, não é um erro
    return;
  }

  fread(clientes, sizeof(struct Cliente), MAX_CLIENTES, arquivo);

  fclose(arquivo);
}

// Repita o mesmo padrão para salvar e carregar veículos e locações

// Função para salvar todas as informações em arquivos binários
void salvar_todas_informacoes_em_arquivo() {
  salvar_clientes_em_arquivo();
  salvar_veiculos_em_arquivo();
  salvar_locacoes_em_arquivo();
}

// Função para carregar todas as informações de arquivos binários
void carregar_todas_informacoes_de_arquivo() {
  carregar_clientes_de_arquivo();
  carregar_veiculos_de_arquivo();
  carregar_locacoes_de_arquivo();
}

void cadastrar_cliente() {
  if (num_clientes == MAX_CLIENTES) {
    printf("Erro: Limite de clientes atingido.\n");
    return;
  }

  printf("Digite o código do cliente: ");
  scanf("%s", clientes[num_clientes].codigo);

  // Verifica se o cliente já está cadastrado
  for (int i = 0; i < num_clientes; i++) {
    if (strcmp(clientes[i].codigo, clientes[num_clientes].codigo) == 0) {
      printf("Erro: Cliente já cadastrado.\n");
      return;
    }
  }

  printf("Digite o nome do cliente: ");
  scanf("%s", clientes[num_clientes].nome);

  printf("Digite o endereço do cliente: ");
  scanf("%s", clientes[num_clientes].endereco);

  printf("Digite o telefone do cliente: ");
  scanf("%s", clientes[num_clientes].telefone);

  num_clientes++;
  printf("Cliente cadastrado com sucesso.\n");
}

void cadastrar_veiculo() {
  if (num_veiculos == MAX_VEICULOS) {
    printf("Erro: Limite de veículos atingido.\n");
    return;
  }

  printf("Digite o código do veículo: ");
  scanf("%s", veiculos[num_veiculos].codigo);

  // Verifica se o veículo já está cadastrado
  for (int i = 0; i < num_veiculos; i++) {
    if (strcmp(veiculos[i].codigo, veiculos[num_veiculos].codigo) == 0) {
      printf("Erro: Veículo já cadastrado.\n");
      return;
    }
  }

  printf("Digite a descrição do veículo: ");
  scanf("%s", veiculos[num_veiculos].descricao);

  printf("Digite o modelo do veículo: ");
  scanf("%s", veiculos[num_veiculos].modelo);

  printf("Digite a cor do veículo: ");
  scanf("%s", veiculos[num_veiculos].cor);

  printf("Digite a placa do veículo: ");
  scanf("%s", veiculos[num_veiculos].placa);

  printf("Digite o valor da diária do veículo: ");
  scanf("%f", & veiculos[num_veiculos].valor_diaria);

  printf("Digite a quantidade de ocupantes do veículo: ");
  scanf("%d", & veiculos[num_veiculos].ocupantes);

  // Inicializa o status como disponível
  strcpy(veiculos[num_veiculos].status, "disponivel");

  num_veiculos++;
  printf("Veículo cadastrado com sucesso.\n");
}

#include <stdbool.h>

bool verificar_disponibilidade_veiculo(const char codigo_veiculo[],
  const char data_retirada[],
    const char data_devolucao[]) {
  // Lógica para verificar a disponibilidade do veículo
  return true; // Implemente a lógica real aqui
}

void cadastrar_locacao() {
  if (num_locacoes == MAX_LOCACOES) {
    printf("Erro: Limite de locações atingido.\n");
    return;
  }

  // Lógica para selecionar um cliente existente
  char codigo_cliente[20];
  printf("Digite o código do cliente: ");
  scanf("%s", codigo_cliente);

  // Lógica para encontrar o cliente
  // (Adapte conforme a estrutura real do seu código)

  // Lógica para selecionar datas de retirada e devolução
  char data_retirada[20], data_devolucao[20];
  printf("Digite a data de retirada (DD/MM/AAAA): ");
  scanf("%s", data_retirada);
  printf("Digite a data de devolução (DD/MM/AAAA): ");
  scanf("%s", data_devolucao);

  // Lógica para selecionar um veículo disponível
  char codigo_veiculo[20];
  printf("Digite o código do veículo desejado: ");
  scanf("%s", codigo_veiculo);

  // Verifica a disponibilidade do veículo para o período selecionado
  if (!verificar_disponibilidade_veiculo(codigo_veiculo, data_retirada, data_devolucao)) {
    printf("Erro: Veículo não disponível para o período selecionado.\n");
    return;
  }

  // Lógica para adicionar a locação à lista
  strcpy(locacoes[num_locacoes].codigo_locacao, "L0001"); // Adapte para gerar IDs únicos
  strcpy(locacoes[num_locacoes].data_retirada, data_retirada);
  strcpy(locacoes[num_locacoes].data_devolucao, data_devolucao);
  strcpy(locacoes[num_locacoes].codigo_cliente, codigo_cliente);
  strcpy(locacoes[num_locacoes].codigo_veiculo, codigo_veiculo);

  // Lógica para calcular a quantidade de dias e adicionar ao registro da locação
  // Lógica para oferecer seguro e calcular o valor total

  num_locacoes++;
  printf("Locação cadastrada com sucesso.\n");
}

void dar_baixa_locacao() {
  if (num_locacoes == 0) {
    printf("Erro: Nenhuma locação registrada.\n");
    return;
  }

  // Lógica para encontrar uma locação existente
  char codigo_locacao[20];
  printf("Digite o código da locação a ser encerrada: ");
  scanf("%s", codigo_locacao);

  // Lógica para encontrar a locação na lista (Adapte conforme a estrutura real do seu código)
  int indice_locacao = -1;
  for (int i = 0; i < num_locacoes; i++) {
    if (strcmp(locacoes[i].codigo_locacao, codigo_locacao) == 0) {
      indice_locacao = i;
      break;
    }
  }

  if (indice_locacao == -1) {
    printf("Erro: Locação não encontrada.\n");
    return;
  }

  // Lógica para verificar a data de devolução real
  char data_devolucao_real[20];
  printf("Digite a data de devolução real (DD/MM/AAAA): ");
  scanf("%s", data_devolucao_real);

  // Lógica para calcular atraso e aplicar multa, se necessário
  // Lógica para calcular o valor total a ser pago pelo cliente

  // Lógica para alterar o status do veículo para "disponível"
  // (Adapte conforme a estrutura real do seu código)
  for (int i = 0; i < num_veiculos; i++) {
    if (strcmp(veiculos[i].codigo, locacoes[indice_locacao].codigo_veiculo) == 0) {
      strcpy(veiculos[i].status, "disponivel");
      break;
    }
  }

  printf("Locação encerrada com sucesso.\n");
}

void pesquisar_cliente(char termo[]) {
  printf("Resultados da pesquisa por clientes:\n");

  for (int i = 0; i < num_clientes; i++) {
    if (strcmp(clientes[i].nome, termo) == 0 || strcmp(clientes[i].codigo, termo) == 0) {
      printf("Código: %s\n", clientes[i].codigo);
      printf("Nome: %s\n", clientes[i].nome);
      printf("Endereço: %s\n", clientes[i].endereco);
      printf("Telefone: %s\n", clientes[i].telefone);
      printf("-----------------------------\n");
    }
  }
}

void pesquisar_veiculo(char termo[]) {
  printf("Resultados da pesquisa por veículos:\n");

  for (int i = 0; i < num_veiculos; i++) {
    if (strcmp(veiculos[i].descricao, termo) == 0 || strcmp(veiculos[i].codigo, termo) == 0) {
      printf("Código: %s\n", veiculos[i].codigo);
      printf("Descrição: %s\n", veiculos[i].descricao);
      printf("Modelo: %s\n", veiculos[i].modelo);
      printf("Cor: %s\n", veiculos[i].cor);
      printf("Placa: %s\n", veiculos[i].placa);
      printf("Valor Diária: %.2f\n", veiculos[i].valor_diaria);
      printf("Ocupantes: %d\n", veiculos[i].ocupantes);
      printf("Status: %s\n", veiculos[i].status);
      printf("-----------------------------\n");
    }
  }
}

void pesquisar(char tipo[], char termo[]) {
  if (strcmp(tipo, "cliente") == 0) {
    pesquisar_cliente(termo);
  } else if (strcmp(tipo, "veiculo") == 0) {
    pesquisar_veiculo(termo);
  } else {
    printf("Erro: Tipo de pesquisa inválido.\n");
  }
}

void mostrar_locacoes_cliente(char codigo_cliente[]) {
  printf("Locações do cliente %s:\n", codigo_cliente);

  for (int i = 0; i < num_locacoes; i++) {
    if (strcmp(locacoes[i].codigo_cliente, codigo_cliente) == 0) {
      printf("Código da Locação: %s\n", locacoes[i].codigo_locacao);
      printf("Data de Retirada: %s\n", locacoes[i].data_retirada);
      printf("Data de Devolução: %s\n", locacoes[i].data_devolucao);
      printf("Código do Veículo: %s\n", locacoes[i].codigo_veiculo);
      // Adicione mais informações da locação conforme necessário
      printf("-----------------------------\n");
    }
  }

  // Se não houver locações para o cliente, exibir mensagem
  if (num_locacoes > 0) {
    printf("Nenhuma locação encontrada para o cliente %s.\n", codigo_cliente);
  }
}

void calcular_pontos_fidelidade(const char codigo_cliente[]) {
  // Lógica para calcular pontos de fidelidade
  int total_pontos = 0;

  for (int i = 0; i < num_locacoes; i++) {
    // Verifica se a locação pertence ao cliente
    // (Adapte conforme a estrutura real do seu código)
    if (strcmp(locacoes[i].codigo_cliente, codigo_cliente) == 0) {
      // Calcula os pontos com base na quantidade de dias da locação
      int dias_locacao = locacoes[i].quantidade_dias;
      int pontos_locacao = dias_locacao * 10;
      total_pontos += pontos_locacao;
    }
  }

  printf("O cliente acumulou %d pontos de fidelidade.\n", total_pontos);
}

void listar_veiculos_disponiveis() {
  printf("Veículos disponíveis para locação:\n");

  for (int i = 0; i < num_veiculos; i++) {
    if (strcmp(veiculos[i].status, "disponivel") == 0) {
      printf("Código: %s\n", veiculos[i].codigo);
      printf("Descrição: %s\n", veiculos[i].descricao);
      printf("Modelo: %s\n", veiculos[i].modelo);
      printf("Cor: %s\n", veiculos[i].cor);
      printf("Placa: %s\n", veiculos[i].placa);
      printf("Valor Diária: %.2f\n", veiculos[i].valor_diaria);
      printf("Ocupantes: %d\n", veiculos[i].ocupantes);
      printf("-----------------------------\n");
    }
  }

  // Se não houver veículos disponíveis, exibir mensagem
  if (num_veiculos > 0) {
    printf("Nenhum veículo disponível para locação no momento.\n");
  }
}

void funcao_extra() {
  // Lógica para a função extra
  listar_veiculos_disponiveis();
}

void exibir_menu() {
  printf("\nMenu:\n");
  printf("1. Cadastrar Cliente\n");
  printf("2. Cadastrar Veículo\n");
  printf("3. Cadastrar Locação\n");
  printf("4. Dar Baixa em Locação\n");
  printf("5. Pesquisar Cliente ou Veículo\n");
  printf("6. Mostrar Locações de um Cliente\n");
  printf("7. Calcular Pontos de Fidelidade\n");
  printf("8. Listar veículos disponiveis\n");
  printf("9. Sair\n");
}

int main() {
  carregar_todas_informacoes_de_arquivo();
  int opcao;
  char codigo_cliente[20];
  do {
    exibir_menu();
    printf("Escolha uma opção (1-9): ");
    scanf("%d", & opcao);
    switch (opcao) {
    case 1:
      cadastrar_cliente();
      salvar_clientes_em_arquivo(); // Salvar clientes após cada cadastro
      break;
    case 2:
      cadastrar_veiculo();
      salvar_veiculos_em_arquivo(); // Salvar veículos após cada cadastro
      break;
    case 3:
      cadastrar_locacao();
      salvar_locacoes_em_arquivo(); // Salvar locações após cada cadastro
      break;
    case 4:
      dar_baixa_locacao();
      salvar_veiculos_em_arquivo(); // Salvar veículos após dar baixa em locação
      salvar_locacoes_em_arquivo(); // Salvar locações após dar baixa em locação
      break;
    case 5: {
      char tipo[20], termo[50];
      printf("Digite o tipo de pesquisa (cliente/veiculo): ");
      scanf("%s", tipo);
      printf("Digite o termo de pesquisa: ");
      scanf("%s", termo);
      pesquisar(tipo, termo);
      break;
    }
    case 6: {
      char codigo_cliente[20];
      printf("Digite o código do cliente: ");
      scanf("%s", codigo_cliente);
      mostrar_locacoes_cliente(codigo_cliente);
      break;
    }
    case 7:
      calcular_pontos_fidelidade(codigo_cliente);
      break;
    case 8:
      funcao_extra();
      break;
    case 9:
      printf("Saindo do programa.\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
    }

  } while (opcao != 9);
  salvar_todas_informacoes_em_arquivo();
  return 0;
}
