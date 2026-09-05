#include <stdio.h>

int main(void) {
    char c;

    printf("Digite o texto/codigo: ");

    // O laço roda enquanto o caractere digitado nao for Enter ('\n') nem fim de arquivo (EOF)
    while ((c = getchar()) != '\n' && c != EOF) {
        printf("%c\n", c); // Imprime o caractere lido e pula para a proxima linha
    }

    return 0;
}