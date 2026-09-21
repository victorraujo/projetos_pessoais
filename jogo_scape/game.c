#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

#define ALTURA 20
#define LARGURA 40
#define LIMITE_TOTAL 20

typedef struct
{
    /* data */
    int y;
    int x;

    char personagem;
    int pontos;

} Usuario;
Usuario usuario;

typedef struct
{
    int y;
    int x;

    char personagem;
} Objetivo;

char tela[ALTURA][LARGURA];

void inicializar()
{

    memset(tela, ' ', sizeof(tela));

    usuario.personagem = '@';
    usuario.pontos = 0;
    usuario.y = ALTURA / 2;
    usuario.x = LARGURA / 2;

    tela[usuario.y][usuario.x] = '@';
}
void barreira()
{
    for (int barreira_altura = 0; barreira_altura < ALTURA; barreira_altura++)
    {
        if (barreira_altura == 0)
        {
            for (int i = 0; i < LARGURA; i++)
            {
                tela[barreira_altura][i] = '#';
            }
        }
        else if (barreira_altura == ALTURA - 1)
        {
            for (int i = 0; i < LARGURA; i++)
            {
                tela[barreira_altura][i] = '#';
            }
        }
        else
        {
            tela[barreira_altura][0] = '#';
            tela[barreira_altura][LARGURA - 1] = '#';
        }
    }
}
void imprimirMatriz()
{
    printf("\033[H");
    for (int i = 0; i < ALTURA; i++)
    {
        for (int j = 0; j < LARGURA; j++)
        {

            printf("%c", tela[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    inicializar();
    barreira();
    bool gamerOver = false;
    Objetivo objetivo;

    objetivo.y = 5;
    objetivo.x = 7;
    objetivo.personagem = '$';

    while (!gamerOver)
    {

        imprimirMatriz();

        char movimento = _getch();

        if (movimento == 224 || movimento == 0)
        {
            movimento  = _getch();
        }
        // Apaga a posição antiga do jogador
        tela[usuario.y][usuario.x] = ' ';

        switch (movimento)
        {
        case 72: // SETA PARA CIMA (Sobe uma linha no terminal)
            if (usuario.y > 1)
                usuario.y--;
            break;

        case 80: // SETA PARA BAIXO (Desce para a linha de baixo)
            if (usuario.y < ALTURA - 2)
                usuario.y++;
            break;

        case 75: // SETA PARA ESQUERDA
            if (usuario.x > 1)
                usuario.x--;
            break;

        case 77: // SETA PARA DIREITA
            if (usuario.x < LARGURA - 2)
                usuario.x++;
            break;
        }
        tela[usuario.y][usuario.x] = usuario.personagem;
        
        if (usuario.y >= ALTURA - 2 && usuario.x >= LARGURA - 2 && usuario.y < 0 && usuario.x < 0)
        {
            gamerOver == true;
        }
    }
    return 0;
}