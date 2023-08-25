#include <stdio.h>

#define MAXSTACK 100

static inline void report(const char* msg)
{
    fprintf(stderr, "%s\n", msg);
}

int mygetc(FILE* file) {
    int c = getc(file);
    
    if (c == '\\') {
        c = getc(file);
        if (c == '\n') {
            return mygetc(file); // Recurse to skip newline
        } else if (c == EOF) {
            ungetc(c, file);
            return '\\'; // Return backslash as next character
        }
    }
    
    return c;
}

int skip_line(FILE* file)
{
    int c;
    while ((c = mygetc(file)) != EOF && c != '\n') {
        continue;
    }

    return c;
}

int skip_multi(FILE* file, int c)
{
    int prev = 0;
    while (prev != '*' || c != '/') {
        prev = c;
        c = mygetc(file);
    }

    c = mygetc(file);

    return c;
}









static int double_quote_check(FILE* file, int c)
{
    while ((c = mygetc(file)) != EOF && c != '\n' && c != '"') {
        continue;
    }
    if (c == EOF || c == '\n') {
        report("Double quotes sintax error.");
        return c == EOF ? EOF : c;
    }
    
    //c = mygetc(file);

    return c;
}


int single_quote_check(FILE* file, int c) {
    c = mygetc(file);

    if (c == '\'') {
        c = mygetc(file);
        if (c != '\'') {
            report("Empty single quotes.");
            return c;
        }

        return c;
    }
    
    if (c == '\\') {
        c = mygetc(file);
        
        if (c == '\'') {
            return c;
        }

        if (c == EOF) {
            report("Unexpected end of file after backslash.");
            return EOF;
        }
        
        if (c == '\n' || c == '\t' || c == '\b' || c == '\0') {
            c = mygetc(file);
            if (c == '\'') {
                return c;
            }
            else {
                report("Syntax with single quote isn't correct.");
                while ((c = mygetc(file)) != EOF && c != '\'') {
                    continue;
                }
                return c;
            }
        } else {
            while ((c = mygetc(file)) != EOF && c != '\'') {
                continue;
            }
            report("Invalid escape sequence.");
            return c;
        }
    }

    c = mygetc(file);
    if (c != '\'') {
        report("There is more than one character in single quotes.");
        while ((c = mygetc(file)) != EOF && c != '\'') {
            continue;
        }
    }

    //c = mygetc(file);

    return c;
}

static int count_pbb(FILE* file, int c) 
{
    char stack[MAXSTACK];
    int top = -1;
    
    
    do {
        if (c == '[' || c == '{' || c == '(') {
            if (top < MAXSTACK - 1) {
                stack[++top] = c;
            } else {
                report("stack overflow.");
                return EOF;
            }
        }
        else if (c == ']' || c == ')' || c == '}') {
            if (top >= 0) {
                if (stack[top] == '[' && c == ']' ||
                    stack[top] == '(' && c == ')' ||
                    stack[top] == '{' && c == '}') {
                    --top;
                    if (top == -1) {
                        return c;
                    }
                } else {
                    report("Unmatched brackets.");
                    return c;
                }
            } else {
                report("Unmatched brackets.");
                return c;
            } 
        }
    } while ((c = mygetc(file)) != EOF);

    if (top == -1)
        return c;
    report("Unmatched brackets.");
    return c;
}

static int global_check(FILE* file)
{
    int c;
    while ((c = mygetc(file)) != EOF) {
        
        if (c == '"') {
            c = double_quote_check(file, c);
            if (c == EOF)
                break;
        }
        else if (c == '\'') {
            c = single_quote_check(file, c);
            if (c == EOF)
                break;
        }
        else if (c == '/') {
            c = mygetc(file);
            if (c == '/') {
                c = skip_line(file);
            } else if (c == '*') {
                c = skip_multi(file, c);
            }
        }
        else if (c == ']' || c == '}' || c == ')') {
            report("Unmatched skobka.");
        }
        else if (c == '[' || c == '{' || c == '(') {
           c = count_pbb(file, c) ;
        }
        if (c == EOF)
            break;
    }

    return 0;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("USAGE: ./a.out <file name>");
        return 1;
    }

    FILE* file = fopen(argv[1], "r");

    if (!file) {
        printf("Failed to open the file: %s", argv[1]);
        return 1;
    }

    int comp = global_check(file);
    if (comp == 1) {
        printf("There is an error somewhere.");
        fclose(file);
        return 1;
    }

    fclose(file);

    return 0;
}
