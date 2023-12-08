#include "sort.h"
void bubbleSort(int *arr, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
        }
        if (0 == flag)
            break;
    }
}
int main(void)
{
    int length = LENGTH;
    int *arr = generateArray(length);
    bubbleSort(arr, length);
    isArraySorted(arr, length) ? printf("Sorted\n") : printf("Not sorted\n");
    free(arr);
    return 0;
}
