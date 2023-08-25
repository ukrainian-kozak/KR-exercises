#include <stdio.h>

#define MAXLEN 1024

#define SWAP(x, y) do { \
    typeof(x) _tmp = x; \
    x = y;           \
    y = _tmp;        \
} while(0)

int gline(char s[], int lim, char del);
void reverse(char s[], int len);


int main()

{
    int len;
    char line[MAXLEN];

    while ((len = gline(line, MAXLEN, '\n')) > 0) {
        reverse(line, len);
        printf("%s", line);
    }

    return 0;
}

int gline(char s[], int lim, char del)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != del; ++i)
        s[i] = c;
    if (c == del) {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

void reverse(char s[], int len)
{
    int i;
    for (i = 0; i < len / 2; ++i) {
        SWAP(s[i], s[len - i - 1]);
    }
}
