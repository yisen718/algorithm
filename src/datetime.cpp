#include <stdio.h>
#include <time.h>
#include "datetime.h"

void datetime_format()
{
    time_t current = time(NULL);
    struct tm* ptr;
    char date_time[21];
    int hour;
    char am_or_pm;

    puts(ctime(&current));

    strftime(date_time, sizeof(date_time), "%m-%d-%Y  %I:%M%p\n", localtime(&current));

    puts(date_time);

    ptr = localtime(&current);
    hour = ptr->tm_hour;
    if (hour <= 11)
    {
        am_or_pm = 'a';
    }
    else
    {
        hour -= 12;
        am_or_pm = 'p';
    }
    if (hour == 0)
    {
        hour = 12;
    }
    printf("%.2d-%.2d-%.2d %2d:%.2d%c\n", ptr->tm_mon + 1, ptr->tm_mday, ptr->tm_year + 1900, hour, ptr->tm_min, am_or_pm);
}

void time_operation()
{
    clock_t start_clock = clock();

    printf("Processor time used: %g sec.\n", ((double)clock() - (double)start_clock) / (double)CLOCKS_PER_SEC);

    time_t start_time = time(NULL);

    printf("Running time: %g sec.\n", difftime(time(NULL), start_time));

    struct tm t;
    t.tm_mday = 27;
    t.tm_mon = 6;
    t.tm_year = 112;

    t.tm_sec = 0;
    t.tm_min = 0;
    t.tm_hour = 0;
    t.tm_isdst = -1;
    // 超出正常取值
    t.tm_mday += 16;
    // 调整为正常取值
    mktime(&t);

    datetime_format();
}
