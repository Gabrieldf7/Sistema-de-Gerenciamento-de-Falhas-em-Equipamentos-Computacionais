#define TAM_hash 67

typedef struct lista lista;

typedef struct equipamento {
  int Cod_identificacao;
  char Nome[11];
  struct lista *incid;
} Equipamento;

typedef struct no{
    Equipamento info;
    struct no* prox;
}no;

typedef struct lista{
    no*inicio;
}lista;

lista* Criarlista(){
    lista*aux;
    aux=(lista*)malloc(sizeof(lista));
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


int *buscatabela_hash(lista *tabela[], int k)
{
  int i = hash(k);
  no *atual = tabela[i] -> inicio;

   if (atual != NULL)
    {
      while (atual != NULL)
      {
        if(atual->info.Cod_identificacao == k)
        {
          return 1;
        }
        atual = atual -> prox;
      }
    }

    return 0;
}

no *busca_no(lista *tabela[], int k)
{
  int i = hash(k);
  no *atual = tabela[i] -> inicio;

   if (atual != NULL)
    {
      while (atual != NULL)
      {
        if(atual->info.Cod_identificacao == k)
        {
          return atual;
        }
        atual = atual -> prox;
      }
    }

    return NULL;
}


void pesquisa(lista *tabela[])
{
    no *aux;
    
    do{
        printf("Digite o código único de identificação(número inteiro de 4 digítos): ");
        scanf("%d",&aux-> info.Cod_identificacao);

    }while (aux -> info.Cod_identificacao < 1000 || aux -> info.Cod_identificacao > 9999);
   

    aux = busca_no;

    if(aux == NULL)
    {
        printf("Código não foi encontrado");
    }
    else
    {
        printf("\n\tCódigo de identificação: %d", aux -> info.Cod_identificacao);
        printf("\n\tNome do Equipamento: %s",aux -> info.Nome);
        while (aux->info.incid != NULL)
        {
            //tem que terminar aqui linkando os incidentes, não sei como faz isso ainda... 
        }
        
    }
}


no* Inserirhash(no *antigo, Equipamento ajuda){

    no *novo = (no*)malloc(sizeof(no));
    novo->info = ajuda; 
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


void ler_hash(lista *tabela[]){
   Equipamento ajuda;
   int flag;
    do{
        flag = 0;
        printf("Digite o código único de identificação(número inteiro de 4 digítos): ");
        scanf("%d",&ajuda.Cod_identificacao);
        
        if(buscatabela_hash(tabela,ajuda.Cod_identificacao)){
            printf("Esse código já foi cadastrado!!");
            flag = 1; 
        }

    }while (ajuda.Cod_identificacao < 1000 || ajuda.Cod_identificacao > 9999 || flag == 1);


    do {
        printf("\nDigite o nome do equipamento de até 11 caractéres: ");
        fgets(ajuda.Nome, sizeof(ajuda.Nome), stdin);
                
        if (strlen(ajuda.Nome) == 0) {
          printf("Erro: O nome do equipamento não pode ser vazio!\n");
        }
    } while (strlen(ajuda.Nome) == 0);

    int indice;
    indice = hash(ajuda.Cod_identificacao);
    tabela[indice]->inicio = Inserirhash(tabela[indice]->inicio,ajuda);
}
