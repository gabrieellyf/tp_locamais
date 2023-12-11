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

// Fun��es para manipula��o de arquivos (continua��o)
void salvar_veiculos_em_arquivo() {
  FILE * arquivo = fopen("veiculos.dat", "wb");
  if (arquivo == NULL) {
    perror("Erro ao abrir o arquivo de ve�culos");
    exit(EXIT_FAILURE);
  }

  fwrite(veiculos, sizeof(struct Veiculo), num_veiculos, arquivo);

  fclose(arquivo);
}

void carregar_veiculos_de_arquivo() {
  FILE * arquivo = fopen("veiculos.dat", "rb");
  if (arquivo == NULL) {
    // Se o arquivo n�o existir, n�o � um erro
    return;
  }

  fread(veiculos, sizeof(struct Veiculo), MAX_VEICULOS, arquivo);

  fclose(arquivo);
}

void salvar_locacoes_em_arquivo() {
  FILE * arquivo = fopen("locacoes.dat", "wb");
  if (arquivo == NULL) {
    perror("Erro ao abrir o arquivo de loca��es");
    exit(EXIT_FAILURE);
  }

  fwrite(locacoes, sizeof(struct Locacao), num_locacoes, arquivo);

  fclose(arquivo);
}

void carregar_locacoes_de_arquivo() {
  FILE * arquivo = fopen("locacoes.dat", "rb");
  if (arquivo == NULL) {
    // Se o arquivo n�o existir, n�o � um erro
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
    // Se o arquivo n�o existir, n�o � um erro
    return;
  }

  fread(clientes, sizeof(struct Cliente), MAX_CLIENTES, arquivo);

  fclose(arquivo);
}

// Repita o mesmo padr�o para salvar e carregar ve�culos e loca��es

// Fun��o para salvar todas as informa��es em arquivos bin�rios
void salvar_todas_informacoes_em_arquivo() {
  salvar_clientes_em_arquivo();
  salvar_veiculos_em_arquivo();
  salvar_locacoes_em_arquivo();
}

// Fun��o para carregar todas as informa��es de arquivos bin�rios
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

  printf("Digite o c�digo do cliente: ");
  scanf("%s", clientes[num_clientes].codigo);

  // Verifica se o cliente j� est� cadastrado
  for (int i = 0; i < num_clientes; i++) {
    if (strcmp(clientes[i].codigo, clientes[num_clientes].codigo) == 0) {
      printf("Erro: Cliente j� cadastrado.\n");
      return;
    }
  }

  printf("Digite o nome do cliente: ");
  scanf("%s", clientes[num_clientes].nome);

  printf("Digite o endere�o do cliente: ");
  scanf("%s", clientes[num_clientes].endereco);

  printf("Digite o telefone do cliente: ");
  scanf("%s", clientes[num_clientes].telefone);

  num_clientes++;
  printf("Cliente cadastrado com sucesso.\n");
}

void cadastrar_veiculo() {
  if (num_veiculos == MAX_VEICULOS) {
    printf("Erro: Limite de ve�culos atingido.\n");
    return;
  }

  printf("Digite o c�digo do ve�culo: ");
  scanf("%s", veiculos[num_veiculos].codigo);

  // Verifica se o ve�culo j� est� cadastrado
  for (int i = 0; i < num_veiculos; i++) {
    if (strcmp(veiculos[i].codigo, veiculos[num_veiculos].codigo) == 0) {
      printf("Erro: Ve�culo j� cadastrado.\n");
      return;
    }
  }

  printf("Digite a descri��o do ve�culo: ");
  scanf("%s", veiculos[num_veiculos].descricao);

  printf("Digite o modelo do ve�culo: ");
  scanf("%s", veiculos[num_veiculos].modelo);

  printf("Digite a cor do ve�culo: ");
  scanf("%s", veiculos[num_veiculos].cor);

  printf("Digite a placa do ve�culo: ");
  scanf("%s", veiculos[num_veiculos].placa);

  printf("Digite o valor da di�ria do ve�culo: ");
  scanf("%f", & veiculos[num_veiculos].valor_diaria);

  printf("Digite a quantidade de ocupantes do ve�culo: ");
  scanf("%d", & veiculos[num_veiculos].ocupantes);

  // Inicializa o status como dispon�vel
  strcpy(veiculos[num_veiculos].status, "disponivel");

  num_veiculos++;
  printf("Ve�culo cadastrado com sucesso.\n");
}

#include <stdbool.h>

bool verificar_disponibilidade_veiculo(const char codigo_veiculo[],
  const char data_retirada[],
    const char data_devolucao[]) {
  // L�gica para verificar a disponibilidade do ve�culo
  return true; // Implemente a l�gica real aqui
}

