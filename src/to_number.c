﻿#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include "to_number.h"


void format_string_to_number(int argc, char* argv[])
{
    char* ptr;
    if (argc != 2)
    {
        printf("usage: tnumconv string\n");
        exit(EXIT_FAILURE);
    }

    printf("Function    Return Value\n");
    printf("--------    ------------\n");

    printf("atof        %g\n", atof(argv[1]));
    printf("atoi        %d\n", atoi(argv[1]));
    printf("atol        %ld\n\n", atol(argv[1]));

    printf("Function    Return Value    Valid?    String Consumed?\n");
    printf("--------    ------------    ------    ----------------\n");

    errno = 0;
    printf("strtod      %-12g", strtod(argv[1], &ptr));
    CHK_VALID;

    errno = 0;
    printf("strtol      %-12ld", strtol(argv[1], &ptr, 10));
    CHK_VALID;

    errno = 0;
    printf("strtoul     %-12lu", strtoul(argv[1], &ptr, 10));
    CHK_VALID;
}
