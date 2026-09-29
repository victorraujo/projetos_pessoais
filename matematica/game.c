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

Tipo* token_string(char* token_atual, char* proximo_token, double token_numero)
{
    Tipo* tmp_string = malloc(sizeof(Tipo));
    if (tmp_string == NULL) return 1;    
}
void converter_em_numero

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

    expressao = malloc(sizeof(Tipo));
    if (expressao == NULL) return 1;

    char* percorrer_string = prompt_texto;
    char* proxima_parte    = NULL;
    double valor_token     = 0;
    while(percorrer_string != NULL)
    {
        // strtod transforma em numero e diz onde foi a quebra de linha e ainda envia o local!!
        valor_token = strtod(percorrer_string, &proxima_parte);        
        // boleanas para quebra de expressão
        bool eh_simbolo_mutiplicacao = (*proxima_parte == '*' || toupper(*proxima_parte) == 'X');
        bool eh_simbolo_barra        = (*proxima_parte == '/');
        bool eh_simbolo_mais         = (*proxima_parte == '+');
        bool eh_simbolo_menos        = (*proxima_parte == '-');
        // caso alguma seja verdade
        if (eh_simbolo_mutiplicacao 
            || eh_simbolo_barra 
            || eh_simbolo_mais 
            || eh_simbolo_menos)
        {

        }
    }
}


