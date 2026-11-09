/*COMANDO INICIAIS DO TERMINAL PARA DIGITOS

Código	Ação
A	Sobe
B	Desce
C	Direita
D	Esquerda
H	Posiciona por coordenadas

----------------APAGAR-----------------------


Sequência	Função
\033[K	Apaga até o final da linha
\033[1K	Apaga do início da linha até o cursor
\033[2K	Apaga a linha inteira
\033[J	Apaga até o final da tela
\033[1J	Apaga do início da tela até o cursor
\033[2J	Apaga a tela inteira

-> obs: apagar não necessariamente e mover cursor. ele pode apagar e ficar na
        mesma posição.
---------------------------------------------

USAMOS |\033 para simbolizar que vamos digitar um comando
USAMOS | [ <- para simbolizar o inicio do comando
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    printf("PRIMEIRA LINHA");
    printf("\033[1B");
    printf("\nSEGUNDA LINHA");
    printf("\033[1B");
    printf("\nTERCEIRA LINHA");
    printf("\033[1B");

    printf("\033[1A");
    printf("\033[2K");

    


    return 0;
}
