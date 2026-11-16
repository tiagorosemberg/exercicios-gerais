#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "banco.h"
#include "agencia.h"
#include "vector.h"

/**
 * @brief Estrutura para representar um banco.
 */
struct Banco {

    Vector *agencias;
    int numAgencias;
    char nome[50];

};

/**
 * @brief Função para criar um novo banco.
 * @return Um ponteiro para o novo banco criado. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tBanco *CriaBanco() {

    tBanco *b = calloc(1, sizeof(tBanco));

    b->agencias = VectorConstruct();

    b->numAgencias = 0;

    return b;
}

/**
 * @brief Função para destruir um banco.
 * @param banco O banco a ser destruído.
 */
void DestroiBanco(tBanco *banco) {

    VectorDestroy(banco->agencias, DestroiAgencia);

    free(banco);
}

/**
 * @brief Função para ler o nome de um banco.
 * @param banco O banco a ser lido.
 */
void LeBanco(tBanco *banco) {

    scanf("%[^\n]\n", banco->nome);
}

/**
 * @brief Função para adicionar uma agência a um banco.
 * @param banco O banco.
 * @param agencia A agência a ser adicionada.
 */
void AdicionaAgencia(tBanco *banco, tAgencia *agencia) {

    VectorPushBack(banco->agencias, agencia);
    banco->numAgencias++;
}

/**
 * @brief Função para inserir uma conta em uma agência pertencente ao banco.
 * @param banco O banco.
 * @param numAgencia O número da agência.
 * @param cliente A conta a ser inserida.
 * @pre A agência deve pertencer ao banco.
*/
void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente) {

    int n, i;

    for (i = 0; i < banco->numAgencias; i++) {

        if (ComparaAgencia(numAgencia, VectorGet(banco->agencias, i))) {

            n = i;
        }

    }

    AdicionaConta(VectorGet(banco->agencias, n), cliente);

}

/**
 * @brief Função para imprimir o relatório de um banco, com o nome do banco e a lista de agências.
 * @param banco O banco.
 */
void ImprimeRelatorioBanco(tBanco *banco) {

    int i;

    printf("%s\n", banco->nome);
    printf("Lista de agencias:\n");

    for (i = 0; i < banco->numAgencias; i++) {

        ImprimeDadosAgencia(VectorGet(banco->agencias, i));
        printf("\n");
    }
}