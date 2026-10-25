#include <stdio.h>
#include <stdlib.h>

int quadrado (int x) {

    return x * x;
}

void dobro (int* x) {

    *x = 2 * (*x);

}

int main() {

    int x = 5;

    printf("%d\n", quadrado(x));
    printf("%d\n", x);

    dobro(&x);

    printf("%d\n", x);

    return 0;
}