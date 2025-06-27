#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "RegistroDeHumor.h"
int id = 0; // Variable global para o ID do registro

// Transforma os numeros de Humor para uma string
const char *nomesHumor[] = { 
    "FELIZ",
    "TRISTE",
    "ANSIOSO",
    "CANSADO",
    "MOTIVADO",
    "ESTRESSADO",
    "NEUTRO"};

// Função para criar um novo registro de humor
RegistroDeHumor *criarRegistro()
{
    RegistroDeHumor *v = (RegistroDeHumor *)malloc(sizeof(RegistroDeHumor)); // Alocar memória para o registro

    if (v == NULL) // Verificar se a alocação foi bem sucedida
    {
        printf("Erro ao criar registro\n"); // Imprimir mensagem de erro
    }
    id++; // Incrementar o ID do registro
    v->id = id; // Atribuir o ID ao registro
    printf("Digite a data de hoje:\n"); // Imprimir mensagem para o usuário
    scanf(" %[^\n]", v->data); // Ler a data do usuário
    printf("Escolha seu humor de hoje:\n"); // Imprimir mensagem para o usuário
    printf("0 - FELIZ\t 1 - TRISTE\n2 - ANSIOSO\t 3 - CANSADO\n4 - MOTIVADO\t 5 - ESTRESSADO\n6 - NEUTRO\n"); // Imprimir opções de humor
    scanf("%d", &v->humor); // Ler o humor do usuário
    if (v->humor < 0 || v->humor > 6) // Verificar se o humor escolhido é válido
    {
        printf("Digite uma opção valida\n"); // Imprimir mensagem de erro
    }
    printf("Fale o motivo do seu humor:\n"); // Imprimir mensagem para o usuário
    scanf(" %[^\n]", v->motivo); // Ler o motivo do usuário
    printf("Qual nota você daria para o seu dia de hoje?\n"); // Imprimir mensagem para o usuário
    scanf("%f", &v->notaDoDia); // Ler a nota do usuário
    return v; // Retornar o registro criado
}

// Função para imprimir o registro de humor
void ImprimirRegistro(RegistroDeHumor v)
{
    printf("LISTA:\n");
    printf("ID: %d\n", v.id);
    printf("DATA: %s\n", v.data);
    printf("HUMOR: %s\n", nomesHumor[v.humor]);
    printf("NOTA DO DIA: %f\n", v.notaDoDia);
    printf("MOTIVO:\n%s\n", v.motivo);
    printf("\n");
}

// Função para liberar o Registro
void liberarRegistro(RegistroDeHumor *v)
{
    free(v);
}
