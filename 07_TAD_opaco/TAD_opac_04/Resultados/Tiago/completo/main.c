#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

int main() {

    int n, i, j;
    
    scanf(" %d", &n);
    
    tAluno **alunos = (tAluno**)calloc(n, sizeof(tAluno*));
    
    for (i = 0; i < n; i ++) {

        tAluno *aluno = CriaAluno();

        LeAluno(aluno);

        alunos[i] = aluno;
    }

    for (i = 0; i < n - 1; i++) {

        tAluno *aux;

        for (j = i + 1; j < n; j++) {

            if (ComparaMatricula(alunos[i], alunos[j]) == 1) {

                aux = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = aux;
            }
        }
    }

    for (i = 0; i < n; i++) {

        if(VerificaAprovacao(alunos[i])) {
            ImprimeAluno(alunos[i]);
        }
    }    


    for (i = 0; i < n; i++) {

        ApagaAluno(alunos[i]);
    }

    free(alunos);

    return 0;
}