#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include "arvores.h"
#include "hash.h"


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL,"portuguese.UTF-8");
    Arv *A = CriaArvore();
    lista *tabela[TAM_hash];
    inicializa_hash(tabela);
    int escolha = 0;

    while(escolha != 7)
    {
        system("cls");
        printf("\n====================================================================");
        printf("\n   SISTEMA DE GERENCIAMENTO DE FALHAS EM EQUIPAMENTOS COMPUTACIONAIS");
        printf("\n====================================================================");
        printf("\n  1 - Cadastrar Equipamento");
        printf("\n  2 - Registrar Incidente");
        printf("\n  3 - Consultar Equipamento e Incidente");
        printf("\n  4 - Listar todos os Incidentes");
        printf("\n  5 - Excluir um Incidente");
        printf("\n  6 - Excluir um Equipamento");
        printf("\n  7 - Encerrar Programa");
        printf("\n====================================================================");
        printf("\n  Escolha uma opção: ");
        scanf("%d",&escolha);
        switch(escolha){
        case 1:
            system("cls");
            ler_hash(tabela);
            printf("\nEquipamento cadastrado com sucesso!\n");
            system("pause");
            break;

        case 2:
            system("cls");
            RegistroDoIncidente(A, tabela);
            system("pause");
            break;

        case 3:
            system("cls");
            pesquisa(tabela, A);
            printf("\n");
            system("pause");
            break;

        case 4:
            system("cls");
            if (A->raiz == NULL)
            {
                printf("\nA árvore está vazia! Nenhum incidente cadastrado.\n");
            }
            else
            {
                PrintaElem(A->raiz);
                printf("\n");
            }
            system("pause");
            break;

        case 5:
            system("cls");
            if (A->raiz == NULL)
            {
                printf("\nA árvore está vazia! Nenhum incidente para remover.\n");
            }
            else
            {
                ler_remover(A, tabela);
            }
            system("pause");
            break;

        case 6:
            system("cls");
            Excluir_equip(tabela, A);
            printf("\n");
            system("pause");
            break;

        case 7:
            system("cls");
            printf("\nEncerrando...\n");
            break;
            
        default:
            printf("\n\tOpção inválida! Tente novamente.\n");
            system("pause");
            break;
        }
       
    }

    return 0;
}
