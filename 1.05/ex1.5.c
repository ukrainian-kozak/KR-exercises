#include <stdio.h>

int main() 
{
    int c = getchar();

    while ((c = getchar()) != EOF)
        putchar(c);

    putchar(c);

    return 0;
}
