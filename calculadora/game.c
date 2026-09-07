#include <stdio.h>
#include <stdlib.h>  // malloc end realloc
#include <string.h>  // strlen
#include <ctype.h>   // verificadores
#include <stdbool.h> // true or false

typedef struct type_text
{
    char *op;
    double *number;

    // -----METADORES-------------
    struct type_text *inicio;
    struct type_text *esquerda;
    struct type_text *direita;
    
} type_text;

int main(void)
{
    type_text *usuario = NULL;
    int caractere_digitado = 0; // vaeriavel de ajuda
    int novo_numero = 0;
    double acumular = 0;
    bool tem_numero = false; // flag

    while ((caractere_digitado = getchar()) != '\n' && caractere_digitado != EOF) // get usuario promt text
    {
        if (isdigit(caractere_digitado) != 0) // and NUMBERS
        {
            int novo_numero = (caractere_digitado - '0'); // The number zero is worth 48. || tabela ascii.

            acumular = (acumular * 10) + novo_numero;
            tem_numero = true; // flag false
        }

        else if (caractere_digitado == '+' || caractere_digitado == '-' || // OPERACION
                 caractere_digitado == '*' || caractere_digitado == '/' ||
                 caractere_digitado == '(' || caractere_digitado == ')')
        {
            tem_numero = false;
        }

        else if (isalpha(caractere_digitado) != 0 || caractere_digitado == ' ')
        {
            continue;
        }

        // AND OPERATOR

        if (!tem_numero)
        {
            type_text *tmp = malloc(sizeof(type_text));
            if (tmp == NULL)
                return 1;

            tmp->number = malloc(sizeof(double));
            tmp->op = malloc(sizeof(char));
            if (tmp->number == NULL || tmp->op == NULL)
                return 1;

            if (usuario == NULL)
            {
                // ADDING NODE LINKS
                tmp->inicio   = tmp;
                tmp->direita  = NULL;
                
                // Cria a caixinha da esquerda para guardar o 5
                tmp->esquerda = malloc(sizeof(type_text));
                tmp->esquerda->number = malloc(sizeof(double));
                tmp->esquerda->esquerda = NULL; 
                
                usuario = tmp;

                // clear
                *tmp->esquerda->number = acumular; // O 5 vai pra esquerda
                *tmp->op = caractere_digitado;     //  '+' save
                acumular = 0;
            }
            else
            {
                tmp->inicio      = usuario->inicio; // <-- ESSA LINHA SALVA O 5 + 5 * 2
                tmp->direita     = NULL; 
                tmp->esquerda    = usuario;
                usuario->direita = tmp; 
                usuario          = tmp; 

                // ASSIGNING NODE NUMBERS
                *tmp->op = caractere_digitado;     

                if(tmp->esquerda != NULL && tmp->esquerda->number != NULL)
                {
                    *tmp->esquerda->number = acumular;
                }

                acumular = 0;
            }
        }
    }
    if (acumular != 0 && usuario != NULL)
    {
        type_text *no_fim = malloc(sizeof(type_text));
        no_fim->number = malloc(sizeof(double));
        no_fim->op = NULL;
        
        *no_fim->number = acumular;
        no_fim->direita = NULL;
        no_fim->esquerda = usuario;
        
        usuario->direita = no_fim;
        acumular = 0;
    }

    double valor_esquerda;
    double valor_direita;
    double resultado;
    bool ZeroDivisionError = false;
    // -------------------------------------------------------------
    // 1: Multiplicação e Divisão
    // -------------------------------------------------------------
    type_text *atual = usuario->inicio;
    while (atual != NULL)
    {

        if (atual->op != NULL)
        {
            valor_esquerda = 0;
            valor_direita = 0;

            if (*atual->op == '*' || *atual->op == '/')
            {

                if (*atual->op == '*')
                {
                    valor_esquerda = *atual->esquerda->number;
                    if (atual->direita != NULL && atual->direita->number != NULL)
                    {
                        valor_direita = *atual->direita->number;
                    }
                    resultado = valor_esquerda * valor_direita;
                }

                if (*atual->op == '/')
                {
                    valor_esquerda = *atual->esquerda->number;
                    if (atual->direita != NULL && atual->direita->number != NULL)
                    {
                        valor_direita = *atual->direita->number;
                    }
                    if (valor_direita == 0)
                    {
                        printf("ZeroDivisionError\n");
                        break;
                    }
                    resultado = valor_esquerda / valor_direita;
                }
                // Reconnect the links after the result.
                // update the node!

                if (atual->esquerda != NULL && atual->direita != NULL)
                {

                    *atual->number = resultado; // update number
                    resultado = 0;
                    atual->op = NULL;           // update operator

                    // ESQUERDA
                    if(atual->esquerda != NULL)
                    {
                        type_text *no_for_deletion = atual->esquerda;
                        if (atual->esquerda->esquerda != NULL)
                        {
                            atual->esquerda->esquerda->direita = atual;
                            atual->esquerda = no_for_deletion->esquerda;
                        }
                        else
                        {
                            usuario->inicio = atual;
                            atual->esquerda = NULL;
                        }
                        free(no_for_deletion);
                    }
                    // DIREITA
                    if (atual->direita !=NULL)
                    {
                      type_text *no_for_deletion = atual->direita;
                       if (atual->direita->direita != NULL)
                       {
                           // Caso normal: tem mais nós para frente
                            atual->direita = no_for_deletion->direita;
                           atual->direita->esquerda = atual;
                        }
                        else
                        {
                            atual->direita = NULL;
                        }
                        free(no_for_deletion);
                    }
                }
            }
        }
        atual = atual->direita;
    }


    type_text *operation_comum = usuario->inicio;
    while (operation_comum != NULL)
    {
        if (operation_comum->op != NULL)
        {
            valor_esquerda = 0;
            valor_direita = 0;

            if (*operation_comum->op == '+' || *operation_comum->op == '-')
            {
                if (*operation_comum->op == '+')
                {
                    valor_esquerda = *operation_comum->esquerda->number;

                    if (operation_comum->direita != NULL)
                    {
                        valor_direita = *operation_comum->direita->number;
                    }
                    resultado = valor_esquerda + valor_direita;
                }
                if (*operation_comum->op == '-')
                {
                    valor_esquerda = *operation_comum->esquerda->number;

                    if (operation_comum->direita != NULL)
                    {
                        valor_direita = *operation_comum->direita->number;
                    }
                    resultado = valor_esquerda - valor_direita;
                }

                *operation_comum->number = resultado;
                resultado = 0; // Zera para a próxima conta
                operation_comum->op      = NULL;
               
                if (operation_comum->esquerda != NULL)
                {
                    type_text *no_for_deletion = operation_comum->esquerda;
                    if (operation_comum->esquerda->esquerda != NULL) 
                    {
                        no_for_deletion->esquerda->direita = operation_comum;
                        operation_comum->esquerda = no_for_deletion->esquerda;
                    }
                    else
                    {
                        usuario->inicio = operation_comum;
                        operation_comum->esquerda = NULL;
                    }
                    free(no_for_deletion);         
                }
                if (operation_comum->direita != NULL)
                {
                    type_text *no_for_deletion = operation_comum->direita;
                    if (operation_comum->direita->direita  != NULL) 
                    {
                        no_for_deletion->direita->esquerda = operation_comum;
                        operation_comum->direita = no_for_deletion->direita;
                    }
                    else
                    {
                        operation_comum->direita = NULL;
                    }
                    free(no_for_deletion);
                }
                
            }
        }
        operation_comum = operation_comum->direita;
    }
   
    if (usuario->inicio != NULL && usuario->inicio->number != NULL)
    {
        printf("resultado = %.1lf\n", *usuario->inicio->number);
    }

    return 0;
}