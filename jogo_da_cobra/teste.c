#include <ncurses.h> // desenhar em qualquer lugar da tela
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>

#define LARGURA 50
#define TAMANHO 20
#define TAMANHO 100

typedef struct 
{
    int x[TAMANHO];
    int y[TAMANHO];

    int comprimento;
    int direcaox;
    int direcaoy;
} Cobra;

Cobra cobra;

void inicializar()
{
    initscr(); // inicializar
    cbreak(); // não aguardar o inter. ler direto
    noecho(); // não escrever na tela
    keypad(stdscr, TRUE); //captura de teclas especiais
    curs_set(0); // nao mostrar na tela
    start_color(); // adiciona cores(Ele sabe que vai lidar com  cores)

    // pares de cores
    init_pair(1, COLOR_GREEN)

}

int main(void)
{
    bool gameOVer == false;
    inicializar();

    while(!gameOVer)
    {

    }

    return 0;

}