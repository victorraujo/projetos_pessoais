#include <stdio.h>
#include <stdlib.h>


void cstring(char **ptr, size_t *size)
{
    //~~~~~~TEMPORARY~~~~~~~~
    //----BUFFER || SIZE-----
    int buffer = 0;
    size_t tmp_size = 50;
    //------------------------

    char *tmp_ptr = malloc(tmp_size * sizeof(char));
    if (tmp_ptr == NULL)
    {
        return;
    }

    int caractere = 0; //number ascii

    while ((caractere = getchar()) != '\n' && caractere != EOF)
    {
        if (buffer + 1 >= tmp_size)
        {
            tmp_size = tmp_size + 50;
            tmp_ptr = realloc(tmp_ptr, tmp_size);
            if (tmp_ptr == NULL)
            {
                return;
            }
        }
        tmp_ptr[buffer] = caractere; // increment
        buffer++;                    // prox
    }
    tmp_ptr[buffer] = '\0';
    //----modifying variables----------
    *ptr = tmp_ptr; // ptr ofc
    *size = buffer;  // size ofc
    //----------------------------------
}


//  EXEMPLO USE
int main(void)
{
    // a função precisa disso
    char* string = NULL;
    size_t tamanho = 0;

    cstring(&string, &tamanho); // ponteiro, size_t

    if (string == NULL) return 1; // NOP NULL

    printf("\n%s\n", string);
    printf("tamanho: %d\n", tamanho);

    free(string);

    return 0;
}