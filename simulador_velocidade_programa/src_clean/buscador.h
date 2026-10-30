#ifndef BUSCADOR_H
#define BUSCADOR_H

#include <stdio.h>
//-------------------BUSCA POR COMPARAÇÕES(simples e lento)-------------------
int busca_unitaria(int numero_buscar, int *arraya, int tamanho)
{
    for (int busca_atual = 0; busca_atual < tamanho - 1; busca_atual++)
    {
        if (arraya[busca_atual] == numero_buscar)
        {
            return busca_atual;
        }
    }
    return -1;
}
//-------------------BUSCA QUEBRANDO AO MEIO(MUITO RAPIDO)-------------------
int busca_binaria(int numero_buscar, int *arraya, int inicio, int fim)
{
   if (inicio > fim)
   {
        return -1;
   }

   int meio = (inicio + fim) / 2;

   if (numero_buscar == arraya[meio])
   {
        return meio;
   }
   if (numero_buscar < arraya[meio])
   {
        return busca_binaria(numero_buscar, arraya, inicio, meio - 1);
   }

   if (numero_buscar > arraya[meio])
   {
        return busca_binaria(numero_buscar, arraya, meio + 1, fim);
   }
}

#endif