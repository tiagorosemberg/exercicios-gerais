#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include "lesao.h"
#include "paciente.h"

/*
Função que cria um paciente a partir dos parâmetros fornecidos.
@param nome: Nome do paciente.
@param cartaoSus: Cartão SUS do paciente.
@param genero: Gênero do paciente.
@param dataNasc: Data de nascimento do paciente.
@return Ponteiro para o paciente criado.
*/
Paciente *criaPaciente(char *nome, char *cartaoSus, char genero, Data *dataNasc) {

    Paciente *paciente = calloc(1, sizeof(Paciente));

    if (paciente == NULL) {
        printf("nao alocou paciente");
        exit(1);
    }

    strcpy(paciente->nome, nome);
    strcpy(paciente->cartaoSus, cartaoSus);
    paciente->genero = genero;
    paciente->dataNasc = dataNasc;
    paciente->numLesoes = 0;

    return paciente;
}

/*
Função que lê os dados de um paciente a partir da entrada padrão. Consulte o enunciado e/ou os casos de teste para o formato esperado.
@return Ponteiro para o paciente lido.
*/
Paciente *lerPaciente() {

    char nome[MAX_NOME_PAC], cartao[MAX_CARTAO_SUS], genero;
    Data *data;
    Paciente *paciente;

    scanf("%[^\n]\n", nome);
    data = lerData();
    scanf("%[^\n]\n", cartao);
    scanf("%c", &genero);

    paciente = criaPaciente(nome, cartao, genero, data);

    return paciente;
}

/*
Função que vincula uma lesão a um paciente.
Basicamente, a lesão é adicionada à lista de lesões do paciente se houver espaço disponível.
O vínculo é realizado de acordo com o cartão do SUS.
@param p: Ponteiro para o paciente ao qual a lesão será vinculada.
@param l: Ponteiro para a lesão a ser vinculada ao paciente.
*/
void vinculaLesaoPaciente(Paciente *p, Lesao *l) {

    p->lesoes[p->numLesoes] = l;
    p->numLesoes++;
}

/*
Função que calcula a idade do paciente em anos completos com base em uma data de referência.
@param p: O paciente cuja idade será calculada.
@param dataBase: A data de referência para o cálculo da idade.
@return A idade do paciente em anos completos.
*/
int calculaIdadePaciente(Paciente *p, Data *dataBase) {

    return diferencaAnoData(p->dataNasc, dataBase);

}

/*
Função que obtém o cartão SUS de um paciente.
@param p: Ponteiro para o paciente do qual se deseja obter o cartão SUS.
@return Ponteiro para cartão SUS do paciente.
*/
char *getCartaoSusPaciente(Paciente *p) {
    return p->cartaoSus;
}

/*
Função que obtém o número de lesões associadas a um paciente.
@param p: Ponteiro para o paciente cuja quantidade de lesões será obtida.
@return O número de lesões do paciente.
*/
int getNumLesoesPaciente(Paciente *p) {
    return p->numLesoes;
}

/*
Função que calcula a quantidade de lesões cirúrgicas (malignas) associadas a um paciente.
@param p: Ponteiro para o paciente cuja quantidade de lesões cirúrgicas será calculada.
@return A quantidade de lesões cirúrgicas do paciente.
*/
int qtdLesoesCirurgicasPaciente(Paciente *p) {

    int i, qtd = 0;

    for (i = 0; i < p->numLesoes; i++) {

        if (verificaCirurgicaLesao(p->lesoes[i])) {
            qtd++;
        }
    }

    return qtd;
}

/*
Função que imprime o nome do paciente e o ID das lesões associadas a ele (exatamente como solicitado no enunciado e nos casos de teste).
@param p: Ponteiro para o paciente cujas informações serão impressas.
*/
void imprimePaciente(Paciente *p) {

    int i;

    if (p->numLesoes > 0) {

        printf("- %s - ", p->nome);

        for (i = 0; i < p->numLesoes; i++) {

            imprimeIdLesao(p->lesoes[i]);
        }

        printf("\n");
    }
}

/*
Função que libera a memória alocada para um paciente.
@param p: Ponteiro para o paciente a ser liberado.
*/
void liberaPaciente(Paciente *p) {

    int i;

    for (i = 0; i < p->numLesoes; i++) {
        free(p->lesoes[i]);
    }

    free(p->dataNasc);
    free(p);    
}