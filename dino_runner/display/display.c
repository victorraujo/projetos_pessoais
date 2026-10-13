#include "display.h"

#include <windows.h>
#include <stdbool.h>
#include <stdio.h>

#define ALTURA 10 
#define LARGURA 35
extern char tela[ALTURA][LARGURA][8];

// desenha a tela igual pixel por pixel(parecido)
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

// mover cursor pra cima
void display()
{
    COORD coord = {0, 0}; // posição linha zero, coluna zero
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // mover
}

// APOIO 2
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