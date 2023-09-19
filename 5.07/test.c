#include <stdio.h>
#include "day_of_year.h"

int main()
{
    int result = day_of_year(1981, 12, 31);
    int day = 0;
    int month = 0;

    month_day(1988, 60, &month, &day);
    printf("%d\n%d %d", result, month, day);

    return 0;
}
