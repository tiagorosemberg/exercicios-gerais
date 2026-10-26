#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"
#include "filme.h"

#define MAX_FILMES 100

struct Locadora {

    tFilme *filmes[MAX_FILMES];
    int numFilmes;
    int lucro;

};

/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 * 
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora* CriarLocadora () {

    int i;
    tLocadora *locadora = (tLocadora*) calloc(1, sizeof(tLocadora));

    for (i = 0; i < MAX_FILMES; i++) {
        locadora->filmes[i] = NULL;
    }

    locadora->numFilmes = 0;
    locadora->lucro = 0;

    return locadora;
}

/**
 * @brief Destrói uma instância de tLocadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora (tLocadora* locadora) {

    int i;

    for (i = 0; i < locadora->numFilmes; i++) {

        DestruirFilme(locadora->filmes[i]);
    }

    free(locadora);

}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser verificada.
 * @param codigo Código do filme a ser verificado.
 * @return int 1 se o filme está cadastrado, 0 caso contrário.
 */
int VerificarFilmeCadastrado (tLocadora* locadora, int codigo) {

    int i;

    for (i = 0; i < locadora->numFilmes; i++) {

        if (EhMesmoCodigoFilme(locadora->filmes[i], codigo)) {

            return 1;
        }
    }

    return 0;
}

/**
 * @brief Cadastra um novo filme na locadora caso ele não esteja cadastrado.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param filme Ponteiro para o filme a ser cadastrado.
 */
void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme) {

    if (!VerificarFilmeCadastrado(locadora, ObterCodigoFilme(filme))) {

        locadora->filmes[locadora->numFilmes] = filme;
        locadora->numFilmes++;

    } else {
        printf("Filme ja cadastrado!\n");
    }
}

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora.
 * 
 * @param Locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerCadastroLocadora (tLocadora* Locadora) {

    int codigo;
    tFilme *filme = CriarFilme();

    scanf("%d,", &codigo);

    LeFilme(filme, codigo);

    CadastrarFilmeLocadora(Locadora, filme);
}

/**
 * @brief Aluga um ou mais filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Número de códigos de filmes a serem alugados.
 */
void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos) {

    int i, j;

    for (i = 0; i < quantidadeCodigos; i++) {

        for (j = 0; j < locadora->numFilmes; j++) {

            if (EhMesmoCodigoFilme(locadora->filmes[j], codigos[i])) {

                if(ObterQtdEstoqueFilme(locadora->filmes[j]) > 0) {

                    AlugarFilme(locadora->filmes[j]);

                } else {

                    printf("Nao da pra alugar\n");
                }

            }
        }
    }
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora (tLocadora* locadora) {

    int codigos[MAX_FILMES], codigo, i = 0;

    while(scanf(" %d", &codigo) == 1) {

        codigos[i] = codigo;
        i++;
    }
    
    scanf("%*c");

    AlugarFilmesLocadora(locadora, codigos, i);
}

/**
 * @brief Devolve um ou mais filmes alugados da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Número de códigos de filmes a serem devolvidos.
 */
void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos) {
    
    int i, j;

    for (i = 0; i < quantidadeCodigos; i++) {

        for (j = 0; j < locadora->numFilmes; j++) {

            if (EhMesmoCodigoFilme(locadora->filmes[j], codigos[i])) {

                DevolverFilme(locadora->filmes[j]);
                locadora->lucro += ObterValorFilme(locadora->filmes[i]);

            }
        }
    }
}

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora (tLocadora* locadora) {

    int codigos[MAX_FILMES], codigo, i = 0;

    while(scanf(" %d", &codigo) == 1) {

        codigos[i] = codigo;
        i++;
    }
    
    scanf("%*c");

    DevolverFilmesLocadora(locadora, codigos, i);
}

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora (tLocadora* locadora) {

    int i, j;
    tFilme *aux = CriarFilme();

    for (i = 0; i < locadora->numFilmes - 1; i++) {

        for (j = 0; j < locadora->numFilmes - i - 1; j++) {
            
            if (CompararNomesFilmes(locadora->filmes[j], locadora->filmes[j+1]) > 0) {
                // Realiza o swap (troca) copiando os caracteres
                aux = locadora->filmes[j];
                locadora->filmes[j] = locadora->filmes[j+1];
                locadora->filmes[j+1] = aux;
            }
        }
    }

    DestruirFilme(aux);
}

/**
 * @brief Consulta o estoque de filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarEstoqueLocadora (tLocadora* locadora) {

    int i;

    printf("~ESTOQUE~\n");

    for (i = 0; i < locadora->numFilmes; i++) {

        printf("%d - ", ObterCodigoFilme(locadora->filmes[i]));
        ImprimirNomeFilme(locadora->filmes[i]);
        printf(" - Fitas em estoque: %d\n", ObterQtdEstoqueFilme(locadora->filmes[i]));
    }
}

/**
 * @brief Consulta o lucro da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora (tLocadora* locadora) {

    if (locadora->lucro > 0) {

        printf("Lucro total R$%d\n", locadora->lucro);
    }
}