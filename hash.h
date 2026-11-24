#define TAM_hash 67

typedef struct lista_incid lista_incid;

typedef struct equipamento {
  int Cod_identificacao;
  char Nome[11];
  struct lista_incid *incid;
} Equipamento;

typedef struct no {
  Equipamento info;
  struct no *prox;
} no;

typedef struct lista_incid {
  int id_incidente;
  struct lista_incid *prox;
} lista_incid;

typedef struct lista {
  no *inicio;
} lista;

lista *Criarlista() {
  lista *aux;
  aux = (lista *)malloc(sizeof(lista));
  aux->inicio = NULL;
  return aux;
}

int hash(int k) {
  float A = 0.6180339887;
  float val = k * A;
  float fracionaria = val - (int)val;
  float resultado = TAM_hash * fracionaria;
  return (int)resultado;
}

void inicializa_hash(lista *tabela[]) {

  for (int i = 0; i < TAM_hash; i++) {
    tabela[i] = Criarlista();
  }

  for (int i = 0; i < TAM_hash; i++) {
    tabela[i]->inicio = NULL;
  }
}

int buscatabela_hash(lista *tabela[], int k) {
  int i = hash(k);
  no *atual = tabela[i]->inicio;

  if (atual != NULL) {
    while (atual != NULL) {
      if (atual->info.Cod_identificacao == k) {
        return 1;
      }
      atual = atual->prox;
    }
  }

  return 0;
}

lista_incid *inserir_incid(lista_incid *inicio, int id) {

  lista_incid *novo = (lista_incid *)malloc(sizeof(lista_incid));
  novo->id_incidente = id;
  novo->prox = inicio;
  return novo;

}

no *busca_no(lista *tabela[], int k) {
  int i = hash(k);
  no *atual = tabela[i]->inicio;

  if (atual != NULL) {
    while (atual != NULL) {
      if (atual->info.Cod_identificacao == k) {
        return atual;
      }
      atual = atual->prox;
    }
  }

  return NULL;
}


void RegistroDoIncidente(Arv *antiga, lista *tabela[]) {
  int flag;
  incidente aux;
  no *equipamento = NULL;

  do {
    printf("Digite o código único de identificação do equipamento(número inteiro de 4 digítos): ");
    scanf("%d", &aux.cod);
  } while (aux.cod < 1000 ||aux.cod > 9999);

  equipamento = busca_no(tabela,aux.cod);

  if (equipamento == NULL)
  {
    printf("O equipamento requerido não existe!");
  }
  else
  { 
    do {
      flag = 0;
      printf("Digite o número único de identificação do incidente (2 dígitos): ");
      scanf("%d", &aux.num_identificacao);
      if (BuscaID_incidente(antiga->raiz, aux.num_identificacao)) {
        printf("Esse número já foi cadastrado!\n");
        flag = 1;
      }
    } while (aux.num_identificacao < 10 || aux.num_identificacao > 99 || flag == 1);
    
    do {
      printf("Digite o nível de gravidade (1-Baixa, 2-Média, 3-Alta): ");
      scanf("%d", &aux.nivel_gravidade);
    } while (aux.nivel_gravidade < 1 || aux.nivel_gravidade > 3);


    antiga->raiz = aux_insere(antiga->raiz,aux);
    equipamento->info.incid = inserir_incid(equipamento->info.incid, aux.num_identificacao);
    printf("\nIncidente cadastrado com sucesso!\n");

  }
}


void Excluir_equip(lista *tabela[], Arv *antiga)
{
  int flag;
  
  int cod;
  no *equipamento = NULL;

  do {
    printf("Digite o código único de identificação do equipamento (número inteiro de 4 digítos): ");
    scanf("%d", &cod);
  } while (cod < 1000 || cod > 9999);

  equipamento = busca_no(tabela,cod);

  
  if(equipamento == NULL)
  {
    printf("Equipamento procurado não existe!");
  }
  else
  {
    lista_incid *apag = equipamento->info.incid;
    lista_incid *aux = NULL;
    while (apag != NULL)
    {
      aux = apag ->prox;
      remover(antiga->raiz, apag->id_incidente);
      free(apag);
      apag = aux;
    }
  }

  free(equipamento);

}



void pesquisa(lista *tabela[]) {
  no *aux;

  do {
    printf("Digite o código único de identificação(número inteiro de 4 digítos): ");
    scanf("%d", &aux->info.Cod_identificacao);

  } while (aux->info.Cod_identificacao < 1000 ||
           aux->info.Cod_identificacao > 9999);

  aux = busca_no(tabela, aux->info.Cod_identificacao);

  if (aux == NULL) {
    printf("Código não foi encontrado");
  } else {
    printf("\n\tCódigo de identificação: %d", aux->info.Cod_identificacao);
    printf("\n\tNome do Equipamento: %s", aux->info.Nome);
    while (aux->info.incid != NULL) {
        
    }
  }
}

no *Inserirhash(no *antigo, Equipamento ajuda) {

  no *novo = (no *)malloc(sizeof(no));
  novo->info = ajuda;
  novo->info.incid = NULL;
  novo->prox = NULL;

  if (antigo == NULL) {
    return novo;
  }

  no *aux = antigo;
  while (aux->prox != NULL) {
    aux = aux->prox;
  }

  aux->prox = novo;

  return antigo;
}

void ler_hash(lista *tabela[]) {
  Equipamento ajuda;
  int flag;
  do {
    flag = 0;
    printf("Digite o código único de identificação(número inteiro de 4 "
           "digítos): ");
    scanf("%d", &ajuda.Cod_identificacao);

    if (buscatabela_hash(tabela, ajuda.Cod_identificacao)) {
      printf("Esse código já foi cadastrado!!");
      flag = 1;
    }

  } while (ajuda.Cod_identificacao < 1000 || ajuda.Cod_identificacao > 9999 ||
           flag == 1);

  do {
    printf("\nDigite o nome do equipamento de até 11 caractéres: ");
    fgets(ajuda.Nome, sizeof(ajuda.Nome), stdin);

    if (strlen(ajuda.Nome) == 0) {
      printf("Erro: O nome do equipamento não pode ser vazio!\n");
    }
  } while (strlen(ajuda.Nome) == 0);

  int indice;
  indice = hash(ajuda.Cod_identificacao);
  tabela[indice]->inicio = Inserirhash(tabela[indice]->inicio, ajuda);
}
