#include <stdio.h>

int mygetc(FILE* in)
{
    for ( ;; ) {

        int c = getc(in);
        if (c == '\\') {
            c = getc(in);
            if (c == '\n') {
                continue;
            }
            if (c != EOF) {
                ungetc(c, in);
            }
            c = '\\';
        }
        return c;
    }
}

static int skip_line(FILE* in)
{
    int c;
    while ((c = mygetc(in)) != EOF && c != '\n') {
           continue;
    }

    return c;
}

static int skip_multi(FILE* in, int c)
{
    int prev = 0;
    while (prev != '*' || c != '/') {
        prev = c;
        c = mygetc(in);
    }

    c = mygetc(in);

    return c;
}

static void remove_comments(FILE* in, FILE* out)
{
    int c;

    while ((c = mygetc(in)) != EOF) {
        if (c == '\'' || c == '"') {
            int sep = c;
            fputc(c, out);
            while ((c = mygetc(in)) != sep && c != EOF) {
                fputc(c, out);
                if (c == '\\') {
                    c = mygetc(in);
                    if (c == EOF) {
                        break;
                    }
                    fputc(c, out);
                }
            }
        } else if (c == '/') {
            c = mygetc(in);
            if (c == '/') {    //line comment.
                c = skip_line(in);
            } else if (c == '*') { //multi comment.
                c = skip_multi(in, c);
            } else {
                fputc('/', out);
            }
        }
        if (c == EOF)
            break;
        fputc(c, out); 
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("USAGE: ./a.out <file name>");
        return 1;
    }

    FILE* in = fopen(argv[1], "r");
    FILE* out = fopen("pure_output.c", "w");

    if (!in) {
        fclose(out);
        printf("Failed to open input file");
        return 1;
    }

    remove_comments(in, out);

    fclose(in);
    fclose(out);

    return 0;
}
