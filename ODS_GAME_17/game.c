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
    char *ods_nome;      // nome ods
    int ods_numero; // numero da ods

    // metadados
    struct ods_status *esquerda;
    struct ods_status *direita;
} ods_status;

typedef struct 
{
    char *prompt;
    int tamanho;

} status_usuario;



// CRIAR TEXTOS MAIS FACEIS
char* criacao_textual (char* ptr)
{
    size_t tamanho = strlen(ptr) + 1;
    char* tmp_ptr = malloc(tamanho * sizeof(char));
    if (tmp_ptr == NULL) return NULL;


    strcpy(tmp_ptr, ptr);
    return tmp_ptr;

}
//  STRINGS DINAMICAS (AUMENTA O TAMANHO A CADA 50)
void cstring(char **ptr, size_t *size)
{
    //~~~~~~TEMPORARIO~~~~~~~~
    //----BUFFER || SIZE-----
    int buffer = 0;         //| variavel aumenta a cada caractere
    size_t tmp_size = 50;   //| a cada 50 ele dobra (TOTAL TAMANHO DO BLOCO PRA NÃO DAR REALLOC DIRETO)
    //------------------------

    char *tmp_ptr = malloc(tmp_size * sizeof(char));
    if (tmp_ptr == NULL)
    {
        return;
    }

    int caractere = 0; //number ascii

    while ((caractere = getchar()) != '\n' && caractere != EOF)
    {
        if (buffer + 1 >= tmp_size)
        {
            tmp_size = tmp_size + 50;  // increment
            tmp_ptr = realloc(tmp_ptr, tmp_size); // auementa reallocando
            if (tmp_ptr == NULL)
            {
                return;
            }
        }
        tmp_ptr[buffer] = caractere; // increment
        buffer++;                    // proxima rodada
    }
    tmp_ptr[buffer] = '\0';          // final do caractere
    //----modifying variables----------
    *ptr = tmp_ptr; // ptr ofc   |volta
    *size = buffer;  // size ofc |volta
    //----------------------------------
}

void clear(void)
{
    printf("\033[H\033[J"); 
}

