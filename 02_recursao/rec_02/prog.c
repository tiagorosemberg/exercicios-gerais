#include <stdio.h>

int SomaElementosPares(int* vet, int numElementos);

int main() {

    int i, j, qtd_vetores, qtd_elementos, elemento;

    scanf(" %d", &qtd_vetores);

    for(i = 0; i < qtd_vetores; i++) {

        scanf(" %d", &qtd_elementos);

        int vetor[qtd_elementos];

        for (j = 0; j < qtd_elementos; j++) {

            scanf(" %d", &vetor[j]);
        }


        printf("%d\n", SomaElementosPares(vetor, qtd_elementos));

    }

    return 0;
}

int SomaElementosPares(int* vet, int numElementos) {

    if (numElementos == 0) {
        return 0;
    } else {
        if (*vet % 2 == 0) {
            return *vet + SomaElementosPares(vet, numElementos - 1);
        } else {
            return SomaElementosPares(vet, numElementos - 1);
        }
    }
}