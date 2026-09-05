#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <unistd.h> // para uso da função sleep
#include <stdbool.h>

#define LINHA 3
#define COLUNA 3
// soma de linha x coluna
#define MATRIZ_SOMADA (LINHA * COLUNA)

#define PLAYER_0 0
#define PLAYER_1 1

//sistema de verificar idade
#define LI_OS_DOIS 2

char jogo[LINHA][COLUNA];


// nao usando...
void limpa_tela(void)
{
  #ifdef _WIN32
    system("cls");
  #else
    system("clear");
  #endif
}


// em uso
void limpa_tela2()
{
  printf("\033[H\033[J");
}



void resetar_matriz()
{
  for (int i = 0; i < LINHA; i++)
  {
    for (int j = 0; j < COLUNA; j++)
    {
      jogo[i][j] = ' ';
    }
    
  }
}



void start_desing()
{
  

  printf(" =====================\n"
             "  JOGO DA VELHA\n"
         " =====================\n");

  printf("Você é: X\n"
         "Robô é: O\n\n");

  printf("Digite linha e coluna (0 a 2)\n");
  printf("Exemplo: 1 2\n");
  
  sleep(1);
  limpa_tela2();
  
  
}  

// temporariamente desativado
void exibir_tabela()
{
  printf("    0   1   2\n");
  printf(" +---+---+---+--+\n");
  printf("0  | %c | %c | %c |\n", jogo[0][0], jogo[0][1], jogo[0][2]);
  printf(" +---+---+---+--+\n");
  printf("1  | %c | %c | %c |\n", jogo[1][0], jogo[1][1], jogo[1][2]);
  printf(" +---+---+---+--+\n");
  printf("2  | %c | %c | %c |\n", jogo[2][0], jogo[2][1], jogo[2][2]);
  printf(" +---+---+---+--+\n");
}
// em uso
void exibir_tabela2()
{
  for (int coluna = 0; coluna < COLUNA; coluna++)
  {
    printf("  %i   ", coluna);
  } 
  printf("\n");
  printf(" +---+---+---+---+\n");
  
  for (int i = 0; i < LINHA; i++)
  {
    printf("%i", i);
    for (int j = 0; j < COLUNA; j++)
    {
      printf("| %c | ", jogo[i][j]);
    }
    printf("\n");
    printf(" +---+---+---+---+\n");
    
  }
}

void escolhendo(int *l, int *c)
{
  
  do
  {
    //sistema pra ler se e letra
    // o scanf tambem consegue retornar valodes
    // para saber se leu com sucesso
    int eh_letra = scanf("%i %i", l, c);
    
    if (eh_letra != 2) // li os 2 valores com sucesso
    {
      printf("digite apenas numeros!! ❌️\n");
      
      while (getchar() != '\n'); //limpa buffet quando encontra o \n
      
      continue; 
    }
    
    if (*l > 2 || *l < 0 || *c > 2 || *c < 0)
    {
      printf("cordenada invalido! ❌️\n");
      continue;
    }
    if (jogo[*l][*c] != ' ')
    {
      printf("local invalido! ❌️\n\n");
      continue; // volte o loop
      
    }
    break;  // sair
    
  } while(true);
}


void colocar(int *l, int *c, int quem_joga)
{
  if (quem_joga == PLAYER_0)
  {
    jogo[*l][*c] = 'X'; // (*) -> para entra dentro de cada variavel
  }
  else if (quem_joga == PLAYER_1)
  {
    jogo[*l][*c] = 'O';
  }
}

void jogador(int quem_joga)
{
  if (quem_joga == 0)
  {
    printf("quem joga e [X]\n");
  }
  else if(quem_joga == 1)
  {
    printf("quem joga e [O]\n");
  }
  
}


bool resultado()
{
  for (int i = 0; i < 3; i++)
  {
        // LINHA
    if (jogo[i][0] == jogo[i][1]
    && jogo[i][1] == jogo[i][2] 
    && jogo[i][2] != ' ')
    {
      return true;
    }
  }
      // COLUNA
  for (int i = 0; i < 3; i++)
  {
    if (jogo[0][i] == jogo[1][i] 
    && jogo[1][i]== jogo[2][i]
    && jogo[2][i] != ' ')
    {
      return true;
    }
  }
        //  vertical esquerda
  if (jogo[0][0] == jogo[1][1] 
      && jogo[1][1] == jogo[2][2] 
      && jogo[2][2] != ' ')
  {
    return true;
  }
      //  vertical direita
  else if(jogo[0][2] == jogo[1][1] 
       && jogo[1][1] == jogo[2][0]
       && jogo[2][0] != ' ')
  {
    return true;
  }
  else
  {
    return false;
  }
 
}


void ganhou(bool ganhou, int turno)
{
  if (ganhou == true)
  {
    if (turno == PLAYER_0)
    {
      printf("\nO [X] GANHOU!!\n");
    }
    else if (turno == PLAYER_1)
    {
      printf("\nO [O] GANHOU!!\n");
    }
    
  }
}


bool empate()
{
  int m = 0;
  
  for (int i = 0; i < LINHA; i++)
  {
    for (int j = 0; j < COLUNA; j++)
    {
      if (jogo[i][j] != ' ')
      {
        m++;
      }
    }
  }
  
  if (m >= MATRIZ_SOMADA)
  {
    printf("EMPATE!!");
    return true;
  }
  
  return false;
  
}


int main(void)
{
  int linha = 0;
  int coluna = 0;
  
  int turno = 0;
  
  bool vencedor = false;
  
  resetar_matriz();
  start_desing();
  while (!vencedor)
  {
    limpa_tela2();
   
    printf("\n[%i]  [%i]\n ", linha, coluna); // visualizar variáveis
    //desativo temporariamente
   // exibir_tabela();
    exibir_tabela2();
    
    jogador(turno);
    escolhendo(&linha, &coluna);
    colocar(&linha, &coluna, turno);
    
    
    vencedor = resultado();
    limpa_tela2();
    //exibir_tabela();
    exibir_tabela2();
    ganhou(vencedor, turno);
    
    if (empate())
    {
      break;
    }
    
    turno = 1 - turno; // infinito
    
  }  
  return 0;
}