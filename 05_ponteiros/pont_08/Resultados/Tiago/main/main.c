#include <stdio.h>
#include "tDepartamento.h"

int main () {

    int m1, m2, m3, qnt, i;
    char nome[STRING_MAX], diretor[STRING_MAX], curso1[STRING_MAX], curso2[STRING_MAX], curso3[STRING_MAX]; 

    scanf(" %d", &qnt);

    tDepartamento departamentos[qnt];

    for (i = 0; i < qnt; i++) {

        scanf(" %[^\n]", nome);
        scanf(" %[^\n]", diretor);
        scanf(" %[^\n]", curso1);
        scanf(" %[^\n]", curso2);
        scanf(" %[^\n]", curso3);
        scanf(" %d", &m1);
        scanf(" %d", &m2);
        scanf(" %d", &m3);

        departamentos[i] = CriaDepartamento(curso1, curso2, curso3, nome, m1, m2, m3, diretor);
    }

    OrdenaDepartamentosPorMedia(departamentos, qnt);

    for (i = 0; i < qnt; i++) {
        ImprimeAtributosDepartamento(departamentos[i]);
    }
 
    return 0;
}