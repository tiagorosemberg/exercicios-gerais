#include <stdio.h>
#include <stdlib.h>

int main() {

    int i, n, fatorial = 1;

    while(1) {
        printf("Numero que quer calcular o fatorial:\n");
        scanf(" %d", &n);
        
        if (n >= 0 && n <= 12) {
            break;
        }

        printf("Numero fora do intervalo (0 a 12)\n");
    }

    for (i = 1; i <= n; i++) {
        fatorial *= i; 
    }

    printf("O fatorial de %d eh %d\n", n, fatorial);

    return 0;
}