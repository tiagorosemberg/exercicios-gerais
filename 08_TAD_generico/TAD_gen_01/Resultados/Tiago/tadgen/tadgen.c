#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

struct generic {

    Type type;
    void *elementos;
    int numElem;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem) {

    tGeneric *g = calloc(1, sizeof(tGeneric));

    g->type = type;
    g->numElem = numElem;

    if (type == INT) {

        g->elementos = calloc(numElem, sizeof(int));
    
    } else if (type == FLOAT) {

        g->elementos = calloc(numElem, sizeof(float));
    }

    return g;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen) {

    free(gen->elementos);

    free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen) {

    printf("\nDigite o vetor:\n");

    if (gen->type == INT) {

        for(int i = 0; i < gen->numElem; i++) {

            scanf("%d", &((int*)gen->elementos)[i]);
        }
    
    } else if (gen->type == FLOAT) {

        for(int i = 0; i < gen->numElem; i++) {

            scanf("%f", &((float*)gen->elementos)[i]);
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen) {

    if (gen->type == INT) {

        for(int i = 0; i < gen->numElem; i++) {

            if(i == gen->numElem - 1) {
        
                printf("%d\n", ((int*)gen->elementos)[i]);
            
            } else {
                
                printf("%d ", ((int*)gen->elementos)[i]);
            }
        }
    } else if (gen->type == FLOAT) {

        for(int i = 0; i < gen->numElem; i++) {
            
            if(i == gen->numElem - 1) {
        
                printf("%.2f\n", ((float*)gen->elementos)[i]);
            
            } else {
                
                printf("%.2f ", ((float*)gen->elementos)[i]);
            }
        }
    }
}