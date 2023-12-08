#include "sort.h"
void quickSort(int arr[], int left, int right)
{
    if (left > right)
        return;
    int i = left;
    int r = right;
    int key = arr[left];
    while (i < r)
    {
        while (i < r && arr[r] >= key)
        {
            r--;
        }
        arr[i] = arr[r];
        while (i < r && arr[i] <= key)
        {
            i++;
        }
        arr[r] = arr[i];
    }
    arr[i] = key;
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}
int main()
{
    int length = LENGTH;
    int *arr = generateArray(length);
    quickSort(arr, 0, length - 1);
    isArraySorted(arr, length) ? printf("Sorted\n") : printf("Not sorted\n");
    free(arr);
    return 0;
}