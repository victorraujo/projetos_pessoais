#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>

// Exibe o menu principal e retorna a opção escolhida pelo utilizador
int interface_menu_principal(void);

// Exibe os detalhes e resultados guardados na struct de métricas
void interface_exibir_metricas(const metricas_t *status, const char *nome_algoritmo);

// Exibe o vetor no terminal (útil para testes com poucos elementos)
void interface_imprimir_vetor(const int array[], int tamanho);


#endif