typedef struct Incidente
{
    int num_identificacao;
    int cod;
    int nivel_gravidade;
}incidente;


typedef struct NoArvore
{
    incidente info;
    struct NoArvore *esq;
    struct NoArvore *dir;
}NoArv;

typedef struct Arvore
{
     NoArv *raiz;
}Arv;

Arv *CriaArvore()
{
    Arv *aux;
    aux = (Arv*) malloc (sizeof(Arv));
    aux -> raiz = NULL;
    return aux;
}

int BuscaID_incidente(NoArv *no, int num)
{
    NoArv *Pai;
    if (no == NULL)
    {
        return 0;
    }
    else
    {
        Pai = no;
        while (Pai != NULL)
        {
            if (Pai -> info.num_identificacao < num)
            {
                Pai = Pai -> dir;
            }
            else if (Pai -> info.num_identificacao > num)
            {
                Pai = Pai -> esq;
            }
            else if (Pai -> info.num_identificacao == num)
            {
                return 1;
            }
        }
        return 0;
    }
}

NoArv* aux_insere(NoArv *no, incidente novo_incidente) {
    int flag;
    NoArv *Pai;
    NoArv *novo = (NoArv*) malloc(sizeof(NoArv));
    novo->info = novo_incidente;
    novo->esq = NULL;
    novo->dir = NULL;

    if (no == NULL) {
        return novo;
    } else {
        Pai = no;
        flag = 0;
        while (flag == 0) {
            if (Pai->info.num_identificacao < novo_incidente.num_identificacao) {
                if (Pai->dir == NULL) {
                    Pai->dir = novo;
                    flag = 1;
                } else {
                    Pai = Pai->dir;
                }
            } else if (Pai->info.num_identificacao > novo_incidente.num_identificacao) {
                if (Pai->esq == NULL) {
                    Pai->esq = novo;
                    flag = 1;
                } else {
                    Pai = Pai->esq;
                }
            } else {
                flag = 1;
                free(novo);
            }
        }
        return no;
    }
}

void InsereArv(Arv *antiga)
{   
    int flag;
    incidente novo;
    do{
        flag = 0;
        printf("Digite o número único de identificação(número inteiro de 2 digítos): ");
        scanf("%d",&novo.num_identificacao);
        
        if(BuscaID_incidente(antiga->raiz,novo.num_identificacao)){
            printf("Esse número ja foi cadastrado!!");
            flag = 1; 
        }

    }while (novo.num_identificacao < 10 || novo.num_identificacao > 99 || flag == 1);

    do{
        printf("Digite o código do equipamento relacionado(número inteiro de 4 dígitos): ");
        scanf("%d",&novo.cod);
    }while(novo.cod <1000 || novo.cod > 9999);

    do{
        printf("Digite o nível de gravidade: ");
        scanf("%d",&novo.nivel_gravidade);
    }while(novo.nivel_gravidade < 1 || novo.nivel_gravidade > 3);    

    antiga -> raiz = aux_insere(antiga -> raiz, novo);
}


void PrintaElem(NoArv *A)
{   
    if(A != NULL)
    {
        PrintaElem(A -> esq);

        printf("Número de identificação: %d \n\t", A -> info.num_identificacao);
        printf("Código: %d \n\t",A -> info.cod);
        printf("Nível de Gravidade: %d, \n\t", A -> info.nivel_gravidade );

        PrintaElem(A -> dir);
    }
}





NoArv* remove_no(NoArv *raiz, int num_id)
{
    NoArv *aux, *maior_esq;

    if(raiz == NULL)
    {
        return raiz;
    }

    else
    {
        if(raiz -> info.num_identificacao < num_id)
        {
            raiz -> dir = remove_no(raiz -> dir, num_id);
            return raiz;
        }

        if(raiz -> info.num_identificacao > num_id)
        {
            raiz -> esq = remove_no(raiz -> esq, num_id);
            return raiz;
        }


        if(raiz -> dir == NULL)
        {
            aux = raiz -> esq;
            free(raiz);
            return aux;
        }

        if(raiz -> esq == NULL)
        {
            aux = raiz -> dir;
            free(raiz);
            return aux;
        }

        maior_esq = raiz -> esq; 
        while (maior_esq -> dir != NULL)
        {
            maior_esq = maior_esq -> dir;
        }
        raiz -> info = maior_esq -> info;
        raiz -> esq = remove_no(raiz -> esq, maior_esq -> info.num_identificacao);
        return raiz;         
    }
}

    void remover(Arv *A)
    {
        int id_remover;
        printf("Digite o número de identificação do incidente que deseja remover: ");
                scanf("%d", &id_remover);
                if (BuscaID_incidente(A->raiz, id_remover))
                {
                    A->raiz = remove_no(A->raiz, id_remover);
                    printf("\nIncidente removido com sucesso!\n");
                }
                else
                {
                    printf("\nIncidente com ID %d não encontrado!\n", id_remover);
                }
    }
