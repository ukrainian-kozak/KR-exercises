#include <stdio.h>

int main()
{
    int blank, tab, line, c;

    while ((c = getchar()) != EOF) {
        if (c == '\t')
            ++tab;
        else if (c == ' ')
            ++blank;
        else if (c == '\n')
            ++line;
    }

    printf("Blank's count: %d\n", blank);
    printf("Tab's count: %d\n", tab);
    printf("Lines' count: %d\n", line);

    return 0;
}
