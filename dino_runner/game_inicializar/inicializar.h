#ifndef INICIALIZAR_H
#define INICIALIZAR_H

#include <stdio.h>
#include <windows.h>
#include <string.h>  // strcpy e memset
#include "../mobs/mob_estrutura.h"

// organizar e ajeitar tela

extern Dino dino; // vem de game.c
void inicializar()
{
    SetConsoleOutputCP(CP_UTF8);

    // Zera os bytes para nao ter lixo de memoria antes de usar o strcpy
    memset(tela, 0, sizeof(tela));

    // Preenche com espaço vazio usando string
    for (int y = 0; y < ALTURA; y++)
    {
        for (int x = 0; x < LARGURA; x++)
        {
            strcpy(tela[y][x], "  ");
        }
    }

    // BARREIRA DE TODOS OS LADOS
    for (int barreira_coluna = 0; barreira_coluna < ALTURA; barreira_coluna++)
    {
        if (barreira_coluna == 0)
        {
            for (int coluna_inteira = 0; coluna_inteira < LARGURA; coluna_inteira++)
            {
                strcpy(tela[barreira_coluna][coluna_inteira], "##");
            }
        }
        else if (barreira_coluna == ALTURA - 1)
        {
            for (int coluna_inteira = 0; coluna_inteira < LARGURA; coluna_inteira++)
            {
                strcpy(tela[barreira_coluna][coluna_inteira], "##");
            }
        }
        else
        {
            strcpy(tela[barreira_coluna][0], "##");
            strcpy(tela[barreira_coluna][LARGURA - 1], "##");
        }
    }

    dino.y = ALTURA - 2; // penultima coisa
    dino.x = DINO_INICIO;

    dino.estaPulando = false;
    dino.andar = 0;

    dino.dinossauro = "🦖";
    strcpy(tela[dino.y][dino.x], dino.dinossauro);

    srand(time(NULL));
}
#endif