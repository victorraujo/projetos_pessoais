#ifndef ORDENADOR_H
#define ORDENADOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


//-------------------PUBBLE SORTING(simples e lento)-------------------
void bubbleSort(int* a, int quantidade)
{
    // quantidade total de volta ate ficar ordenado
    for(int i = 0; i < quantidade - 1; i++)
    {
        // ordenado
        bool trocou = false;
        // sai ordenando um por um comparando
        // i e pq empurrei o ultimo pra gaveta final.
        for (int j = 0; j < quantidade - i - 1; j++)
        {
            // 3 -> 2([2, 3])
            if(a[j] > a[j+1])
            {
                int tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;

                trocou = true;
            }
        }
        if (trocou == false)
        {
            break;
        }
    }
}

//-------------------MERGE SORTING TOP 1-------------------


// a criar. merge sorting.
// auxiliar = leitura
// array    = modoficar
// inicio   = começo
// meio     = quebra em duas parte
// fim      = final

// juntar partes e comparar (parte 3)
void merge(int auxiliar[], int array[], int inicio, int meio, int fim)
{
    for(int copy = inicio; copy <= fim; copy++)
    {
        auxiliar[copy] = array[copy];
    }


    // iniciadores
    int i = inicio;
    int j = meio + 1;
    int k = inicio;
    // comparar o menor e atribuir
    while(i <= meio && j <= fim)
    {
        if (auxiliar[i] <= auxiliar[j])
        {
            array[k] = auxiliar[i];
            i++;
            k++;
        }
        else
        {
            array[k] = auxiliar[j];
            j++;
            k++;
        }
    }
    // ver se ficou sobrou algo...
    while(i <= meio)
    {
        array[k] = auxiliar[i];
        i++;
        k++;
    }
    while (j <= fim)
    {
        array[k] = auxiliar[j];
        j++;
        k++;
    }
}

// separação (parte 2)
void merge_sorting(int auxiliar[], int array[], int inicio, int fim)
{
    
    if (inicio >= fim)
    {
        return;
    }

    // devide ao meio
    int meio = inicio + (fim - inicio) / 2;

    // separação esquerda
    merge_sorting(auxiliar, array, inicio, meio);
    // separação direita
    merge_sorting(auxiliar, array, meio + 1, fim);

    merge(auxiliar, array, inicio, meio, fim);
}
// interface codigo dev (parte 1)
void mergeSorting(int array[], int tamanho)
{

    int *auxiliar = (int *)malloc(tamanho * sizeof(int)); // cast
    if (auxiliar == NULL) { return; }
    merge_sorting(auxiliar, array, 0,  tamanho - 1);
}

#endif
