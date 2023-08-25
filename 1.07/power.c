#include <stdio.h>

int power(int a, int count);

int main()
{
    int i;

    for (i = 0; i < 10; ++i) {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }

    return 0;
}

/*power function*/
int power(int a, int count)
{
    int i, p;
    p = 1;
    for (i = 1; i <= count; ++i) {
        p *= *a;
    }

    return p;
}
