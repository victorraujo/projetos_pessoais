// interpreter de expressao

#include <stdlib.h>  // malloc end realloc
#include <ctype.h>   // verificadores
#include <stdbool.h> // verdadeiro ou falso
#include <stdio.h>
typedef struct Tipo
{
    double *numero;
    char *token;

    struct Tipo *direita;
    struct Tipo *esquerda;
} Tipo;

typedef struct usuario
{
    void *aponta;

    struct usuario *direita;
    struct usuario *esquerda;
} Usuario;
 
// Exemplo de uso:
// char* meu_texto = input();
#include <stdio.h>
#include <stdlib.h>

char* input(void)
{
    size_t buffer_text_total = 20;
    size_t buffer_text_atual = 0;
    char* prompt = malloc(buffer_text_total);

    // 1. Trata falha no malloc inicial
    if (prompt == NULL)
    {
        return NULL;
    }

    int caractere_atual = 0;
    while ((caractere_atual = getchar()) != '\n' && caractere_atual != EOF)
    {
        if (buffer_text_atual >= buffer_text_total - 1)
        {
            buffer_text_total += 20;
            char* prompt_tmp = realloc(prompt, buffer_text_total);
            
            // 2. Libera a memória anterior se o realloc falhar
            if (prompt_tmp == NULL)
            {
                free(prompt);
                return NULL;
            }
            prompt = prompt_tmp;
        }
        prompt[buffer_text_atual] = (char)caractere_atual;
        buffer_text_atual++;
    }

    // 3. Trata leitura vazia em caso de EOF imediato
    if (buffer_text_atual == 0 && caractere_atual == EOF)
    {
        free(prompt);
        return NULL;
    }

    // 4. Ajusta tamanho final mantendo os dados caso o realloc falhe
    char* prompt_tmp = realloc(prompt, buffer_text_atual + 1);
    if (prompt_tmp != NULL)
    {
        prompt = prompt_tmp;
    }

    prompt[buffer_text_atual] = '\0';
    return prompt;
}

// limpar uma estrutura inteira
// conceitos:
// | quando usamos uma função ela cria variaveis temporaria para lidar com as informaçoes
// | que enviamos para ela. se criarmos **ponteiro ela vai guardar um ponteiro.
// |_______________PONTEIROS______________________________
// | bloco = Endereço do ponteiro da main.
// |*bloco = Endereço da variável real (que está guardado no ponteiro da main).
// |**bloco = A própria variável / informação real.
// |____________________________________________________
// DESFERENCIAR:
// usamos (*variavel) para dizer: calma, entre primeiro aqui depois acesse o membro dela. 
// membro : -> (que tambem e um desfereciador)
void limpar_bloco(Tipo** bloco)
{
    if ((*bloco)->numero != NULL) free((*bloco)->numero); // liberar numero 
    if ((*bloco)->token  != NULL) free((*bloco)->token);   // liberar token
    free(*bloco);
    *bloco = NULL;
}
void limpar_encadeadas(Tipo** bloco)
{
    while(*bloco != NULL)
    {
        if ((*bloco)->direita == NULL) // ve se tem alguem na frente
        {
            free(*bloco);
            *bloco = NULL;
            return;
        }
        *bloco = (*bloco)->direita; // andar
        free((*bloco)->esquerda); // exclutir o de tras
    }
}
void display(Tipo* expressao)
{
    printf("%d\n\n", expressao);
    return;
}

