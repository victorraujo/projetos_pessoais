/*
==========================================
          ANOTAÇÕES DO PROJETO
==========================================
 
  Autor:   Victor Rafael Dantas de Araújo
  Data:     09/09/2026
 
  Descrição:
    Função que retorna uma string dinamica conforme o usuario escreve.
    ela pode modifica sua variavel guardando um texto ou caso
    fique sem memoria ela ira retornar o text que estava montando,
     então certifique de usar NULL nas variaveis antes.
    e verificar se veio diferente de NULL por segunraça caso vá utilizar.

    SINTAXE CHAMADA:
    cstring(char &ptr, size_t &size)

    SINTAXE POR DENTRO:
    cstring(char **ptr, size_t *size)

    MEXE NAS VARIAVEIS:
    tenta alocar um ponteiro pra ptr e retorna o tamanho dela em size.

    OBS
    ela não possui quebra de linha no final.
   
  Anotações importantes:
    - strings dinamicas
    - inspiração = getline
    - inspiração = fgets

==========================================
*/




#include <stdio.h>
#include <stdlib.h>


void cstring(char **ptr, size_t *size)
{

    size_t size_tmp = 50;
    *ptr = malloc(size_tmp * sizeof(char)); // memoria de recomeço
    
    if(*ptr == NULL)
    {
        return;
    }
    int text = 0; // text atual


    while ((text = getchar()) != '\n' && text != EOF)
    {
        
        if (*size + 1 >= size_tmp)
        {
            size_tmp =  size_tmp + 50;
            char* tmp = realloc(*ptr, size_tmp);
            if (tmp == NULL) 
            {
                return; // segurança
            }
            else
            {
                *ptr = tmp;
            }
        }
        (*ptr)[*size] = text;
        (*size)++;
    }
    (*ptr)[*size] = '\0';
}


// EXEMPLO

int main(void)
{
    // a função precisa disso
    char* string = NULL;
    size_t tamanho = 0;

    cstring(&string, &tamanho); // ponteiro, size_t

    printf("\n%s\n", string);
    printf("tamanho: %d\n", tamanho);


}