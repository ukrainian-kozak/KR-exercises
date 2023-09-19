#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    char* line = NULL;
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;
    size_t len = 0;

    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0]) {
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }

    if (argc != 1) {
        printf("Usage: find -x -n pattern\n");
    } else {
        while (getline(&line, &len, stdin) > 0) {
            lineno++;
            if ((strstr(line, argv[1]) != NULL) != except) {
                if (number)
                    printf("%ld:", lineno);
                printf("%s", line);
                found++;
            }
        }
    }
    return found;
}
