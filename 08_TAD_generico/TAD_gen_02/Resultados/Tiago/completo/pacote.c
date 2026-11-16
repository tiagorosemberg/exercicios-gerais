#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"

struct pacote {

    Type type;
    void *elementos;
    int numElem;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote* CriaPacote(Type type, int numElem) {

    tPacote *p = calloc(1, sizeof(tPacote));

    p->numElem = numElem;
    p->type = type;

    if (p->type == INT) {

        p->elementos = calloc(p->numElem, sizeof(int));

    } else if (p->type == CHAR){

        p->elementos = calloc(p->numElem + 1, sizeof(char));
    }

    return p;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote* pac) {

    free(pac->elementos);
    free(pac);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote* pac) {

    int i;

    if (pac->type == INT) {

        for (i = 0; i < pac->numElem; i++) {
            
            scanf(" %d", &((int*)pac->elementos)[i]);
        }
    
    } else if (pac->type == CHAR) {
        
        scanf("%[^\n]\n", (char*)pac->elementos);
    }

}

/**
 * @brief Imprime na tela um pacote que possui um id específico com seu valor calculado
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote* pac) {

    int i;

    if (pac->type == INT) {

        for (i = 0; i < pac->numElem; i++) {

            if (i == pac->numElem - 1) {

                printf("%d\n", ((int*)pac->elementos)[i]);
            
            } else {
                printf("%d ", ((int*)pac->elementos)[i]);
            }
        }
    
    } else if (pac->type == CHAR) {

        printf("%s\n", (char*)pac->elementos);
    }

}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote* pac) {

    int i, soma = 0;

    if (pac->type == INT) {

        for (i = 0; i < pac->numElem; i++) {
            
            soma += ((int*)pac->elementos)[i];
        }
    
    } else if (pac->type == CHAR) {
        
        for (i = 0; i < pac->numElem; i++) {
            
            soma += ((char*)pac->elementos)[i];
        }
    }
}