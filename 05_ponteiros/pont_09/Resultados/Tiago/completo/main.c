#include <stdio.h>
#include "pessoa.h"

int main () {

    int n_pessoas, n_associacoes;
    int i;

    scanf("%d", &n_pessoas);

    tPessoa pessoas[n_pessoas];

    for (i = 0; i < n_pessoas; i++) {

        pessoas[i] = CriaPessoa();
        LePessoa(&pessoas[i]);
    }

    scanf(" %d", &n_associacoes);


    for (i = 0; i < n_associacoes; i++) {

        AssociaFamiliasGruposPessoas(pessoas);

    }

    for (i = 0; i < n_associacoes; i++) {

        ImprimePessoa(&pessoas[i]);

    }

    return 0;
}