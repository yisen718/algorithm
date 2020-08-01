#include <stdlib.h>
#include "sort.h"

void insertion_sort(int* a, int len)
{
    // 1, 2, 9, 5, 2, 3, 6
    for (int j = 1; j < len; j++)
    {
        int key = a[j];
        int i = j - 1;
        while (i >= 0 && a[i] > key)
        {
            // 向后移
            a[i + 1] = a[i];
            i--;
        }
        // 确定新元素位置
        a[i + 1] = key;
    }
}


void merge(int* a, int p, int q, int r)
{
    // [p, q], (q, r]
    const int n1 = q - p + 1;
    const int n2 = r - q;

    // 声明并复制数组
    int* left = (int*)malloc((n1 + 1) * 4);
    int* right = (int*)malloc((n2 + 1) * 4);

    for (int i = 0; i < n1; i++)
    {
        left[i] = a[p + i];
    }
    for (int i = 0; i < n2; i++)
    {
        right[i] = a[q + i + 1];
    }

    // 使用哨兵sentinal
    left[n1] = 10000;
    right[n2] = 10000;

    // 开始合并数组到原数组中
    for (int i = 0, j = 0, k = p; k <= r; k++)
    {
        if (left[i] <= right[j])
        {
            a[k] = left[i];
            i++;
        }
        else
        {
            a[k] = right[j];
            j++;
        }
    }
}

void merge_sort(int* a, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(a, p, q);
        merge_sort(a, q + 1, r);
        merge(a, p, q, r);
    }
}
