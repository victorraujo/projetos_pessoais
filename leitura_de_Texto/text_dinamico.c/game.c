#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int c;
    printf("diga algo:");
    while(c = getchar())
    {
        printf("peguei: %c", c);
    }

}