#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "paciente.h"

void addLesaoPaciente(Paciente **lista, int qtdLista, Lesao *l) {

    int i, encontrou = 0;

    for (i = 0; i < qtdLista; i++) {

        if (strcmp(getCartaoSusPaciente(lista[i]), getCartaoSusLesao(l)) == 0) {
            vinculaLesaoPaciente(lista[i], l);
            encontrou = 1;
            break;
        }
    }

    if (!encontrou) {
        liberaLesao(l);
    }
}

void estatisticas (Paciente **lista, int qtdLista) {

    int i, soma = 0, total = 0, cirurgicas = 0;
    Data *dataBase = criaData(12, 9, 2023);

    for (i = 0; i < qtdLista; i++) {
        soma += calculaIdadePaciente(lista[i], dataBase);
    }

    for (i = 0; i < qtdLista; i++) {
        total += getNumLesoesPaciente(lista[i]);
    }

    for (i = 0; i < qtdLista; i++) {
        cirurgicas += qtdLesoesCirurgicasPaciente(lista[i]);
    }


    printf("TOTAL PACIENTES: %d\n", qtdLista);

    if (qtdLista > 0) {
        printf("MEDIA IDADE (ANOS): %d\n", soma / qtdLista);
    } else {
        printf("MEDIA IDADE (ANOS): -\n");
    }

    printf("TOTAL LESOES: %d\n", total);

    printf("TOTAL CIRURGIAS: %d\n", cirurgicas);

    printf("LISTA DE PACIENTES:\n");

    for (i = 0; i < qtdLista; i++) {
        if (getNumLesoesPaciente(lista[i]) > 0) {
            imprimePaciente(lista[i]);
        }
    }

    liberaData(dataBase);
}

// TOTAL PACIENTES: 4
// MEDIA IDADE (ANOS): 29
// TOTAL LESOES: 3
// TOTAL CIRURGIAS: 2
// LISTA DE PACIENTES:
// - TRISTANA - L8 
// - LUCIAN - L2 
// - LUX - L100 


int main () {

    char opcao;
    int qtdLista = 0, i;

    Paciente **listaPacientes = NULL;
    Lesao *lesao;

    while (1) {

        scanf(" %c\n", &opcao);

        if (opcao == 'P') {

            listaPacientes = realloc(listaPacientes, (qtdLista+1)*sizeof(Paciente*));

            listaPacientes[qtdLista] = lerPaciente();
            qtdLista++;
        
        } else if (opcao == 'L') {

           lesao = lerLesao();
           addLesaoPaciente(listaPacientes, qtdLista, lesao);
        
        } else if(opcao == 'F') {
            break;
        }
    }
    
    estatisticas(listaPacientes, qtdLista);

    for (i = 0; i < qtdLista; i++) {
        liberaPaciente(listaPacientes[i]);
    }
    free(listaPacientes);
    
    return 0;
}