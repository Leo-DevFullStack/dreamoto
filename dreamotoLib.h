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
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < totalMotos; i++) {
        fprintf(arquivo, "ID: %d;%s;%s;%s;%d;%s;%.2f\n", motos[i].id, motos[i].marca, motos[i].tipo, motos[i].modelo, motos[i].ano, motos[i].cor, motos[i].preco);
    }

    fclose(arquivo);
}

void carregarMotos() {
    FILE *arquivo = fopen("dreamoto.txt", "r");
    if (arquivo == NULL) {
        printf("Nenhum arquivo de motos encontrado.\n");
        return;
    }

    totalMotos = 0;
    while (fscanf(arquivo, "%d;%49[^;];%49[^;];%49[^;];%d;%49[^;];%f\n", &motos[totalMotos].id, motos[totalMotos].marca, motos[totalMotos].tipo, motos[totalMotos].modelo, &motos[totalMotos].ano, motos[totalMotos].cor, &motos[totalMotos].preco) != EOF) {
        totalMotos++;
    }

    fclose(arquivo);
}

void cadastrarMoto() {
    limparTela();
    printf("-------- Cadastro Nova Moto --------\n");
    if (totalMotos >= MAX_MOTOS) {
        printf("Limite de motos atingido.\n");
        pausar();
        return;
    }

    Moto novaMoto;

    printf("Digite o ID da moto (deve ser unico e um numero inteiro): ");
    scanf("%d", &novaMoto.id);
    getchar();

    for (int i = 0; i < totalMotos; i++) {
        if (motos[i].id == novaMoto.id) {
            printf("ID ja existente, tente novamente.\n");
            pausar();
            return;
        }
    }

    printf("Digite a marca da moto: ");
    fgets(novaMoto.marca, TAMANHO_STRING, stdin);
    novaMoto.marca[strcspn(novaMoto.marca, "\n")] = '\0';

    printf("Digite o tipo da moto: ");
    fgets(novaMoto.tipo, TAMANHO_STRING, stdin);
    novaMoto.tipo[strcspn(novaMoto.tipo, "\n")] = '\0';

    printf("Digite o modelo da moto: ");
    fgets(novaMoto.modelo, TAMANHO_STRING, stdin);
    novaMoto.modelo[strcspn(novaMoto.modelo, "\n")] = '\0';

    printf("Digite o ano da moto: ");
    scanf("%d", &novaMoto.ano);
    getchar();

    printf("Digite a cor da moto: ");
    fgets(novaMoto.cor, TAMANHO_STRING, stdin);
    novaMoto.cor[strcspn(novaMoto.cor, "\n")] = '\0';

    printf("Digite o preco da moto: ");
    scanf("%f", &novaMoto.preco);
    getchar();

    motos[totalMotos] = novaMoto;
    totalMotos++;

    salvarMotos();
    printf("Moto cadastrada com sucesso!\n");
    pausar();
}

void editarMoto() {
    limparTela();
    printf("-------- Editar Moto Cadastrada --------\n");
    
    if (totalMotos == 0) {
        printf("Nenhuma moto cadastrada.\n");
        pausar();
        return;
    }

    int id;
    printf("Digite o ID da moto que deseja editar: ");
    scanf("%d", &id);
    getchar();

    int indice = -1;
    for (int i = 0; i < totalMotos; i++) {
        if (motos[i].id == id) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("ID invalido.\n");
        pausar();
        return;
    }

    printf("-------- Editar Moto de ID: %d --------\n", motos[indice].id);
    printf("Aperte ENTER para manter os dados atuais.\n");

    printf("Marca atual: %s\nDigite a nova marca da moto: ", motos[indice].marca);
    char novaMarca[TAMANHO_STRING];
    fgets(novaMarca, TAMANHO_STRING, stdin);
    novaMarca[strcspn(novaMarca, "\n")] = '\0';
    if (strlen(novaMarca) > 0) {
        strcpy(motos[indice].marca, novaMarca);
    }

    printf("\nTipo atual: %s\nDigite o novo tipo da moto: ", motos[indice].tipo);
    char novoTipo[TAMANHO_STRING];
    fgets(novoTipo, TAMANHO_STRING, stdin);
    novoTipo[strcspn(novoTipo, "\n")] = '\0';
    if (strlen(novoTipo) > 0) {
        strcpy(motos[indice].tipo, novoTipo);
    }

    printf("\nModelo atual: %s\nDigite o novo modelo da moto: ", motos[indice].modelo);
    char novoModelo[TAMANHO_STRING];
    fgets(novoModelo, TAMANHO_STRING, stdin);
    novoModelo[strcspn(novoModelo, "\n")] = '\0';
    if (strlen(novoModelo) > 0) {
        strcpy(motos[indice].modelo, novoModelo);
    }

    printf("\nAno atual: %d\nDigite o novo ano da moto: ", motos[indice].ano);
    char novoAnoInput[10];
    fgets(novoAnoInput, 10, stdin);
    novoAnoInput[strcspn(novoAnoInput, "\n")] = '\0';
    if (strlen(novoAnoInput) > 0) {
        motos[indice].ano = atoi(novoAnoInput);
    }

    printf("\nCor atual: %s\nDigite a nova cor da moto: ", motos[indice].cor);
    char novaCor[TAMANHO_STRING];
    fgets(novaCor, TAMANHO_STRING, stdin);
    novaCor[strcspn(novaCor, "\n")] = '\0';
    if (strlen(novaCor) > 0) {
        strcpy(motos[indice].cor, novaCor);
    }

    printf("\nPreco atual: %.2f\nDigite o novo preco da moto: ", motos[indice].preco);
    char novoPrecoInput[20];
    fgets(novoPrecoInput, 20, stdin);
    novoPrecoInput[strcspn(novoPrecoInput, "\n")] = '\0';
    if (strlen(novoPrecoInput) > 0) {
        motos[indice].preco = atof(novoPrecoInput);
    }

    salvarMotos();
    printf("Moto editada com sucesso!\n");
    pausar();
}

#endif