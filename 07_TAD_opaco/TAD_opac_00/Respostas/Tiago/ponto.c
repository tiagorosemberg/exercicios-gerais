#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

/********************************************************************
	TAD: Ponto (x,y) 
	
********************************************************************/
/* TAD Opaco */
struct ponto {
	float x;
	float x;
};

/* Funcoes exportadas */

/**
 * @brief Cria uma variável do tipo Ponto
 * @param x o valor da coordenada x do ponto 
 * @param y o valor da coordenada y do ponto
 * @return A variável do tipo Ponto criada 
 */
tPonto Pto_Cria (float x, float y) {

	tPonto ponto;


}

/**
 * @brief Apaga (Libera a memória) alocada pelo ponto
 * @param p A variável do tipo ponto que será apagada e terá sua memória liberada
 */
void Pto_Apaga (tPonto p);

/**
 * @brief Função que acessa a coordenada "x" do ponto p
 * @param p A variável que representa um ponto qualquer
 * @return O valor da coordenada x de um ponto p
 */
float Pto_Acessa_x (tPonto p);

/**
 * @brief Função que acessa a coordenada "y" do ponto p
 * @param p A variável que representa um ponto qualquer
 * @return O valor da coordenada y de um ponto p
 */
float Pto_Acessa_y (tPonto p);

/**
 * @brief Função que atribui a coordenada "x" do ponto p
 * @param p A variável que representa um ponto qualquer
 * @param x O novo valor da coordenada x do ponto p
 */
void Pto_Atribui_x (tPonto p, float x);

/**
 * @brief Função que atribui a coordenada "y" do ponto p
 * @param p A variável que representa um ponto qualquer
 * @param y O novo valor da coordenada y do ponto p
 */
void Pto_Atribui_y (tPonto p, float y);

/**
 * @brief Função que calcula a distância euclidiana entre dois pontos: p1 e p2
 * @param p1 A variável que representa um primeiro ponto
 * @param p2 A variável que representa um segundo ponto
 * @return A distância euclidiana entre p1 e p2
 */
float Pto_Distancia (tPonto p1, tPonto p2);
