#include <stdio.h>
#include <stdlib.h>

double calcularArea(double largura, double altura);
double aplicarMargem(double *area, double percentual);

int main() {

    double largura, altura, area, percentual;

    printf("Insira altura e largura, respectivamente, maiores do que zero:\n");
    
    scanf("%lf %lf", &altura, &largura);

    printf("Digite um percentual de segurança maior do que zero:\n");

    scanf("%lf", &percentual);
    
    area = calcularArea(largura, altura);

    printf("Area sem margem de seguranca: %.2f\n", area);

    aplicarMargem(&area, percentual);

    printf("Area com margem de seguranca: %.2f\n", area);

    return 0;
}

double calcularArea(double largura, double altura) {

    return largura * altura;
}


double aplicarMargem(double *area, double percentual) {

    *area = *area + ((percentual/100) * (*area));
}