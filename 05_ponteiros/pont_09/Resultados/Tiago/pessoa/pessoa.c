#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pessoa.h"

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai e mae com NULL.
 * 
 * @return Uma nova pessoa e sem pais.
 */
tPessoa CriaPessoa() {

    tPessoa pessoa;

    *pessoa.nome = '\0';
    pessoa.mae = NULL;
    pessoa.pai = NULL;

    return pessoa;

}

/**
 * @brief Lê os dados de uma pessoa.
 * 
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa) {

    scanf(" %[ˆ\n]\n", pessoa->nome);

}

/**
 * @brief Verifica se uma pessoa tem pai e/ou mae associado(s).
 * Ou seja, verifica pelo menos um dos ponteiros pai e mae é diferente de NULL.
 * 
 * @param pessoa Ponteiro para a pessoa a ser verificada.
 * 
 * @return 1 se a pessoa tiver pai e/ou mae associado(s) e 0 caso contrário.
*/
int VerificaSeTemPaisPessoa(tPessoa *pessoa) {

    if (pessoa->pai != NULL || pessoa->mae != NULL) {
        return 1;
    }

    return 0;
}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * Dica: use a função VerificaSeTemPaisPessoa para verificar se a pessoa tem pai e/ou mae associado(s).
 * Alem disso, imprimir o nome do irmao caso exista.
 * 
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa) {

    if (VerificaSeTemPaisPessoa(pessoa)) {

        printf("NOME COMPLETO: %s\n", pessoa->nome);
        
        if (pessoa->pai == NULL) {
            printf("PAI: NAO INFORMADO\n");
        
        } else {
            printf("PAI: %s\n", pessoa->pai->nome);
        }

        if (pessoa->mae == NULL) {
            printf("MAE: NAO INFORMADO\n");
        
        } else {
            printf("MAE: %s\n", pessoa->mae->nome);
        }
    }
}

/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 * 
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 */
void AssociaFamiliasGruposPessoas(tPessoa *pessoas) {

    int idx_filho, idx_mae, idx_pai;

    scanf(" mae: %d, pai: %d, filho: %d\n", &idx_mae, &idx_pai, &idx_filho);

    if (idx_pai != -1) {
        pessoas[idx_filho].pai = &pessoas[idx_pai];
    }
    
    if (idx_mae != -1) {
        pessoas[idx_filho].mae = &pessoas[idx_mae];
    }
}