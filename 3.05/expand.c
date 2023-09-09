#include <stdio.h>
#include <string.h>
#include <ctype.h>

void expand(char s1[], char s2[]) {
    int i, j, start, end, sign;
    int size = strlen(s1);

    for (i = 0; isspace(s1[i]); ++i)
        ;

    sign = (s1[i] == '-') ? -1 : 1;
    if (s1[i] == '-')
        ++i;

    start = s1[i];
    i += 2; 
    end = s1[i];

    j = 0; 

    while (start <= end) {
        s2[j++] = start;
        start++;
    }

    if (i == size - 1) {
        s2[j] = '\0'; 
        return;
    }

    i += 2; 
    start = s1[i];
    i += 2; 
    end = s1[i];

    s2[j++] = ' '; 

    while (start <= end) {
        s2[j++] = start;
        start++;
    }

    s2[j] = '\0'; 
}

int main()
{
    char s1[] = "0-9-a-m";
    char s2[256] = { 0 };
    expand(s1, s2);

    printf("%s\n", s2);

    return 0;
}
