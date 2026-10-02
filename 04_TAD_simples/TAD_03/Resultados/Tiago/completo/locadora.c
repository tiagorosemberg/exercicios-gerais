#include <stdio.h>
#include <string.h>
#include "locadora.h"
#include "filme.h"

/**
 * @brief Cria uma nova locadora.
 * @return Locadora criada.
 */
tLocadora criarLocadora () {

    tLocadora locadora;

    locadora.lucro = 0;
    locadora.numFilmes = 0;

    return locadora;
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * @param locadora Locadora a ser consultada.
 * @param codigo Código do filme a ser verificado.
 * @return 1 se o filme está cadastrado, 0 caso contrário.
 */
int verificarFilmeCadastrado (tLocadora locadora, int codigo) {

    int i;

    for (i = 0; i < locadora.numFilmes; i++) {
        if(locadora.filme[i].codigo == codigo) {
            return 1;
        }
    }

    return 0;
}

/**
 * @brief Cadastra um filme na locadora, desde que ele não esteja cadastrado.
 * @param locadora Locadora a ser atualizada.
 * @param filme Filme a ser cadastrado.
 * @return Locadora atualizada.
*/
tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme) {

    locadora.filme[locadora.numFilmes] = filme;
    locadora.numFilmes++;

    printf("Filme cadastrado %d - %s\n", filme.codigo, filme.nome);

    return locadora;
}

/**
 * @brief Lê o cadastro de um ou mais filmes a partir da entrada padrão e o cadastra na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerCadastroLocadora (tLocadora locadora) {

    tFilme filme;
    int codigo;
    char c;

    while (scanf(" %d,", &codigo) == 1) {
        filme = leFilme(codigo);
        locadora = cadastrarFilmeLocadora(locadora, filme);
    }

    scanf(" %c", &c);

    return locadora;
}

/**
 * @brief Aluga um conjunto de filmes da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos) {

    int i, j;

    for (i = 0; i < quantidadeCodigos; i++) {
        for (j = 0; j < locadora.numFilmes; j++) {
            if (codigos[i] == locadora.filme[j].codigo) {
                locadora.filme[j] = alugarFilme(locadora.filme[j]);
            }
        }
    }

    return locadora;
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerAluguelLocadora (tLocadora locadora) {

    int i = 0, j = 0, k = 0, codigos[MAX_FILMES], custo = 0, nao_cadastrados = 0, alugados = 0;
    char c;


    while (scanf("%d", &codigos[i]) == 1) {
        i++;
    }

    scanf(" %c", &c);

    locadora = alugarFilmesLocadora(locadora, codigos, i);

    for (j = 0; j < i; j++) {

        if (!verificarFilmeCadastrado(locadora, codigos[j])) {
            printf("Filme %d nao cadastrado.\n", codigos[j]);
            nao_cadastrados++;
            continue;
        }

        for(k = 0; k < locadora.numFilmes; k++) {
            if (codigos[j] == locadora.filme[k].codigo) {
                
                if(locadora.filme[k].qtdEstoque <= 0) {
                    printf("Filme %d - %s nao disponivel no estoque. Volte mais tarde.\n", locadora.filme[k].codigo, locadora.filme[k].nome);
                    continue;
                }

                custo += locadora.filme[k].valor;
                alugados++;
            }
        }
    }

    if (alugados > 0) {
        printf("Total de filmes alugados: %d com custo de R$%d\n", i - nao_cadastrados, custo);
    }
    return locadora;
}

/**
 * @brief Devolve um conjunto de filmes alugados da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int quantidadeCodigos) {
    int i, j;

    for (i = 0; i < quantidadeCodigos; i++) {
        for (j = 0; j < locadora.numFilmes; j++) {
            if (codigos[i] == locadora.filme[j].codigo) {
                locadora.filme[j] = devolverFilme(locadora.filme[j]);
                locadora.lucro += locadora.filme[j].valor;

                printf("Filme %d - %s Devolvido!\n", codigos[i], locadora.filme[j].nome);
            }
        }
    }

    return locadora;
}

/**
 * @brief Lê a devolução de um conjunto de filmes a partir da entrada padrão e os devolve na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerDevolucaoLocadora (tLocadora locadora) {
    int i = 0, codigos[MAX_FILMES];
    char c;


    while (scanf("%d", &codigos[i]) == 1) {
        i++;
    }

    locadora = devolverFilmesLocadora(locadora, codigos, i);

    return locadora;
}

/**
 * @brief Ordena os filmes da locadora por nome.
 * @param locadora Locadora a ser ordenada.
 * @return Locadora ordenada.
 */
tLocadora ordenarFilmesLocadora (tLocadora locadora) {
    
    tFilme aux;
    int i, j;

    for (i = 0; i < locadora.numFilmes; i++) {
        for (j = i + 1; j < locadora.numFilmes; j++) {
            if(strcmp(locadora.filme[i].nome, locadora.filme[j].nome) > 0) {
                aux = locadora.filme[i];
                locadora.filme[i] = locadora.filme[j];
                locadora.filme[j] = aux;
            }
        }
    }
    
    return locadora;
}

/**
 * @brief Imprime o estoque da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarEstoqueLocadora (tLocadora locadora) {
    
    int i;
    
    printf("~ESTOQUE~\n");
    
    for (i = 0; i < locadora.numFilmes; i++) {
        printf("%d - %s Fitas em estoque: %d\n", locadora.filme[i].codigo, locadora.filme[i].nome, locadora.filme[i].qtdEstoque);
    }
}

/**
 * @brief Imprime o lucro da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarLucroLocadora (tLocadora locadora) {
    if (locadora.lucro > 0) {
        printf("\n");
        printf("Lucro total R$%d\n", locadora.lucro);
    }
}