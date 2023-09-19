#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 100
#define MAXLEN 1000
#define MAXTOKEN 100

enum { NAME, BRACKETS, PARENS };
enum { FAIL, GOOD };

void undcl();
int gettoken();

int buf[BUFSIZE];
int bufp = 0;
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[MAXTOKEN];
char state;

int main()
{
    while (gettoken() != EOF) { 
        if (tokentype == '\n')
            continue;
        strcpy(out, token);
        undcl();
        printf("%s\n", out);
    }
    return 0;
}

int gettoken()
{
    int c, getch();
    void ungetch(int);
    char *p = token;

    if (state == FAIL) {
        state = GOOD;
        return tokentype;
    }
    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        ungetch(c);
        return tokentype = '(';
    }
    if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    return tokentype = c;
}

int needs_parens()
{
    int next_type;

    next_type = gettoken();
    state = FAIL;
    return next_type == PARENS || next_type == BRACKETS;
}

void undcl()
{
    int type;
    char temp[MAXLEN];

    while ((type = gettoken()) != '\n')
        if (type == PARENS || type == BRACKETS)
            strcat(out, token);
        else if (type == '*') {
            sprintf(temp, needs_parens() ? "(*%s)" : "%s", out);
            strcpy(out, temp);
        } else if (type == NAME) {
            sprintf(temp, "%s %s", token, out);
            strcpy(out, temp);
        } else 
            printf("invalid input at %s\n", token);
}

int getch()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE) 
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
