#ifndef ESTRUTURA_H
#define ESTRUTURA_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct 
{
    time_t inicio;
    time_t fim;
    double tempo_total;
} tempo_relogio;


// Para medir tempo de processamento/CPU (em milissegundos)
typedef struct
{
    clock_t inicio;
    clock_t fim;
    double tempo_total;
} tempo_clock; 

typedef struct
{
    int *array;
    int tamanho;
    
    void(*ordenador)(int*, int);           // ponteiro para ordenador
    int*(*buscador)(int*, int, int);       // ponteiro para buscador

} array_estrutura;



// 3. PROTÓTIPOS DAS FUNÇÕES QUE USAM ESSAS STRUCTS


//-----------CLOCK FUNÇÕES//-----------

// iniciar = iniciar a contagem
// sintaxe: iniciar_clock(&variavel);
void iniciar_clock(tempo_clock *c)
{
    c->inicio = clock();
    return;
}
// parar = parar a contagem e atribuir
// sintaxe: parar_clock(&variavel);
void parar_clock(tempo_clock *c)
{
    c->fim;
    c->tempo_total = (c->fim - c->inicio) / CLOCKS_PER_SEC;
    return;
}
// exibir na tela usando printf
// sintaxe: exibir_resultado_clock(variavel);
void exibir_resultado_clock(tempo_clock c)
{
    printf("%.10d", c.tempo_total);
    return;
}

//-----------TIME TEMPO(RELOGIO) FUNÇÕES//-----------

// iniciar = iniciar a contagem
// sintaxe: iniciar_tempo(&variavel);
void iniciar_tempo(tempo_relogio *t)
{
    t->inicio = time(NULL);
}
// parar = parar a contagem
// sintaxe: parar_tempo(&variavel)
void parar_tempo(tempo_relogio *t)
{
    t->fim;
    t->tempo_total = t->fim - t->inicio;
    return;
}

// exibir na tela usando printf
// sintaxe: exibir_temo(variavel);
void exibir_resultado_tempo(tempo_relogio t)
{
    printf("%lld", (long long) t.tempo_total);
    return;
}
#endif;