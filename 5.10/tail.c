#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 1000

int main(int argc, char *argv[])
{
    int n = 10;
    char *line = NULL;

    if (argc < 2) {
        printf("USAGE: ./a.out [-n](optional) [input text]");
    } else {
        if (argc == 2 && argv[1][0] == '-') {
            printf("There is no input text!\n");
        } 
        else {
            if (argv[1][0] == '-') {
                if (argv[1][1] < '0' || argv[1][1] > '9') {
                    printf("Wrong [-n], n == number!\n");
                    abort();
                }

                int j = 1;
                n = 0;
                while (argv[1][j] >= '0' && argv[1][j] <= '9') {
                    n = n * 10 + argv[1][j] - '0';
                    ++j;
                }
            }

            line = (char *) malloc(sizeof(char) * MAXSIZE);

            if (line == NULL) {
                fprintf(stderr, "Memory allocation error!\n");
                return 1;
            }

            line[0] = '\0';

            for (int i = 2; i < argc; ++i) {
                strcat(line, argv[i]);
                strcat(line, " ");
            }

            int len = strlen(line);

            if (n >= len) {
                printf("%s\n", line);
            } else {
                printf("%s\n", line + len - n);
            }

            free(line);
        }
    }
    return 0;
}

