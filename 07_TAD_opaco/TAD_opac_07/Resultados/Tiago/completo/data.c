#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int DataParaDias(tData* data);

struct Data {

    int dia;
    int mes;
    int ano;

};

/**
 * @brief Aloca dinamicamente uma estrutura do tipo tData, e a retorna. 
 * Os campos dessa estrutura devem ser preenchidos inicialmente com -1.
 * 
 * @return tData - Data "Vazia"
 */
tData* CriaData() {

    tData *d = (tData*) calloc(1, sizeof(tData));

    d->dia = -1;
    d->mes = -1;
    d->ano = -1;

    return d;
}

/**
 * @brief Lê o dia, mês e ano e armazena em uma estrutura tData alocada dinamicamente.
 * 
 * @param data - Ponteiro para a estrutura onde os dados serão armazenados. Lembre-se: Não pode ter valor NULL.
 */
void LeData(tData* data) {

    scanf(" %d/%d/%d", &data->dia, &data->mes, &data->ano);

}

/**
 * @brief Libera a memória alocada dinamicamente para uma estrutura do tipo tData, passada como parâmetro
 * @param data - Ponteiro para a estrutura onde os dados estão armazenados. 
*/
void LiberaData(tData* data) {

    free(data);

}

/**
 * @brief Verifica se uma data é válida.
 * 
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData* data) {

    if (data->dia > 31 || data->dia < 1 || data->mes < 1 || data->mes > 12) {
        return 0;
    }

    return 1;
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 * 
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData* data) {

    switch (data->mes) {

        case 1:
        printf("Janeiro");
        break;

        case 2:
        printf("Fevereiro");
        break;

        case 3:
        printf("Marco");
        break;

        case 4:
        printf("Abril");
        break;

        case 5:
        printf("Maio");
        break;

        case 6:
        printf("Junho");
        break;

        case 7:
        printf("Julho");
        break;

        case 8:
        printf("Agosto");
        break;

        case 9:
        printf("Setembro");
        break;

        case 10:
        printf("Outubro");
        break;

        case 11:
        printf("Novembro");
        break;

        case 12:
        printf("Dezembro");
        break;
    }
}

/**
 * @brief Imprime uma data em formato extenso.
 * 
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData* data) {

    printf("%d de ", data->dia);
    ImprimeMesExtenso(data);
    printf(" de %d", data->ano);
    printf("\n");
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData* data) {

    if((data->ano % 400 == 0) || (data->ano % 4 == 0 && data->ano % 100 != 0)) {
        
        return 1;
    }

    return 0;
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 * 
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData* data) {

    if (data->mes == 2) {

        if (VerificaBissexto(data)) {

            return 29;
        } else{
            return 28;
        }


    } else if (data->mes == 1 || data->mes == 3 || data->mes ==  5 || data->mes ==  7 || data->mes ==  8 || data->mes ==  10 || data->mes == 12) {

        return 31;

    } else {

        return 30;
    }
}

/**
 * @brief Compara duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 * A data ser maior significa que ela é mais recente.
 */
int ComparaData(tData* data1, tData* data2) {
    // Compara os anos
    if (data1->ano > data2->ano) {
        return 1;
    } else if (data1->ano < data2->ano) {
        return -1;
    }
    
    // Se os anos são iguais, compara os meses
    if (data1->mes > data2->mes) {
        return 1;
    } else if (data1->mes < data2->mes) {
        return -1;
    }
    
    // Se os meses também são iguais, compara os dias
    if (data1->dia > data2->dia) {
        return 1;
    } else if (data1->dia < data2->dia) {
        return -1;
    }
    
    // Se chegar até aqui, ano, mês e dia são idênticos
    return 0;
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 * 
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData* data) {

    return NumeroDiasMes(data) - data->dia;

}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData* data1, tData* data2) {

    int diff = DataParaDias(data1) - DataParaDias(data2);

    if (diff < 0) {
        diff *= -1;
    }

    return diff;

}

int DataParaDias(tData* data) {
    if (!data) return 0;

    int ano = data->ano;
    int mes = data->mes;
    int dia = data->dia;

    int diasMeses[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int anosAnteriores = ano - 1;
    int bissextosAnteriores = (anosAnteriores / 4) - (anosAnteriores / 100) + (anosAnteriores / 400);
    int totalDias = (anosAnteriores * 365) + bissextosAnteriores;

    for (int i = 1; i < mes; i++) {
        totalDias += diasMeses[i];
    }

    if (mes > 2 && VerificaBissexto(ano)) {
        totalDias += 1;
    }

    totalDias += dia;

    return totalDias;
}