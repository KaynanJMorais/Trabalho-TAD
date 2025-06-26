#ifndef DUPLAMENTEENCAD_H
#define DUPLAMENTEENCAD_H
#include "RegistroDeHumor.h"

NoLista *ultimo(NoLista **l);
int estavazia(NoLista **l);
void inseNoFim(NoLista **l, RegistroDeHumor v);
void removeID(NoLista **l, int v);
void buscaporHumor(NoLista **l, int v);
void ImprimirTodos(NoLista **l);
float medianotaDoDia(NoLista **l, int v);
void humorfrequente(NoLista **l, int v);
void motivohumor(NoLista **l, int v);
#endif