void cadastrar_locacao() {
  if (num_locacoes == MAX_LOCACOES) {
    printf("Erro: Limite de loca��es atingido.\n");
    return;
  }

  // L�gica para selecionar um cliente existente
  char codigo_cliente[20];
  printf("Digite o c�digo do cliente: ");
  scanf("%s", codigo_cliente);

  // L�gica para encontrar o cliente
  // (Adapte conforme a estrutura real do seu c�digo)

  // L�gica para selecionar datas de retirada e devolu��o
  char data_retirada[20], data_devolucao[20];
  printf("Digite a data de retirada (DD/MM/AAAA): ");
  scanf("%s", data_retirada);
  printf("Digite a data de devolu��o (DD/MM/AAAA): ");
  scanf("%s", data_devolucao);

  // L�gica para selecionar um ve�culo dispon�vel
  char codigo_veiculo[20];
  printf("Digite o c�digo do ve�culo desejado: ");
  scanf("%s", codigo_veiculo);

  // Verifica a disponibilidade do ve�culo para o per�odo selecionado
  if (!verificar_disponibilidade_veiculo(codigo_veiculo, data_retirada, data_devolucao)) {
    printf("Erro: Ve�culo n�o dispon�vel para o per�odo selecionado.\n");
    return;
  }

  // L�gica para adicionar a loca��o � lista
  strcpy(locacoes[num_locacoes].codigo_locacao, "L0001"); // Adapte para gerar IDs �nicos
  strcpy(locacoes[num_locacoes].data_retirada, data_retirada);
  strcpy(locacoes[num_locacoes].data_devolucao, data_devolucao);
  strcpy(locacoes[num_locacoes].codigo_cliente, codigo_cliente);
  strcpy(locacoes[num_locacoes].codigo_veiculo, codigo_veiculo);

  // L�gica para calcular a quantidade de dias e adicionar ao registro da loca��o
  // L�gica para oferecer seguro e calcular o valor total

  num_locacoes++;
  printf("Loca��o cadastrada com sucesso.\n");
}

void dar_baixa_locacao() {
  if (num_locacoes == 0) {
    printf("Erro: Nenhuma loca��o registrada.\n");
    return;
  }

  // L�gica para encontrar uma loca��o existente
  char codigo_locacao[20];
  printf("Digite o c�digo da loca��o a ser encerrada: ");
  scanf("%s", codigo_locacao);

  // L�gica para encontrar a loca��o na lista (Adapte conforme a estrutura real do seu c�digo)
  int indice_locacao = -1;
  for (int i = 0; i < num_locacoes; i++) {
    if (strcmp(locacoes[i].codigo_locacao, codigo_locacao) == 0) {
      indice_locacao = i;
      break;
    }
  }

  if (indice_locacao == -1) {
    printf("Erro: Loca��o n�o encontrada.\n");
    return;
  }

  // L�gica para verificar a data de devolu��o real
  char data_devolucao_real[20];
  printf("Digite a data de devolu��o real (DD/MM/AAAA): ");
  scanf("%s", data_devolucao_real);

  // L�gica para calcular atraso e aplicar multa, se necess�rio
  // L�gica para calcular o valor total a ser pago pelo cliente

  // L�gica para alterar o status do ve�culo para "dispon�vel"
  // (Adapte conforme a estrutura real do seu c�digo)
  for (int i = 0; i < num_veiculos; i++) {
    if (strcmp(veiculos[i].codigo, locacoes[indice_locacao].codigo_veiculo) == 0) {
      strcpy(veiculos[i].status, "disponivel");
      break;
    }
  }

  printf("Loca��o encerrada com sucesso.\n");
}

void pesquisar_cliente(char termo[]) {
  printf("Resultados da pesquisa por clientes:\n");

  for (int i = 0; i < num_clientes; i++) {
    if (strcmp(clientes[i].nome, termo) == 0 || strcmp(clientes[i].codigo, termo) == 0) {
      printf("C�digo: %s\n", clientes[i].codigo);
      printf("Nome: %s\n", clientes[i].nome);
      printf("Endere�o: %s\n", clientes[i].endereco);
      printf("Telefone: %s\n", clientes[i].telefone);
      printf("-----------------------------\n");
    }
  }
}

