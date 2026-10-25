#include <stdio.h>
#include <stdlib.h>

int main () {

    int soma = 0, i;

    printf("--------------------\n");

    for (i = 1; i <= 7; i+= 2) {

        soma += i;

        printf("i: %d ----- Soma: %d\n", i, soma);

    }

    printf("--------------------\n");

    return 0;
}