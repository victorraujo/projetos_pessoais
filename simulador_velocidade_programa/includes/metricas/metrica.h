#ifndef METRICA_H
#define METRICA_H

#include <stdio.h>
#include <time.h>

typedef struct
{
    clock_t inicio;  // <-
    clock_t fim;     // <-
    double tempo_ms; // <-

    unsigned long long comparacoes; // <- quantas vezes fez (a > b)
    unsigned long long trocas;      // <- quantas vezes trocou elementos (Swap)
    unsigned long long copias;      // <- Quantas atribuições/cópias de memória fez
} metricas_t;


// FUNÇÕES PARA GERENCIAR O CRONOMETRO E OS DADOS
#endif