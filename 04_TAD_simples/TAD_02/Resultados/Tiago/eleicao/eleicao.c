#include <stdio.h>
#include <string.h>
#include "eleicao.h"
#include "candidato.h"
#include "eleitor.h"

int TotalVotos(tEleicao eleicao);

/**
 * @brief Inicializa uma eleição com valores padrão (zerando os votos invalidos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados.
 * @return Eleição inicializada.
 */
tEleicao InicializaEleicao() {

    tEleicao eleicao;
    tCandidato candidato;

    int n_candidatos, i;

    eleicao.totalPresidentes = 0;
    eleicao.totalGovernadores = 0;
    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosPresidente = 0;
    eleicao.votosBrancosGovernador = 0;
    eleicao.votosNulosGovernador = 0;
    eleicao.totalEleitores = 0;

    scanf(" %d", &n_candidatos);

    for (i = 0; i < n_candidatos; i++) {

        candidato = LeCandidato();

        if (candidato.cargo == 'P') {
            eleicao.presidentes[eleicao.totalPresidentes] = candidato;
            eleicao.totalPresidentes++;

        } else if (candidato.cargo == 'G') {
            eleicao.governadores[eleicao.totalGovernadores] = candidato;
            eleicao.totalGovernadores++;
        }
    }

    return eleicao;
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 * @return Eleição com os resultados da votação.
 */
tEleicao RealizaEleicao(tEleicao eleicao) {

    int n_eleitores, j;
    tEleitor eleitor;

    scanf(" %d", &n_eleitores);

    for (j = 0; j < n_eleitores; j++) {

        eleitor = LeEleitor();
        eleicao.eleitores[j] = eleitor;
        eleicao.totalEleitores++;        
    }

    return eleicao;
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao eleicao) {

    int i, j, id, maior = 0, id_vencedor;
    tCandidato vencedor;

    // ELEICAO ANULADA -----------------

    // eleitor repetido

    for (i = 0; i < eleicao.totalEleitores; i++) {

        for (j = 0; j < eleicao.totalEleitores; j++) {
            
            if (j == i) {
                continue;
            }

            if (EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j])) {
                printf("ELEICAO ANULADA");
                return;
            }
        }
    }


    // num max eleitores

    if (eleicao.totalEleitores > 10) {
        printf("ELEICAO ANULADA");
        return;
    }

    // num max candidatos 
    
    if (eleicao.totalPresidentes > 3) {
        printf("ELEICAO ANULADA");
        return;
    }

    if (eleicao.totalGovernadores > 3) {
        printf("ELEICAO ANULADA");
        return;
    }

    // ELEICAO VENCIDA OU EMPATADA ---------------
        // PRESIDENTE
    
    for (i = 0; i < eleicao.totalPresidentes; i++) {

        if (eleicao.presidentes[i].votos > maior) {
            maior = eleicao.presidentes[i].votos;
            vencedor = eleicao.presidentes[i];
            id_vencedor = eleicao.presidentes[i].id;
        }
    }

    for (i = 0; i < eleicao.totalPresidentes; i++) {

        if (eleicao.presidentes[i].votos == vencedor.votos && eleicao.presidentes[i].id != vencedor.id) {
            printf("empate");
            return;
        }
    }

    if (vencedor.votos < eleicao.votosNulosPresidente) {
        printf("ninguem foi eleito");
        return;
    }

    printf("- PRESIDENTE ELEITO: ");
    ImprimeCandidato(vencedor, CalculaPercentualVotos(vencedor, TotalVotos(eleicao)));
}






int TotalVotos(tEleicao eleicao) {
    return eleicao.votosBrancosGovernador + eleicao.votosBrancosPresidente + eleicao.votosNulosGovernador + eleicao.votosNulosPresidente;
}