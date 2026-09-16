
// acerte todas as ods!!


#include <stdio.h>
#include <stdlib.h>  // malloc
#include <stdbool.h> // true e false
#include <string.h>  // strlen | strcmp
#include <ctype.h>   // toupper

// WINDOWS OU LINUX
#ifdef _WIN32
#include <windows.h>

#else
#include <unistd.h>
#endif

#define MAX_ODS 17

typedef struct ods_status
{
    char *ods_nome; // nome ods
    int ods_numero; // numero da ods

    // metadados
    struct ods_status *esquerda;
    struct ods_status *direita;
} ods_status;

typedef struct
{
    char *prompt;
    size_t tamanho;

} status_usuario;

// CRIAR TEXTOS MAIS FACEIS
char *criacao_textual(char *ptr)
{
    size_t tamanho = strlen(ptr) + 1;
    char *tmp_ptr = malloc(tamanho * sizeof(char));
    if (tmp_ptr == NULL)
        return NULL;

    strcpy(tmp_ptr, ptr);
    return tmp_ptr;
}
//  STRINGS DINAMICAS (AUMENTA O TAMANHO A CADA 50)
void cstring(char **ptr, size_t *size)
{
    //~~~~~~TEMPORARIO~~~~~~~~
    //----BUFFER || SIZE-----
    int buffer = 0;       //| variavel aumenta a cada caractere
    size_t tmp_size = 50; //| a cada 50 ele dobra (TOTAL TAMANHO DO BLOCO PRA NÃO DAR REALLOC DIRETO)
    //------------------------

    char *tmp_ptr = malloc(tmp_size * sizeof(char));
    if (tmp_ptr == NULL)
    {
        return;
    }

    int caractere = 0; // number ascii

    while ((caractere = getchar()) != '\n' && caractere != EOF)
    {
        if (buffer + 1 >= tmp_size)
        {
            tmp_size = tmp_size + 50;             // increment
            tmp_ptr = realloc(tmp_ptr, tmp_size); // auementa reallocando
            if (tmp_ptr == NULL)
            {
                return;
            }
        }
        tmp_ptr[buffer] = caractere; // increment
        buffer++;                    // proxima rodada
    }
    tmp_ptr[buffer] = '\0'; // final do caractere
    //----modifying variables----------
    *ptr = tmp_ptr; // ptr ofc   |volta
    *size = buffer; // size ofc |volta
    //----------------------------------
}

// LIBERAR MEMORIA DO MODULO DE ODS
void liberar_ods(ods_status *ods)
{
    //  LIBERAÇÃO DA MEMORIA ALLOCADA
    ods_status *atual = ods;
    ods_status *proximo = NULL;
    while(true)
    {
        proximo = atual->direita;

        free(atual->ods_nome);
        free(atual);

        if (proximo == NULL)
        {
            break;
        }

        atual = proximo;
    }
    return;
}

void clear(void)
{
    printf("\033[H\033[J");
}

