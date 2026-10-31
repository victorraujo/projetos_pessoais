#ifndef BUSCADOR_H
#define BUSCADOR_H

#include <stdio.h>


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

// 1. Define a "assinatura padrão" que toda função de ordenação vai ter na tabela
// literalmente um guia de via ponteiro
typedef int (*FuncaoBuscador)(int numero_buscar, int array[], int tamanho);

//-----------------------CRIAÇÃO PONTEIROS PARA FUNÇÕES-----------------------
// Criamos um vetor do tipo 'FuncaoOrdenacao' que guarda as nossas funções!
// Tabela guarda os endereços das funções de 3 parâmetros
// Declara e inicializa o vetor de funções logo de uma vez:

//  wrapper_busca_linear  = 1
//  wrapper_busca_binaria = 2
FuncaoBuscador meus_buscador[] = {
     wrapper_busca_linear,
     wrapper_busca_binaria
};

#endif