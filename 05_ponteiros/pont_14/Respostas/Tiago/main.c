#include <stdio.h>
#include "botao.h"
#include "tela.h"

void executaSalvar () {
    printf("- Botao de SALVAR dados ativado!\n");
}

void executaExcluir () {
    printf("- Botao de EXCLUIR dados ativado!\n");
}

void executaOpcoes () {
    printf("- Botao de OPCOES ativado!\n");
}

int main () {

    Botao btnSalvar = CriarBotao("Salvar", 12, "FFF", CLICK, executaSalvar);
    Botao btnExcluir = CriarBotao("Excluir", 18, "000", CLICK, executaExcluir);
    Botao btnOpcoes = CriarBotao("Opcoes", 10, "FF0000", LONGO_CLICK, executaOpcoes);

    Tela tela = CriarTela(200, 400);

    RegistraBotaoTela(&tela, btnSalvar);
    RegistraBotaoTela(&tela, btnExcluir);
    RegistraBotaoTela(&tela, btnOpcoes);

    DesenhaTela(tela);

    OuvidorEventosTela(tela);

    return 0;
}