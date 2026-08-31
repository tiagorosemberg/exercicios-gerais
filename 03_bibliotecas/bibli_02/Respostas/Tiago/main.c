#include <stdio.h>
#include "matrix_utils.h"

int main() {

    int opcao, linhas1, colunas1, linhas2, colunas2;

    scanf(" %d %d", &linhas1, &colunas1);
    int matriz1[linhas1][colunas1];
    matrix_read(linhas1, colunas1, matriz1);

    scanf(" %d %d", &linhas2, &colunas2);
    int matriz2[linhas2][colunas2];
    matrix_read(linhas2, colunas2, matriz2);

    while(1) {

        printf("1 - Somar Matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: \n");

        if(scanf(" %d", &opcao) == 1) {

            if (opcao == 1) {

                if (possible_matrix_sum(linhas1, colunas1, linhas2, colunas2)) {
                    int resultado[linhas1][colunas1];
                    matrix_add(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, resultado);
                    matrix_print(linhas1, colunas1, resultado);
                } else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }

            } else if (opcao == 2) {

                if (possible_matrix_sub(linhas1, colunas1, linhas2, colunas2)) {
                    int resultado[linhas1][colunas1];
                    matrix_sub(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, resultado);
                    matrix_print(linhas1, colunas1, resultado);
                } else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }

            } else if (opcao == 3) {
                
                if (possible_matrix_multiply(linhas1, colunas2)) {
                    int resultado[linhas1][colunas2];
                    matrix_multiply(linhas1, colunas1, matriz1, linhas2, colunas2, matriz2, resultado);
                    matrix_print(linhas1, colunas2, resultado);
                } else {
                    printf("Erro: as dimensoes da matriz nao correspondem\n");
                }

            } else if (opcao == 4) {
                int escalar, num_matriz;
                scanf(" %d %d", &escalar, &num_matriz);
                
                if(num_matriz == 1) {
                    scalar_multiply(linhas1, colunas1, matriz1, escalar);
                    matrix_print(linhas1, colunas1, matriz1);

                } else if(num_matriz == 2) {
                    scalar_multiply(linhas2, colunas2, matriz2, escalar);
                    matrix_print(linhas2, colunas2, matriz2);
                }
                    
            } else if (opcao == 5) {
                int resultado1[colunas1][linhas1], resultado2[colunas2][linhas2];

                transpose_matrix(linhas1, colunas1, matriz1, resultado1);
                transpose_matrix(linhas2, colunas2, matriz2, resultado2);

                matrix_print(linhas1, colunas1, matriz1);
                matrix_print(linhas2, colunas2, matriz2);

            } else if (opcao == 6) {
                break;       
            }
        }
    }

    return 0;
}