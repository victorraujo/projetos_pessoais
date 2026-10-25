#ifndef MOB_CREATE_H
#define MOB_CREATE_H

#include <stdio.h>
#include "../macros/macro.h"
#include "mob_estrutura.h" 

void criando_mobs(inimigos *mob, desastres_naturais *desatre)
{
    mob->y = ALTURA - 2;
    mob->x = CACTO_INICIO;
    mob->personagem = "🌵";
    mob->ativado = false;

    desatre->ativado = false;
    desatre->y = 1;
    desatre->x = 0;
    desatre->personagem = "☄️ ";
}

#endif