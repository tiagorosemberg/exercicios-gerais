#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "vector.h"

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos) {

    int i;
    float media = 0, soma = 0, phomem, pmulher, poutro, paprovados;
    int homem = 0, mulher = 0, outro = 0, aprovados = 0;

    for (i = 0; i < VectorSize(alunos); i++) {

        soma += GetNotaAluno((tAluno*)VectorGet(alunos, i));

        if(GetNotaAluno((tAluno*)VectorGet(alunos, i)) >= 6) {
            aprovados++;
        }

        if(GetGeneroAluno((tAluno*)VectorGet(alunos, i)) == 'M') {
            homem++;
        
        } else if (GetGeneroAluno((tAluno*)VectorGet(alunos, i)) == 'F') {

            mulher++;
        
        } else if (GetGeneroAluno((tAluno*)VectorGet(alunos, i)) == 'O') {

            outro++;
        }
    }

    media = soma / VectorSize(alunos);

    phomem = (float)homem / VectorSize(alunos);
    pmulher = (float)mulher / VectorSize(alunos);
    poutro = (float)outro / VectorSize(alunos);

    paprovados = (float)aprovados / VectorSize(alunos);

    printf("Media das notas: %.2f\n", media);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", 100 * paprovados);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", 100 * phomem);
    printf("Feminino: %.2f%%\n", 100 * pmulher);
    printf("Outro: %.2f%%\n", 100 * poutro);

    /*
Media das notas: 7.05
Porcentagem de alunos aprovados: 75.00%
Porcentagem de cada genero:
Masculino: 25.00%
Feminino: 25.00%
Outro: 50.00%
    */
}