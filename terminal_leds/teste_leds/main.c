#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALTURA 20
#define LARGURA 20

typedef enum
{
  SAIR,
  RODANDO
} sistema;

typedef enum
{
    LED_RESET,
    LED_RED,
    LED_GREEN,
    LED_YELLOW,
    LED_BLUE,
    LED_MAGENTA,
    LED_CYAN,
    LED_WHITE,
    LED_BOLD_WHITE,
    LED_BRIGHT_WHITE,
    LED_MAX // Guarda automaticamente o total de cores (10)
} colors_led;
const char* leds_enderecos[LED_MAX] = {
    [LED_RESET]        = "\033[0m",
    [LED_RED]          = "\033[31m",
    [LED_GREEN]        = "\033[32m",
    [LED_YELLOW]       = "\033[33m",
    [LED_BLUE]         = "\033[34m",
    [LED_MAGENTA]      = "\033[35m",
    [LED_CYAN]         = "\033[36m",
    [LED_WHITE]        = "\033[37m",
    [LED_BOLD_WHITE]   = "\033[1;37m",
    [LED_BRIGHT_WHITE] = "\033[97m"
};
const char* cores_fundo[LED_MAX] = {
    [LED_RESET]   = "40",     [LED_RED]   = "41",     [LED_GREEN] = "42",
    [LED_YELLOW]  = "43",     [LED_BLUE]  = "44",     [LED_MAGENTA] = "45",
    [LED_CYAN]    = "46",     [LED_WHITE] = "47"
};


typedef struct 
{
    const char* pixel_shape;     // Guarda o formato do LED (ex: "■")
    int cor;        // Guarda o ID da cor (ex: LED_RED)
    int cor_fundo;
    int token_id;   // O identificador único desse bloco específico!

}tela_bloco_t;
typedef struct painel_t{
    tela_bloco_t tela[ALTURA][LARGURA]; // Guarda o ID da cor de cada LED (ex: LED_RED, LED_GREEN)
    int largura;
    int altura;
    // estrutura que quer, estilo, altura, largura
    void(*painel_init)(struct painel_t*, const char*); //inciar estrutura
    void(*painel_display)(struct painel_t*);
    
    //decida a cor
    void(*painel_led)(int cor);
} painel_t;

// --- FUNÇÕES REAIS ---

// --- FUNÇÕES PAINEL ---
void painel_init_fun(painel_t* strct, const char* skin)
{  
    int id = 0;
        // Preenche toda a matriz com a string do bloco "■"
    for(int i = 0; i < ALTURA; i++) {
        for(int j = 0; j < LARGURA; j++) {
            strct->tela[i][j].pixel_shape = skin;
            strct->tela[i][j].cor = LED_WHITE;
            strct->tela[i][j].token_id = id;
            id++;
        }
    }
    strct->altura  = ALTURA;
    strct->largura = LARGURA;
    
    return;
}
void painel_display_fun(painel_t* strct)
{
    for(int i = 0; i < strct->altura; i++){
        for(int j = 0; j < strct->largura; j++){
            printf("%s ", strct->tela[i][j].pixel_shape);
        }
        printf("\n");
    }
}

void painel_led_fun(int cor)
{
    printf("%s", leds_enderecos[cor]);
    
}
void painel_cursor_reset()
{
    printf("\033[H");
    fflush(stdout);
}
// 1 ligar || 0 desligar
void painel_cursor_visivel(int op)
{
    if (op == 1)
    {
        printf("\033[?25h\033[0m\n");
    }
    else if (op == 0)
    {
        
        printf("\033[?25l"); 
    }
}
 // MACROS PONTEIROS
 
 // Esse macro preenche os ponteiros de função de forma invisível para você
#define NEW_PAINEL { \
    .painel_init    = painel_init_fun, \
    .painel_display = painel_display_fun, \
    .painel_led     = painel_led_fun \
}


int main(void)
{
    painel_t interface = NEW_PAINEL;
    interface.painel_init(&interface, "██");
    
    int modo = RODANDO;
    painel_cursor_visivel(0);
    while(modo == RODANDO)
    {
        interface.painel_led(LED_BLUE);
        interface.painel_display(&interface);
        painel_cursor_reset();
        interface.painel_led(LED_GREEN);
        interface.painel_display(&interface);
        painel_cursor_reset();
        interface.painel_led(LED_RED);
        interface.painel_display(&interface);
        painel_cursor_reset();
        
        
    }
    painel_cursor_visivel(1);
    
}
