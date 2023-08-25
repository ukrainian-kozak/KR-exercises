#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float convert_to_cel(int fahr)
{
    return (5.0/9.0) * (fahr - 32.0);
}

int main()
{
    printf("Fahrenheit:\t");
    printf("Celsium:\n");

    for (float fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
        printf("%3.1f\t\t%6.1f\n", fahr, convert_to_cel(fahr));
    }

    return 0;
}
