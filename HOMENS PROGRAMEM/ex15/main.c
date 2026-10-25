#include <stdio.h>
#include <stdlib.h>

int main() {

    int op;
    do {

        printf("1 - Cadastrar\n");
        printf("2 - Consultar\n");
        printf("0 - Encerrar\n");
        
        scanf("%d", &op);
        
        switch (op) {

            case 1:
                printf("Cadastrar\n");
                break;

            case 2:
                printf("Consultar\n");
                break;
            
            case 0:
                printf("Encerrando\n");
                break;

            default:
                printf("Opcao invalida\n");
                break;
        }

    } while (op != 0);

    return 0;
}