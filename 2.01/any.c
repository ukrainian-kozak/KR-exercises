#include <stdio.h>

int any(char s1[], char s2[])
{
    int hash[256] = { 0 };
    
    for (int j = 0; s2[j] != '\0'; ++j) {
        hash[(int)s2[j]] = 1;
    }

    for (int i = 0; s1[i] != '\0'; ++i) {
        if (hash[(int)s1[i]])
            return i;
    }

    return -1;
}

int main()
{
    char s1[] = "asdfgh";
    char s2[] = "hjkl;";
    char s3[] = "vb";

    printf("%d, %d", any(s2, s3), any(s3, s1));

    return 0;
}
