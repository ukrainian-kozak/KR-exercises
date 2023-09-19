#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 100
#define MAXLEN 1000
#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };
enum { FAIL, GOOD };

void dcl();
void dirdcl();
int gettoken();
void errmsg(const char *);

int buf[BUFSIZE];
int bufp = 0;
int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[MAXLEN];
char state;

int main()
{
    while (gettoken() != EOF) {
        if (tokentype == '\n')
            continue;
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();
        if (tokentype != '\n')
            printf("syntax error\n");
        else if (state == GOOD)
            printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

int gettoken() /* return next token */
{
    int c, getch();
    void ungetch();
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
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    return tokentype = c;
}

/* dcl: parse a declarator */
void dcl()
{
    int ns;

    for (ns = 0; gettoken() == '*'; ++ns) /* count *'s*/
        ;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

/* dirdcl: parse a direct declarator */
void dirdcl()
{
    int type;

    if (tokentype == '(') {
        dcl();
        if (tokentype != ')')
            errmsg("error: missing )\n");
    } else if (tokentype == NAME)
        strcpy(name, token);
    else
        errmsg("error: expected name or (dcl)\n");
    while ((type = gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}

void errmsg(const char *msg)
{
    printf("%s", msg);
    state = FAIL;
}

int getch()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters!\n");
    else
        buf[bufp++] = c;
}
