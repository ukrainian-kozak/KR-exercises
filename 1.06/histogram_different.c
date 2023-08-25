#include <stdio.h>

#define SIZE 256

static inline int max(const int* a, const int* b) 
{
    return *a >= *b ? *a : *b;
}

int main()
{
    int c;
    int max_count = 0;

    int characters[SIZE] = { 0 };

    while ((c = getchar()) != EOF) {
        characters[c]++;
        max_count = max(&max_count, &characters[c]);
    }

    for (int i = max_count; i > 0; --i) {
        printf("%3d|", i);

        for (int j = 0; j < SIZE; ++j) {
            if (characters[j] == 0)
                continue;
            if (characters[j] >= i)
                printf("x");
            else
                printf(" ");
        }
        printf("\n");
    }
    
    printf("'");
    for (int i = 0; i < SIZE; ++i) {
        if (characters[i] > 0) {
            if (i == '\n')
                printf("\\n'");
            else if (i == '\t')
                printf("\\t'");
            else if (i == '\\')
                printf("\\'");
            else 
                printf("%c'", i);
        }
    }

    return 0;
}
