#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <stdlib.h> // Define rand(), srand() e RAND_MAX
#include <stdint.h> // uint8_t

// ou sim ou nao
uint8_t sortearSimOuNao(void)
{
    return rand() % 2;
}
// posicao x aleatoria entre 11 e largura total
uint8_t aleatorio_posicao_x()
{
    return 11 + (rand() % 23);
}


// desativado..
//int aleatorio_mob();
//{
//    return rand() % MOBS_TOTAIS;
//}

#endif