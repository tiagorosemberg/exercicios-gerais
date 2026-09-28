#include <stdio.h>
#include "pessoa.h"

int main () {

    int n_pessoas;
    int i;

    scanf("%d", &n_pessoas);

    tPessoa pessoas[n_pessoas];

    for (i = 0; i < n_pessoas; i++) {

        pessoas[i] = CriaPessoa();
        LePessoa(&pessoas[i]);
    }

    AssociaFamiliasGruposPessoas(pessoas, n_pessoas);

    for (i = 0; i < n_pessoas; i++) {

        ImprimePessoa(&pessoas[i]);

    }

    return 0;
}