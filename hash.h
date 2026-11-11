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

//PRECISA TERMINAR ESSA FUNCTION DE INSERIR 
void InserirHash(Equipamento *tabela[], Equipamento *ajuda)
{

}


void insere_hash(Equipamento *tabela[])
{
   Equipamento *ajuda;
   int flag;
    do{
        flag = 0;
        printf("Digite o código único de identificação(número inteiro de 2 digítos): ");
        scanf("%d",&ajuda->Cod_identificacao);
        
        if(buscatabela_hash(tabela,ajuda->Cod_identificacao)){
            printf("Esse código já foi cadastrado!!");
            flag = 1; 
        }

    }while (ajuda->Cod_identificacao < 1000 || ajuda->Cod_identificacao > 9999 || flag == 1);


    do {
        printf("\nDigite o nome do equipamento de até 11 caractéres: ");
        fgets(ajuda->Nome, sizeof(ajuda->Nome), stdin);
                
        if (strlen(ajuda->Nome) == 0) {
          printf("Erro: O nome do equipamento não pode ser vazio!\n");
        }
        

      } while (strlen(ajuda->Nome) == 0);

    InserirHash(tabela,ajuda);

}