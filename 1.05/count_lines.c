#include <stdio.h>

int main()
{
    int count = 0;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\n')
            ++count;
    }
    printf("%d\n", count);

    return 0;
}
