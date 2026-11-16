#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "encaminhamento.h"
/*
    Estrutura do tipo Receita contendo os atributos necessários para a manipulação
*/
struct _Encaminhamento {

    char nomeMedico[100];
    char nomePaciente[100];
    char especialidade[50];
    char motivo[200];

};

/*
    Função que cria uma receita e retorna o seu endereço de memória
    @param nomeMedicamento: nome do medicamento prescrito na receita
    @param nomePaciente: nome do paciente para quem a receita foi prescrita
    @param nomeMedico: nome do médico que prescreveu a receita
    @param instrucoes: instruções para o uso do medicamento
    @return: endereço de memória da receita criada
*/
Encaminhamento *criaEncaminhamento(char *nomeMedico, char *nomePaciente, char *especialidade, char *motivo) {

    Encaminhamento *e = calloc(1, sizeof(Encaminhamento));

    strcpy(e->nomeMedico, nomeMedico);
    strcpy(e->nomePaciente, nomePaciente);
    strcpy(e->especialidade, especialidade);
    strcpy(e->motivo, motivo);

    return e;
}

/*
    Função que lê os dados de uma receita a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da receita lida
*/
Encaminhamento *leEncaminhamento() {

    char medico[100], paciente[100], especialiadde[50], motivo[200];

    scanf("%[^\n]\n", medico);
    scanf("%[^\n]\n", paciente);
    scanf("%[^\n]\n", especialiadde);
    scanf("%[^\n]\n", motivo);

    Encaminhamento *e = criaEncaminhamento(medico, paciente, especialiadde, motivo);

    return e;
}

/*
    Função que calcula o preço de impressão de uma receita de acordo com a especificação
    @param dado: ponteiro genérico para a receita a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da receita
*/
float calculaPrecoImpressaoEncaminhamento(void *dado, float precoCaractere) {

    Encaminhamento *e = (Encaminhamento*)dado;

    float soma = 0;

    soma += strlen(e->nomeMedico);
    soma += strlen(e->nomePaciente);
    soma += strlen(e->especialidade);
    soma += strlen(e->motivo);

    soma *= precoCaractere;

    return soma;
}

/*
    Função que imprime uma receita de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a receita a ser impressa
*/
void imprimeEncaminhamento(void *dado) {

    Encaminhamento *e = (Encaminhamento*)dado;

    printf("- - ENCAMINHAMENTO - -\n");
    printf("PACIENTE: %s\n", e->nomePaciente);
    printf("ESPECIALIDADE: %s\n", e->especialidade);
    printf("MOTIVO: %s\n", e->motivo);
    printf("MEDICO: %s\n", e->nomeMedico);
    printf("- - - - - - - - - - - -\n");

}

/*
    Função que desaloca uma receita
    @param dado: ponteiro genérico para a receita a ser desalocada
*/
void desalocaEncaminhamento(void *dado) {
    Encaminhamento *e = (Encaminhamento*)dado;

    free(e);
}