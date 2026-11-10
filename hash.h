typedef struct equipamento
{
    int Cod_identificacao;
    char Nome[11];
    Equipamento *prox;
}Equipamento;

int hash(int tam, int k) 
{
    float A = 0.6180339887;
    float val = k * A; 
    float fracionaria = val - (int)val; 
    float resultado = tam * fracionaria;
    return (int)resultado;
}