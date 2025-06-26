#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "RegistroDeHumor.h"
int id = 0;

const char *nomesHumor[] = {
    "FELIZ",
    "TRISTE",
    "ANSIOSO",
    "CANSADO",
    "MOTIVADO",
    "ESTRESSADO",
    "NEUTRO"};

RegistroDeHumor *criarRegistro()
{
    RegistroDeHumor *v = (RegistroDeHumor *)malloc(sizeof(RegistroDeHumor));

    if (v == NULL)
    {
        printf("Erro ao criar registro\n");
    }
    id++;
    v->id = id;
    printf("Digite a data de hoje:\n");
    scanf(" %[^\n]", v->data);
    printf("Escolha seu humor de hoje:\n");
    printf("0 - FELIZ\t 1 - TRISTE\n2 - ANSIOSO\t 3 - CANSADO\n4 - MOTIVADO\t 5 - ESTRESSADO\n6 - NEUTRO\n");
    scanf("%d", &v->humor);
    if (v->humor < 0 || v->humor > 6)
    {
        printf("Digite uma opção valida\n");
    }
    printf("Fale o motivo do seu humor:\n");
    scanf(" %[^\n]", v->motivo);
    printf("Qual nota você daria para o seu dia de hoje?\n");
    scanf("%d", &v->notaDoDia);
    return v;
}

void ImprimirRegistro(RegistroDeHumor v)
{
    printf("LISTA:\n");
    printf("ID: %d\n", v.id);
    printf("DATA: %s\n", v.data);
    printf("HUMOR: %s\n", nomesHumor[v.humor]);
    printf("NOTA DO DIA: %d\n", v.notaDoDia);
    printf("MOTIVO:\n%s\n", v.motivo);
    printf("\n");
}

void liberarRegistro(RegistroDeHumor *v)
{
    free(v);
}
