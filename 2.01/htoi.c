#include <stdio.h>

int htoi(char s[])
{
    int n, val;
    for (int i = 0; s[i] != '\0' && ((s[i] >= '0' && s[i] <= '9') 
                || (s[i] >= 'a' && s[i] <= 'f') 
                || (s[i] >= 'A' && s[i] <= 'F')); ++i) {
        switch (s[i]) {
            case 'a': case 'A':
                val = 10; break;
            case 'b': case 'B':
                val = 11; break;
            case 'c': case 'C':
                val = 12; break;
            case 'd': case 'D':
                val = 13; break;
            case 'e': case 'E':
                val = 14; break;
            case 'f': case 'F':
                val = 15; break;
            default:
                val = s[i] - '0'; break;
        }
        n = n * 16 + val;
    }

    return n;
}

int main()
{
    char hex[] = "1A";  // Replace with your desired hex value
    int decimal = htoi(hex);
    printf("Hex: %s\nDecimal: %d\n", hex, decimal);
    return 0;
}