int main(void)
{
    struct ods_status *inicio; // inicio da lista
    ods_status *ods = NULL;

    int contador = 0;

    while (contador < MAX_ODS)
    {
        ods_status *tmp_ods = malloc(sizeof(ods_status));
        if (tmp_ods == NULL) return 1; // segurança

        // zeramento
        tmp_ods->ods_nome   = NULL;
        tmp_ods->ods_numero = 0;
        tmp_ods->tamanho    = 0;


        
        switch (contador + 1)
        {
        case 1:
            
            tmp_ods->ods_nome = criacao_textual("Erradicação da Pobreza ");
            if (tmp_ods->ods_nome == NULL) return 1;
            break;

        case 2:
            tmp_ods->ods_nome = criacao_textual("Fome Zero e Agricultura Sustentável");
            if (tmp_ods->ods_nome == NULL) return 1;
            break;

        case 3:
            tmp_ods->ods_nome = criacao_textual("Saúde e Bem-Estar");
            if (tmp_ods->ods_nome == NULL) return 1;
            break;

        case 4:
            tmp_ods->ods_nome = criacao_textual("Educação de Qualidade");
            if (tmp_ods->ods_nome == NULL) return 1;
            break;

        case 5:
            tmp_ods->ods_nome = criacao_textual("Igualdade de Gênero ");
            if (tmp_ods->ods_nome == NULL) return 1;
            break;

        case 6:
            tmp_ods->ods_nome = criacao_textual("Água Potável e Saneamento");
            if (tmp_ods->ods_nome == NULL) return 1;
            break;

        case 7:
            tmp_ods->ods_nome = criacao_textual("Energia Limpa e Acessível");
            if (tmp_ods->ods_nome == NULL) return 1;
            break;

        case 8:
            tmp_ods->ods_nome = criacao_textual("Trabalho Decente e Crescimento Econômico");
            if (tmp_ods->ods_nome == NULL) return 1;
            break;

        case 9:
            tmp_ods->ods_nome = criacao_textual("Indústria, Inovação e Infraestrutura");
            if (tmp_ods->ods_nome == NULL) return 1;
            break;

        case 10:
            tmp_ods->ods_nome = criacao_textual("Redução das Desigualdades");
            if (tmp_ods->ods_nome == NULL) return 1;
            break;

        case 11:
            tmp_ods->ods_nome = criacao_textual("Cidades e Comunidades Sustentáveis");
            if (tmp_ods->ods_nome == NULL) return 1;
            break;

        case 12:
            tmp_ods->ods_nome = criacao_textual("Consumo e Produção Responsáveis");
            if (tmp_ods->ods_nome == NULL) return 1;
            break;

        case 13:
            tmp_ods->ods_nome = criacao_textual("Ação Contra a Mudança Global do Clima");
            if (tmp_ods->ods_nome == NULL) return 1;
            break;

        case 14:
            tmp_ods->ods_nome = criacao_textual("Vida na Água");
            if (tmp_ods->ods_nome == NULL) return 1;
            break;

        case 15:
            tmp_ods->ods_nome = criacao_textual("Vida Terrestre");
            if (tmp_ods->ods_nome == NULL) return 1;
            break;

        case 16:
            tmp_ods->ods_nome = criacao_textual("Paz, Justiça e Instituições Eficazes");
            if (tmp_ods->ods_nome == NULL) return 1;
            break;

        case 17:
            tmp_ods->ods_nome = criacao_textual("Parcerias e Meios de Implementação");
            if (tmp_ods->ods_nome == NULL) return 1;
            break;

        default:
            break;
        }
        tmp_ods->ods_numero = contador + 1;


        // listas encadeadas
        if (ods == NULL)
        {
           inicio = tmp_ods; // marcar o primeiro elemento

           tmp_ods->esquerda = NULL;
           tmp_ods->direita  = NULL;
           ods = tmp_ods;
        }
        else
        {
            ods->direita      = tmp_ods;  // apontar para o proximo (TMP_ODS)
            tmp_ods->esquerda = ods; // apontar para o antigo (ODS)
            tmp_ods->direita  = NULL; // o novo da direita vai apontar  pra nada

            ods = tmp_ods; // andar na lista
        }
        contador++;
    }  

    // JOGO COMEÇA AQUI
    status_usuario usuario;

    while (true)
    {
        
        printf("\n===================================================\n");
        printf("     🎮 INICIANDO O DESAFIO DAS 17 ODS            \n");
        printf("===================================================\n\n");

        printf("s = continue\n"
               "n = parar\n");
        
        string(&usuario.prompt, &usuario.tamanho);
        if (usuario.prompt == NULL)
        {
            return 2;
        }
        if (strcmp(*usuario.prompt, "n" ) == 0 || strcmp(*usuario.prompt, "n") == 0) 
        {
            free(usuario.prompt);
            usuario.tamanho = 0;
            break;
        }
        free(usuario.prompt);
        usuario.tamanho = 0;

        ods_status *sensor = inicio;

        #ifdef _WIN32 // windows 2 segundos
            Sleep(2000);
        #else // linux 2 segundos
            sleep(2);
        #endif

        contador = 0;
        resultados[MAX_ODS] = {0};
        while (contador + 1 < MAX_ODS)
        {
            clear();
            printf("%d\n\n", sensor->ods_numero);
            printf("qual e a ods [%d]", contador);

            cstring(usuario.prompt, tamanho);

            if (toupper(usuario.prompt) == toupper(sensor->ods_nome))
            {
                
                printf("RESULTADO = ✅\n");
                printf("ODS:\n"
                        "%d, %s", sensor->ods_numero, sensor->ods_nome);
                sensor = sensor->direita;
                
                contador++;
            }
            else
            {
                printf("RESULTADO = ❌\n");
                printf("ODS:\n"
                        "%d, %s", sensor->ods_numero, sensor->ods_nome);

                break;
            }   
        }
    }
}