#ifndef REGISTRO_H
#define REGISTRO_H

typedef enum
{
    FELIZ,
    TRISTE,
    ANSIOSO,
    CANSADO,
    MOTIVADO,
    ESTRESSADO,
    NEUTRO
} Humor;

typedef struct registro
{
    int id;
    char data[30];
    Humor humor;
    char motivo[100];
    int notaDoDia;
} RegistroDeHumor;

typedef struct nolista
{
    RegistroDeHumor registros;
    struct nolista *prox;
    struct nolista *ant;
} NoLista;

extern const char *nomesHumor[];
RegistroDeHumor *criarRegistro();
void ImprimirRegistro(RegistroDeHumor v);
void liberarRegistro(RegistroDeHumor *v);

#endif
