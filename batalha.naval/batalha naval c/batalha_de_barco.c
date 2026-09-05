#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h> // pausa o programa



#define MAX_JOGADORES 2
#define INIMIGOS_MAX 5

//___________________________________
// tabuleiro dos jogadores
#define COLUNA 10
#define LINHA 10
//____________________________________

typedef struct {
    int id_jogador;
    int defesas;
    int pts;
    bool vivo;
    char tabuleiro[LINHA][COLUNA];

} status_jogadores;

status_jogadores jogador[MAX_JOGADORES];



void limpa_tela()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void zeramento(void)
{
    for (int i = 0; i < MAX_JOGADORES; i++)
    {
        jogador[i].defesas = INIMIGOS_MAX;
        jogador[i].pts = 0;
        jogador[i].vivo = true;

        for (int j = 0; j < LINHA; j++)
        {
            for (int k = 0; k < COLUNA; k++)
            {
                jogador[i].tabuleiro[j][k] = ' ';
            }
        }
    }
    //saber quem e quem
    jogador[0].id_jogador = 0;
    jogador[1].id_jogador = 1;
}


void bem_vindo()
{
    // Limpa a tela do terminal (opcional, mas deixa o visual limpo)
    // No Windows usa "cls", no Linux/Mac usa "clear"
    limpa_tela();

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                  B A T A L H A   N A V A L                \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("          [~]                               [~]            \n");
    printf("          /_\\_    _   _   _   _   _   _    _/_\\            \n");
    printf("  ~~~~  _\\____\\__/_\\_/_\\_/_\\_/_\\_/_\\_/_\\__/____/_  ~~~~    \n");
    printf("  ~~~~  \\_______________________________________/  ~~~~    \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("                Seja bem-vindo ao grande jogo!             \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n");
    printf("  Prepare suas coordenadas... O oceano espera por voce.\n\n");
    printf("===========================================================\n");
    printf(" Pressione ENTER para iniciar a batalha...");
    
    getchar(); 
}

void contagem()
{
    for (int i = 0; i < 3; i++)
    {
        printf("%i", i + 1);
        sleep(1);

        limpa_tela();
    }
    printf("GO!!");
    sleep(1);
    limpa_tela();


}

void exibir_matriz(int quem_joga)
{
    printf("\n~~~~~~~~~~~~~~JOGADOR {%i}~~~~~~~~~~~~~~\n", quem_joga);
    printf("   0    1    2    3    4    5    6    7    8    9\n");

    for (int i = 0; i < LINHA; i++)
    {
        printf("%i", i);
        for (int j = 0; j < COLUNA; j++)
        {
            printf(" [%c] ", jogador[quem_joga].tabuleiro[i][j]);
        }

        printf("\n");
    }

    printf("\n\ncom sucesso!");
}

void escolhendo_posicoes(int quem_joga)
{
    int linha;
    int coluna;
    int verdadeiros = 0;
    printf("escolha %i posições!\n", INIMIGOS_MAX);
    printf("-------------------\n");
    printf("Digite a linha e a coluna (ex: 5 8)\n");
    printf("-------------------\n");
   
    printf("me = ");
    do
    {
        if(scanf("%i %i", &linha, &coluna) == 2) // verifica se os 2 sao numeros
        {
            if (linha <= COLUNA - 1 && linha >= 0 &&
                coluna <= COLUNA - 1 && coluna >= 0 )
            {
                
                if (jogador[quem_joga].tabuleiro[linha][coluna] == ' ')
                {
                     jogador[quem_joga].tabuleiro[linha][coluna] = 'N';
                     verdadeiros++;
                }
                else
                {
                    printf("escolha um lugar diferente! [esse lugar ja tem dono]\n");
                }
            }
            else
            {
                printf("numero nao suportado![diga um numero de 0 a 9!]\n");
            }
        }
        else // caso um nao seja numero
        {
            printf("invalido [digite um numero!!!]\n");
            // limpamento de buffet
            while (getchar() != '\n');
            
        }

    }  while(verdadeiros < INIMIGOS_MAX);
}
int main() {
   
   zeramento();

   // tabela de bem vindo(antes do jogo começar)
   bem_vindo();
   contagem();

   int roud = 0;
   //aqui começa

   exibir_matriz(jogador[0].id_jogador);
   escolhendo_posicoes(jogador[0].id_jogador);
   //testes
   limpa_tela();
   exibir_matriz(jogador[0].id_jogador);

   while (jogador[0].vivo != false || jogador[1].vivo != false)
   {
        
   }
   

   
   return 0; 

}