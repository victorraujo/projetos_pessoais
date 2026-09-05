#include <stdio.h>
#include <stdlib.h> // malloc end realloc
#include <string.h> // strlen
#include <ctype.h> // verificadores
#include <stdbool.h> // true or false


// SAVE STRING IN HEAP
// RETURN NULL OR ADDRESS
char* save_string(void)
{
    char text[50000];
    fgets(text, sizeof(text), stdin);

    size_t size = (text + 1);

    char* text_promt = malloc(size * sizeof(char));
    
    if (text_promt ==  NULL) return NULL;

    return text_promt;
}


typedef struct type_text
{
    char *op;
    int *number;
    
 // metadores
    type_text *inicio;
    type_text *esquerda;
    type_text *direita;
} type_text;



int main(void)
{
    type_text* usuario = NULL;

    int caractere_digitado = 0; // vaeriavel de ajuda
    while ((caractere_digitado = getchar()) !='\n' && caractere_digitado != EOF)
    {
        type_text* tmp = malloc(sizeof(type_text));
        if (tmp == NULL) return 1;

        if (isdigit(caractere_digitado) != 0) // NUMBERS
        {
            tmp->number = malloc(sizeof(caractere_digitado));
            if (tmp->number == NULL) return 1;
   
            *tmp->number = (caractere_digitado - '0'); //The number zero is worth 48.
            tmp->op == NULL;
        }

        else if (caractere_digitado == '+' || caractere_digitado == '-' || // OPERACION
            caractere_digitado == '*' || caractere_digitado == '/' || 
            caractere_digitado == '(' || caractere_digitado == ')') 
        {
            tmp->op = malloc(sizeof(char));
            if (tmp->op) return 1;

            *tmp->op = caractere_digitado;
            tmp->number == NULL;
        }

        else if(isalpha(caractere_digitado) != 0 || caractere_digitado == ' ')
        {
            free(tmp);
            continue;
        }
        

        if (usuario == NULL)
        {
            tmp->inicio = tmp;
            tmp->direita = tmp;
            tmp->direita->direita = NULL;
            tmp->esquerda = NULL;
            usuario = tmp;
        }
        else
        {  
            tmp->direita = NULL;  // entra dentro do nov e deixa como terminador null      
            usuario->esquerda = usuario; // salva o de tras    
            usuario->direita = tmp; // aponta pro novo
            usuario = tmp;
        }

}
