
/* patience sorting ele e um ordenador que consiste em:
 organizar uma lista distribuindo em varios potes
 
 e logo depois de organizar os potes monta ordenado
  1.
 
 */


#include <stdio.h>
#include <stdbool.h>
#include <string.h> // memset
#include <limits.h>

int main(void)
{
    
    int bloco[] = {5, 1, 6, 103, 10, 11};
    size_t bloco_totais = sizeof(bloco) / sizeof(bloco[0]);
    bool percorreu_todos_blocos = false;
    // ordenar por bloco
    // caso compara em casa em casa
    // logo depois se nao acha ele cria a propria casa
    // organizacao que logo depois de todos os numeros ele monta
    while(!percorreu_todos_blocos)
    {
        size_t elemento_full = sizeof(bloco) / sizeof(bloco[0]);
        int pote[elemento_full][50];
        size_t size_elemento_pote[elemento_full]; // metadados quantos objeto tem em cada pote
            memset(pote, 0, sizeof(pote)); // zera bloco
            memset(size_elemento_pote, 0, sizeof(size_elemento_pote)); // zera bloco
            
        for(int i = 0; i < elemento_full; i++)
        {
            for (int escolha_pote = 0; escolha_pote < elemento_full; escolha_pote++)
            {
                if (size_elemento_pote[escolha_pote] != 0)
                {
                      // pegar o primeiro elemento
                    if (pote[escolha_pote][size_elemento_pote[escolha_pote] - 1] >= bloco[i])
                    {
                        pote[escolha_pote][size_elemento_pote[escolha_pote]] = bloco[i];
                        size_elemento_pote[escolha_pote]++;
                        break;
                    }
                }
                if (size_elemento_pote[escolha_pote] == 0)
                {
                    pote[escolha_pote][size_elemento_pote[escolha_pote]] = bloco[i];
                    size_elemento_pote[escolha_pote]++;
                    break;
                }
            }
    
        }

        int pote_usando;
        for (pote_usando = 0; size_elemento_pote[pote_usando] != 0; pote_usando++);
        
        //------------ORGANIZAR-------------------
        // monte as peças novamnete em ordem.
        for(int i = 0; i < elemento_full; i++)
        {
            int guarda_valor = INT_MAX; // guardar o valor do pote
            int pote_escolhido = -1;    // usado para deminuir 1 do pote
 
            for(size_t escolha_pote = 0; escolha_pote < pote_usando; escolha_pote++)
            {
                if (pote[escolha_pote][size_elemento_pote[escolha_pote] - 1] != 0)
                {
                    if(pote[escolha_pote][size_elemento_pote[escolha_pote] - 1] <= guarda_valor)
                    {
                        guarda_valor = pote[escolha_pote][size_elemento_pote[escolha_pote] - 1];
                        pote_escolhido = escolha_pote;
                    }
                }
            }
            bloco[i] = guarda_valor; // atribuição
            pote[pote_escolhido][size_elemento_pote[pote_escolhido]] == 0;
            size_elemento_pote[pote_escolhido]--;
        }
        percorreu_todos_blocos = true;
    }
    // modelo visual para visualizar cada etapa
    // |de organização
    
    for (int visual = 0; visual < bloco_totais; visual++)
    printf("%d ",bloco[visual]);
    
}
