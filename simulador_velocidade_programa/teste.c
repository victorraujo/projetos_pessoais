// versão -> 0.3




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// ALGORITMOS
#include "includes/buscadores/buscador.h"
#include "includes/ordenadores/ordenador.h"
// ESTRUTURAS E INTERFACE USUARIO (TERMINAL)
#include "includes/estruturas/estrutura.h"
#include "includes/interface/interface.h"
// STATUS DO ALGORITMO EM TEMPO (ESPAÇO PARA SIMULAÇÃO)
#include "includes/metricas/metrica.h"
// NUMEROS ALEATÓRIOS
#include "gerador/gerador.h"


// ARRAY INICIAL TESTE
#define TESTE_ARRAY 50

int main(void)
{
    // start numeros aleatorio (semente)
    gerador_init();

    
    // criação do array
    array_t *array;
    
    array_start(&array, TESTE_ARRAY);
    // aleatorio numero
    const int size_array = array->tamanho;
    
    gerador_array(array, array->tamanho, 0, size_array);
    // temporizadores
    metricas_t statusAlgoritmo;

    // teste aqui
    metrica_start(&statusAlgoritmo);
    mergeSorting(array->dados, size_array);
    metrica_fim(&statusAlgoritmo);
    //---------------------

    //printf("tempo segundos:%lld\n", (long long) tempo_segundos);
    //printf("clock: %.10f\n", resultado_processador);
    interface_exibir_tutorial();

    while(true)
    {
        int entrada = 0;
        int correto = 0;
        do
        {
            printf("diga o tipo de busca.\n"
                "0 = sair\n"
                "1 = unitaria\n"
                "2 = binária\n");
            correto = scanf("%d", &entrada);
        } while(correto != 1);
        int numeroBuscar;
        int indice_encontrado = -1;
        puts("diga o numero a procurar:");
        scanf("%d", &numeroBuscar);

        // INICIO DO PROCURADOR CRONOMETRO
        time_t tempo_segundos_procurador_inicio = time(NULL);
        clock_t processador_procurador_inicio   = clock();
        
        // FIM
        time_t tempo_segundos_procurador_fim = 0;
        clock_t processador_procurador_fim   = 0;

        // TEMPO TOTAL
        time_t tempo_procurador_segundos_total = 0;
        double tempo_clock = 0;
        if(entrada == 0) { break; }

        if (entrada == 1)
        {
            indice_encontrado = busca_unitaria(numeroBuscar, array->dados, size_array);
        }
        else if(entrada == 2)
        {
            indice_encontrado = busca_binaria(numeroBuscar, array->dados, 0, size_array - 1);
        }

        // PEGAR O TEMPO AGORA
        tempo_segundos_procurador_fim = time(NULL);
        processador_procurador_fim    = clock();

        tempo_procurador_segundos_total = (tempo_segundos_procurador_fim - tempo_segundos_procurador_inicio);
        tempo_clock = (double) (processador_procurador_fim - processador_procurador_inicio) / CLOCKS_PER_SEC;

        printf("\ntempo em vida real: %lld\n", (long long) tempo_procurador_segundos_total);
        printf("\nclock time procurador: %.10f\n", tempo_clock);
        printf("\n\n\n");

        if (indice_encontrado == -1)
        {
            printf("não foi possivel encontrar. tente novamente\n");
        }

        printf("\nindice encontrado: %d\n", indice_encontrado);
        printf("bloco %d -> [%d]\n", indice_encontrado, array->dados[indice_encontrado]);


    }
    return 0;
}