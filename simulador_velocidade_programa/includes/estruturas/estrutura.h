#ifndef ESTRUTURA_H
#define ESTRUTURA_H


// proxima upd -> mover as estruturas e funçoes para -> metricas
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct 
{
    time_t inicio;
    time_t fim;
    double tempo_total;
} tempo_relogio_t;


// Para medir tempo de processamento/CPU (em milissegundos)
typedef struct
{
    clock_t inicio;
    clock_t fim;
    double tempo_total;
} tempo_clock_t; 

typedef struct
{
    int *dados;
    int tamanho;
    
    //void(*ordenador)(int*, int);           // ponteiro para ordenador
    //int*(*buscador)(int*, int, int);       // ponteiro para buscador

} array_t;



// 3. PROTÓTIPOS DAS FUNÇÕES QUE USAM ESSAS STRUCTS


//-----------CLOCK FUNÇÕES//-----------

// iniciar = iniciar a contagem
// sintaxe: iniciar_clock(&variavel);
void iniciar_clock(tempo_clock_t *c)
{
    c->inicio = clock();
    return;
}
// parar = parar a contagem e atribuir
// sintaxe: parar_clock(&variavel);
void parar_clock(tempo_clock_t *c)
{
    c->fim;
    c->tempo_total = (c->fim - c->inicio) / CLOCKS_PER_SEC;
    return;
}
// exibir na tela usando printf
// sintaxe: exibir_resultado_clock(variavel);
void exibir_resultado_clock(tempo_clock_t c)
{
    printf("%.10d", c.tempo_total);
    return;
}

//-----------TIME TEMPO(RELOGIO) FUNÇÕES//-----------

// iniciar = iniciar a contagem
// sintaxe: iniciar_tempo(&variavel);
void iniciar_tempo(tempo_relogio_t *t)
{
    t->inicio = time(NULL);
}
// parar = parar a contagem
// sintaxe: parar_tempo(&variavel)
void parar_tempo(tempo_relogio_t *t)
{
    t->fim;
    t->tempo_total = t->fim - t->inicio;
    return;
}

// exibir na tela usando printf
// sintaxe: exibir_temo(variavel);
void exibir_resultado_tempo(tempo_relogio_t t)
{
    printf("%lld", (long long) t.tempo_total);
    return;
}

/*-----------ARRAY (ESTRUTURA) FUNÇÕES//-----------

---------VERSÃO------------

-> update 0.2 - > bug de não trocar o ponteiro em main resolvido.

---------O QUE FAZ----------
-> Já organiza a estrutura do array com todos os elemento sendo 0 e
   com tamanho tudo prontinho para utilizar a estrutura ("array_t").

---------SINTAXE------------

-> sintaxe: iniciar_array(&ptr, tamanho);

---------NOVIDADES------------
 -> estrutura na heap
 -> array na heap
 -----------------------------
 */
void iniciar_array(array_t **ptr, int tamanho)
{
    // CRIAÇÃO DA ESTRUTURA E ORGANIZAÇÃO
    *ptr = NULL;
    *ptr = malloc(sizeof(array_t));

    // SEGURANÇA 2 (ponteiro)
    if ((*ptr) == NULL) { return; }

    (*ptr)->dados = malloc(tamanho * sizeof((*ptr)->dados));

    // SEGURANÇA 2 (dados)
    if ((*ptr)->dados == NULL) 
    { 
        free((*ptr));
        (*ptr) = NULL; 
        return;
    }

    // ATRIBUINDO VALORES
    (*ptr)->tamanho = tamanho;
    // LIMPEZA ARRAY (TUDO PARA 0)
    memset((*ptr)->dados, 0, tamanho * sizeof(int));
    return;
}
#endif;