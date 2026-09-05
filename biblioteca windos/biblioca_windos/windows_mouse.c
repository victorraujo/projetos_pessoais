#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

int main(void)
{
   int larguraDatela = GetSystemMetrics(SM_CXSCREEN);
   int alturaDatela = GetSystemMetrics(SM_CYSCREEN);

   int centroX = larguraDatela / 2;
   int centroY = alturaDatela / 2;

   int destinoX = 0;
   int destinoY = 0;

   int x = centroX;
   int y = centroY;
   printf("Sua tela eh de: %ix%i\n", larguraDatela, alturaDatela);
   printf("O mouse vai comecar no centro: (%i, %i)\n", x, y);
   printf("Digite o X e Y de destino: ");

   scanf("%i %i", &destinoX, &destinoY);


   // zona de mover o cursor
   while (x < destinoX || y < destinoY)
   {
       SetCursorPos(x, y);

       if (x < destinoX) x++;

       if (y < destinoY) y++;

       Sleep(3);
   }

   // zona de click
   INPUT clique = {0};
   clique.type = INPUT_MOUSE;
   clique.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
   SendInput(1,&clique, sizeof(INPUT));
   Sleep(10);


   return 0;
}