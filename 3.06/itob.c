#include <stdio.h>
#include <string.h>

void reverse(char s[])
{
    int size = strlen(s);
    
    for (int i = 0, j = size - 1; i < j; ++i, --j) {
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void convert_binary(int n, char s[]) {
    int i = 0;
    
    if (n < 0) {
        s[i++] = '1'; // Add the sign bit for negative numbers
        n = -n;      // Convert negative to positive for two's complement
    } else {
        s[i++] = '0'; // Add the sign bit for non-negative numbers
    }

    if (n == 0) {
        s[i++] = '0';
    } else {
        while (n > 0) {
            s[i++] = n % 2 + '0';
            n /= 2;
        }
    }

    s[i] = '\0';
    reverse(s);
}

void convert_four(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0)
        n *= -1;

    i = 0;
    do {
        s[i++] = n % 4 + '0';
    } while ((n /= 4) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

void convert_octal(int n, char s[])
{
    int i, sign;
    if ((sign = n) < 0)
        n *= -1;

    i = 0;
    do {
        s[i++] = n % 8 + '0';
    } while ((n /= 8) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

void convert_decimal(int n, char s[])
{
    int i, sign;
    long long num = n;

    if ((sign = num) < 0)
        num *= -1;

    i = 0;
    do {
        s[i++] = num % 10 + '0';
    } while ((num /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';
    
    s[i] = '\0';
    reverse(s);
}

void convert_hex(int n, char s[])
{
    int sign;
    int i = 0;
    long long num = n;

    if ((sign = num) < 0)
        num *= -1;

    while (num > 0) {
        int rem = num % 16;
        if (rem < 10) {
            s[i++] = rem + '0';
        } else {
            s[i++] = rem - 10 + 'A';
        }
        num /= 16;
    }

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

void itob(int n, char s[], int b)
{
    if (b == 2) convert_binary(n, s);
    else if (b == 4) convert_four(n, s);
    else if (b == 8) convert_octal(n, s);
    else if (b == 10) convert_decimal(n, s);
    else if (b == 16) convert_hex(n, s);
    else printf("The value of 'b' is wrong.\n");
}

int main()
{
    int n = -156;
    char s[256] = { 0 };

    itob(n, s, 2);
    printf("%d -> %s\n", n, s);
    itob(n, s, 4);
    printf("%d -> %s\n", n, s);
    itob(n, s, 8);
    printf("%d -> %s\n", n, s);
    itob(n, s, 10);
    printf("%d -> %s\n", n, s);
    itob(n, s, 16);
    printf("%d -> %s\n", n, s);

    return 0;
}
