#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "relatorio.h"
#include "vector.h"

int main() {

    int n, i;

    Vector *v = VectorConstruct();

    scanf("%d", &n);

    for (i = 0; i < n; i++) {

        tAluno *a = CriaAluno();
        LeAluno(a);
        VectorPushBack(v, a);
    }

    ImprimeRelatorio(v);

    VectorDestroy(v, DestroiAluno);

    return 0;
}