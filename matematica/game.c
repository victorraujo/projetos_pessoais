// interpreter de expressao

#include <stdlib.h>  // malloc end realloc
#include <ctype.h>   // verificadores
#include <stdbool.h> // verdadeiro ou falso
#include <stdio.h>

typedef struct Tipo
{
    double* numero;
    char* token;

    struct Tipo* direita;
    struct Tipo* esquerda;
} Tipo;

typedef struct  usuario
{
    void* aponta;

    struct usuario* direita;
    struct usuario* esquerda;
} Usuario; 

Tipo* token_string(Tipo* expressao, char* token_atual, int ate_token)
{
    Tipo* tmp_string = malloc(sizeof(Tipo));
    if (tmp_string == NULL) return 1;

    if (token == NULL)
    {
        tmp_string->esquerda = NULL;
        tmp_string->direita  = NULL;

        tmp_string->numero = 
    }

    
}

int main(void)
{

    Tipo* expressao_inicio = NULL;
    Tipo* expressao = NULL; 

    char* prompt_texto == NULL;
    size_t buffer = 0;

    getline(&prompt_texto, &buffer, stdin); // pedir expressão ao usuario
    if (prompt_texto == NULL)
    {
        return 1;
    }

    char *percorrer_string = *prompt_texto;
    while(percorrer_string != '\0')
    {

        // boleanas para quebra de expressão
        bool eh_simbolo_mutiplicacao = (percorrer_string == '*' || toupper(percorrer_string) == 'X');
        bool eh_simbolo_barra        = (percorrer_string == '/');
        bool eh_simbolo_mais         = (percorrer_string == '+');
        bool eh_simbolo_menos        = (percorrer_string == '-');
        // caso alguma seja verdade
        if (eh_simbolo_mutiplicacao 
            || eh_simbolo_barra 
            || eh_simbolo_mais 
            || eh_simbolo_menos)
            {
                expressao_inicio = token_string(expressao, percorrer_string, );
                
            }
        

    }
}


