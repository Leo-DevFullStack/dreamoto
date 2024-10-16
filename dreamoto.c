#include "dreamotoLib.h"

int main() {
    carregarMotos();
    int opcao;

    do {
        printf("0 - Sair do Programa\n");
        printf("1 - Cadastrar Moto\n");
        printf("2 - Editar Moto Cadastrada\n");
        printf("3 - Excluir Moto\n");
        printf("4 - Ver Moto Cadastrada\n");
        printf("5 - Listar Todas Motos\n");
        printf("6 - Excluir Todas Motos\n");
        printf("7 - Add Favoritas\n");
        printf("8 - Ver Favoritas\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                limparTela();
                printf("-------- Voce esta em Cadastrar Moto --------\n");
                break;
            case 2:
                limparTela();
                printf("-------- Voce esta em Editar Moto Cadastrada --------\n");
                break;
            case 3:
                limparTela();
                printf("-------- Voce esta em Excluir Moto --------\n");
                break;
            case 4:
                limparTela();
                printf("-------- Voce esta em Ver Moto Cadastrada --------\n");
                break;
            case 5:
                limparTela();
                printf("-------- Voce esta em Listar Todas Motos --------\n");
                break;
            case 6:
                limparTela();
                printf("-------- Voce esta em Excluir Todas Motos --------\n");
                break;
            case 7:
                limparTela();
                printf("-------- Voce esta em Add Favoritas --------\n");
                break;
            case 8:
                limparTela();
                printf("-------- Voce esta em Ver Favoritas --------\n");
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                limparTela();
                printf("Opcao invalida.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}