#ifndef DISPLAY_H
#define DISPLAY_H

#include "../macros/macro.h"
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

extern char tela[ALTURA][LARGURA][8];


// DISPLAY DO JOGO E ADICIONANDO ESTRUTURAS
void display(void)
{
    for (int altura = 0; altura < ALTURA; altura++)
    {
        for (int largura = 0; largura < LARGURA; largura++)
        {
            printf("%s", tela[altura][largura]);
        }
        printf("\n");
    }
}

// APOIO 1 (RESETA O CURSOR PRA CIMA)
void resetarCursor()
{
    COORD coord = {0, 0}; // posição linha zero, coluna zero
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // mover
}

// APOIO 2 (ESCONDE O CURSOR)
void esconderCursor(bool desativar)
{
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;

    if (desativar == true)
    {
        info.bVisible = FALSE;
    }
    else
    {
        info.bVisible = TRUE;
    }
    SetConsoleCursorInfo(consoleHandle, &info);
}


//TELA COMENTARIOS (GAME OVER)
void displayGmerOver(char* prompt_texto)
{

    size_t tamanho = strlen(prompt_texto);

    for (int largura_tela_atual = LARGURA_MEIO - (tamanho + 2), i = 0; largura_tela_atual < LARGURA_MEIO; largura_tela_atual++, i++)
    {
        char texto_string[2] =  {prompt_texto[i], '\0'}; // conversao para string
        strcpy(tela[ALTURA_MEIO][largura_tela_atual], texto_string); // copiar de um e colar do outro
    }
    return;
}
#endif