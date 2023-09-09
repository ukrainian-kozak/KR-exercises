#include <stdio.h>

#define swap(t, a, b) { \
    t tmp = a; \
    a = b; \
    b = tmp; \
}


int main()
{
    int a = 10;
    int b = 5;
    swap(int, a, b);
    printf("%d,%d", a, b);

    return 0;
}
