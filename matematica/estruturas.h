#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

//------------------ESTRUTURA DE APELIDOS DE NUMERO------------------
typedef enum {
    TOKEN_NUMERO,
    TOKEN_OPERADOR
} tipo_token_t;
//--------------------------------------------------------------------

//------------------ESTRUTURA DE LISTA ENCADEADAS DE CAD PEDAÇO DA EXPRESÃO------------------
typedef struct token_t
{
    tipo_token_t  type_dado; // 1 = número, 0 = operador
    union // unir bytes
    {
        /* data */
        double numero;
        int operador;
    }dado;

    struct token_t *esq;
    struct token_t *dir;
    
} token_t;

typedef struct
{
    // inicio 
    token_t *raiz; // Ponteiro para o início da árvore

    // SUAS FUNÇÕES (OPERAÇÕES)
    void(*soma)(token_t*);
    void(*subtracao)(token_t*);
    void(*multiplicacao)(token_t*);
    void(*divisao)(token_t*);

}expressao_t;


//------------------DESIGNATED INITIALIZERS------------------
#define NEW_EXPRESSAO    \
{                         \
    .raiz          = NULL, \
    .soma          = NULL,  \
    .subtracao     = NULL,   \
    .multiplicacao = NULL,    \
    .divisao       = NULL      \
}

#endif