#ifndef DAY_OF_YEAR_
#define DAY_OF_YEAR_

#include <stdlib.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

static void year_check(int year)
{
    if (year > 0 && year <= 2022) {
        return;
    }

    printf("Year is incorrect.\n");
    abort();
}

static int month_day_check(int month, int day, int leap)
{
    if (month > 0 && month <= 12) { 
        if (month == 2) {
            if (leap)
                if (day > 0 && day <= 28) {
                    return 1;
                } else
                    if (day > 0 && day <= 29) {
                        return 1; 
                    }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day > 0 && day <= 30) {
                return 1;
            }
        } else {
            if (day > 0 && day <= 31)
                return 1;
        } 
    }
                
    printf("Month or day is incorrect.\n");
    abort();
}

static void month_day_func_check(int yearday, int leap, int* pmonth, int *pday)
{
    if (!pmonth || !pday) {
        printf("pmonth or pday is NULL!\n");
        abort();
    }
    
    int num = leap == 1 ? 366 : 365;   
    if (yearday < 0 || yearday > num) {
        printf("Yearday is incorrect!\n");
        abort();
    }
}

int leap_check(int year)
{
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? 1 : 0;
}


/*day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    year_check(year);

    int i, leap;
    leap = leap_check(year);
    month_day_check(month, day, leap);

    for (i = 1; i < month; ++i)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    year_check(year);

    int i, leap;

    leap = leap_check(year);
    month_day_func_check(yearday, leap, pmonth, pday);

    for (i = 1; yearday > daytab[leap][i]; ++i)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

#endif
