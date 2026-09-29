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

    char* percorrer_string = prompt_texto;
    char* proxima_parte    = NULL;
    double valor_token     = 0;
    while(percorrer_string != NULL)
    {
        // strtod transforma em numero e diz onde foi a quebra de linha e ainda envia o local!!
        
        valor_token = strtod(percorrer_string, &proxima_parte);       
        if (*proxima_parte == '\0')  { break; }

        if (expressao == NULL)
        {
            Tipo* tmp_expressao   = malloc(sizeof(Tipo));
            tmp_expressao->numero = malloc(sizeof(Tipo));
            if (tmp_expressao == NULL) { return 1; }

            // NÓS
            tmp_expressao->esquerda = NULL;
            tmp_expressao->direita  = NULL;
            expressao_inicio = tmp_expressao; // salvar o primeiro nó

            // atribuição das informações
            tmp_expressao->token  = NULL;
            tmp_expressao->numero = valor_token;

            expressao = tmp_expressao;


            // para os caracteres (/, +, -, ) e ligar com o proximo proximo nó com numero
            // considere tmp_expressao agora apenas 'expressao'

            Tipo* tmp_tmp_expressao  = malloc(sizeof(Tipo));
            tmp_tmp_expressao->token = malloc(sizeof(char));
            if (tmp_tmp_expressao == NULL || tmp_tmp_expressao == NULL) { return 1; }

            tmp_tmp_expressao->token = *proxima_parte[0]; // adicionar o conteúdo do caractere especial(quebra da expressao)
            tmp_tmp_expressao->numero = NULL;

            tmp_tmp_expressao->esquerda = expressao;
            tmp_tmp_expressao->direita  = NULL;


            expressao->direita = tmp_tmp_expressao; 
            expressao = tmp_tmp_expressao; // a expressao agora está no caractere especial

            // fim
        }
        else
        {
            Tipo* tmp_expressao   = malloc(sizeof(Tipo));
            tmp_expressao->numero = malloc(sizeof(Tipo));


        }



    }
}


