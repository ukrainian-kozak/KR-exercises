#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("Min schar: %d | Max schar: %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Max uchar: %d\n", UCHAR_MAX);
    printf("Min char: %d | Max char: %d\n", CHAR_MIN, CHAR_MAX);
    printf("Min short int: %d | Max short int: %d\n", SHRT_MIN, SHRT_MAX);
    printf("Max ushort int: %d\n", USHRT_MAX);
    printf("Min int: %d | Max int: %d\n", INT_MIN, INT_MAX);
    printf("Max uint: %ld\n", UINT_MAX);
    printf("Min long: %ld | Max long: %ld\n", LONG_MIN, LONG_MAX);
    printf("Min float: %.10e | Max float: %.10e\n", FLT_MIN, FLT_MAX);

    return 0;
}
