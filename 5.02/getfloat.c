#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>

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

int getfloat(double *pn) {
    int c, sign;
    double power = 1.0;
    bool hasFraction = false;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '-' && c != '+') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();

    for (*pn = 0.0; isdigit(c) || c == '.'; c = getch()) {
        if (c == '.') {
            hasFraction = true;
            continue; // Skip the decimal point, we'll handle it later
        }

        *pn = 10.0 * *pn + (c - '0');
        
        if (hasFraction)
            power *= 10.0;
    }

    *pn = (*pn * sign) / power;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main()
{
    double c;
    double num;

    while ((c = getfloat(&num)) != EOF)
        printf("%3f\n", num);

    return 0;
}
