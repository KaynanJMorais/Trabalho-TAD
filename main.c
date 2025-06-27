#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "ListaDuplamenteEnc.h"

int main()
{
    system("chcp 65001 > nul"); // para o console aceitar caracteres especiais
    setlocale(LC_ALL, "pt_BR.UTF-8"); // para definir como portugues
    NoLista *lista = NULL;
    RegistroDeHumor *salvar;
    int p, v;
    do
    {
        printf("-------------------MENU---------------------\n");
        printf("Escolha sua opção:\n");
        printf("1-Adicionar novo registro.\n");
        printf("2-Remover regristro por id.\n");
        printf("3-Buscar por humor.\n");
        printf("4-Imprimir todos os regristros.\n");
        printf("5-Mostra média da nota do dia.\n");
        printf("6 Mostrar humor mais frequentes.\n");
        printf("7-Mostrar os motivos do humor.\n");
        printf("8-Sair.\n");
        printf("--------------------------------------------\n");
        scanf("%d", &p);
        printf("\n");

        switch (p)
        {
        case 1:
            salvar = criarRegistro();
            inseNoFim(&lista, *salvar);
            free(salvar);
            break;
        case 2:
            printf("Digite o ID para remover:\n");
            scanf("%d", &v);
            removeID(&lista, v);
            break;
        case 3:
            printf("Qual humor procura:\n");
            printf("0 - FELIZ\t 1 - TRISTE\n2 - ANSIOSO\t 3 - CANSADO\n4 - MOTIVADO\t 5 - ESTRESSADO\n6 - NEUTRO\n");
            scanf("%d", &v);
            buscaporHumor(&lista, v);
            break;
        case 4:
            ImprimirTodos(&lista);
            break;
        case 5:
            printf("Para calcular a média dos últimos n dias, digite o valor para n:");
            scanf("%d", &v);
            printf("A média é: %.2f\n", medianotaDoDia(&lista, v));
            break;
        case 6:
            printf("Para exibir o humor mais frequente dos últimos n dias, digite o valor para n:\n");
            scanf("%d", &v);
            humorfrequente(&lista, v);
            break;
        case 7:
            printf("Escolha o Humor que voce deseja ver os motivos:\n");
            printf("0 - FELIZ\t 1 - TRISTE\n2 - ANSIOSO\t 3 - CANSADO\n4 - MOTIVADO\t 5 - ESTRESSADO\n6 - NEUTRO\n");
            scanf("%d", &v);
            motivohumor(&lista, v);
            break;
        default:
            printf("Elemento digitado invalido.\n");
            break;
        }
    } while (p != 8);

    return 0;
}