#include <gtest/gtest.h>
#include "../src/sort.h"

namespace TestSortFuncs
{
    TEST(TestInsertionSort, TestSort)
    {
        int arr[] = { 2, 3, 1, 5, 2, 6, 8, 1, 9 };
        int len = sizeof(arr) / sizeof(arr[0]);
        insertion_sort(arr, len);
        for (int i = 1; i < len; i++)
        {
            EXPECT_TRUE(arr[i] >= arr[i - 1]);
        }
    }
}
