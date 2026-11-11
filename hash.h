#define TAM_hash 67

typedef struct equipamento {
  int Cod_identificacao;
  char Nome[11];
  struct equipamento *prox;
} Equipamento;

int hash(int k) {
  float A = 0.6180339887;
  float val = k * A;
  float fracionaria = val - (int)val;
  float resultado = TAM_hash * fracionaria;
  return (int)resultado;
}

void inicializa_hash(Equipamento *tabela[]) {
  for (int i = 0; i < TAM_hash; i++) {
    tabela[i] = NULL;
  }
}


int buscatabela_hash(Equipamento *tabela[], int k)
{
  int i = hash(k);
  Equipamento *atual = tabela[i];

   if (atual != NULL)
    {
      while (atual != NULL)
      {
        if(atual->Cod_identificacao == k)
        {
          return 1;
        }
        atual = atual -> prox;
      }
    }

    return 0;
}

//PRECISA TERMINAR ESSA FUNCTION DE INSERIR, FALTA LER NOME, E INSERIR REALMENTE NA TABELA HASH
void insere_hash(Equipamento *tabela[])
{
   int cod;
   int flag;
   char nome[11];
    do{
        flag = 0;
        printf("Digite o código único de identificação(número inteiro de 2 digítos): ");
        scanf("%d",&cod);
        
        if(buscatabela_hash(tabela,cod)){
            printf("Esse código já foi cadastrado!!");
            flag = 1; 
        }

    }while (cod < 1000 || cod > 9999 || flag == 1);

    


}