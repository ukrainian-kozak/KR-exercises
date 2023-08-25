#include <stdio.h>

static void process(FILE *file)
{
    int c, next;
    while ((c = getc(file)) != EOF) {
        if (c == '/') {
            next = getc(file);
            if (c == next) {
                while ((c = getc(file)) != EOF && c != '\n') {
                    continue;
                }
            } else if (next == '*') {
                do {
                    next = c;
                    c = getc(file);
                } while (c != '/' || next != '*');
            }
        } else {
            putchar(c);
        }
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2)
        printf("USAGE: ./a.out <file name>");

    FILE* file = fopen(argv[1], "r+");
    if (!file) {
        printf("failed to open file");
        return 1;
    }

    process(file);
    fclose(file);


    return 0;
}
