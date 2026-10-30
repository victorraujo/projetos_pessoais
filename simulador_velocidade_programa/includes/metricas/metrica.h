#ifndef METRICA_H
#define METRICA_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct
{
    // Para medir tempo de processamento/CPU (em milissegundos)
    clock_t inicio;  // <-
    clock_t fim;     // <-
    double tempo_ms; // <-

    time_t inicio_tempo; // <-
    time_t fim_tempo;    // <-
    time_t seg;          // <-


    unsigned long long comparacoes; // <- quantas vezes fez (a > b)
    unsigned long long trocas;      // <- quantas vezes trocou elementos (Swap)
    unsigned long long copias;      // <- Quantas atribuições/cópias de memória fez
} metricas_t;




// FUNÇÕES PARA GERENCIAR O CRONOMETRO E OS DADOS


//-----------TIME TEMPO(RELOGIO) FUNÇÕES//-----------
#endif