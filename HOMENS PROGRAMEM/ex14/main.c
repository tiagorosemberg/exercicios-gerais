#include <stdio.h>
#include <stdlib.h>

int main() {

    double corrente, limite, limite_90;

    printf("Digite a corrente e o limite, respectivamente:\n");

    scanf("%lf %lf", &corrente, &limite);

    limite_90 = (limite * 90)/100;

    if (corrente < 0 || limite <= 0) {
        printf("Entrada invalida\n");
    }

    printf("Corrente: %.2lf\n", corrente);
    printf("Limite: %.2lf\n", limite);
    printf("90%% do limite: %.2lf\n", limite_90);

    if (corrente > limite) {

        printf("Sobrecarga\n");
    
    } else if(corrente > limite_90) {
        printf("Atencao\n");
    
    } else {
        printf("Normal\n");
    }

    return 0;
}