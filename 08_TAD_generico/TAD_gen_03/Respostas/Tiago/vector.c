#include <stdio.h>
#include <stdio.h>
#include <string.h>

#include "vector.h"

typedef void *data_type; // void pointer
struct Vector {

    data_type *data;
    int numElem;

};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct() {

    Vector *v = (Vector*)calloc(1, sizeof(Vector));

    v->numElem = 0;

    v->data = NULL;

    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, data_type val) {

    v->data = realloc(v->data, (v->numElem+1) * sizeof(data_type));

    v->data[v->numElem] = val;

    v->numElem++;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return data_type Elemento do vetor
*/
data_type VectorGet(Vector *v, int i)  {

    return v->data[i];

}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v) {
    return v->numElem;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(data_type)) {

    int i;

    for (i = 0; i < v->numElem; i++) {

        destroy(v->data[i]);
    }

    free(v->data);
    free(v);
}