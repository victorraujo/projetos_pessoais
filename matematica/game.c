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

main(void)
{

    Tipo *expressao_inicio = NULL;
    Tipo *expressao = NULL;

    char *prompt_texto == NULL;
    size_t buffer = 0;

    getline(&prompt_texto, &buffer, stdin); // pedir expressão ao usuario
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

        //            boleanas para quebra de expressão
        bool eh_simbolo_mutiplicacao = (*proxima_parte == '*' || toupper(*proxima_parte) == 'X');
        bool eh_simbolo_barra = (*proxima_parte == '/');
        bool eh_simbolo_mais = (*proxima_parte == '+');
        bool eh_simbolo_menos = (*proxima_parte == '-');

        bool eh_o_fim = (*proxima_parte == '\0');

        // caso alguma seja verdade
        if (eh_simbolo_mutiplicacao || eh_simbolo_barra || eh_simbolo_mais || eh_simbolo_menos)
        {
            if (expressao == NULL)
            {
                Tipo *tmp_expressao = malloc(sizeof(Tipo));
                tmp_expressao->numero = malloc(sizeof(double));
                if (tmp_expressao == NULL || tmp_expressao->numero == NULL)
                {
                    return 1;
                }

                // NÓS
                tmp_expressao->esquerda = NULL;
                tmp_expressao->direita = NULL;

                *tmp_expressao->numero = valor_token;
                tmp_expressao->token = NULL;

                expressao_inicio = tmp_expressao;
                expressao = tmp_expressao;
            }
            else
            {
                Tipo *tmp_expressao = malloc(sizeof(Tipo));
                tmp_expressao->numero = malloc(sizeof(double));

                expressao->direita = tmp_expressao; // o antigo liga com o novo

                tmp_expressao->esquerda = expressao; // o novo liga com o antigo
                tmp_expressao->direita = NULL;

                *tmp_expressao->numero = valor_token;
                tmp_expressao->token = NULL;

                expressao = tmp_expressao; // anda
            }

            Tipo *atribute_token = malloc(sizeof(Tipo));
            atribute_token->token = malloc(sizeof(char));
            if (atribute_token == NULL || atribute_token->== NULL)
                return 1;

            expressao->direita = atribute_token;

            atribute_token->esquerda = expressao;
            atribute_token->direita = NULL;

            atribute_token->numero = NULL;
            *atribute_token->token = proxima_parte[0];
        }
        if (eh_o_fim) // caso Seja o caractere final
        {
            Tipo *tmp_expressao = malloc(sizeof(Tipo));
            tmp_expressao->numero = malloc(sizeof(double));
            if (tmp_expressao == NULL || tmp_expressao->numero == NULL)
                return 1; // erro de locação

            *tmp_expressao->numero = valor_token;
            tmp_expressao->token = NULL;

            valor_token = 0;
            if (expressao == NULL)
            {
                tmp_expressao->esquerda = NULL;
                tmp_expressao->direita = NULL;

                expressao = tmp_expressao;
                expressao_inicio = expressao;
            }
            else
            {
                expressao->direita = tmp_expressao;
                tmp_expressao->esquerda = expressao;
                tmp_expressao->direita = NULL;
                expressao = tmp_expressao;
            }
            break;
        }
        // andar
        percorrer_string = proxima_parte;
    }

    free(prompt_texto);


    // ACHAR MULTIPLICAÇÃO OU DIVIÃO (prioridade 2)
    Tipo *elemento_atual = expressao_inicio;
    if (elemento_atual == NULL) return 1;


    while (elemento_atual != NULL)
    {
        bool eh_mutiplicacao = (elemento_atual->token == '*' || toupper(elemento_atual->token) == 'X');
        bool eh_divisao      = (elemento_atual->token == '/');

        if (eh_mutiplicacao || eh_divisao)
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
    

            if (eh_mutiplicação)
            {
                free(elemento_atual->token);
                elemento_atual->token = NULL;
                resultado = numero_esquerda * numero_direita;
            }
            if (eh_divisao)
            {
                free(elemento_atual->token);
                elemento_atual->token = NULL;
                if (*numero_direita == 0)
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
                    limpar_bloco(&elemento_atual->esquerda)
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
                    limpar_bloco(&elemento_atual->esquerda)

                    // Religa os ponteiros (Ida e Volta)
                    elemento_atual->direita                 = novo_realigamento_dois_frente;
                    novo_realigamento_dois_frente->esquerda = elemento_atual;
                }

                // Se não tem ninguém depois, é o fim da lista
                else
                {
                    limpar_bloco(&elemento_atual->esquerda)
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
        bool eh_simbolo_mais  = (*elemento_atual->token  == '+');
        bool eh_simbolo_menos = (*elemento_atual->token == '-');
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
                elemento_atual = NULL;
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
                    limpar_bloco(&elemento_atual->esquerda)
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
                    limpar_bloco(&elemento_atual->esquerda)

                    // Religa os ponteiros (Ida e Volta)
                    elemento_atual->direita                 = novo_realigamento_dois_frente;
                    novo_realigamento_dois_frente->esquerda = elemento_atual;
                }

                // Se não tem ninguém depois, é o fim da lista
                else
                {
                    limpar_bloco(&elemento_atual->esquerda)
                }
            }
            //-----------------------------------------------------------------------  
        }
        elemento_atual = elemento_atual->direita;
    }

    limpar_encadeadas(&expressao_inicio);
}
