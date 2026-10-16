#include <stdio.h>
#include <stdbool.h>

void merge(int *arraya, int inicio, int meio, int fim);
void merge_sorting(int *arraya, int inicio, int fim);


int main(void)
{
    int arraya[] = {2, 4, 5, 9, 3, 6, 7};
    int tamanho = sizeof(arraya) / sizeof(arraya[0]);
   
    merge_sorting(arraya, 0, tamanho - 1);
}

void merge(int *arraya, int tamanho, int inicio, int fim)
{
   
}
void merge_sorting(int *arraya, int inicio, int fim)
{
    if (inicio >= fim)
    {
        return;
    }

    int meio = inicio + (fim - inicio) / 2;

    // Dividir a metade esquerda
    merge

    // Dividir a metade direita

    // Juntar as duas metades
}

