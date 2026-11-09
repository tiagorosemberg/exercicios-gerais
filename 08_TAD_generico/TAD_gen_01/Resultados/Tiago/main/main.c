#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

int main() {

    int tipo, n;

    printf("tad_gen_01\n");    
    printf("Digite o tipo e numero de elementos:");

    scanf("%d %d", &tipo, &n);

    tGeneric *g = CriaGenerico(tipo, n);

    LeGenerico(g);

    ImprimeGenerico(g);

    DestroiGenerico(g);

    return 0;
}