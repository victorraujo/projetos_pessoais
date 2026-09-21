#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>

#define ALTURA 20
#define LARGURA 20
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
    usuario.x = LARGURA /2;

    tela[usuario.y][usuario.x] = '@';

}
void barreira()
{
    for (int barreira_altura = 0; barreira_altura <= ALTURA; barreira_altura++)
    {
        if (barreira_altura == 0)
        {
            for (int i = 0; i < LARGURA; i++)
            {
                tela[barreira_altura][i] = '#';
            }
        }
        if (barreira_altura == ALTURA)
        {
            for (int i = 0; i < LARGURA; i++)
            {
                tela[barreira_altura][i] = '#';
            }
        }
        printf("\n");
    }
}
void imprimirMatriz()
{
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {

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

    while(!gamerOver)
    {
        printf("\033[2J\033[H");

        imprimirMatriz();

        char movimento = _getch();

        switch (movimento)
        {
        case 80: // cima
            tela[usuario.y][usuario.x] = ' '; 
            usuario.y++;
            tela[usuario.y][usuario.x] = '@'; 
            
            break;
        case 72: // baixo
            tela[usuario.y][usuario.x] = ' '; 
            usuario.y--;
            tela[usuario.y][usuario.x] = '@'; 

            break;
        case 75: // esquerda
            tela[usuario.y][usuario.x] = ' '; 
            usuario.x--;
            tela[usuario.y][usuario.x] = '@'; 
            break;
        case 77: // direita
            tela[usuario.y][usuario.x] = ' '; 
            usuario.x++;
            tela[usuario.y][usuario.x] = '@'; 

        break;

        default:
            break;
        }
        if (usuario.y >= 20 && usuario.x >= 20 && usuario.y < 0 && usuario.x < 0)
        {
            gamerOver == true;
        }
    }
    return 0;

}