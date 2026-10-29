// upgrade por vim...




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// ALGORITMOS
#include "includes/buscadores/buscador.h"
#include "includes/ordenadores/ordenador.h"
// ESTRUTURAS
#include "estruturas/estrutura.h"

int main(void)
{
    srand(time(NULL));

    

    array_t *arraya;

    iniciar_array(array, 50);
    for (int i = 0; i < t; i++) 
    {
        arraya[i] = rand() % t;
    }
    
    // temporizadores
    time_t inicio = time(NULL);
    clock_t processador_inicio = clock();

    // teste aqui
    mergeSorting(arraya, t);
    //---------------------

    // fim dos temporizadores
    time_t fim = time(NULL);
    time_t tempo_segundos = fim - inicio;

    clock_t processador_fim = clock();
    double resultado_processador = (double) (processador_fim - processador_inicio) / CLOCKS_PER_SEC;

    printf("tempo segundos:%lld\n", (long long) tempo_segundos);
    printf("clock: %.10f\n", resultado_processador);

    for (int i = 0; i < t; i++)
    {
        printf("bloco %d: [%d]\n", i, arraya[i]);
    }

    puts("");
    puts("");

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
            indice_encontrado = busca_unitaria(numeroBuscar, arraya, t);
        }
        else if(entrada == 2)
        {
            indice_encontrado = busca_binaria(numeroBuscar, arraya, 0, t - 1);
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
        printf("bloco %d -> [%d]\n", indice_encontrado, arraya[indice_encontrado]);


    }
    return 0;
}