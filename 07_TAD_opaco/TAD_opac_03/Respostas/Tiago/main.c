#include <stdio.h>
#include <string.h>
#include "locadora.h"

int main() {

    tLocadora *locadora = CriarLocadora();
    char comando[MAX_CARACTERES];

    while (scanf(" %s", comando) == 1) {
        if (strcmp(comando, "Cadastrar") == 0) {
            LerCadastroLocadora(locadora);
        } 
        else if (strcmp(comando, "Alugar") == 0) {
            LerAluguelLocadora(locadora);
        } 
        else if (strcmp(comando, "Devolver") == 0) {
            LerDevolucaoLocadora(locadora);
        } 
        else if (strcmp(comando, "Estoque") == 0) {
            OrdenarFilmesLocadora(locadora);
            ConsultarEstoqueLocadora(locadora);
        }
    }

    ConsultarLucroLocadora(locadora);
    DestruirLocadora(locadora);

    return 0;
}
