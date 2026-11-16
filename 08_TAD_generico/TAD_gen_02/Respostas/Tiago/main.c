#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gerenciadorpacotes.h"
#include "pacote.h"

int main() {

    int op, tipo, numElem, idx;

    
    tGerenciador *g = CriaGerenciador();

    while(1) {

        if (op == 1) {

            scanf(" %d %d", &tipo, &numElem);

            tPacote *p = CriaPacote(tipo, numElem);

            AdicionaPacoteNoGerenciador(g, p);

        } else if (op == 2) {

           scanf(" %d", &idx);
           
           ImprimirPacoteNoIndice(g, idx);

        } else if (op == 3) {

            ImprimirTodosPacotes(g);
            break;
        }
    }

    return 0;
}