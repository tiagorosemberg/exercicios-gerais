#include <stdio.h>
#include "calculadora.h"

float fazAdicao(float n1, float n2);
float fazSubtracao(float n1, float n2);
float fazMultiplicacao(float n1, float n2);
float fazDivisao(float n1, float n2);


int main () {

    int sair = 1;
    char opcao;
    float n1, n2;

    while(sair) {
        
        scanf(" %c", &opcao);

        scanf(" %f %f", &n1, &n2);

        switch (opcao) {

            case 'a':
                Calcular(n1, n2, fazAdicao);
                break;

            case 's':
                Calcular(n1, n2, fazSubtracao);
                break;
            
            case 'm':
                Calcular(n1, n2, fazMultiplicacao);
                break;

            case 'd':
                Calcular(n1, n2, fazDivisao);
                break;

            case 'f':
                sair = 0;
                break;
        }
    }
    
    return 0;
}

float fazAdicao(float n1, float n2) {

    float resultado = n1 + n2;

    printf("%.2f + %.2f = %.2f\n", n1, n2, resultado);

    return resultado;
}

float fazSubtracao(float n1, float n2) {

    float resultado = n1 - n2;

    printf("%.2f - %.2f = %.2f\n", n1, n2, resultado);

    return resultado;
}

float fazMultiplicacao(float n1, float n2) {

    float resultado = n1 * n2;

    printf("%.2f x %.2f = %.2f\n", n1, n2, resultado);

    return resultado;
}

float fazDivisao(float n1, float n2) {

    float resultado = n1 / n2;

    printf("%.2f / %.2f = %.2f\n", n1, n2, resultado);

    return resultado;
}