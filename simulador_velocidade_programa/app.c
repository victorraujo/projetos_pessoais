// versão -> 0.5




#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
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
#include "includes/gerador/gerador.h"


// ARRAY INICIAL TESTE
#define TESTE_ARRAY 50
#define SAIR 0

int main(void)
{
    // start numeros aleatorio (semente)
    gerador_init();


    
    // criação do array
    array_t *array;
    array_start(&array, TESTE_ARRAY);
    const int size_array = array->tamanho;
    gerador_array(array->dados, array->tamanho, 0, size_array);

    // TRATAMENTO USUARIO


    // temporizadores
    metricas_t statusAlgoritmo;
    //---------------------

    //printf("tempo segundos:%lld\n", (long long) tempo_segundos);
    //printf("clock: %.10f\n", resultado_processador);

    // tutorial
    interface_exibir_tutorial(); // tutorial
    interface_limpar_tela();     // clear

    // iniciamento de navegacao
    navegacao_t navegacao;
    sessao_start(&navegacao);
    navegacao.estado_atual = ESTADO_MENU_PRINCIPAL;

    while(navegacao.estado_atual == ESTADO_MENU_PRINCIPAL)
    {
        navegacao.tipo_ordenador = interface_menu_ordenadores();

        meus_ordenadores[navegacao.tipo_ordenador -1](array->dados, array->tamanho);

        while (navegacao.estado_atual == ESTADO_MENU_SEGUNDARIO)
        {
            int buscador = interface_menu_buscadores();
            if (buscador <= SAIR) { break; }
            if (buscador == 3 ) 
            { 
                interface_organizacao_array(array->dados, array->tamanho); 
                continue; 
            }

            int chave = interface_pedir_chave_buscar();
            int local = meus_buscador[buscador - 1](chave, array->dados, array->tamanho);
        }

    }
    return 0;
}