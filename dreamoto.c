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
        printf("7 - Planejar compra\n");
        printf("8 - Visualizar planos\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastrarMoto();
                break;
            case 2:
                editarMoto();
                break;
            case 3:
                excluirMoto();
                break;
            case 4:
                verMoto();
                break;
            case 5:
                listarMotos();             
                break;
            case 6:
                limparTela();
                printf("-------- Voce esta em Excluir Todas Motos --------\n");
                break;
            case 7:
                planejarCompra();
                break;
            case 8:
                visualizarPlanos();
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