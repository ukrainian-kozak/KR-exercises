#include <stdio.h>

#define MAXLINE 512

int main()
{
    int c, blanks;
    
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t') {
            ++blanks;
            if (blanks == 1) {
                putchar('\n');
            }
        } else {
            putchar(c);
            blanks = 0;
        }
    }

    return 0;
}
