#include"fun.h"

int add (int a, int b)
{
    return a + b;
}

bool is_prime(int digit)
{
    if (digit <= 1)
    {
        return false;
    }
    for (int i = 2; i * i < digit; i++)
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
