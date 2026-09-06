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
        }

        else if(isalpha(caractere_digitado) != 0 || caractere_digitado == ' ')
        {
            continue;
        }
        
        // eh operador

        if (!tem_numero)
        {
            type_text* tmp = malloc(sizeof(type_text));  // ajeitar || escopo
            if (tmp == NULL) return 1;
            
            
            tmp->number = malloc(sizeof(double));
            tmp->op     = malloc(sizeof(char));
            if (tmp->number == NULL || tmp->op == NULL) return 1;
            
            *tmp->number = 0;
            
            *tmp->op = caractere_digitado;
            *tmp->esquerda->number = acumular;
            acumular = 0;
            
            if (!tem_numero)
            {
                if (usuario == NULL)
                {
                    tmp->inicio   = tmp;
                    tmp->direita  = NULL;
                    tmp->direita  = NULL;
                    tmp->esquerda = NULL;
                    usuario       = tmp;
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
    }
    
    double valor_esquerda;
    double valor_direita;
    double resultado;
    
    
    for(type_text* atual = usuario->inicio; atual != NULL; atual = atual->direita)
    {
        
        if (atual->op != NULL)
        {
            valor_esquerda = 0;
            valor_direita  = 0;
          
            if(atual->op == '*' || atual->op == '/')
            {
                
                if(atual->op == '*')
                {
                   valor_esquerda = *atual->esquerda->number;
                   if (atual->direita->op != NULL)
                   {
                       valor_direita = *atual->direita->number;
                   }
                   resultado = valor_esquerda * valor_direita;
                }
                if(atual->op == '/')
                {
                   valor_esquerda = *atual->esquerda->number;
                   if (atual->direita->op != NULL)
                   {
                       valor_direita = *atual->direita->number;
                   }
                }
            }
        }
    }
}