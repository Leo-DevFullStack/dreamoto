#ifndef DREAMOTOLIB_H
#define DREAMOTOLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOTOS 100
#define TAMANHO_STRING 50

typedef struct {
    int id;
    char marca[TAMANHO_STRING];
    char tipo[TAMANHO_STRING];
    char modelo[TAMANHO_STRING];
    int ano;
    char cor[TAMANHO_STRING];
    float preco;
} Moto;

Moto motos[MAX_MOTOS];
int totalMotos = 0;

void limparTela() {
    system("cls || clear");
}

void pausar() {
    printf("\nPressione Enter para continuar...");
    getchar();
}

#endif