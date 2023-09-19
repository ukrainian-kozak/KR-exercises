#include "calc.h"
#include <stdio.h>

#define MAXVAL 100

static int sp = 0;          /* next free stack position */
static double val[MAXVAL];  /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else {
        printf("error: stack full, cannot push %g\n", f);
    }
}

/* pop: pop and return top value from stack */
double pop()
{
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack is empty\n");
        return 0.0;
    }
}

double top()
{
    if (sp >= 0)
        return val[sp];
    printf("error: sp < 0.\n");
    return 0.0;
}

void clear()
{
    for (int i = 0; i < sp; ++i) {
        val[i] = 0.0;
    }
}

void swap()
{
    double op1 = pop();
    double op2 = pop();
    push(op1);
    push(op2);
}
