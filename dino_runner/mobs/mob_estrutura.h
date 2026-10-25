#ifndef MOB_ESTRUTURA_H
#define MOB_ESTRUTURA_H

#include <stdio.h>

//-------------------------DINO STATUS----------------
typedef struct                                     //|
{                                                  //|
    int y;           // posição y (altura)         //|
    int x;           // posição x (coluna)         //|
    // COMANDOS (w corre|| space pula)             //|
    int andar;                                     //|
    bool estaPulando;                              //|
    char *dinossauro; // skin                      //|
} Dino;                                            //|
//----------------------------------------------------

//-------------------------INIMIGOS DO DINO STATUS STATUS--------
typedef struct                                                //|
{                                                             //|
    int y;            // posição y (altura)                   //|
    int x;            // posição x (coluna)                   //|
    int andar;        // excluir (nao esta sendo usado)       //|
    bool estaPulando; // não usado (ainda)                    //|
    bool ativado;     // esta na tela? (matriz)               //|
    char *personagem; // eskin                                //|
} inimigos;                                                   //|
//---------------------------------------------------------------

//-------------------------DESASTRES DO MAPA STATUS-------------
typedef struct {                                            //|
    int y;              // posição y (altura)               //|
    int x;              // posição x (coluna)               //|
    bool ativado;       // esta na tela? (matriz)           //|
    int tempo_aparecer; // tempo pra ele nascer             //|
    char*personagem;    // eskin                            //|
} desastres_naturais;                                       //|
//-------------------------------------------------------------

#endif