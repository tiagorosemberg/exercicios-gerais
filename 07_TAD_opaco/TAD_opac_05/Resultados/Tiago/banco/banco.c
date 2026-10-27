#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banco.h"
#include "conta.h"
#include "usuario.h"

struct Banco {

    tConta **contas;
    int contas_abertas;
    int contas_disponiveis;

};

/**
 * @brief Cria um novo banco, com 5 contas alocadas e nenhuma conta aberta.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo banco criado.
 */
tBanco *CriaBanco() {

    tBanco *banco = calloc(1, sizeof(tBanco));

    banco->contas = calloc(5, sizeof(tConta*));

    banco->contas_abertas = 0;
    banco->contas_disponiveis = 5;

    return banco;
}

/**
 * @brief Desaloca a memória de um banco e de todas as suas contas.
 * 
 * @param banco Ponteiro para o banco a ser destruído.
 */
void DestroiBanco(tBanco *banco) {

    int i;

    for (i = 0; i < banco->contas_abertas; i++) {
        DestroiConta(banco->contas[i]);
    }

    free(banco->contas);

    free(banco);
}

/**
 * @brief Abre uma nova conta no banco e a adiciona ao vetor de contas.
 * 
 * @param banco Ponteiro para o banco onde a conta será aberta.
 */
void AbreContaBanco(tBanco *banco) {

    tConta *conta = CriaConta();

    LeConta(conta);

    if (banco->contas_abertas == banco->contas_disponiveis) {

        banco->contas = realloc(banco->contas, (banco->contas_disponiveis + 1) * sizeof(tConta*));

        banco->contas[banco->contas_disponiveis] = conta;

        banco->contas_abertas++;
        banco->contas_disponiveis++;
    
    } else {

        banco->contas[banco->contas_abertas] = conta;

        banco->contas_abertas++;

    }

}

/**
 * @brief Realiza um saque em uma conta do banco se ela existir e tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta e o valor do saque.
 * 
 * @param banco Ponteiro para o banco onde a conta será sacada.
 */
void SaqueContaBanco(tBanco *banco) {

    int codigo, i, achou = 0;
    float valor;

    scanf(" %d %f\n", &codigo, &valor);

    for (i = 0; i < banco->contas_abertas; i++) {

        if (VerificaConta(banco->contas[i], codigo)) {

            achou = 1;

            SaqueConta(banco->contas[i], valor);
        }
    }

    if (achou == 0) {
        printf("CONTA NAO ENCONTRADA para saque\n");
    }

}

/**
 * @brief Realiza um depósito em uma conta do banco se ela existir.
 * Nessa função é necessário ler o número da conta e o valor do depósito. 
 * 
 * @param banco Ponteiro para o banco onde a conta será depositada.
 */
void DepositoContaBanco(tBanco *banco) {
    
    int codigo, i, achou = 0;
    float valor;

    scanf(" %d %f\n", &codigo, &valor);

    for (i = 0; i < banco->contas_abertas; i++) {

        if (VerificaConta(banco->contas[i], codigo)) {

            achou = 1;

            DepositoConta(banco->contas[i], valor);
        }
    }

    if (!achou) {
        printf("CONTA NAO ENCONTRADA para deposito\n");
    }


}

/**
 * @brief Realiza uma transferência entre duas contas do banco se elas existirem e a conta de origem tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta de origem, o número da conta de destino e o valor da transferência.
 * 
 * @param banco Ponteiro para o banco onde as contas estão.
 */
void TransferenciaContaBanco(tBanco *banco) {

    int c1, c2, i, achou1 = 0, achou2 = 0;
    float valor;
    tConta *origem, *destino;

    scanf(" %d %d %f\n", &c1, &c2, &valor);

    for (i = 0; i < banco->contas_abertas; i++) {

        if (VerificaConta(banco->contas[i], c1)) {

            achou1 = 1;
            origem = banco->contas[i];
        }
    }
    
    for (i = 0; i < banco->contas_abertas; i++) {

        if (VerificaConta(banco->contas[i], c2)) {

            achou2 = 1;
            destino = banco->contas[i];
        }
    }

    if (achou1 && achou2) {
        
        TransferenciaConta(origem, destino, valor);

    
    } else {
        printf("NAO ACHOU UMA DAS CONTAS\n");
    }
}

/**
 * @brief Imprime o relatório do banco, com todas as contas e seus respectivos dados.
 * 
 * @param banco Ponteiro para o banco a ser impresso.
 */
void ImprimeRelatorioBanco(tBanco *banco) {

    int i;

    printf("===| Imprimindo Relatorio |===\n");

    for (i = 0; i < banco->contas_abertas; i++) {
        ImprimeConta(banco->contas[i]);
    }
}