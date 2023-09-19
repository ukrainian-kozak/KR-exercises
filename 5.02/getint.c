#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

static int buf[BUFSIZE];
static int bufp = 0;

int getch()
{
    return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getint(int* pn)
{
    int c, sign;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != '+' && c != EOF && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        if (!isdigit((c = getch())))
            return 0;

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int main()
{
    int in, num;

    while ((in = getint(&num)) && in != EOF)
        printf("%i\n", num);

    return 0;
}
