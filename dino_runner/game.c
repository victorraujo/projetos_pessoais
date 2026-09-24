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
// BORDA DA COLUNA
#define COLUNA_BORDA (LARGURA - 3)
// DINO
#define DINO_INICIO 11      // coluna
#define DINO_Y (ALTURA - 2) // altura
#define DINO_PULO -2
#define DINO_PULO_MAX (DINO_Y - 4) // 4 blocos de altura

// MOB CACTO
#define CACTO_INICIO (LARGURA - 2)
#define CACTO_FIM (LARGURA - (LARGURA - 2))
#define MOB_CACTOS_SPAW 20

typedef struct
{
    int y;
    int x;
    // COMANDOS (w corre|| space pula)
    int andar;
    bool estaPulando;
    char *dinossauro; // skin
} Dino;
Dino dino;

typedef struct
{
    int y;
    int x;
    int andar;
    bool estaPulando;
    bool ativado;
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

    dino.estaPulando = false;
    dino.andar = 0;

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
    cacto.ativado = false;
    uint8_t spawn_mob = 1;

    int contador = 0;

    clock_t inicio = clock();
    while (!gameOver)
    {
        if (contador < MOB_CACTOS_SPAW)
        {
            contador++;
        }
        // SPAW MOB

        if (contador >= MOB_CACTOS_SPAW)
        {
            if ((spawn_mob = sortearSimOuNao()) == 0)
            {
                contador = 0;
            }
            else
            {
                cacto.ativado = true;
                contador = 0;
            }
        }
        if (cacto.ativado == true)
        {
            strcpy (tela[cacto.y][cacto.x], "  ");
            cacto.x--;
            strcpy (tela[cacto.y][cacto.x], "🌵");

            if (cacto.x == CACTO_FIM)
            {
                strcpy (tela[cacto.y][cacto.x], "  ");
                cacto.x = CACTO_INICIO;
                cacto.ativado = false;
            }

        }
        //----------------------DINO-------------------------------------------------

        // PULO DO DINO E FISICA
        if ((dino.estaPulando == false) && dino.y != DINO_Y)
        {
            strcpy(tela[dino.y][dino.x], "  ");
            dino.y++;
            strcpy(tela[dino.y][dino.x], "🦖");
        }
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

        // vai pra frente o dino

        if (dino.x > DINO_INICIO)
        {
            // fisica pra voltar pra tras
            strcpy(tela[dino.y][dino.x], "  ");
            dino.x--;
            strcpy(tela[dino.y][dino.x], "🦖");
        }

        if (dino.andar > 0 && dino.x + 4 != LARGURA)
        {
            strcpy(tela[dino.y][dino.x], "  ");
            dino.x = dino.x + 2;
            strcpy(tela[dino.y][dino.x], "🦖");

            dino.andar--;
        }

        // GAMER OVER! (caso 1 = encostou no cafto)
        if (dino.y == cacto.y && dino.x == cacto.x)
        {
            displayGmerOver("GAMER OVER!!");
            gameOver = true;
            break;
        }
        //-------------------------------------------------------------------
        
       // 5. LEITURA DO TECLADO
        if (_kbhit())
        {
            char tecla = _getch();

            // PULO (Space): Só pula se estiver no chão
            if ((tecla == ' ' || tecla == 32) && (dino.estaPulando == false) && (dino.y == ALTURA - 2))
            {
                dino.estaPulando = true;
            }

            // CORRER (W): Só corre se Não estiver na borda
            if ( (dino.x + 4 != LARGURA) && (tecla == 87 || tecla == 119 || tecla == 'W' || tecla == 'w'))
            {
                dino.andar = 3;
            }

            // CTRL + C (Sair do jogo)
            if (tecla == 3)
            {
                gameOver = true;
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
        Sleep(50); // frames
    }
            resetarCursor();
        display();
        esconderCursor(true);
        Sleep(50); // frames
    esconderCursor(false);

    return 0;
}
