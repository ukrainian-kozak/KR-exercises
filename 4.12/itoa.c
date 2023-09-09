#include <stdio.h>
#include <string.h>

void swap(char* a, char* b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

static void reverse_recursive(char s[], int start, int end)
{
    if (start >= end)
        return;

    swap(&s[start], &s[end]);
    reverse_recursive(s, start + 1, end - 1);
}

void reverse(char s[]) {
    int length = strlen(s);
    reverse_recursive(s, 0, length - 1);
}

static void itoa_recursive(char s[], long long num, int* index) {
    if (num / 10)
        itoa_recursive(s, num / 10, index);
    s[(*index)++] = num % 10 + '0';
}

void itoa(int n, char s[]) {
    int i, sign;
    i = 0;
    int* index = &i;
    long long num = n;
    
    if ((sign = num) < 0)
        num *= -1;
    if (sign < 0) {
        s[i++] = '-';
    }
    if (num == 0) {  // Handle the case when num is 0
        s[i++] = '0';
    } else {
        itoa_recursive(s, num, index);
    }

   
    s[i] = '\0';
}

int main() {
    char buffer[20]; // Make sure it's large enough to hold your integers

    int num = -12345;
    itoa(num, buffer);
    printf("Integer as string: %s\n", buffer);
    reverse(buffer);
    printf("%s\n", buffer);

    return 0;
}
