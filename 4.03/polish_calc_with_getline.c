#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define NUMBER '0'
#define MAXOP 256
#define MAXVAL 100

int sp = 0;          /* next free stack position */
double val[MAXVAL];  /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else 
        printf("error: stack full, cannot push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0) {
        val[--sp];
    } else {
        printf("error: stack is empty\n");
        return 0.0;
    }
}

double top()
{
    if (sp >= 0)
        return val[sp - 1];
    printf("error: sp < 0.\n");
    return 0.0;
}

int my_getline(char s[], int lim)
{
    int c, i;
    i = 0;

    while ((c = getchar()) != EOF && isspace(c))
        ;

    if (c == EOF)
        return -1;

    while ((c = getchar()) != EOF && c != '\n' && i < lim - 1)
        s[i++] = c;

    if (c == EOF)
        return -1;

    if (c == '\n')
        s[i++] = '\n';

    s[i] = '\0';
    return i;
}

int main()
{
    int type;
    double op2;
    int len;
    char s[MAXOP];

    while ((len = my_getline(s, MAXOP)) > 0) {
        for (int i = 0; i < len; ++i) {
            type = s[i];
            //push(type);
            switch (type) {
                case NUMBER:
                    push(atof(s));
                    break;
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '/':
                    op2 = pop();
                    if (op2 != 0.0)
                        push(pop() / op2);
                    else
                        printf("error: zero divisor\n");
                    break;
                case '%':
                    int op3 = (int)pop();
                    int op1 = (int)pop();
                    push(op1 % op3);
                    break;
                case '\n':
                    printf("\t%.8g\n", pop());
                    break;
                default:
                    //printf("error: unknown command %s\n", s);
                    break;
            }
        }
        
    }
    return 0;
}


