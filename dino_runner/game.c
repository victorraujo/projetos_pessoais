#include <time.h> // time
#include <windows.h> // Sleep
#include <stdbool.h> // boleanos
#include <string.h>
#include <conio.h> // _kbhit() || _getch()
#include <stdio.h>
// TELA
#define ALTURA 10
#define LARGURA 70
#define ALTURA_MEIO (ALTURA / 2)
#define LARGURA_MEIO (LARGURA / 2)
#define DINO_INICIO 11

typedef struct
{
    int y;
    int x;

    char dinossauro;
} Dino;
Dino dino;

typedef struct
{
    int y;
    int x;

    char personagem;
} inimigos;

char tela[ALTURA][LARGURA];

// organizar e ajeitar tela
void inicializar()
{
    memset(tela, ' ', sizeof(tela));

    // BARREIRA DE TODOS OS LADOS
    for (int barreira_coluna = 0; barreira_coluna < ALTURA; barreira_coluna++)
    {
        if (barreira_coluna == 0)
        {
            for (int coluna_inteira = 0; coluna_inteira < LARGURA; coluna_inteira++)
            {
                tela[barreira_coluna][coluna_inteira] = '#';
            }
        }
        else if (barreira_coluna == ALTURA - 1)
        {
            for (int coluna_inteira = 0; coluna_inteira < LARGURA; coluna_inteira++)
            {
                tela[barreira_coluna][coluna_inteira] = '#';
            }
        }
        else
        {
            tela[barreira_coluna][0] = '#';
            tela[barreira_coluna][LARGURA - 1] = '#';
        }
    }

    dino.y = ALTURA - 2; // penultima coisa
    dino.x = DINO_INICIO;

    dino.dinossauro = '@';
    tela[dino.y][dino.x] = dino.dinossauro;
}

// APOIO
void resetarCursor()
{
    // COORD é uma struct simples do Windows que guarda duas variáveis {short X, short Y}
    COORD coord = {0, 0};

    // Coluna 0, Linha 0
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// EXIBIR TELA
void display()
{
    for (int altura = 0; altura < ALTURA; altura++)
    {
        for (int largura = 0; largura < LARGURA; largura++)
        {
            printf("%c", tela[altura][largura]);
        }
        printf("\n");
    }
}

int main(void)
{
    inicializar();

    bool gameOver = false;

    while (!gameOver)
    {

        // pula o dino
        if (dino.y < ALTURA - 2)
        {
            tela[dino.y][dino.x] = ' ';
            dino.y++;
            tela[dino.y][dino.x] = dino.dinossauro;
        }
        if (dino.x > DINO_INICIO)
        {
            tela[dino.y][dino.x] = ' ';
            dino.x--;
            tela[dino.y][dino.x] = dino.dinossauro;
            
        }
        if (dino.y == ALTURA - 2)
        {

            if (_kbhit())
            {
                char tecla = _getch();
                if (tecla == ' ' || tecla == 32)
                {
                    tela[dino.y][dino.x] = ' ';
                    dino.y = dino.y - 4;  
                    tela[dino.y][dino.x] = dino.dinossauro;
                }
                if (dino.x == DINO_INICIO)
                {
                    if (tecla == 87 || tecla == 119) // teclas W e w
                    {
                        tela[dino.y][dino.x] = ' ';
                        dino.x = dino.x + 5;
                        tela[dino.y][dino.x] = dino.dinossauro;
                    }
                }
            }
        }
        // Enquanto existir qualquer tecla presa no buffer..
        while (_kbhit())
        {
            _getch(); 
        }
        resetarCursor();
        display();
        Sleep(100); // 50 mili || 20 fps
    }
    return 0;
}