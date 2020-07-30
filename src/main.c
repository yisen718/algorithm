#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "sort.h"

int main(int argc, char* argv[])
{
    int array[] = { 9, 2, 1, 5, 2, 3, 6 };

    merge_sort(array, 0, 6);

    for (int i = 0; i < 7; i++)
    {
        printf("%d, ", array[i]);
    }

    return 0;
}
