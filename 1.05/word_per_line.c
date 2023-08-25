#include <stdio.h>

#define SIZE 1000

int main()
{
    int c;
    int  prev;
    while ((c = getchar()) != EOF) {
        if (prev == c && (c == ' ' || c == '\t')) {
            continue;
        }
        else if (c == ' ' || c == '\t') {
            putchar('\n');
        } else {
            putchar(c);
        }
        prev = c;
    }

    return 0;
}
