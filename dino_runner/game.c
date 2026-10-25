/*
==========================================
          ANOTAÇÕES DO PROJETO
==========================================
 
  Autor:   Victor Rafael Dantas de Araújo     
 
  Descrição:
  game criado em homenagem ao "dino runner" de navegador. 
  e homenagem ao meu game no scrach "CS50: The Extinction Escape"
  https://scratch.mit.edu/projects/1264628797/
   
  Anotações importantes:
    - w:     para avançar.
    - space: pular.
    - 

==========================================
*/

#include <stdint.h>  // uint8_t etc...
#include <stdlib.h>  // srand
#include <time.h>    // time
#include <windows.h> // Sleep
#include <stdbool.h> // boleanos
#include <conio.h>   // _kbhit() || _getch()
#include <string.h>  // strcpy e memset
#include <stdio.h>   // padrão

// MACROS(TELA, POSIÇÕES)
#include "macros/macro.h"
// ESTRUTURAS E INICIALIZAÇÃO DOS MOBS
#include "mobs/mob_estrutura.h"
#include "mobs/mob_create.h"
//DISPLAY GAME
#include "display/display.h" 
// START GAME
#include "game_inicializar/inicializar.h"
// VALORES ALEATÓRIO
#include "sorting/sorting.h"

// tela do jogo
char tela[ALTURA][LARGURA][8];
// mob principal
Dino dino;

