#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *v1, int *v2)
{
    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
}
void heapify(int *arr, int length, int index)
{
    int max = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    if (left_child < length && arr[max] < arr[left_child])
    {
        max = left_child;
    }
    if (right_child < length && arr[max] < arr[right_child])
    {
        max = right_child;
    }
    if (max != index)
    {
        swap(&arr[index], &arr[max]);
        heapify(arr, length, max);
    }
}
void heap_sort(int *arr, int length)
{
    // make heap
    for (int i = length / 2 - 1; i >= 0; i--)
    {
        heapify(arr, length, i);
    }
    // sort
    for (int i = length - 1; i > 0; i--)
    {
        swap(&arr[i], &arr[0]);
        heapify(arr, i, 0);
    }
}
int main()
{
    int n = 10000;
    int arr[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }
    heap_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d\t", arr[i]);
    }
}

// Mon Nov 20 19:40:07 KST 2023
