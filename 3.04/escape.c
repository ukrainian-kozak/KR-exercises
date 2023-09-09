#include <stdio.h>

int main()
{
    int c;
    while ((c = getchar()) != EOF) {
        switch(c) {
            case '\n':
                putchar('\\');
                putchar('n');
                break;
            case '\t':
                putchar('\\');
                putchar('t');
                break;
            default:
                putchar(c);
                break;
        }
    }
    return 0;
}
