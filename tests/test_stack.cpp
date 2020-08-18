#include <iostream>
#include <gtest/gtest.h>
#include "../src/stack.h"

#define MAX_LEN 1000


TEST(TestStack, TestStackFunction)
{
    Stack* s = (Stack*)malloc(sizeof(Stack));
    int* values = (int*)malloc(MAX_LEN * 4);
    for (size_t i = 0; i < MAX_LEN; i++)
    {
        push_to_stack(s, values[i]);
    }

    /*for (int i = MAX_LEN - 1; i >= 0; i--)
    {
        EXPECT_EQ(values[i], pop_from_stack(s));
    }*/

    for (size_t i = 1; i <= MAX_LEN; i++)
    {
        EXPECT_EQ(values[MAX_LEN - i], pop_from_stack(s));
    }
}
