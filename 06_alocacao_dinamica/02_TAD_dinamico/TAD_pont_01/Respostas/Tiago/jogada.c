#include <stdio.h>
#include <stdlib.h>
#include "jogada.h"

/**
 * Aloca e retorna uma estrutura do tipo tJogada.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tJogada alocada.
 */
tJogada* CriaJogada() {

    tJogada *jogada = calloc(1, sizeof(tJogada));

    if (jogada == NULL) {
        printf("alocacao deu errado ai pai??\n");
        exit(1);
    }
}


/**
 * Libera a memória de uma estrutura do tipo tJogada.
 * 
 * @param jogada a estrutura do tipo tJogada a ser liberada.
 */
void DestroiJogada(tJogada* jogada){
    free(jogada);
}

/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 * 
 * @param jogada a estrutura do tipo tJogada a ser preenchida.
 */
void LeJogada(tJogada* jogada){

    printf("Digite uma posicao (x e y):\n");
    if (scanf(" %d %d", &jogada->x, &jogada->y) == 2){
        jogada->sucesso = 1;
    } else {
        jogada->sucesso = 0;
    }
    
}

/**
 * Retorna a coordenada X da jogada.
 * 
 * @param jogada a estrutura do tipo tJogada.
 * 
 * @return a coordenada X da jogada.
 */
int ObtemJogadaX(tJogada* jogada) {
    return jogada->x;
}


/**
 * Retorna a coordenada Y da jogada.
 * 
 * @param jogada a estrutura do tipo tJogada.
 * 
 * @return a coordenada Y da jogada.
 */
int ObtemJogadaY(tJogada* jogada) {
    return jogada->y;
}


/**
 * Retorna 1 se a jogada foi bem sucedida e 0 caso contrário.
 * 
 * @param jogada a estrutura do tipo tJogada.
 * 
 * @return 1 se a jogada foi bem sucedida, 0 caso contrário.
 */
int FoiJogadaBemSucedida(tJogada* jogada) {


    if (jogada->x <= 2 && jogada->y <= 2 && jogada->x >= 0 && jogada->y >= 0) {
        return 1;

    } else {
        printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", jogada->x, jogada->y);
        return 0;
    }
}