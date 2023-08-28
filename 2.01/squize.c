#include <stdio.h>

void squize(char s[], char f[])
{
    int k, j;
    for (int i = 0; s[i] != '\0'; ++i) {
        char target = s[i];
        for (j = k = 0; f[j] != '\0'; ++j) {
            if (f[j] != target)
                f[k++] = f[j];
        }
    }
    f[k] = '\0';
}

int main()
{
    char f[] = "Seva is top 1 and best in the world.";
    char s[] = "in the world.";
    squize(s, f);

    printf("%s\n", s);
    printf("%s\n", f);

    return 0;
}
