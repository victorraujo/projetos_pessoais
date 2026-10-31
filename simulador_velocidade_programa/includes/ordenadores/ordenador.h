#ifndef ORDENADOR_H
#define ORDENADOR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// STATUS TIPOS E MODELOS (metricas_t)
#include "../metricas/metrica.h"

//-------------------PUBBLE SORTING(simples e lento)-------------------
void bubbleSort(int array[], int quantidade)
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
            if(array[j] > array[j+1])
            {
                int tmp = array[j+1];
                array[j+1] = array[j];
                array[j] = tmp;

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


// array criar. merge sorting.
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

    int *auxiliar = (int*) malloc(tamanho * sizeof(int));
    if (auxiliar == NULL) { return; }
    merge_sorting(auxiliar, array, 0,  tamanho - 1);
}

//--------------------//EMPACOTAMENTO DAS FUNÇÕES//--------------------
// wrapper_bubble = empacotamento apenas para organizar para os ponteiros.

wrapper_bubble(int array[], int tamanho)
{
    bubbleSort(array, tamanho);
}

void wrapper_merge(int array[], int tamanho)
{
    mergeSorting(array, tamanho);
}

// 1. Define a "assinatura padrão" que toda função de ordenação vai ter na tabela
// literalmente um guia de via ponteiro
typedef void (*FuncaoOrdenacao)(int array[], int tamanho);

//-----------------------CRIAÇÃO PONTEIROS PARA FUNÇÕES-----------------------
// Criamos um vetor do tipo 'FuncaoOrdenacao' que guarda as nossas funções!
// Tabela guarda os endereços das funções de 3 parâmetros
// Declara e inicializa o vetor de funções logo de uma vez:

//  wrapper_bubble = 1
//  wrapper_merge  = 2
FuncaoOrdenacao meus_algoritmos[] = {
    wrapper_bubble,
    wrapper_merge
};


/* equivale:

Posição 0 guarda a função do Bubble Sort
meus_algoritmos[0] = bubbleSort;
// Posição 1 guarda a função do Merge Sort
meus_algoritmos[1] = mergeSorting;
*/
#endif
