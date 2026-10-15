#include <stdio.h>
#include <stdlib.h>
#include "paciente.h"

void addLesaoPaciente(Paciente **lista, int qtdLista, Lesao *l) {

    int i;

    for (i = 0; i < qtdLista; ) {

        if (strcmp(getCartaoSusPaciente(lista[i]), getCartaoSusLesao(l))) {
            vinculaLesaoPaciente(lista[i], l);
        }
    }
}

void estatisticas (Paciente **lista, int qtdLista) {

    int i, soma = 0;
    Data *dataBase = criaData(12, 9, 2023);

    for (i = 0; i < qtdLista; i++) {
        soma += calculaIdadePaciente(lista[i], dataBase);
    }


    printf("TOTAL PACIENTES: %d", qtdLista);

    if (soma != 0) {
        printf("MEDIA IDADE (ANOS): %d\n", soma / qtdLista);
    } else {
        printf("MEDIA IDADE (ANOS): -\n");
    }
    


    printf("TOTAL PACIENTES: %d\n", qtdLista);
    printf("TOTAL LESOES");

    liberaData(dataBase);
}

int main () {

    char opcao;
    int qtdLista;

    Paciente **listaPacientes = NULL;

    while (1) {

        if (opcao == 'P') {



        }


    }

}