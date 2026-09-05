#include <stdio.h>
#include <stdbool.h>
#include <windows.h> // biblioteca que conversa com o Windows

int main(void)
{
    LARGE_INTEGER frequencia;
    LARGE_INTEGER tempo_agora;

    QueryPerformanceFrequency(&frequencia);
    QueryPerformanceCounter(&tempo_agora);

    printf("Frequencia do seu PC: %lld pulsos por segundo\n", frequencia.QuadPart);
    printf("Valor atual do cronometro: %lld\n", tempo_agora.QuadPart);
    int frames_fps = 0;
    while (true)
    {
        frames_fps = 0;

        
    }
}