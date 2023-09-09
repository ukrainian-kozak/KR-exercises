#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next character or numerical operand */
int getop(char s[]) {
    int i, c, sign;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0'; // Initialize the second character of s

    if (c == '-') {
        sign = -1;
        c = getch(); // Read the next character
        if (!isdigit(c) && c != '.') {
            ungetch(c); // Push the character back to input
            return '-'; // Return '-' as an operator
        }
    } else {
        sign = 1;
    }

    i = 0;
    if (c == '-' || c == '+') // Skip the sign characters
        s[++i] = c;

    if (isdigit(c)) // Collect integer part
        while (isdigit(s[++i] = c = getch()))
            ;

    if (c == '.') // Collect fraction part
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
