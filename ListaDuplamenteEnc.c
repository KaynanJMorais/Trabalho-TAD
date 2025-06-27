#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaDuplamenteEnc.h" // inclui o arquivo ListaDuplamenteEnc.h

// Função para verificar se a lista esta vazia
int estavazia(NoLista **l)
{
    return (*l == NULL);
}

// Função para verificar o ultimo elemento da lista
NoLista *ultimo(NoLista **l)
{
    NoLista *p;        // Cria um ponteiro auxiliar
    if (!estavazia(l)) // Verifica se a lista não está vazia
    {
        for (p = *l; p->prox != NULL; p = p->prox) // Percorre a lista até o último elemento
            ;
        return p; // Retorna o último elemento
    }
    else
        printf("Lista vazia!\n"); // Caso a lista esteja vazia
    return NULL;
}

// Função para adicionar os elementos
void inseNoFim(NoLista **l, RegistroDeHumor v) /*função insere no fim*/
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista)); // Aloca memória para o novo nó
    NoLista *p;                                         // Cria um ponteiro auxiliar
    if (novo == NULL)                                   // Verifica se a alocação foi bem sucedida
    {
        printf("ERRO AO ALOCAR MEMORIA\n"); // Caso a alocação falhe
    }
    else
    {
        novo->registros = v; // Insere o valor no novo nó
        novo->prox = NULL;   // Define o próximo nó como NULL
        novo->ant = NULL;    // Define o nó anterior como NULL
        if (!estavazia(l))   // Verifica se a lista não está vazia
        {
            for (p = *l; p->prox != NULL; p = p->prox) // Percorre a lista até o último elemento
                ;
            p->prox = novo; // Insere o novo nó no fim da lista
            novo->ant = p;  // Define o nó anterior do novo nó como o último elemento da lista
        }
        else
        {
            *l = novo; // Caso a lista esteja vazia, insere o novo nó como o primeiro elemento
        }
    }
}

// Função para remover pelo ID
void removeID(NoLista **l, int v) /*Remove o elemento com o ID v*/
{
    NoLista *p;        // Cria um ponteiro auxiliar
    if (!estavazia(l)) // Verifica se a lista não está vazia
    {
        for (p = *l; p->registros.id != v && p != NULL; p = p->prox) // Percorre a lista até encontrar o elemento com o ID V ou até o fim da lista caso não encontre
            ;
        if (p == NULL) // Caso o elemento não seja encontrado
        {
            printf("ID NAO ENCONTRADO\n"); // Imprime mensagem de erro
        }
        else if (p->ant == NULL && p->prox != NULL) // Caso o elemento seja o primeiro da lista
        {
            *l = p->prox;        // Remove o elemento da lista
            p->prox->ant = NULL; // Define o nó anterior do elemento removido como NULL
            free(p);             // Libera a memória alocada para o elemento removido
        }
        else if (p->prox == NULL && p->ant != NULL) // Caso o elemento seja o último da lista
        {
            p->ant->prox = NULL; // Remove o elemento da lista
            free(p);             // Libera a memória alocada para o elemento removido
        }
        else if (p->prox != NULL && p->ant != NULL) // Caso o elemento seja um elemento no meio da lista
        {
            p->ant->prox = p->prox; // Remove o elemento da lista, faz o anterior receber o proximo cortando o do meio
            p->prox->ant = p->ant;  // Define o nó anterior do elemento removido como o nó anterior do elemento removido
            free(p);                // Libera a memória alocada para o elemento removido
        }
        else // Caso seja o primeiro e unico
        {
            free(p);   // Libera a memória alocada para o elemento removido
            *l = NULL; // Define a lista como vazia
        }
    }
    else // caso lista esteja vazia
    {
        printf("Lista vazia\n");
    }
}

// Busca e imprime o registro que contem o humor que o usario deseja
void buscaporHumor(NoLista **l, int v) /*Exibi o humor escolhido pelo usuario*/
{
    NoLista *p;                          // Cria um ponteiro auxiliar
    for (p = *l; p != NULL; p = p->prox) // Percorre a lista até o fim
    {
        if (p->registros.humor == v)        // Verifica se o humor do registro é igual ao valor passado
            ImprimirRegistro(p->registros); // Imprime o registro
    }
}