int main(void)
{

    Tipo *expressao_inicio = NULL;
    Tipo *expressao = NULL;

    size_t buffer = 0;
    char* prompt_texto = input(); // pedir expressão ao usuario
    if (prompt_texto == NULL)
    {
        return 1;
    }

    char *percorrer_string = prompt_texto;
    char *proxima_parte = NULL;
    double valor_token = 0;
    while (percorrer_string != NULL)
    {
        
        // strtod transforma em numero e diz onde foi a quebra de linha e ainda envia o local!!

        valor_token = strtod(percorrer_string, &proxima_parte);
        while (isspace((unsigned char)*proxima_parte)) 
        { 
            proxima_parte++; // for espaço pula 1 caractere
        } 
            // Se o strtod conseguiu ler um número (o ponteiro andou)
        
        //            boleanas para quebra de expressão
        bool eh_simbolo_mutiplicacao = (*proxima_parte == '*' || toupper(*proxima_parte) == 'X');
        bool eh_simbolo_barra = (*proxima_parte == '/');
        bool eh_simbolo_mais = (*proxima_parte == '+');
        bool eh_simbolo_menos = (*proxima_parte == '-');
        bool eh_algum_operador = (eh_simbolo_mutiplicacao || eh_simbolo_barra || eh_simbolo_mais || eh_simbolo_menos)
        bool eh_o_fim = (*proxima_parte == '\0');

        if (expressao == NULL)
        {
            Tipo*tmp_expressao    = malloc(sizeof(Tipo));
            tmp_expressao->numero = malloc(sizeof(double));
            if (tmp_expressao == NULL ||tmp_expressao == NULL) return 1;

            tmp_expressao->esquerda  = NULL;
            tmp_expressao->direita   = NULL;
            tmp_expressao->token     = NULL;
            *(tmp_expressao->numero) = valor_token;

            expressao_inicio = tmp_expressao;
            expressao = tmp_expressao;
        }
        else
        {
            Tipo*tmp_expressao    = malloc(sizeof(Tipo));
            tmp_expressao->numero = malloc(sizeof(double));
            if (tmp_expressao == NULL ||tmp_expressao == NULL) return 1;

            tmp_expressao->esquerda  = expressao;
            tmp_expressao->direita   = NULL;
            tmp_expressao->token     = NULL;
            *(tmp_expressao->numero) = valor_token;

            expressao->direita = tmp_expressao;
            
            expressao = tmp_expressao;
        }

        // caso alguma seja verdade
        if (eh_algum_operador)
        {
            // organizar o sistema
            Tipo* tmp_expressao  = malloc(sizeof(Tipo));
            tmp_expressao->token = malloc(sizeof(char));
            if (tmp_expressao == NULL || tmp_expressao->token == NULL) if return 1;

            tmp_expressao->esquerda = expressao;
            tmp_expressao->direita  = NULL;
            *(tmp_expressao->token) = *proxima_parte;
            tmp_expressao->numero   = NULL;

            expressao->direita = tmp_expressao;

            expressao = tmp_expressao;
        }
        if (eh_o_fim)
        {
            break;
        }
    }

    free(prompt_texto);


    // ACHAR MULTIPLICAÇÃO OU DIVIÃO (prioridade 2)
    Tipo *elemento_atual = expressao_inicio;
    if (elemento_atual == NULL) return 1;


    while (elemento_atual != NULL)
    {
        if (elemento_atual->token != NULL)
        {

            bool eh_multiplicacao = (*(elemento_atual->token) == '*' || toupper(*(elemento_atual->token)) == 'X'); // desferenciando  o membro
            bool eh_divisao      = (*(elemento_atual->token) == '/');

            if (eh_multiplicacao || eh_divisao)
            {
                // pre status para calculo
                double numero_esquerda = 0;
                double numero_direita  = 0;
                double resultado       = 0;

                // ponteiros renomeados para facilitar leitura
                Tipo* elemento_frente = elemento_atual->direita;
                Tipo* elemento_tras   = elemento_atual->esquerda;
            
                if (elemento_frente == NULL || elemento_tras == NULL) return 1;

                elemento_atual->numero = malloc(sizeof(double));
                if (elemento_atual->numero == NULL) return 1;

                if (elemento_tras != NULL)
                {

                    if (elemento_tras->numero != NULL) // tratar caso o numero que verificar seja outra coisa alem de numero
                    {
                        numero_esquerda = *(elemento_tras->numero); // caso seja numero
                    }
                }
                if (elemento_frente != NULL)
                {
                    if (elemento_frente->numero != NULL)  // tratar caso o numero que verificar seja outra coisa alem de numero
                    {
                        numero_direita  = *(elemento_frente->numero);
                    }   
                }
    

                if (eh_multiplicacao)
                {
                    free(elemento_atual->token);
                    elemento_atual->token = NULL;
                    resultado = numero_esquerda * numero_direita;
                }
                if (eh_divisao)
                {
                    free(elemento_atual->token);
                    elemento_atual->token = NULL;
                    if (numero_direita == 0)
                    {
                        printf("expressão invalida.\n");
                        return 1;
                    }
                    resultado = numero_esquerda / numero_direita;
                }
                //atribui o resultado ->
                *elemento_atual->numero = resultado;


                //------------ORGANIZANDO OS PONTEIRO APÓS EXPRESSÃO RESOLVIDA-------------------------------
                //   

                // ==================== NÓS À ESQUERDA <- ====================
                if (elemento_atual->esquerda != NULL)
                {
                    // existe elementos a frente
                    if (elemento_atual->esquerda->esquerda != NULL)
                    {
                        //      SINTAXE MAIS FACIL (REALIGAR PONTEIRO APÓS RESOLVER EXPRESSÃO)
                        Tipo* novo_realigamento_dois_tras    = elemento_atual->esquerda->esquerda; // salvei 2 nós a frente

                        // DESLIGAR PONTEIRO DO LADO ESQUERDO
                        limpar_bloco(&elemento_atual->esquerda);

                        // Religa os ponteiros (Ida e Volta)
                        elemento_atual->esquerda             = novo_realigamento_dois_tras;
                        novo_realigamento_dois_tras->direita = elemento_atual;  
                    }
                    // Se não tem ninguém depois, é o fim da lista
                    else
                    {
                        limpar_bloco(&elemento_atual->esquerda);
                    }
                }
        
                // ==================== NÓS À DIREITA -> ====================
           
                if (elemento_atual->direita != NULL)
                {
                    if (elemento_atual->direita->direita != NULL)
                    {
                        //      SINTAXE MAIS FACIL (REALIGAR PONTEIRO APÓS RESOLVER EXPRESSÃO)
                        Tipo* novo_realigamento_dois_frente = elemento_atual->direita->direita; // salvei 2 nós a frente          

                        // DESLIGAR PONTEIRO DOS LADOS
                        limpar_bloco(&elemento_atual->direita);

                     // Religa os ponteiros (Ida e Volta)
                        elemento_atual->direita                 = novo_realigamento_dois_frente;
                        novo_realigamento_dois_frente->esquerda = elemento_atual;
                    }
                    // Se não tem ninguém depois, é o fim da lista
                    else
                    {
                    limpar_bloco(&elemento_atual->direita);
                    }
                }
            }
            //-----------------------------------------------------------------------  
        }
    elemento_atual = elemento_atual->direita;
    }

    //ACHAR SOMA OU SUBTRAÇÃO (PRIORIDADE MAIS BAIXA) 
    elemento_atual = expressao_inicio;
    while(elemento_atual != NULL)
    {
        if(elemento_atual->token != NULL)
        {
            bool eh_simbolo_mais  = (*(elemento_atual->token)  == '+');
            bool eh_simbolo_menos = (*(elemento_atual->token) == '-');
            if (eh_simbolo_mais || eh_simbolo_menos)
            {
                // pre status para calculo
                double numero_esquerda = 0;
                double numero_direita  = 0;
                double resultado       = 0;

                // ponteiros renomeados para facilitar leitura
                Tipo* elemento_frente = elemento_atual->direita;
                Tipo* elemento_tras   = elemento_atual->esquerda;

                elemento_atual->numero = malloc(sizeof(double));
                if (elemento_atual->numero == NULL) return 1;

                if (elemento_tras != NULL)
                {
                    if (elemento_tras->numero != NULL) // tratar caso o numero que verificar seja outra coisa alem de numero
                    {
                        numero_esquerda = *(elemento_tras->numero); // caso seja numero
                    }
                }
                if (elemento_frente != NULL)
                {
                    if (elemento_frente->numero != NULL)  // tratar caso o numero que verificar seja outra coisa alem de numero
                    {
                        numero_direita  = *(elemento_frente->numero);
                    }   
                }
    
                if (eh_simbolo_mais)
                {
                  free(elemento_atual->token);
                    elemento_atual->token = NULL;
                    resultado = numero_esquerda + numero_direita;
                }
                if (eh_simbolo_menos)
                {
                    free(elemento_atual->token);
                    elemento_atual->token = NULL;
                    resultado = numero_esquerda - numero_direita;
                }

                //atribui o resultado ->
                *elemento_atual->numero = resultado;

                //------------ORGANIZANDO OS PONTEIRO APÓS EXPRESSÃO RESOLVIDA------------------------------- 

                // ==================== NÓS À ESQUERDA <- ====================
                if (elemento_atual->esquerda != NULL)
                {
                    // existe elementos a frente
                    if (elemento_atual->esquerda->esquerda != NULL)
                    {
                        //      SINTAXE MAIS FACIL (REALIGAR PONTEIRO APÓS RESOLVER EXPRESSÃO)
                        Tipo* novo_realigamento_dois_tras    = elemento_atual->esquerda->esquerda; // salvei 2 nós a frente

                        // DESLIGAR PONTEIRO DO LADO ESQUERDO
                        limpar_bloco(&elemento_atual->esquerda);

                        // Religa os ponteiros (Ida e Volta)
                        elemento_atual->esquerda             = novo_realigamento_dois_tras;
                        novo_realigamento_dois_tras->direita = elemento_atual;  
                    }

                    // Se não tem ninguém depois, é o fim da lista
                    else
                    {
                        limpar_bloco(&elemento_atual->esquerda);
                    }
                }
            }
            // ==================== NÓS À DIREITA -> ====================
           
            if (elemento_atual->direita != NULL)
            {
                if (elemento_atual->direita->direita != NULL)
                {
                    //      SINTAXE MAIS FACIL (REALIGAR PONTEIRO APÓS RESOLVER EXPRESSÃO)
                    Tipo* novo_realigamento_dois_frente = elemento_atual->direita->direita; // salvei 2 nós a frente          

                    // DESLIGAR PONTEIRO DOS LADOS
                    limpar_bloco(&elemento_atual->esquerda);

                    // Religa os ponteiros (Ida e Volta)
                    elemento_atual->direita                 = novo_realigamento_dois_frente;
                    novo_realigamento_dois_frente->esquerda = elemento_atual;
                }

                // Se não tem ninguém depois, é o fim da lista
                else
                {
                    limpar_bloco(&elemento_atual->direita);
                }
            }
            //-----------------------------------------------------------------------  
        }
        
        elemento_atual = elemento_atual->direita;
        
    }
    display(elemento_atual);

    limpar_encadeadas(&expressao_inicio);
    return 0;
}
