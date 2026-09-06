#include <stdio.h>
#include <stdlib.h> // malloc end realloc
#include <string.h> // strlen
#include <ctype.h> // verificadores
#include <stdbool.h> // true or false

typedef struct type_text
{
    char *op;
    double *number;
    
 // metadores
    struct type_text *inicio;
    struct type_text *esquerda;
    struct type_text *direita;
} type_text;

int main(void)
{
    type_text* usuario = NULL;
     int caractere_digitado = 0; // vaeriavel de ajuda
     int novo_numero        = 0;
     double acumular        = 0;
     bool tem_numero        = false; // flag


    while ((caractere_digitado = getchar()) !='\n' && caractere_digitado != EOF)
    {
        if (isdigit(caractere_digitado) != 0) // NUMBERS
        {
            int novo_numero = (caractere_digitado - '0'); //The number zero is worth 48.
                
            acumular   = (acumular * 10) + novo_numero;
            tem_numero = true;
                
        }

        else if (caractere_digitado == '+' || caractere_digitado == '-' || // OPERACION
            caractere_digitado == '*' || caractere_digitado == '/' || 
            caractere_digitado == '(' || caractere_digitado == ')') 
        {
            tem_numero = false;
            

            tmp->op = malloc(sizeof(char));
            if (tmp->op == NULL) return 1;

            *tmp->op    = caractere_digitado;
            tmp->number = NULL;
            
        }

        else if(isalpha(caractere_digitado) != 0 || caractere_digitado == ' ')
        {
            continue;
        }

        if (!tem_numero)
        {
            type_text* tmp = malloc(sizeof(type_text));
            if (tmp == NULL) return 1;

            tmp->number = malloc(sizeof(double));
            tmp->op     = malloc(sizeof(char));

            if (tmp->number == NULL && tmp->op == NULL) return 1;

            tmp->number = acumular;
            acumular    = 0;

            tmp->op = caractere_digitado; 
            
            
        }
        if (!tem_numero)
        {
            if (usuario == NULL)
            {
                tmp->inicio   = tmp;
                tmp->direita  = NULL;
                tmp->direita  = NULL;
                tmp->esquerda = NULL;
                usuario = tmp;
            }
            else
            {  
                tmp->direita     = NULL;  // entra dentro do nó e deixa como terminador null      
                tmp->esquerda    = usuario; // salva o de tras    
                usuario->direita = tmp; // apontar pro novo
                usuario          = tmp;
            }
        } 
    }
    type_text *sensor  = usuario->inicio;
    type_text*start_op = NULL;
    double valor_esquerda;
    double valor_direta;
    double resultado;


    while(sensor != NULL)
    {
        if(sensor != NULL && sensor->op == '*' || sensor->op == '/')
        {
            type_text *inicio_op = sensor;
            while(inicio_op->op == NULL)
            {
                
                inicio_op->direita;
            }
        }
    }
}