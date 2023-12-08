#include "sort.h"
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
    int length =LENGTH ;
    int *arr = generateArray(length);
    heap_sort(arr, length);
    isArraySorted(arr, length) ? printf("Sorted\n") : printf("Not sorted\n");
    free(arr);
    return 0;
}
