#ifndef MACRO_H
#define MACRO_H

#define MOBS_TOTAIS 2
//-------------------------DINO---------------------
#define ALTURA 10                                //| 
#define LARGURA 35                               //|
#define ALTURA_MEIO (ALTURA / 2)                 //|
#define LARGURA_MEIO (LARGURA / 2)               //| 
#define COLUNA_BORDA (LARGURA - 3)               //| BORDA DA COLUNA 
//--------------------------------------------------

//-------------------------DINO-----------------------------
#define DINO_INICIO 11             // coluna             //|
#define DINO_Y (ALTURA - 2)        // altura             //|
#define DINO_PULO -2                                     //|
#define DINO_PULO_MAX (DINO_Y - 4) // 4 blocos de altura //|
//----------------------------------------------------------

//-------------------------CACTO------------------------------
#define CACTO_INICIO (LARGURA - 2)                         //|
#define CACTO_FIM (LARGURA - (LARGURA - 2))                //|
#define MOB_CACTOS_SPAW 20                                 //|
//------------------------------------------------------------

//-------------------------DESATRE NATURAIS (METEORO)---------
#define METEORO_SPAW 10                                    //|
//------------------------------------------------------------

#define RELOGIO_INICIO_Y 2
#define RELOGIO_INICIO_X 2

// game fps
#define FPS 50

#endif