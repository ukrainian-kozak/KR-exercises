#include <stdio.h>

#define TABSIZE 4

int main()
{
    int c, nspaces, nchars;
    nspaces = nchars = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++nspaces;
        } else {
            while (nspaces >= TABSIZE - nchars) {
                putchar('\t');
                nspaces -= TABSIZE;
            }

            while (nspaces > 0) {
                putchar(' ');
                --nspaces;
            }

            nchars = 0;

            if (c != '\t') {
                ++nchars;
            }

            putchar(c);
        }
    }

    return 0;
}

