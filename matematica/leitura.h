#ifndef LEITURA_H
#define LEITURA_H

#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"



//------------------INPUT FERRAMENTA------------------

typedef struct string_t
{
    char *str;
    size_t size;

    void(*input)(string_t*);
}string_t;

//------------------DESIGNATED INITIALIZERS------------------
#define NEW_STRING     \
{                       \
    .input = input_fun,  \
    .string = NULL,       \
    .size = 0              \
}

void input_fun(string_t *string)
{  
    if (string->str != NULL)
    {
        free(string->str);
    }
}

#endif