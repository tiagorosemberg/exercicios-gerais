#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main () {

    int tamanho;
    float media;

    scanf(" %d", &tamanho);

    int *vetor = CriaVetor(tamanho);

    LeVetor(vetor, tamanho);

    media = CalculaMedia(vetor, tamanho);

    printf("%.2f", media);

    LiberaVetor(vetor);

    return 0;
}