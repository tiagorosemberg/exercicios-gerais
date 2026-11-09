#include <stdio.h>
#include <string.h>
#include "receita.h"



/*
    Estrutura do tipo Receita contendo os atributos necessários para a manipulação
*/
struct _Receita {

    char nomeMedico[100];
    char nomePaciente[100];
    char nomeMedicamento[100];
    char instrucoes[200];

};

/*
    Função que cria uma receita e retorna o seu endereço de memória
    @param nomeMedicamento: nome do medicamento prescrito na receita
    @param nomePaciente: nome do paciente para quem a receita foi prescrita
    @param nomeMedico: nome do médico que prescreveu a receita
    @param instrucoes: instruções para o uso do medicamento
    @return: endereço de memória da receita criada
*/
Receita *criaReceita(char *nomeMedicamento, char *nomePaciente, char *nomeMedico, char *instrucoes) {

    Receita *r = calloc(1, sizeof(Receita));

    strcpy(r->nomeMedico, nomeMedico);
    strcpy(r->nomePaciente, nomePaciente);
    strcpy(r->nomeMedicamento, nomeMedicamento);
    strcpy(r->instrucoes, instrucoes);

    return r;
}

/*
    Função que lê os dados de uma receita a partir da entrada padrão de acordo com a especificação
    @return: endereço de memória da receita lida
*/
Receita *leReceita() {

    char medicamento[100], paciente[100], medico[100], instrucoes[100];

    scanf("%[^\n]\n", medico);
    scanf("%[^\n]\n", paciente);
    scanf("%[^\n]\n", medicamento);
    scanf("%[^\n]\n", instrucoes);

    Receita *r = criaReceita(medicamento, paciente, medico, instrucoes);

    return r;
}

/*
    Função que calcula o preço de impressão de uma receita de acordo com a especificação
    @param dado: ponteiro genérico para a receita a ser calculada
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão da receita
*/
float calculaPrecoImpressaoReceita(void *dado, float precoCaractere) {

    Receita *r = (Receita*)dado;

    float soma = 0;

    soma += strlen(r->nomeMedicamento);
    soma += strlen(r->nomePaciente);
    soma += strlen(r->nomeMedico);
    soma += strlen(r->instrucoes);

    soma *= precoCaractere;

    return soma;
}

/*
    Função que imprime uma receita de acordo com a especificação (veja os casos de teste)
    @param dado: ponteiro genérico para a receita a ser impressa
*/
void imprimeReceita(void *dado) {

    Receita *r = (Receita*)dado;

    printf("- - RECEITA - -\n");
    printf("MEDICAMENTO: %s\n", r->nomeMedicamento);
    printf("PACIENTE: %s\n", r->nomePaciente);
    printf("INSTRUCOES: %s\n", r->instrucoes);
    printf("MEDICO: %s\n", r->nomeMedico);
    printf("- - - - - - - -\n");
}

/*
    Função que desaloca uma receita
    @param dado: ponteiro genérico para a receita a ser desalocada
*/
void desalocaReceita(void *dado) {

    Receita *r = (Receita*)dado;

    free(r);
}