#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define QUANTIDADE_DE_VARIAVEIS 200
#define TAMANHO_DE_VARIAVEIS 200

typedef int quantidade;
typedef bool true_ou_false;
typedef int posicao;

int main(void)
{
    char variaveis[QUANTIDADE_DE_VARIAVEIS][TAMANHO_DE_VARIAVEIS];
    

    quantidade prenchido = 0;
    true_ou_false controle = true;
    posicao numero = 0;


    while (controle)
    {
        scanf("%s", variaveis[numero]);
        if (strcmp(variaveis[numero], "!!")== 0)
        {
            break;
        }
        prenchido++;
        numero++;
    }
    
}