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




int main(void)
{

    char* usuario = save_string()
}
