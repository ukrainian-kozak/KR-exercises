#include <stdio.h>
#include "stralg.h"

int main()
{
    char dest[50];
    char src[50];

    strcpy(dest, "aaaaHello");
    strcpy(src, "Hello");
//    strcat(dest, src);
    int res = strend(dest, src);
    printf("%s\n%d\n", dest, res);

    return 0;
}
