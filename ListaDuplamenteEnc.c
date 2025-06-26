#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaDuplamenteEnc.h"

int estavazia(NoLista **l)
{
    return (*l == NULL);
}

NoLista *ultimo(NoLista **l)
{
    NoLista *p;
    if (!estavazia(l))
    {
        for (p = *l; p->prox != NULL; p = p->prox)
            ;
        return p;
    }
    else
        printf("Lista vazia!\n");
    return NULL;
}

void inseNoFim(NoLista **l, RegistroDeHumor v) /*função insere no fim*/
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    NoLista *p;
    if (novo == NULL)
    {
        printf("ERRO AO ALOCAR MEMORIA\n");
    }
    else
    {
        novo->registros = v;
        novo->prox = NULL;
        novo->ant = NULL;
        if (!estavazia(l))
        {
            for (p = *l; p->prox != NULL; p = p->prox)
                ;
            p->prox = novo;
            novo->ant = p;
        }
        else
        {
            *l = novo;
        }
    }
}

void removeID(NoLista **l, int v) /*Remove o elemento com o ID v*/
{
    NoLista *p;
    if (!estavazia(l))
    {
        for (p = *l; p->registros.id != v && p != NULL; p = p->prox)
            ;
        if (p == NULL)
        {
            printf("ID NAO ENCONTRADO\n");
        }
        else if (p->ant == NULL && p->prox != NULL)
        {
            *l = p->prox;
            p->prox->ant = NULL;
            free(p);
        }
        else if (p->prox == NULL && p->ant != NULL)
        {
            p->ant->prox = NULL;
            free(p);
        }
        else if (p->prox != NULL && p->ant != NULL)
        {
            p->ant->prox = p->prox;
            p->prox->ant = p->ant;
            free(p);
        }
        else
        {
            free(p);
            *l = NULL;
        }
    }
    else
    {
        printf("Lista vazia\n");
    }
}

void buscaporHumor(NoLista **l, int v) /*Exibi o humor escolhido pelo usuario*/
{
    NoLista *p;
    for (p = *l; p != NULL; p = p->prox)
    {
        if (p->registros.humor == v)
            ImprimirRegistro(p->registros);
    }
}

void ImprimirTodos(NoLista **l)
{
    NoLista *p;
    if (!estavazia(l))
    {
        for (p = *l; p != NULL; p = p->prox)
            ImprimirRegistro(p->registros);
    }
    else
    {
        printf("Lista vazia!\n");
    }
}

float medianotaDoDia(NoLista **l, int v) /*Mostra a media das notas dos x dias*/
{
    if (!estavazia(l))
    {
        float n = 0;
        NoLista *p = ultimo(l);
        for (int i = 0; i != v; i++)
        {
            n += p->registros.notaDoDia;
            p = p->ant;
        }
        return n / v;
    }
    else
    {
        printf("Lista vazia!\n");
        return 0;
    }
}

void humorfrequente(NoLista **l, int v) /*Humor frequente nos ultimos x dias*/
{
    NoLista *p = ultimo(l);
    if (p != NULL)
    {
        int m = 0, i, cont[7] = {0, 0, 0, 0, 0, 0, 0};
        for (i = 0; i < v && p != NULL; i++)
        {
            cont[p->registros.humor]++;
            p = p->ant;
        }
        for (i = 0; i < 7; i++)
        {
            if (cont[i] > m)
            {
                m = cont[i];
            }
        }
        for (i = 0; i < 7; i++)
        {
            if (cont[i] == m && m > 0)
            {
                printf("O humor %s aparece %d vezes!\n", nomesHumor[i], m);
            }
        }
    }
}

void motivohumor(NoLista **l, int v)
{
    NoLista *p;
    int enc = 0;
    if (!estavazia(l))
    {
        for (p = *l; p != NULL; p = p->prox)
        {
            if (p->registros.humor == v)
            {
                printf("No dia %s o motivo era:\n%s\n", p->registros.data, p->registros.motivo);
                enc = 1;
            }
            printf("\n");
        }
        if (!enc)
        {
            printf("Nenhum registro encontrado!\n");
        }
    }
    else
    {
        printf("Lista vazia!\n");
    }
}
