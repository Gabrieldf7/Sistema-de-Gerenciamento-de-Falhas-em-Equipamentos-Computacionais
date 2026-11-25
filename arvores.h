typedef struct Incidente {
  int num_identificacao;
  int cod;
  int nivel_gravidade;
} incidente;

typedef struct NoArvore {
  incidente info;
  struct NoArvore *esq;
  struct NoArvore *dir;
} NoArv;

typedef struct Arvore {
  NoArv *raiz;
} Arv;

Arv *CriaArvore() {
  Arv *aux;
  aux = (Arv *)malloc(sizeof(Arv));
  aux->raiz = NULL;
  return aux;
}

int VerificaArvore(NoArv *raiz) {
  if (raiz == NULL) {
    return 1;
  }
  return 0;
}

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
} 

NoArv *BuscaNo_incidente(NoArv *no, int num) {
  NoArv *Pai = no;
  while (Pai != NULL) {
    if (Pai->info.num_identificacao < num) {
      Pai = Pai->dir;
    } else if (Pai->info.num_identificacao > num) {
      Pai = Pai->esq;
    } else {
      return Pai;
    }
  }
  return NULL;
}

NoArv *aux_insere(NoArv *no, incidente novo_incidente) {
  int flag;
  NoArv *Pai;
  NoArv *novo = (NoArv *)malloc(sizeof(NoArv));
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
      } else if (Pai->info.num_identificacao >
                 novo_incidente.num_identificacao) {
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


void PrintaElem(NoArv *A) {
  if (A != NULL) {
    PrintaElem(A->esq);

    printf("Número de identificação: %d \n\t", A->info.num_identificacao);
    printf("Código: %d \n\t", A->info.cod);
    printf("Nível de Gravidade: %d, \n\t", A->info.nivel_gravidade);

    PrintaElem(A->dir);
  }
}


NoArv *remove_no(NoArv *raiz, int num_id) {
  NoArv *aux, *maior_esq;

  if (raiz == NULL) {
    return raiz;
  }

  else {
    if (raiz->info.num_identificacao < num_id) {
      raiz->dir = remove_no(raiz->dir, num_id);
      return raiz;
    }

    if (raiz->info.num_identificacao > num_id) {
      raiz->esq = remove_no(raiz->esq, num_id);
      return raiz;
    }

    if (raiz->dir == NULL) {
      aux = raiz->esq;
      free(raiz);
      return aux;
    }

    if (raiz->esq == NULL) {
      aux = raiz->dir;
      free(raiz);
      return aux;
    }

    maior_esq = raiz->esq;
    while (maior_esq->dir != NULL) {
      maior_esq = maior_esq->dir;
    }
    raiz->info = maior_esq->info;
    raiz->esq = remove_no(raiz->esq, maior_esq->info.num_identificacao);
    return raiz;
  }
}

Arv *remover(Arv *RAIZ, int num_id) {
  NoArv *aux = RAIZ->raiz;
  if (aux->info.cod == num_id && aux->dir == NULL && aux->esq == NULL) {
    free(aux);
    free(RAIZ);
    return NULL;
  }
  RAIZ->raiz = remove_no(RAIZ->raiz, num_id);
  return RAIZ;
}