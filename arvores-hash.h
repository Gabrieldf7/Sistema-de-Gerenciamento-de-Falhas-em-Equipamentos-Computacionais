typedef struct Incidente
{
    int num_identificacao;
    int cod;
    int nivel_gravidade;

}incidente;


typedef struct NoArvore
{
    incidente *info;
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

NoArv* aux_insere(NoArv *no, incidente *novo_incidente) {
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
            if (Pai->info->num_identificacao < novo_incidente->num_identificacao) {
                if (Pai->dir == NULL) {
                    Pai->dir = novo;
                    flag = 1;
                } else {
                    Pai = Pai->dir;
                }
            } else if (Pai->info->num_identificacao > novo_incidente->num_identificacao) {
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

void InsereArv(Arv *antiga, incidente *novo_incidente)
{

    
    antiga -> raiz = aux_insere(antiga -> raiz, novo_incidente);
}
