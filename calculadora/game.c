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
    char text;
    
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

        tmp->text = caractere_digitado;
        

        if (usuario == NULL)
        {
            tmp->inicio = tmp;
            tmp->direita = tmp;
            tmp->esquerda = NULL;
            usuario = tmp;
        }
        else
        {
            usuario->direita = tmp;
            usuario = tmp;    
        }


        
    }



}
