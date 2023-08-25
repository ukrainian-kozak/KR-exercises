#include <stdio.h>

int main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;
    printf("Fahrenheit:\t");
    printf("Celsius:\n\n");
    for (fahr = lower; fahr <= upper; fahr += step) {
        celsius = 5.0 * (fahr-32.0) / 9.0;
        printf("%3.0f\t|\t%3.1f\n", fahr, celsius);
    }

    return 0;
}
