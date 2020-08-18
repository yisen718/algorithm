#include <gtest/gtest.h>
#include <iostream>
#include <random>
#include "../src/sort.h"

#define MAX_LEN 100


TEST(TestSort, TestInsertionSort)
{
    int* arr = (int*)malloc(MAX_LEN * 4);
    for (size_t i = 0; i < MAX_LEN; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
    insertion_sort(arr, MAX_LEN);
    for (size_t i = 1; i < MAX_LEN; i++)
    {
        EXPECT_TRUE(arr[i] >= arr[i - 1]);
    }
}

TEST(TestSort, TestMergeSort)
{
    int* arr = (int*)malloc(MAX_LEN * 4);
    for (size_t i = 0; i < MAX_LEN; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
    merge_sort(arr, 0, MAX_LEN);
    for (size_t i = 1; i < MAX_LEN; i++)
    {
        EXPECT_TRUE(arr[i] >= arr[i - 1]);
    }
}
