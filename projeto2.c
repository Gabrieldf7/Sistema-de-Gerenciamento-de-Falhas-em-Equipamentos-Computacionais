#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <windows.h>
#include "arvores.h"
#include "hash.h"


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL,"portuguese.UTF-8");
    Arv *A = CriaArvore();
    Equipamento *tabela[TAM_hash];

    int escolha = 1;

    while(escolha != 0)
    {
        system("cls");
        printf("\n====================================================================");
        printf("\n   SISTEMA DE GERENCIAMENTO DE FALHAS EM EQUIPAMENTOS COMPUTACIONAIS");
        printf("\n====================================================================");
        printf("\n  1 - Inserir um Incidente");
        printf("\n  2 - Remover um Incidente");
        printf("\n  3 - Listar Incidentes (Ordem Crescente de ID)");
        printf("\n  0 - Finalizar");
        printf("\n====================================================================");
        printf("\n  Escolha uma opção: ");
        scanf("%d",&escolha);
        switch(escolha){
        case 0:
            system("cls");
            printf("\nEncerrando...\n");
            break;

        case 1:
            system("cls");
            InsereArv(A);
            printf("\nIncidente cadastrado com sucesso!\n");
            system("pause");
            break;

        case 2:
            system("cls");
            if (A->raiz == NULL)
            {
                printf("\nA árvore está vazia! Nenhum incidente para remover.\n");
            }
            else
            {
                remover(A);     
            }
            system("pause");
            break;

        case 3:
            system("cls");
            if (A->raiz == NULL)
            {
                printf("\nA árvore está vazia! Nenhum incidente cadastrado.\n");
            }
            else
            {
                PrintaElem(A->raiz);
            }
            system("pause");
            break;
            
        default:
            printf("\n\tOpção inválida! Tente novamente.\n");
            system("pause");
            break;
        }
       
    }

    return 0;
}
