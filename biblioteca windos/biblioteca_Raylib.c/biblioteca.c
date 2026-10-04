#include <stdio.h>
#include "raylib.h"

#define LARGURA 700
#define ALTURA 500
#define TITULO "Primeira Janela"

int main(void)
{
    // Nota: O padrão da Raylib é InitWindow(largura, altura, titulo)
    InitWindow(LARGURA, ALTURA, TITULO);      
    SetTargetFPS(60);

    // Ciclo principal do jogo/aplicação
    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Janela criada com sucesso!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow(); // Fecha a janela e o contexto OpenGL

    return 0;
}