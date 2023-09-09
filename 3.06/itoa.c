#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
    int n = strlen(s);
    
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void itoa(int n, char s[])
{
    int i, sign;
    long long num = n;
    if ((sign = num) < 0) {
        num *= -1;
    }
    i = 0;
    do {
        s[i++] = num % 10 + '0';
    } while ((num /= 10) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main()
{
    int n = -123;
    char s[100] = { 0 };
    itoa(n, s);

    printf("%s\n", s);

    return 0;
}
