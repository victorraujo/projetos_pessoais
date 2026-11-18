#ifndef METRICA_H
#define METRICA_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>



typedef struct metricas_t
{
    // desativado temporariamente..
    /* Para medir tempo (em nano segundos)
    struct timespec nano_inicio;
    struct timespec nano_fim;
    double tempo_mono_ms;
    */
    // Para medir tempo de processamento/CPU (em milissegundos)

    // CPU Time
    clock_t cpu_inicio;  // <-
    clock_t cpu_fim;     // <-
    double cpu_tempo_ms; // <-

    // RELOGIO Time
    time_t relogio_inicio; // <-
    time_t relogio_fim;    // <-
    time_t relogio_seg;    // <-

    // OEPRAÇÕES Time
    unsigned long long comparacoes; // <- Quantas vezes fez (a > b)
    unsigned long long trocas;      // <- Quantas vezes trocou elementos (Swap)
    unsigned long long copias;      // <- Quantas atribuições/cópias de memória fez
    unsigned long long pilha;       // <- Quantas chamadas


    //TEMPO
    void(*metrica_start)(metricas_t*);
    void(*metrica_fim)(metricas_t*);
    // AUMENTAR PARAMETROS
    void(*metrica_comparacoes)(metricas_t*, int);
    void(*metrica_trocas)(metricas_t*, int);
    void(*metrica_copias)(metricas_t*, int);
    void(*metrica_pilha)(metricas_t*, int);

} metricas_t;

// FUNÇÕES PARA GERENCIAR O CRONOMETRO E OS DADOS


//-----------TIME TEMPO(RELOGIO) FUNÇÕES//-----------

void metrica_start_fun(metricas_t *status)
{
    status->cpu_inicio = clock();
    status->relogio_inicio = time(NULL);

    return;
}
void metrica_fim_fun(metricas_t *status)
{
    status->cpu_fim     = clock();
    status->relogio_fim = time(NULL);

    // CALCULO PARA RESULTADO
    status->cpu_tempo_ms = (double) (status->cpu_fim - status->cpu_inicio) / CLOCKS_PER_SEC;
    status->relogio_seg = (status->relogio_fim - status->relogio_inicio);
}


// SOMAR METRICAS
void metrica_comparacoes_fun(metricas_t *status, int valor_aumentar)
{
    status->comparacoes = status->comparacoes  + valor_aumentar;
    return;
}
void metrica_trocas_fun(metricas_t *status, int valor_aumentar)
{
    status->trocas = status->trocas  + valor_aumentar;
    return;
}
void metrica_copias_fun(metricas_t *status, int valor_aumentar)
{
    status->copias = status->copias  + valor_aumentar;
    return;
}
void metrica_pilha_fun(metricas_t *status, int valor_aumentar)
{
    status->pilha = status->pilha  + valor_aumentar;
    return;
}


// inicializadores designados
#define NEW_METRICAS { \
    .cpu_inicio = 0, \
    .cpu_fim = 0, \
    .cpu_tempo_ms = 0.0, \
    .relogio_inicio = 0, \
    .relogio_fim = 0, \
    .relogio_seg = 0, \
    .comparacoes = 0, \
    .trocas = 0, \
    .copias = 0, \
    .pilha = 0, \
    .metrica_start = metrica_start_fun, \
    .metrica_fim = metrica_fim_fun, \
    .metrica_comparacoes = metrica_comparacoes_fun, \
    .metrica_trocas = metrica_trocas_fun, \
    .metrica_copias = metrica_copias_fun, \
    .metrica_pilha = metrica_pilha_fun \
}
#endif