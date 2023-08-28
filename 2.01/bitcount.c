#include <stdio.h>

int my_bitcount(int x) 
{
    int count;
    for (count = 0; x != 0; x >>= 1) {
        if (x & 1)
            ++count;
    }
    return count;
}

int main()
{
    for (int i = 0; i <= 10; ++i) {
        printf("%d\n", my_bitcount(i));
    }

    return 0;
}
