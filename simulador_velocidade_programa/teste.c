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
    const int size_array = array->tamanho;
    gerador_array(array, array->tamanho, 0, size_array);

    // TRATAMENTO USUARIO
    usuario_t usuario;
    usuario_git(&usuario);

    // temporizadores
    metricas_t statusAlgoritmo;
    //---------------------

    //printf("tempo segundos:%lld\n", (long long) tempo_segundos);
    //printf("clock: %.10f\n", resultado_processador);


    interface_exibir_tutorial(); // tutorial
    interface_limpar_tela();     // clear
    while(true)
    {
        usuario.ordenadores = interface_menu_ordenadores();
        if(usuario.ordenadores <= 0) { break; }


    }
    return 0;
}