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
                excluirTodasMotos();
                break;
            case 7: {
                int subOpcao;
                do {
                    limparTela();
                    printf("-------- Planejar Compra --------\n");
                    printf("0 - Voltar ao menu anterior\n");
                    printf("1 - Planos para uma moto pelo ID\n");
                    printf("2 - Gerar plano para todas motos em \"X\" meses\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &subOpcao);
                    getchar();

                    switch (subOpcao) {
                        case 0:
                            printf("Voltando ao menu principal...\n");
                            break;
                        case 1:
                            planejarCompra();
                            break;
                        case 2:
                            planejarCompraTodasMotos();
                            break;
                        default:
                            printf("Opcao invalida.\n");
                            pausar();
                            break;
                    }
                } while (subOpcao != 0);
                break;
            }
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