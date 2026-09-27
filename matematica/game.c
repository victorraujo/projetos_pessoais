// interpreter de expressao

#include <stdlib.h>  // malloc end realloc
#include <ctype.h>   // verificadores
#include <stdbool.h> // verdadeiro ou falso
#include <stdio.h>

typedef struct Tipo
{
    double* numero; // convertor de numero
    char*   caractere;

    struct Tipo* direita;
    struct Tipo* esquerda;
} Tipo;

typedef struct  usuario
{
    void* aponta;

    struct usuario* direita;
    struct usuario* esquerda;
} Usuario; 


int main(void)
{

    Tipo* lista_comeco_tipo = NULL;
    Tipo* expressao;

    char* prompt_texto == NULL;
    size_t buffer = 0;

    getline(&prompt_texto, &buffer, stdin);

    if (prompt_texto == NULL) { return 1; };
    
    int percorrerString = 0;
    while (percorrerString < buffer) // get usuario promt text
    {
        if (tmp_expressao == NULL) { return 1; };

        if (isdigit(caractere_atual) != 0)
        {
            
        }
    }
}


