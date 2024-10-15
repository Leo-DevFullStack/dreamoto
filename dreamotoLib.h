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

void salvarMotos() {
    FILE *arquivo = fopen("dreamoto.txt", "w");
    if (arquivo == NULL) return;

    for (int i = 0; i < totalMotos; i++) {
        fprintf(arquivo, "%d;%s;%s;%s;%d;%s;%.2f\n", motos[i].id, motos[i].marca, motos[i].tipo, motos[i].modelo, motos[i].ano, motos[i].cor, motos[i].preco);
    }

    fclose(arquivo);
}

void carregarMotos() {
    FILE *arquivo = fopen("dreamoto.txt", "r");
    if (arquivo == NULL) return;

    while (fscanf(arquivo, "%d;%49[^;];%49[^;];%49[^;];%d;%49[^;];%f\n", &motos[totalMotos].id, motos[totalMotos].marca, motos[totalMotos].tipo, motos[totalMotos].modelo, &motos[totalMotos].ano, motos[totalMotos].cor, &motos[totalMotos].preco) != EOF) {
        totalMotos++;
    }

    fclose(arquivo);
}

#endif