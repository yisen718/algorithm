#include <stdio.h>
#include <stdlib.h>
#include "fun.h"


int add(int a, int b)
{
    return a + b;
}

bool is_prime(int digit)
{
    if (digit <= 1)
    {
        return false;
    }
    for (size_t i = 2; i * i < digit; i++)
    {
        if (digit % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool has_repeat_digit(int digit)
{
    bool digits[10] = { false };
    int index;

    while (digit > 0)
    {
        index = digit % 10;
        if (digits[index])
        {
            return true;
        }
        digits[index] = true;
        digit /= 10;
    }
    return false;
}

int max_int(int n, ...)
{
    va_list ap;
    int current, largest;

    va_start(ap, n);
    largest = va_arg(ap, int);

    for (size_t i = 0; i < n; i++)
    {
        current = va_arg(ap, int);
        if (current > largest)
        {
            largest = current;
        }
    }
    va_end(ap);

    return largest;
}

int errorf(const char* format, ...)
{
    static int num_errors = 0;
    int n;
    va_list ap;

    num_errors++;
    fprintf(stderr, "** Error %d: ", num_errors);
    va_start(ap, format);
    n = vfprintf(stderr, format, ap);
    va_end(ap);
    fprintf(stderr, "\n");
    return n;
}

void rand_seed()
{
    int i, seed;

    while (1)
    {
        for (i = 0; i < 5; i++)
        {
            printf("%d ", rand());
        }
        printf("\n\n");
        printf("Enter new seed value (0 to terminate: ");
        scanf_s("%d", &seed);
        if (seed == 0)
        {
            break;
        }
        srand(seed);
    }
}

void copy_file(int argc, char* argv[])
{
    FILE* source_fp, * desk_fp;
    int ch;
    if (argc != 3)
    {
        fprintf(stderr, "usage: fcopy source dest\n");
        exit(EXIT_FAILURE);
    }

    if ((source_fp = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((desk_fp = fopen(argv[2], "wb")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(source_fp)) != EOF)
    {
        putc(ch, desk_fp);
    }

    fclose(source_fp);
    fclose(desk_fp);
}
