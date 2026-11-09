#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "receita.h"
#include "encaminhamento.h"
#include "exame.h"
#include "documento.h"
#include "fila_imp.h"

int main() {

    char opcao[100];
    FilaImp *f = criaFilaImp();

    float preco;

    scanf(" %f\n", &preco);

    while(1) {

        scanf("%s\n", &opcao);

        if (strcmp(opcao, "FIM") == 0) {
            break;
        
        } else if (strcmp(opcao, "RECEITA") == 0) {

            Receita *r = leReceita();

            insereDocumentoFilaImp(f, r, imprimeReceita, desalocaReceita, calculaPrecoImpressaoReceita);

        } else if (strcmp(opcao, "ENCAMINHAMENTO") == 0) {

            Encaminhamento *enc = leEncaminhamento();

            insereDocumentoFilaImp(f, enc, imprimeEncaminhamento, desalocaEncaminhamento, calculaPrecoImpressaoEncaminhamento);

        } else if (strcmp(opcao, "EXAME") == 0) {

            Exame *ex = leExame();

            insereDocumentoFilaImp(f, ex, imprimeExame, desalocaExame, calculaPrecoImpressaoExame);
            
        } else if (strcmp(opcao, "QUANTIDADE") == 0) {

            printf("- QUANTIDADE DE DOCUMENTOS NA FILA: %d\n", quantidadeDocumentosNaFilaImp(f));
            
        } else if (strcmp(opcao, "PRECO") == 0) {

            printf("- PRECO TOTAL DA FILA: R$ %.2f\n", precoTotalImpressaoFilaImp(f, preco));
            
        } else if (strcmp(opcao, "IMPRIME") == 0) {

            imprimeFilaImp(f);
        }
    }

    desalocaFilaImp(f);

    return 0;
}