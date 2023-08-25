#include <stdio.h>

#define MAXLINE 1024

int gline(char s[], int lim);

int main()
{
    int len = 0;

    char line[MAXLINE];

    while ((len = gline(line, MAXLINE)) > 0)
        if (len >= 80)
            printf("%s", line);

    return 0;
}

int gline(char s[], int lim) 
{
    int c;
    int i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}
