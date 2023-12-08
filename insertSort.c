#include "sort.h"
void insertSort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int r = i;
        while (r > 0 && arr[r] < arr[r - 1])
        {
            int tmp = arr[r];
            arr[r] = arr[r - 1];
            arr[r - 1] = tmp;
            r--;
        }
    }
}
int main()
{
    int length = LENGTH;
    int *arr = generateArray(length);
    insertSort(arr, length);
    isArraySorted(arr, length) ? printf("Sorted\n") : printf("Not sorted\n");
    free(arr);
    return 0;
}
