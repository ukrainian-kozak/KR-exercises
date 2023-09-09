#include "calc.h"
#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (c == EOF)
        return;
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[])
{
	int i;

	for (i = strlen(s) - 1; i >= 0 ; --i)
			ungetch(s[i]);
}