int main(void)
{
    inicializar();
    
    int tempo_vivo = 0;
    
    char buffer_tela[LARGURA - 2] = {0};
    
    
    bool gameOver = false;

    uint8_t spawn_mob = 1;
    inimigos cacto;
    desastres_naturais meteoro;
    criando_mobs(&cacto, &meteoro);

    
    // para mobs
    //int mob_atual = 0; // qual objeto para tentar parar o dinossauro
    int contador  = 0;
    int desastres_contador_spawnar_start = 0;
    int desatres_contador_spawnar = 0;

    while (!gameOver)
    {
        // --------------------RELOGIO--------------------
        for (int apagar = 0, tamanho = strlen(buffer_tela); apagar < tamanho; apagar++)
        {
            strcpy(tela[RELOGIO_INICIO_Y][RELOGIO_INICIO_X + apagar], "  ");
        }
        tempo_vivo++;
        snprintf(buffer_tela, sizeof(buffer_tela), "%d", tempo_vivo);
        for (int quantidade = 0, tamanho = strlen(buffer_tela); quantidade < tamanho; quantidade++)
        {
            tela[RELOGIO_INICIO_Y][RELOGIO_INICIO_X + quantidade][0] = buffer_tela[quantidade];
            tela[RELOGIO_INICIO_Y][RELOGIO_INICIO_X + quantidade][1] = ' ';
            tela[RELOGIO_INICIO_Y][RELOGIO_INICIO_X + quantidade][2] = '\0';
        }
        //--------------------------------------------------------------------------------

        // SPAWNAR METEORO
        if (desastres_contador_spawnar_start < 100)
        {
            desastres_contador_spawnar_start++;
        }
        else if (meteoro.ativado == false)
        {
            if (desatres_contador_spawnar < 10 && meteoro.ativado == false)
            {
                desatres_contador_spawnar++;
            }
            else
            {
                meteoro.x = aleatorio_posicao_x();
                meteoro.ativado = true;
                desatres_contador_spawnar = 0;
            }
        }
        // DESCIDA DO METEORO
        if (meteoro.ativado == true)
        {
            strcpy(tela[meteoro.y][meteoro.x], "  ");
            meteoro.y++; // desce
            strcpy(tela[meteoro.y][meteoro.x], "☄️ ");

            if (meteoro.y == DINO_Y)
            {
                meteoro.ativado = false; // caso encoste no chão
                strcpy(tela[meteoro.y][meteoro.x], "  ");

                // reset status
                meteoro.y = 1;
                meteoro.x = DINO_INICIO;
                meteoro.ativado = false;

            }

        }
        if (contador < MOB_CACTOS_SPAW)
        {
            contador++;
        }
        // SPAW MOB

        if (contador >= MOB_CACTOS_SPAW)
        {
            if ((spawn_mob = sortearSimOuNao()) == 0)
            {
                contador = 0;
            }
            else
            {
                cacto.ativado = true;
                contador = 0;
            }
        }
        if (cacto.ativado == true)
        {
            strcpy (tela[cacto.y][cacto.x], "  ");
            cacto.x--;
            strcpy (tela[cacto.y][cacto.x], "🌵");

            if (cacto.x == CACTO_FIM)
            {
                strcpy (tela[cacto.y][cacto.x], "  ");
                cacto.x = CACTO_INICIO;
                // reset status
                cacto.ativado = false;
            }

        }
        //----------------------DINO-------------------------------------------------

        // PULO DO DINO E FISICA
        if ((dino.estaPulando == false) && dino.y != DINO_Y)
        {
            strcpy(tela[dino.y][dino.x], "  ");
            dino.y++;
            strcpy(tela[dino.y][dino.x], "🦖");
        }
        // Aplica o movimento do pulo/gravidade
        if (dino.estaPulando == true)
        {
            // APAGAR POSIÇÃO
            if (dino.y == DINO_PULO_MAX)
            {
                // parar de subir
                dino.estaPulando = false;
            }
            else
            {
                strcpy(tela[dino.y][dino.x], "  ");
                dino.y = dino.y + DINO_PULO;
                strcpy(tela[dino.y][dino.x], "🦖");
            }
        }

        // vai pra frente o dino

        if (dino.x > DINO_INICIO)
        {
            // fisica pra voltar pra tras
            strcpy(tela[dino.y][dino.x], "  ");
            dino.x--;
            strcpy(tela[dino.y][dino.x], "🦖");
        }

        if (dino.andar > 0 && dino.x + 4 != LARGURA)
        {
            strcpy(tela[dino.y][dino.x], "  ");
            dino.x = dino.x + 2;
            strcpy(tela[dino.y][dino.x], "🦖");

            dino.andar--;
        }

        // GAMER OVER! (caso 1 = encostou no cacto. caso 2 caiu no meteoro)

        //----------------------------HITBOXS MOBS (DINOSSAURO)---------------------------------------
        // posicoes cactos
        bool y_perto_cacto  = (dino.y == cacto.y);                            // verifica posicao y
        bool x_perto_cacto  = (dino.x == cacto.x || dino.x - 1 == cacto.x);   // verifica posicao x               
        bool bateu_no_cacto = (x_perto_cacto && y_perto_cacto);               // resultado final
        
        // posicoes meteoros
        bool y_perto_meteoro  = (dino.y == meteoro.y || dino.y + 1 == meteoro.y || dino.y - 1 == meteoro.y); // verifica posicao y
        bool x_perto_meteoro  = (dino.x == meteoro.x || dino.x + 1 == meteoro.x || dino.x - 1 == meteoro.x); // verifica posicao x  
        bool bateu_no_meteoro = (x_perto_meteoro && y_perto_meteoro);                                        // resultado final

        if (bateu_no_cacto || bateu_no_meteoro) // se algum bateu e game over e sai do loop.
        {
            displayGmerOver("GAMER OVER!!");
            gameOver = true;
            break;
        }
        //---------------------------------------------------------------------------------------------
        
       // 5. LEITURA DO TECLADO
        if (_kbhit())
        {
            char tecla = _getch();

            // PULO (Space): Só pula se estiver no chão
            if ((tecla == ' ' || tecla == 32) && (dino.estaPulando == false) && (dino.y == ALTURA - 2))
            {
                dino.estaPulando = true;
            }

            // CORRER (W): Só corre se Não estiver na borda
            if ( (dino.x + 4 != LARGURA) && (tecla == 87 || tecla == 119 || tecla == 'W' || tecla == 'w'))
            {
                dino.andar = 3;
            }

            // CTRL + C (Sair do jogo)
            if (tecla == 3)
            {
                gameOver = true;
            }
        }
            // Enquanto existir qualquer tecla presa no buffer..
        while (_kbhit())
        {
            _getch();
        }

        resetarCursor();
        display();
        esconderCursor(true);
        Sleep(FPS); // frames
    }
    resetarCursor();
    display();
    esconderCursor(false);

    return 0;
}