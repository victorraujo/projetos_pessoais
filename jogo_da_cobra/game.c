#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h> // memset
#define ALTURA 50
#define LARGURA 50
#define TAMANHO 100

typedef struct 
{
    int y[TAMANHO];
    int x[TAMANHO];

    int comprimento;


} Cobra;

Cobra cobra;

char tela[ALTURA][LARGURA];
void inicializar()
{
    // Preenche toda a matriz com o caractere ' '
    memset(tela, ' ', sizeof(tela));

    cobra.y[0] = ALTURA / 2;
    cobra.x[0] = LARGURA / 2;

    cobra.comprimento = 1;

    tela[cobra.y[0]][cobra.x[0]] = '@';
    

}

void imprimirMatriz()
{
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
    imprimirMatriz();

}