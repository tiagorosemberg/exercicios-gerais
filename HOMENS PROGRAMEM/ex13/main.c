#include <stdio.h>

int main () {

    int temp, vib;

    while(1) {
        
        printf("TEMPERATURA: \n");
        scanf("%d", &temp);

        if(temp < 0) {
            printf("Entrada invalida\n");
            continue;
        }

        break;
    }

    while(1) {
        
        printf("VIBRACAO: \n");
        scanf("%d", &vib);

        if(vib < 0) {
            printf("Entrada invalida\n");
            continue;
        }

        break;
    }

    if (temp >= 90 || vib > 10) {
        printf("Critico\n");

    } else if (temp >= 75 || vib > 7) {
        printf("Atencao\n");

    } else {
        printf("Normal\n");
    }


    return 0;
}