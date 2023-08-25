#include <stdio.h>

#define SIZE 256

static inline int max(const int* a, const int* b) 
{
    return *a >= *b ? *a : *b;
}

int main()
{
    int c, len, count, max_count;
    max_count = count = len = 0;

    int lengths[SIZE] = { 0 };

    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == ' ' || c == '\t') {
            lengths[len] = count;
            ++len;
            max_count = max(&max_count, &count);
            count = 0;
        } else {
            ++count;
        }
    }

    for (int i = max_count; i > 0; --i) {
        printf("%2d|", i);

        for (int j = 0; j < len; ++j) {
            if (lengths[j] >= i)
                printf("x");
            else 
                printf(" ");
        }

        putchar('\n');
    }

    printf("---------------------------------------------------------\n");
    printf("  ");

    for (int i = 0; i < len; ++i) {
        printf("%d ", lengths[i]);
    }

    return 0;
}
