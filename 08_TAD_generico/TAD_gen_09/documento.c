#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "documento.h"

/*
    Estrutura do tipo Documento contendo os atributos necessários para a manipulação
*/
struct _Documento {

    void *dado;
    func_ptr_calculaPreco calculaPreco;
    func_ptr_imprime imprime;
    func_ptr_desaloca desaloca;
};
/*
    Função que cria um documento genérico e retorna o seu endereço de memória
    @param dado: ponteiro genérico para o dado do documento
    @param imprimeDado: ponteiro para a função de impressão do dado do documento genérico
    @param desalocaDado: ponteiro para a função de desalocação do dado do documento genérico
    @param calculaPrecoDado: ponteiro para a função de cálculo do preço do dado do documento genérico
    @return: endereço de memória do documento genérico criado
*/
Documento *criaDocumento(void *dado, func_ptr_imprime imprimeDado, func_ptr_desaloca desalocaDado, func_ptr_calculaPreco calculaPrecoDado) {

    Documento *d = calloc(1, sizeof(Documento));

    d->dado = dado;
    d->imprime = imprimeDado;
    d->desaloca = desalocaDado;
    d->calculaPreco = calculaPrecoDado; 
    
    return d;
}

/*
    Função que imprime um documento genérico de acordo com a função de impressão passada
    @param doc: ponteiro para um documento a ser impresso
*/
void imprimeDocumento(Documento *doc) {

    doc->imprime(doc->dado);
}

/*
    Função que calcula o preço de impressão de um documento de acordo com a função de cálculo estabelecida na especificação
    @param doc: ponteiro para um documento a ser calculado o preço
    @param precoCaractere: preço por caractere utilizado no cálculo
    @return: preço de impressão do documento
*/
float calculaPrecoImpressaoDocumento(Documento *doc, float precoCaractere) {

    return doc->calculaPreco(doc->dado, precoCaractere);
}

/*
    Função que desaloca um documento de acordo com a função de desalocação passada
    @param doc: ponteiro para um documento a ser desalocado
*/
void desalocaDocumento(Documento *doc) {

    doc->desaloca(doc->dado);
    free(doc);
}