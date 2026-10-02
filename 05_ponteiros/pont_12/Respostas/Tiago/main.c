#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

int fazSoma(int n1, int n2);
int fazMultiplicacao(int n1, int n2);

int  main() {

    Vetor vetor;

    LeVetor(&vetor);

    printf("Soma: %d\n", AplicarOperacaoVetor(&vetor, fazSoma));
    printf("Produto: %d\n", AplicarOperacaoVetor(&vetor, fazMultiplicacao));

    return 0;
}

int fazSoma(int n1, int n2) {

    return n1 + n2;
}

int fazMultiplicacao(int n1, int n2) {
    return n1 * n2;
}