#ifndef DREAMOTOLIB_H
#define DREAMOTOLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOTOS 500
#define TAMANHO_STRING 200

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
        fprintf(arquivo, "%d;%s;%s;%s;%d;%s;%.2f\n", motos[i].id, motos[i].marca, motos[i].tipo, motos[i].modelo, motos[i].ano, motos[i].cor, motos[i].preco);
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
    while (fscanf(arquivo, "%d;%499[^;];%4999[^;];%499[^;];%d;%499[^;];%f\n", &motos[totalMotos].id, motos[totalMotos].marca, motos[totalMotos].tipo, motos[totalMotos].modelo, &motos[totalMotos].ano, motos[totalMotos].cor, &motos[totalMotos].preco) != EOF) {
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

void excluirMoto() {
    limparTela();
    printf("-------- Excluir Moto --------\n");

    if (totalMotos == 0) {
        printf("Nenhuma moto cadastrada.\n");
        pausar();
        return;
    }

    int id;
    printf("Digite o ID da moto que deseja excluir: ");
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
        printf("ID nao encontrado.\n");
        pausar();
        return;
    }

    for (int i = indice; i < totalMotos - 1; i++) {
        motos[i] = motos[i + 1];
    }
    totalMotos--;

    salvarMotos();
    printf("Moto excluida com sucesso!\n");
    pausar();
}

void verMoto() {
    limparTela();
    printf("-------- Visualizar Moto --------\n");

    if (totalMotos == 0) {
        printf("Nenhuma moto cadastrada.\n");
        pausar();
        return;
    }

    int id;
    printf("Digite o ID da moto que deseja visualizar: ");
    scanf("%d", &id);
    getchar();

    int encontrada = 0;
    for (int i = 0; i < totalMotos; i++) {
        if (motos[i].id == id) {
            Moto moto = motos[i];
            printf("ID: %d | Marca: %s | Tipo: %s | Modelo: %s | Ano: %d | Cor: %s | Preco: %.2f\n", moto.id, moto.marca, moto.tipo, moto.modelo, moto.ano, moto.cor, moto.preco);
            encontrada = 1;
            break;
        }
    }

    if (!encontrada) {
        printf("Nenhuma moto encontrada com o ID informado.\n");
    }

    pausar();
}

void listarMotos() {
    limparTela();
    printf("-------- Listar Todas Motos --------\n");

    if (totalMotos == 0) {
        printf("Nenhuma moto cadastrada.\n");
        pausar();
        return;
    }

    for (int i = 0; i < totalMotos; i++) {
        printf("ID: %d | %s | %s | %s | %d | %s | R$%.2f\n", motos[i].id, motos[i].marca, motos[i].tipo, motos[i].modelo, motos[i].ano, motos[i].cor, motos[i].preco);
    }
    pausar();
}

void excluirTodasMotos() {
    limparTela();
    printf("-------- Excluir Todas Motos --------\n");

    if (totalMotos == 0) {
        printf("Nenhuma moto cadastrada.\n");
        pausar();
        return;
    }

    int opcao;
    printf("Escolha uma opcao:\n");
    printf("0 - Voltar ao menu inicial\n");
    printf("1 - Excluir todas as motos cadastradas\n");
    printf("2 - Excluir todos planejamentos cadastrados\n");
    printf("3 - Excluir todos os dados de ambos os arquivos\n");
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
        case 0:
            printf("\n-------- DREAMOTO / MENU PRINCIPAL --------\n");
            return;
        case 1:
            totalMotos = 0;
            salvarMotos();
            printf("Todas as motos cadastradas foram excluidas.\n");
            break;
        case 2: {
            FILE *arquivoPlanos = fopen("planos.txt", "w");
            if (arquivoPlanos != NULL) fclose(arquivoPlanos);
            printf("Todos planejamentos foram excluidos.\n");
            break;
        }
        case 3:
            totalMotos = 0;
            salvarMotos();
            FILE *arquivoPlanos = fopen("planos.txt", "w");
            if (arquivoPlanos != NULL) fclose(arquivoPlanos);
            printf("Todos os dados de ambos os arquivos foram excluidos.\n");
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }

    pausar();
}