int main(void)
{
    ods_status *inicio; // inicio da lista
    ods_status *ods = NULL;

    int contador = 0;

    while (contador < MAX_ODS)
    {
        ods_status *tmp_ods = malloc(sizeof(ods_status));
        if (tmp_ods == NULL)
        {
            liberar_ods(inicio);
            return 1; // segurança
        }
        // zeramento
        tmp_ods->ods_nome = NULL;
        tmp_ods->ods_numero = 0;

        switch (contador + 1)
        {
        case 1:

            tmp_ods->ods_nome = criacao_textual("erradicação da pobreza");
            if (tmp_ods->ods_nome == NULL)
                
                return 1;
            break;

        case 2:
            tmp_ods->ods_nome = criacao_textual("fome zero e agricultura sustentável");
            if (tmp_ods->ods_nome == NULL)
                return 1;
            break;

        case 3:
            tmp_ods->ods_nome = criacao_textual("saúde e bem estar");
            if (tmp_ods->ods_nome == NULL)
                return 1;
            break;

        case 4:
            tmp_ods->ods_nome = criacao_textual("educação de qualidade");
            if (tmp_ods->ods_nome == NULL)
                return 1;
            break;

        case 5:
            tmp_ods->ods_nome = criacao_textual("igualdade de gênero");
            if (tmp_ods->ods_nome == NULL)
                return 1;
            break;

        case 6:
            tmp_ods->ods_nome = criacao_textual("água potável e saneamento");
            if (tmp_ods->ods_nome == NULL)
                return 1;
            break;

        case 7:
            tmp_ods->ods_nome = criacao_textual("energia limpa e acessível");
            if (tmp_ods->ods_nome == NULL)
                return 1;
            break;

        case 8:
            tmp_ods->ods_nome = criacao_textual("trabalho decente e crescimento econômico");
            if (tmp_ods->ods_nome == NULL)
                return 1;
            break;

        case 9:
            tmp_ods->ods_nome = criacao_textual("indústria, inovação e infraestrutura");
            if (tmp_ods->ods_nome == NULL)
                return 1;
            break;

        case 10:
            tmp_ods->ods_nome = criacao_textual("redução das desigualdades");
            if (tmp_ods->ods_nome == NULL)
                return 1;
            break;

        case 11:
            tmp_ods->ods_nome = criacao_textual("cidades e comunidades sustentáveis");
            if (tmp_ods->ods_nome == NULL)
                return 1;
            break;

        case 12:
            tmp_ods->ods_nome = criacao_textual("consumo e produção responsáveis");
            if (tmp_ods->ods_nome == NULL)
                return 1;
            break;

        case 13:
            tmp_ods->ods_nome = criacao_textual("ação contra a mudança global do clima");
            if (tmp_ods->ods_nome == NULL)
                return 1;
            break;

        case 14:
            tmp_ods->ods_nome = criacao_textual("vida na água");
            if (tmp_ods->ods_nome == NULL)
                return 1;
            break;

        case 15:
            tmp_ods->ods_nome = criacao_textual("vida terrestre");
            if (tmp_ods->ods_nome == NULL)
                return 1;
            break;

        case 16:
            tmp_ods->ods_nome = criacao_textual("paz, justiça e instituições eficazes");
            if (tmp_ods->ods_nome == NULL)
                return 1;
            break;

        case 17:
            tmp_ods->ods_nome = criacao_textual("parcerias e meios de implementação");
            if (tmp_ods->ods_nome == NULL)
                return 1;
            break;

        default:
            break;
        }
        if (tmp->ods_nome == NULL)
        {
            liberar_ods(inicio);
            return 2;
        }
        tmp_ods->ods_numero = contador + 1;

        // listas encadeadas
        if (ods == NULL)
        {
            inicio = tmp_ods; // marcar o primeiro elemento

            tmp_ods->esquerda = NULL;
            tmp_ods->direita = NULL;
            ods = tmp_ods;
        }
        else
        {
            ods->direita = tmp_ods;  // apontar para o proximo (TMP_ODS)
            tmp_ods->esquerda = ods; // apontar para o antigo (ODS)
            tmp_ods->direita = NULL; // o novo da direita vai apontar  pra nada

            ods = tmp_ods; // andar na lista
        }
        contador++;
    }

    // JOGO COMEÇA AQUI
    status_usuario usuario;

    while (true)
    {
        printf("s = continue\n"
               "n = parar\n");

        cstring(&usuario.prompt, &usuario.tamanho);
        if (usuario.prompt == NULL)
        {
            liberar_ods(inicio);
            free(usuario.prompt);
            return 2;
        }
        
        if (strcmp(usuario.prompt, "n") == 0 || strcmp(usuario.prompt, "N") == 0)
        {
            liberar_ods(inicio);
   
            
            free(usuario.prompt);
            usuario.tamanho = 0;
            break;
        }
        free(usuario.prompt);
        usuario.tamanho = 0;


        clear();
        printf("\n===================================================\n");
        printf("     🎮 INICIANDO O DESAFIO DAS 17 ODS            \n");
        printf("===================================================\n\n");
        ods_status *sensor = inicio;

        #ifdef _WIN32 // windows 2 segundos
            Sleep(2000);
        #else // linux 2 segundos
            sleep(2);
        #endif

        contador = 0;

        while (contador < MAX_ODS)
        {
            printf("qual e a ods [%d]\n", contador+1);

            cstring(&usuario.prompt, &usuario.tamanho);
            if (usuario.prompt == NULL)
            {
                // SEGURAÇA
                liberar_ods(inicio);
                break;
            }

            //           DEIXA STRING MINUSCULA
            for (int i = 0; usuario.prompt[i] != '\0'; i++)
            {
                usuario.prompt[i] = tolower(usuario.prompt[i]);
            }
            //                   COMPARA
            if (strcmp(usuario.prompt, sensor->ods_nome) == 0)
            {
                // ACERTOU
                printf("\n--------------\n");
                printf("RESULTADO = ✅\n");
                printf("ODS:\n"
                        "%d, %s\n",
                        sensor->ods_numero, sensor->ods_nome);
                printf("--------------\n");
            }
            else
            {
                // ERROU E FINALIZA
                printf("\n--------------\n");
                printf("\nRESULTADO = ❌\n");
                printf("ODS:\n"
                       "%d, %s\n\n",
                        sensor->ods_numero, sensor->ods_nome);
                printf("--------------\n");
            }
            //   LIBERAR
            free(usuario.prompt);
            usuario.prompt = NULL;

            // ZERAR
            usuario.tamanho = 0;
            //    ANDAR
            sensor = sensor->direita;
            contador++;
        }
    }
    liberar_ods(inicio);
    free(usuario.prompt);
    return 0;
}