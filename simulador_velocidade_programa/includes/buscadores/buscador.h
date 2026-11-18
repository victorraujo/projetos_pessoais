#ifndef BUSCADOR_H
#define BUSCADOR_H

#include <stdio.h>
typedef struct
{
    // Dados da busca
    int alvo;
    int indice_encontrado;
    int tamanho;

    // Ponteiros para funções
    int (*busca_linear)(int, int[], int);
    int (*busca_binaria)(int, int[], int);

} buscador_t;
//-------------------BUSCA POR COMPARAÇÕES(simples e lento)-------------------
int busca_linear(int numero_buscar, int array[], int tamanho)
{
    for (int busca_atual = 0; busca_atual < tamanho - 1; busca_atual++)
    {
        if (array[busca_atual] == numero_buscar)
        {
            return busca_atual;
        }
    }
    return -1;
}
//-------------------BUSCA QUEBRANDO AO MEIO(MUITO RAPIDO)-------------------
int busca_binaria(int numero_buscar, int array[], int inicio, int fim)
{
   if (inicio > fim)
   {
        return -1;
   }

   int meio = (inicio + fim) / 2;

   if (numero_buscar == array[meio])
   {
        return meio;
   }
   if (numero_buscar < array[meio])
   {
        return busca_binaria(numero_buscar, array, inicio, meio - 1);
   }

   if (numero_buscar > array[meio])
   {
        return busca_binaria(numero_buscar, array, meio + 1, fim);
   }
}
int wrapper_busca_linear(int numero_buscar, int array[], int tamanho)
{
     return busca_linear(numero_buscar, array, tamanho);
}
int wrapper_busca_binaria(int numero_buscar, int array[], int tamanho)
{
     return busca_binaria(numero_buscar, array, 0, tamanho - 1);
}


#define NEW_BUSCADOR { \
    .alvo = 0, \
    .indice_encontrado = -1, \
    .tamanho = 0, \
    .busca_linear = wrapper_busca_linear, \
    .busca_binaria = wrapper_busca_binaria \
}
#endif