#ifndef GERADOR_H
#define GERADOR_H

#include <stdio.h>
#include <time.h>   // time(NULL)
#include <stdlib.h> // srand -> semente || rand() -> numero aleatorio



// NUMEROS ALEATÓRIO
void gerador_array(int array[], int tamanho, int min, int max)
{
    for (int i = 0; i < tamanho; i++)
    {
        array[i] = min + (rand() % (max - min + 1));
    }
}

#endif