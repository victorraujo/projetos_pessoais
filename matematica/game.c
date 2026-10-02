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

Tipo *token_string(char *token_atual, char *proximo_token, double token_numero)
{
    Tipo *tmp_string = malloc(sizeof(Tipo));
    if (tmp_string == NULL)
        return 1;
}
void converter_em_numero

    int
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
    // achar mutiplicação e divisão (prioridade 2)

    Tipo *procurador_de_token = expressao_inicio;
    if (procurador_de_token == NULL)
        return 1;
    while (procurador_de_token != NULL)
    {
        bool eh_mutiplicacao = (procurador_de_token->token == '*' || toupper(procurador_de_token->token) == 'X');
        bool eh_divisao      = (procurador_de_token->token == '/');

        if (eh_mutiplicacao || eh_divisao)
        {
            // pre status para calculo
            procurador_de_token->numero = malloc(sizeof(double));
            if (procurador_de_token->numero == NULL) return 1;

            double numero_esquerda = *(procurador_de_token->esquerda->numero);
            double numero_direita  = *(procurador_de_token->direita->numero);
            double resultado = 0;
  

            if (eh_mutiplicação)
            {
                free(procurador_de_token->token);
                procurador_de_token->token = NULL;
                resultado = numero_esquerda * numero_direita;
            }
            if (eh_divisao)
            {
                free(procurador_de_token->token);
                procurador_de_token->token = NULL;
                resultado = numero_esquerda / numero_direita;
            }
                //atribui o resultado ->
                *procurador_de_token->numero = resultado;


            //------------ORGANIZANDO OS PONTEIRO APÓS EXPRESSÃO RESOLVIDA-------------------------------
            //   

            // ==================== NÓS À ESQUERDA <- ====================
            if (procurador_de_token->esquerda != NULL)
            {
                // existe elementos a frente
                if (procurador_de_token->esquerda->esquerda != NULL)
                {
                    //      SINTAXE MAIS FACIL (REALIGAR PONTEIRO APÓS RESOLVER EXPRESSÃO)
                    Tipo* novo_realigamento_dois_tras    = procurador_de_token->esquerda->esquerda; // salvei 2 nós a frente
                    Tipo* novo_realigamento_atual        = procurador_de_token;                     // mudei o nome para facilitar leitura 

                    // DESLIGAR PONTEIRO DO LADO ESQUERDO
                    Tipo* desligamento_ponteiro = novo_realigamento_atual;
                    free(desligamento_ponteiro->esquerda);

                    // Religa os ponteiros (Ida e Volta)
                    novo_realigamento_atual->esquerda    = novo_realigamento_dois_tras;
                    novo_realigamento_dois_tras->direita = novo_realigamento_atual;  
                }

                // Se não tem ninguém depois, é o fim da lista
                else
                {
                    free(procurador_de_token->esquerda);
                    procurador_de_token->esquerda = NULL;
            
                }
            }
        
            // ==================== NÓS À DIREITA -> ====================
           
            if (procurador_de_token->direita != NULL)
            {
                if (procurador_de_token->direita->direita != NULL)
                {
                    //      SINTAXE MAIS FACIL (REALIGAR PONTEIRO APÓS RESOLVER EXPRESSÃO)
                    Tipo* novo_realigamento_dois_frente = procurador_de_token->direita->direita; // salvei 2 nós a frente
                    Tipo* novo_realigamento_atual       = procurador_de_token;                   // mudei o nome para facilitar leitura           

                    // DESLIGAR PONTEIRO DOS LADOS
                    Tipo* desligamento_ponteiro = novo_realigamento_atual;
                    free(desligamento_ponteiro->direita);

                    // Religa os ponteiros (Ida e Volta)
                    novo_realigamento_atual->direita        = novo_realigamento_dois_frente;
                    novo_realigamento_dois_frente->esquerda = novo_realigamento_atual;
                }

                // Se não tem ninguém depois, é o fim da lista
                else
                {
                    free(procurador_de_token->direita);
                    procurador_de_token->direita = NULL;
                }
                
            }
            //-----------------------------------------------------------------------
        }

    procurador_de_token = procurador_de_token->direita;
    }
}