// Imprime todos os registros da lista
void ImprimirTodos(NoLista **l)
{
    NoLista *p;        // Cria um ponteiro auxiliar
    if (!estavazia(l)) // Verifica se a lista não está vazia
    {
        for (p = *l; p != NULL; p = p->prox) // Percorre a lista até o fim
            ImprimirRegistro(p->registros);  // Imprime o registro
    }
    else
    {
        printf("Lista vazia!\n"); // Imprime mensagem caso a lista esteja vazia
    }
}

// Retorna a media das notas dos dias que o usuario escolheu
float medianotaDoDia(NoLista **l, int v) /*Mostra a media das notas dos x dias*/
{
    if (!estavazia(l)) // Verifica se a lista não está vazia
    {
        float n = 0;                 // Cria uma variavel para armazenar a soma das notas
        NoLista *p = ultimo(l);      // Cria um ponteiro auxiliar para apontar para o ultimo elemento da lista
        for (int i = 0; i != v; i++) // Percorre a lista até o dia escolhido
        {
            if (p == NULL)
            { // Caso o dia escolhido seja maior que a quantidade de dias :)
                printf("Dia nao encontrado\n");
                return 0;
            }
            n += p->registros.notaDoDia; // Soma as notas
            p = p->ant;                  // Move o ponteiro para o elemento anterior
        }
        return n / v; // Retorna a media das notas
    }
    else
    {
        printf("Lista vazia!\n"); // Imprime mensagem caso a lista esteja vazia
        return 0;                 // Retorna 0 caso a lista esteja vazia
    }
}

// Imprimi o quais os humores mais frequentes dos ultimos dias definidos pelo usuario
void humorfrequente(NoLista **l, int v) /*Humor frequente nos ultimos x dias*/
{
    NoLista *p = ultimo(l); // Cria um ponteiro auxiliar para apontar para o ultimo elemento da lista
    if (p != NULL)          // Verifica se a lista não está vazia
    {
        int m = 0, i, cont[7] = {0, 0, 0, 0, 0, 0, 0}; // Cria um vetor para armazenar a contagem de cada humor
        for (i = 0; i < v && p != NULL; i++)           // Percorre a lista até o dia escolhido
        {
            cont[p->registros.humor]++; // Incrementa a contagem do humor
            p = p->ant;                 // Move o ponteiro para o elemento anterior
        }
        for (i = 0; i < 7; i++) // Percorre o vetor de contagem
        {
            if (cont[i] > m) // Verifica se a contagem do humor é maior que a maior contagem encontrada
            {
                m = cont[i]; // Atualiza a maior contagem
            }
        }
        for (i = 0; i < 7; i++) // Percorre o vetor de contagem
        {
            if (cont[i] == m && m > 0) // Verifica se a contagem do humor é igual a maior contagem encontrada e maior qu
            {
                printf("O humor %s aparece %d vezes!\n", nomesHumor[i], m); // Imprime o humor mais frequente
            }
        }
    }
}

// Imprime os motivos do humor desejado pelo usuario
void motivohumor(NoLista **l, int v)
{
    NoLista *p;        // Cria um ponteiro auxiliar para apontar para o elemento da lista
    int enc = 0;       // Cria uma variavel para armazenar a posicao do elemento da lista
    if (!estavazia(l)) // Verifica se a lista não está vazia
    {
        for (p = *l; p != NULL; p = p->prox) // Percorre a lista
        {
            if (p->registros.humor == v) // Verifica se o humor do registro é igual ao desejado
            {
                printf("No dia %s o motivo era:\n%s\n", p->registros.data, p->registros.motivo); // Imprime o motivo do humor
                enc = 1;                                                                         // Atualiza a variavel para 1
            }
            printf("\n"); // Imprime uma quebra de linha
        }
        if (!enc) // Verifica se o humor não foi encontrado
        {
            printf("Nenhum registro encontrado!\n"); // Imprime uma mensagem de erro
        }
    }
    else
    {
        printf("Lista vazia!\n"); // Imprime uma mensagem de erro
    }
}
