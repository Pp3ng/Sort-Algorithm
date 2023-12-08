#ifndef SORTING_H
#define SORTING_H
#define LENGTH 100000
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int *generateArray(int length)
{
    int *arr = (int *)malloc(length * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < length; i++)
    {
        arr[i] = rand() % 100000000;
    }
    return arr;
}

void printArray(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int isArraySorted(int arr[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0; // Not sorted
        }
    }
    return 1; // Sorted
}

#endif /* SORTING_H */
