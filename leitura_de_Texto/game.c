// colocar um texto em um arquivo e depois fazer esse arquivo aparecer na tela



#include <stdio.h>
#include <stdbool.h>
int main(void)
{
    FILE *input = fopen("texto.txt", "a");
    if (input == NULL)
    {
        return 1;
    }

    while (true)
    {
        char promt_text[100];
        scanf("%s", promt_text);
    }
}