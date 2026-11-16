#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


#ifdef _WIN32
    #include <windows.h>
    // Cria uma função "usleep" falsa no Windows que converte para milissegundos
    void usleep(unsigned int microssegundos) 
    {
        Sleep(microssegundos / 1000);
    }
#elif __linux__
    #include <unistd.h> // No Linux, a usleep original já existe aqui
#endif



#define CAR2_Y 1

typedef enum
{
    MONITOR_ALTURA  = 2,
    MONITOR_LARGURA = 40,
    MONITOR_BASE     = 8
} MonitorDimensoes_t;

typedef struct
{
    int atual;
}System_t;
typedef struct Carro_t
{
    int posicaoY;
    int posicaoX;
    bool vitoria;
    char* eskin;
    void (*velocidade)(struct Carro_t*);
    void (*verificarVitoria)(struct Carro_t*);
}Carro_t;

void velocidade_fun(Carro_t* v)
{
    const int max_x = 4;
    int teto_andar = MONITOR_LARGURA - v->posicaoX;
    
    if (teto_andar == 0 ) { return; }
    if (teto_andar > max_x) { teto_andar = max_x; }
    
   int passo = (rand() % teto_andar) +1;
   v->posicaoX = v->posicaoX + passo;
}


void carro_verificar_vitoria_fun(Carro_t* carro)
{
    carro->vitoria = (carro->posicaoX >= MONITOR_LARGURA);
    
}
typedef struct Monitor_t
{
    char tela[MONITOR_ALTURA][MONITOR_LARGURA][MONITOR_BASE];
    //void (*mostrarCarro)(struct Monitor_t*, const Carro_t*);
    void (*init)(struct Monitor_t*);
    void (*mostrarTela)(struct Monitor_t*);
    void (*clear)(void);
    void (*colocarCarro)(struct Monitor_t*, const Carro_t*);
    void (*removerCarro)(struct Monitor_t*, const Carro_t*);
    
} Monitor_t;

void monitorInit_fun(Monitor_t* strct)
{
    for(int i = 0; i < MONITOR_ALTURA; i++)
    {
        for(int j = 0; j < MONITOR_LARGURA; j++)
        {
            strcpy(strct->tela[i][j], "  ");
        }
    }
}

void monitor_mostrarTela_fun(Monitor_t* strct)
{
    for(int i = 0; i < MONITOR_ALTURA; i++)
    {
        for(int j = 0; j < MONITOR_LARGURA; j++)
        {
            printf("%s", strct->tela[i][j]);
        }
        printf("\n");
    }
}

void monitor_clear_fun(void)
{
    #ifdef _WIN32
        system("cls");
    #elif __linux__
        printf("\033[2J\033[H");
    #endif
}


void monitor_colocar_carro_fun(Monitor_t* monitor, const Carro_t* carro)
{
    // DADOS SIMPLIFICADO PARA COLOCAR NA MATRIZ
    const int y = carro->posicaoY;
    const int x = carro->posicaoX;
    const char *modelo = carro->eskin;
    
    // ORIGEM || DESTINO
    strcpy(monitor->tela[y][x], modelo);
    
}
void monitor_remover_carro_fun(Monitor_t* monitor, const Carro_t* carro)
{
    // DADOS SIMPLIFICADO PARA COLOCAR NA MATRIZ
    const int y = carro->posicaoY;
    const int x = carro->posicaoX;
    const char *modelo = carro->eskin;
    
    // ORIGEM || DESTINO
    strcpy(monitor->tela[y][x], "  ");
}
#include <string.h>
#define NEW_MONITOR                       \
{                                          \
    .init         = monitorInit_fun,        \
    .mostrarTela  = monitor_mostrarTela_fun, \
    .clear        = monitor_clear_fun,        \
    .colocarCarro = monitor_colocar_carro_fun, \
    .removerCarro = monitor_remover_carro_fun   \
};

#define NEW_SYSTEM \
{                   \
    .atual = RODANDO \
};

#define NEW_CARRO                             \
{                                              \
    .posicaoY   = 0,                            \
    .posicaoX   = 0,                             \
    .vitoria    = false,                          \
    .velocidade = velocidade_fun,                  \
    .verificarVitoria = carro_verificar_vitoria_fun \
};

int main(void)
{
    #ifdef _WIN32
        system(""); // Faz o terminal do Windows destravar a tabela Escape (\033)
#endif

    srand(time(NULL));
    Carro_t car1 = NEW_CARRO;
    Carro_t car2 = NEW_CARRO;
    
    car1.eskin = "🚙 ";
    
    car2.eskin    = "🚗 ";
    car2.posicaoY = CAR2_Y;
    // CRIAÇÃO DO VISUAL DO TERMINAL E INICIAR
    Monitor_t monitor = NEW_MONITOR;
    monitor.init(&monitor);
    
    while(car1.vitoria != true && car2.vitoria != true)
    {
        monitor.colocarCarro(&monitor, &car1);
        monitor.colocarCarro(&monitor, &car2);
        
        monitor.mostrarTela(&monitor);
        
        monitor.removerCarro(&monitor, &car1);
        monitor.removerCarro(&monitor, &car2);
        
        car1.velocidade(&car1);
        car1.velocidade(&car2);
        
        car1.verificarVitoria(&car1);
        car2.verificarVitoria(&car2);
        usleep(350000); // 0.35 segundo
        monitor.clear();
    }
    if (car1.vitoria == true && car2.vitoria == true)
    {
        puts("empate")
    }
    else if (car1.vitoria == true)
    {
        puts("carro 1 ganhou");
    }
    else if (car2.vitoria == true)
    {
        puts("carro 2 ganhou");
    }

    return 0;
}