void planejarCompra() {
    limparTela();
    printf("-------- Planejar compra --------\n");

    if (totalMotos == 0) {
        printf("Nenhuma moto cadastrada.\n");
        pausar();
        return;
    }

    int id;
    printf("Escolha uma moto digitando o ID referente a mesma, ou volte ao menu e veja os IDs na opcao 5: ");
    scanf("%d", &id);
    getchar();

    Moto *motoEscolhida = NULL;
    for (int i = 0; i < totalMotos; i++) {
        if (motos[i].id == id) {
            motoEscolhida = &motos[i];
            break;
        }
    }

    if (motoEscolhida == NULL) {
        printf("ID invalido.\n");
        pausar();
        return;
    }

    printf("Moto escolhida: %s %s %s, Ano: %d, Cor: %s, Preco: %.2f\n", motoEscolhida->marca, motoEscolhida->tipo, motoEscolhida->modelo, motoEscolhida->ano, motoEscolhida->cor, motoEscolhida->preco);

    float economiaMensal;
    printf("Digite o valor que voce pode guardar por mes: ");
    scanf("%f", &economiaMensal);
    getchar();

    int meses = (int)(motoEscolhida->preco / economiaMensal);
    printf("Voce deve guardar %.2f por %d meses para comprar a %s %s %s\n", economiaMensal, meses, motoEscolhida->marca, motoEscolhida->tipo, motoEscolhida->modelo);

    FILE *arquivoPlanos = fopen("planos.txt", "a");
    if (arquivoPlanos == NULL) return;

    fprintf(arquivoPlanos, "Moto: %s %s %s | Economia Mensal: %.2f | Qntd. de Meses: %d\n", motoEscolhida->marca, motoEscolhida->tipo, motoEscolhida->modelo, economiaMensal, meses);
    fclose(arquivoPlanos);

    pausar();
}

void visualizarPlanos() {
    limparTela();
    printf("-------- Voce esta Visualizando seus ultimos planos de compra --------\n");

    if (totalMotos == 0) {
        printf("Nenhuma moto cadastrada.\n");
        pausar();
        return;
    }

    FILE *arquivoPlanos = fopen("planos.txt", "r");
    if (arquivoPlanos == NULL) {
        printf("Nenhuma compra planejada foi registrada.\n");
        pausar();
        return;
    }

    char linha[200];
    while (fgets(linha, sizeof(linha), arquivoPlanos)) {
        printf("%s", linha);
    }

    fclose(arquivoPlanos);
    pausar();
}

void planejarCompraTodasMotos() {
    limparTela();
    printf("-------- Planejar compra para todas as motos --------\n");

    if (totalMotos == 0) {
        printf("Nenhuma moto cadastrada.\n");
        pausar();
        return;
    }

    int meses;
    printf("Digite o numero de meses para planejar (valor inteiro): ");
    scanf("%d", &meses);
    getchar();

    if (meses <= 0) {
        printf("Numero de meses deve ser maior que zero.\n");
        pausar();
        return;
    }

    FILE *arquivoPlanos = fopen("planos.txt", "a");
    if (arquivoPlanos == NULL) {
        printf("Erro ao abrir o arquivo de planos.\n");
        pausar();
        return;
    }

    for (int i = 0; i < totalMotos; i++) {
        Moto *motoEscolhida = &motos[i];
        float economiaMensal = motoEscolhida->preco / meses;

        fprintf(arquivoPlanos, "Moto: %s %s %s | Economia Mensal: %.2f | Qntd. de Meses: %d\n",
                motoEscolhida->marca, motoEscolhida->tipo, motoEscolhida->modelo, economiaMensal, meses);

        printf("Moto: %s %s %s | Economia Mensal: %.2f | Qntd. de Meses: %d\n",
               motoEscolhida->marca, motoEscolhida->tipo, motoEscolhida->modelo, economiaMensal, meses);
    }

    fclose(arquivoPlanos);
    printf("Planos gerados e salvos com sucesso!\n");
    pausar();
}

void pesquisarPlanosSalvos() {
    limparTela();
    printf("-------- Pesquisar Planos --------\n");

    FILE *arquivoPlanos = fopen("planos.txt", "r");
    if (arquivoPlanos == NULL) {
        printf("Nenhum plano registrado.\n");
        pausar();
        return;
    }

    char busca[TAMANHO_STRING];
    printf("Digite dados da moto para pesquisar em planos\n(Ex: Marca, Tipo, Modelo, etc...):\n");
    fgets(busca, TAMANHO_STRING, stdin);
    busca[strcspn(busca, "\n")] = '\0';

    char linha[300];
    int encontrou = 0;

    while (fgets(linha, sizeof(linha), arquivoPlanos)) {
        if (strstr(linha, busca)) {
            printf("%s", linha);
            encontrou = 1;
        }
    }

    fclose(arquivoPlanos);

    if (!encontrou) {
        printf("\nNenhum plano encontrado com o criterio informado\n\nDigite um criterio novamente ou aperte enter para voltar ao menu\n");
    }

    pausar();
}

#endif