#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    
}usuario_t;


// LIMPEZA DE TELA (WINDOWS E LINUX)
void interface_limpar_tela(void)
{
#ifdef _WIN32
    system("cls");  // No Windows
#else
    system("clear"); // No Linux / macOS
#endif
}
void interface_exibir_tutorial(void)
{
    printf("\n=========================================================\n");
    printf("   BEM-VINDO AO SIMULADOR DE DESEMPENHO DE ALGORITMOS   \n");
    printf("=========================================================\n");
    printf(" Este sistema analisa a eficiencia de algoritmos de     \n");
    printf(" ordenacao e busca medindo tempo de CPU, trocas e       \n");
    printf(" comparacoes de memoria em tempo real.                   \n");
    printf("---------------------------------------------------------\n");
    printf(" COMO USAR O SIMULADOR:\n\n");
    printf(" 1. GERAR VETOR  -> Crie um vetor com numeros aleatorios.\n");
    printf(" 2. ORDENAR      -> Rode Bubble, Merge, etc. e veja as\n");
    printf("                    metricas da ordenacao.\n");
    printf(" 3. BUSCAR       -> A Busca Linear funciona sempre.\n");
    printf("                    A Busca Binaria EXIGE o vetor ordenado!\n\n");
    printf(" Mostraremos sempre as metricas que sao:                 \n");
    printf("------------------- TEMPO -------------------------------\n");
    printf(" -> Tempo de CPU\n");
    printf(" -> Tempo de Relogio\n");
    printf("------------------- OPERACOES ---------------------------\n");
    printf(" -> Comparacoes\n");
    printf(" -> Trocas\n");
    printf(" -> Copias\n");
    printf(" -> Pilha (uso de memoria/recursao)\n");
    printf("---------------------------------------------------------\n");
    printf(" Pressione ENTER para iniciar o programa...");
    
    // Aguarda o usuário apertar a tecla ENTER para prosseguir
    getchar();
}
// Exibe o menu principal e retorna a opção escolhida pelo utilizador
int interface_menu_ordenadores(void)
{
    int opcao;
    printf("\n=========================================\n");
    printf("   SIMULADOR DE DESEMPENHO DE ALGORITMOS \n");
    printf("=========================================\n");
    printf("1. Bubble Sort\n");
    printf("2. Merge Sort\n");
    printf("0. Sair\n");
    printf("-----------------------------------------\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

// Menu 2A: Escolha do Algoritmo de Busca
int interface_menu_buscadores(void)
{
    int opcao;
    printf("\n--- ALGORITMOS DE BUSCA ---\n");
    printf("1. Busca Linear (Funciona em vetor desordenado)\n");
    printf("2. Busca Binaria (Requer vetor ordenado)\n");
    printf("0. Voltar\n");
    printf("---------------------------\n");
    printf("Escolha o tipo de busca: ");
    scanf("%d", &opcao);
    return opcao;
}

// Pergunta o valor a ser buscado
int interface_pedir_chave_busca(void)
{
    int opcao;
    int entrada;
    do
    {
        entrada = printf("\nDigite o numero que deseja buscar no vetor: ");
    scanf("%d", &opcao);
    } while (entrada != 1);

    return;
    
}
// Exibe os detalhes e resultados guardados na struct de métricas
void interface_exibir_metricas(const metricas_t *status, const char *nome_algoritmo);

// Exibe o vetor no terminal (útil para testes com poucos elementos)
void interface_imprimir_vetor(const int array[], int tamanho);


#endif