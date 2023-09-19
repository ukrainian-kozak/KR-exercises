#include <stdio.h>
#include <limits.h>
#include "stack.h"


int main(int argc, char *argv[])
{
    int option;

    if (argc < 2) {
        printf("Usage: ./a.out polish notation\n");
    } else {
        int num, j, op2, result = 0;
        for (int i = 1; i < argc; ++i) {
            if (argv[i][0] >= '0' && argv[i][0] <= '9') {
                j = 0;
                num = 0;
                while (argv[i][j] >= '0' && argv[i][j] <= '9') {
                    num = num * 10 + argv[i][j] - '0';
                    ++j;
                }
                push(num);
            } else {
                option = argv[i][0];
                switch (option) {
                    case '+':
                        push(pop() + pop());
                        break;
                    case '-':
                        op2 = pop();
                        push(pop() - op2);
                        break;
                    case '*':
                        // to input it write '*'

                        push(pop() * pop());
                        break;
                    case '/':
                        op2 = pop();
                        push(pop() / op2);
                        break;
                    case ' ':
                    case '\n':
                        break;
                    default:
                        printf("Undefined symbol: %c\n", argv[i][0]);
                        break;
                }
            }
        }

        result = pop();
        printf("Result: %d\n", result);
    }

    return 0;
}
