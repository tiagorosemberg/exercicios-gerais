#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exame.h"

/*
    Estrutura do tipo Exame contendo os atributos necessários para a manipulação
*/
typedef struct _Exame {

    char nomeMedico[100];
    char nomePaciente[100];
    char solicitacao[100];
};

/*
    Função que cria uma Exame e retorna o seu endereço de memória
    @param nomeMedicamento: nome do medicamento prescrito na Exame
    @param nomePaciente: nome do paciente para quem a Exame foi prescrita
    @param nomeMedico: nome do médico que prescreveu a Exame
    @param instrucoes: instruções para o uso do medicamento
    @return: endereço de memória da Exame criada
*/
Exame *criaExame(char *nomeMedico, char *nomePaciente, char *solicitacao) {

    Exame *e = calloc(1, sizeof(Exame));

    strcpy(e->nomeMedico, nomeMedico);
    strcpy(e->nomePaciente, nomePaciente);
    strcpy(e->solicitacao, solicitacao);

    return e;
}

/*
    Função que lê os dados de uma Exame a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da Exame lida
*/
Exame *leExame() {

    char medico[100], paciente[100], solicitacao[100];

    scanf("%[^\n]\n", medico);
    scanf("%[^\n]\n", paciente);
    scanf("%[^\n]\n", solicitacao);

    Exame *e = criaExame(medico, paciente, solicitacao);

    return e;
}

/*
    Função que calcula o preço de impressão de uma Exame de acordo com a especificação
    @param dado: ponteiro genérico para a Exame a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da Exame
*/
float calculaPrecoImpressaoExame(void *dado, float precoCaractere) {

    Exame *e = (Exame*)dado;

    float soma = 0;

    soma += strlen(e->nomeMedico);
    soma += strlen(e->nomePaciente);
    soma += strlen(e->solicitacao);

    soma *= precoCaractere;

    return soma;
}

/*
    Função que imprime uma Exame de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a Exame a ser impressa
*/
void imprimeExame(void *dado) {

    Exame *e = (Exame*)dado;

    printf("- - EXAME - -\n");
    printf("PACIENTE: %s\n", e->nomePaciente);
    printf("SOLICITACAO: %s\n", e->solicitacao);
    printf("MEDICO: %s\n", e->nomeMedico);
    printf("- - - - - - -\n");
}

/*
    Função que desaloca uma Exame
    @param dado: ponteiro genérico para a Exame a ser desalocada
*/
void desalocaExame(void *dado) {

    Exame *e = (Exame*)dado;

    free(e);
}