void pesquisar_veiculo(char termo[]) {
  printf("Resultados da pesquisa por ve�culos:\n");

  for (int i = 0; i < num_veiculos; i++) {
    if (strcmp(veiculos[i].descricao, termo) == 0 || strcmp(veiculos[i].codigo, termo) == 0) {
      printf("C�digo: %s\n", veiculos[i].codigo);
      printf("Descri��o: %s\n", veiculos[i].descricao);
      printf("Modelo: %s\n", veiculos[i].modelo);
      printf("Cor: %s\n", veiculos[i].cor);
      printf("Placa: %s\n", veiculos[i].placa);
      printf("Valor Di�ria: %.2f\n", veiculos[i].valor_diaria);
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
    printf("Erro: Tipo de pesquisa inv�lido.\n");
  }
}

void mostrar_locacoes_cliente(char codigo_cliente[]) {
  printf("Loca��es do cliente %s:\n", codigo_cliente);

  for (int i = 0; i < num_locacoes; i++) {
    if (strcmp(locacoes[i].codigo_cliente, codigo_cliente) == 0) {
      printf("C�digo da Loca��o: %s\n", locacoes[i].codigo_locacao);
      printf("Data de Retirada: %s\n", locacoes[i].data_retirada);
      printf("Data de Devolu��o: %s\n", locacoes[i].data_devolucao);
      printf("C�digo do Ve�culo: %s\n", locacoes[i].codigo_veiculo);
      // Adicione mais informa��es da loca��o conforme necess�rio
      printf("-----------------------------\n");
    }
  }

  // Se n�o houver loca��es para o cliente, exibir mensagem
  if (num_locacoes > 0) {
    printf("Nenhuma loca��o encontrada para o cliente %s.\n", codigo_cliente);
  }
}

void calcular_pontos_fidelidade(const char codigo_cliente[]) {
  // L�gica para calcular pontos de fidelidade
  int total_pontos = 0;

  for (int i = 0; i < num_locacoes; i++) {
    // Verifica se a loca��o pertence ao cliente
    // (Adapte conforme a estrutura real do seu c�digo)
    if (strcmp(locacoes[i].codigo_cliente, codigo_cliente) == 0) {
      // Calcula os pontos com base na quantidade de dias da loca��o
      int dias_locacao = locacoes[i].quantidade_dias;
      int pontos_locacao = dias_locacao * 10;
      total_pontos += pontos_locacao;
    }
  }

  printf("O cliente acumulou %d pontos de fidelidade.\n", total_pontos);
}

void listar_veiculos_disponiveis() {
  printf("Ve�culos dispon�veis para loca��o:\n");

  for (int i = 0; i < num_veiculos; i++) {
    if (strcmp(veiculos[i].status, "disponivel") == 0) {
      printf("C�digo: %s\n", veiculos[i].codigo);
      printf("Descri��o: %s\n", veiculos[i].descricao);
      printf("Modelo: %s\n", veiculos[i].modelo);
      printf("Cor: %s\n", veiculos[i].cor);
      printf("Placa: %s\n", veiculos[i].placa);
      printf("Valor Di�ria: %.2f\n", veiculos[i].valor_diaria);
      printf("Ocupantes: %d\n", veiculos[i].ocupantes);
      printf("-----------------------------\n");
    }
  }

  // Se n�o houver ve�culos dispon�veis, exibir mensagem
  if (num_veiculos > 0) {
    printf("Nenhum ve�culo dispon�vel para loca��o no momento.\n");
  }
}

void funcao_extra() {
  // L�gica para a fun��o extra
  listar_veiculos_disponiveis();
}

void exibir_menu() {
  printf("\nMenu:\n");
  printf("1. Cadastrar Cliente\n");
  printf("2. Cadastrar Ve�culo\n");
  printf("3. Cadastrar Loca��o\n");
  printf("4. Dar Baixa em Loca��o\n");
  printf("5. Pesquisar Cliente ou Ve�culo\n");
  printf("6. Mostrar Loca��es de um Cliente\n");
  printf("7. Calcular Pontos de Fidelidade\n");
  printf("8. Listar ve�culos disponiveis\n");
  printf("9. Sair\n");
}

int main() {
  carregar_todas_informacoes_de_arquivo();
  int opcao;
  char codigo_cliente[20];
  do {
    exibir_menu();
    printf("Escolha uma op��o (1-9): ");
    scanf("%d", & opcao);
    switch (opcao) {
    case 1:
      cadastrar_cliente();
      salvar_clientes_em_arquivo(); // Salvar clientes ap�s cada cadastro
      break;
    case 2:
      cadastrar_veiculo();
      salvar_veiculos_em_arquivo(); // Salvar ve�culos ap�s cada cadastro
      break;
    case 3:
      cadastrar_locacao();
      salvar_locacoes_em_arquivo(); // Salvar loca��es ap�s cada cadastro
      break;
    case 4:
      dar_baixa_locacao();
      salvar_veiculos_em_arquivo(); // Salvar ve�culos ap�s dar baixa em loca��o
      salvar_locacoes_em_arquivo(); // Salvar loca��es ap�s dar baixa em loca��o
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
      printf("Digite o c�digo do cliente: ");
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
      printf("Op��o inv�lida. Tente novamente.\n");
    }

  } while (opcao != 9);
  salvar_todas_informacoes_em_arquivo();
  return 0;
}
