#ifndef DREAMOTOLIB_H
#define DREAMOTOLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char marca[TAMANHO_STRING];
    char tipo[TAMANHO_STRING];
    char modelo[TAMANHO_STRING];
    int ano;
    char cor[TAMANHO_STRING];
    float preco;
} Moto;

#endif