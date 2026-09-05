#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>
#include <stdlib.h>

#define QUANTIDADE_DE_VARIAVEIS 200
#define TAMANHO_DE_VARIAVEIS 200

bool apenas_numero(entrada)
{
    if(strlen(entrada) == 0) return false;
}
int main(void)
{
    char entrada[QUANTIDADE_DE_VARIAVEIS][TAMANHO_DE_VARIAVEIS];
    int prenchido = 0;
    bool controle = true;
    int  posicao = 0;

    printf("Digite um numero (ou '!!' para sair): ");
    while (controle)
    {
        for (int i = 0, n = strlen(entrada[posicao]); i < n; i++)
        {

        }
        scanf("%s", entrada[posicao]);
    }
    
}