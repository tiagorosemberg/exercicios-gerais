#include <stdio.h>

void ImprimeInvertido(char* string);

int main () {

    char palavra[1000];

    while(scanf("%s", palavra) == 1) {

        ImprimeInvertido(palavra);
        printf(" ");
    }

    return 0;
}

void ImprimeInvertido(char* string) {

    if (*string == '\0') {
        return;
    }

    ImprimeInvertido(string + 1);

    printf("%c", *string);
}