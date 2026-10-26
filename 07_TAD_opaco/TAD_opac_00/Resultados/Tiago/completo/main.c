#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "circulo.h"

int main() {

    float xc, yc, r, xp, yp;

    tCirculo circulo;
    tPonto ponto;

    scanf(" %f %f %f %f %f", &xc, &yc, &r, &xp, &yp);

    circulo = Circulo_Cria(xc, yc, r);
    ponto = Pto_Cria(xp, yp);

    printf("%d", Circulo_Interior(circulo, ponto));

    Circulo_Apaga(circulo);
    Pto_Apaga(ponto);

    return 0;
}