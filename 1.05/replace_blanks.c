#include <stdio.h>

int main()
{
    int prev, c;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            c = ' ';

        if (c == ' ' && prev == c)
            continue;
        putchar(c);
        prev = c;
    }

    return 0;
}
