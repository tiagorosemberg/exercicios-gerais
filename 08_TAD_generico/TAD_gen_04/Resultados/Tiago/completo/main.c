#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"
#include "agencia.h"
#include "conta.h"
#include "vector.h"

int main() {

    char op;

    int numAgencia;

    tBanco *b = CriaBanco();

    LeBanco(b);

    while(1) {

        scanf("%c\n", &op);

        if (op == 'A') {

            tAgencia *a = CriaAgencia();

            LeAgencia(a);

            AdicionaAgencia(b, a);
        
        } else if(op == 'C') {

            tConta *c = CriaConta();

            LeConta(c);

            scanf("%d\n", &numAgencia);

            InsereContaBanco(b, numAgencia, c);
        
        } else if (op == 'F') {
            break;
        }
    }

    ImprimeRelatorioBanco(b);

    DestroiBanco(b);

    return 0;
}