#include <stdio.h>

int main()
{
    long nc;
    int c;

    for (; (c = getchar()) != EOF; )
        ++nc;
    printf("%ld", nc);

    return 0;
}
