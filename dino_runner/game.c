#include <stdint.h>  // uint8_t etc...
#include <stdlib.h>  // srand
#include <time.h>    // time
#include <windows.h> // Sleep
#include <stdbool.h> // boleanos
#include <conio.h>   // _kbhit() || _getch()
#include <stdio.h>
#include <string.h> // strcpy e memset

// TELA
#define ALTURA 10
#define LARGURA 40
#define ALTURA_MEIO (ALTURA / 2)
#define LARGURA_MEIO (LARGURA / 2)

// DINO
#define DINO_INICIO 11      // coluna
#define DINO_Y (ALTURA - 2) // altura
#define DINO_PULO -2
#define DINO_PULO_MAX (DINO_Y - 4) // 4 blocos de altura
// MOB CACTO
#define CACTO_INICIO (LARGURA - 2)
#define CACTO_FIM (LARGURA - 68)
#define MOB_CACTOS_SPAW 20

typedef struct
{
    int y;
    int x;

    // COMANDOS (w corre|| space pula)
    bool estaPulando;
    int velocidadeY;

    char *dinossauro; // skin
} Dino;
Dino dino;

typedef struct
{
    int y;
    int x;
    char *personagem;
} Inimigos;

char tela[ALTURA][LARGURA][8];

// organizar e ajeitar tela
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

    dino.dinossauro = "🦖";
    strcpy(tela[dino.y][dino.x], dino.dinossauro);

    srand(time(NULL));
}

// APOIO 1
void resetarCursor()
{
    COORD coord = {0, 0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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

// EXIBIR TELA
void display()
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

uint8_t sortearSimOuNao(void)
{
    return rand() % 2;
}

int main(void)
{
    inicializar();

    bool gameOver = false;

    Inimigos cacto;
    cacto.y = ALTURA - 2;
    cacto.x = CACTO_INICIO;
    cacto.personagem = "🌵";
    uint8_t spawn_mob = sortearSimOuNao();

    int contador = 0;

    clock_t inicio = clock();
    while (!gameOver)
    {
        if (contador < MOB_CACTOS_SPAW)
        {

            contador++;
        }

        if ((dino.estaPulando == false) && dino.y != DINO_Y)
        {
            strcpy(tela[dino.y][dino.x], "  ");
            dino.y++;
            strcpy(tela[dino.y][dino.x], "🦖");
        }

        // vai pra frente o dino

        if (dino.x > DINO_INICIO)
        {
            strcpy(tela[dino.y][dino.x], " ");
            dino.x--;
            strcpy(tela[dino.y][dino.x], "🦖");
        }

        // SPAW MOB
        if (contador >= MOB_CACTOS_SPAW && spawn_mob)
        {
            strcpy(tela[cacto.y][cacto.x], " ");
            cacto.x--;

            if (cacto.x == CACTO_FIM + 1)
            {
                cacto.x = CACTO_INICIO;
                strcpy(tela[cacto.y][cacto.x], " ");
                contador = 0;
            }
            else
            {
                strcpy(tela[cacto.y][cacto.x], cacto.personagem);
            }
        }

        if (dino.y == ALTURA - 2)
        {
            if (_kbhit())
            {
                char tecla = _getch();
                // PULO (Space)
                if ((tecla == ' ' || tecla == 32) && dino.estaPulando == false)
                {
                    dino.velocidadeY = -2;
                    dino.estaPulando = true;
                }
                // CORRER (W)
                if (dino.x == DINO_INICIO)
                {
                    if (tecla == 87 || tecla == 119) // teclas W e w
                    {
                        strcpy(tela[dino.y][dino.x], "  ");
                        dino.x = dino.x + 5;
                        strcpy(tela[dino.y][dino.x], "🦖");
                    }
                }
                // CARACTERE ESPECIAL (CTRL E C)
                if (tecla == 3)
                {
                    gameOver = true;
                }
            }
        }

        // IFS DE CARACTERE APERTADO

        // Aplica o movimento do pulo/gravidade
        if (dino.estaPulando == true)
        {
            // APAGAR POSIÇÃO
            if (dino.y == DINO_PULO_MAX)
            {
                // parar de subir
                dino.estaPulando = false;
            }
            else
            {
                strcpy(tela[dino.y][dino.x], "  ");
                dino.y = dino.y + DINO_PULO;
                strcpy(tela[dino.y][dino.x], "🦖");
            }
        }

        // Enquanto existir qualquer tecla presa no buffer..
        while (_kbhit())
        {
            _getch();
        }

        resetarCursor();
        display();
        esconderCursor(true);
        Sleep(100);
    }
    esconderCursor(false);
    return 0;
}