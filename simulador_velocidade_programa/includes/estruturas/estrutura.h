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
/*-----------ARRAY (ESTRUTURA) FUNÇÕES//-----------

---------VERSÃO------------

-> update 0.2 - > bug de não trocar o ponteiro em main resolvido.

---------O QUE FAZ----------
-> Já organiza a estrutura do array com todos os elemento sendo 0 e
   com tamanho tudo prontinho para utilizar a estrutura ("array_t").

---------SINTAXE------------

-> sintaxe: array_start(&ptr, tamanho);

---------NOVIDADES------------
 -> estrutura na heap
 -> array na heap
 -----------------------------
 */
void array_start(array_t **ptr, int tamanho)
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