#include <stdio.h>

#define MAXLINE 1024

int gline(char s[], int lim, char del);

int main()
{
    int len;
    char buffer[MAXLINE] = { 0 };

    while ((len = gline(buffer, MAXLINE, '\n')) > 0) {
        printf("%s", buffer);
    }
}

int gline(char s[], int lim, char del)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n' && c != del; ++i) {
        if (c == '\t') {
            for (int j = 0; j < 4 && i < lim - 1; ++j) {
                s[i++] = ' ';
            }
            --i;
        } else {
            s[i] = c;
        }
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}
