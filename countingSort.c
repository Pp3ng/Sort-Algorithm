#include "sort.h"
void countingSort(int *arr, int length)
{
    int max = arr[0];
    for (int i = 1; i < length; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    int *count = (int *)calloc(max + 1, sizeof(int));
    for (int i = 0; i < length; i++)
        count[arr[i]]++;

    int index = 0;
    for (int i = 0; i <= max; i++)
    {
        while (count[i] > 0)
        {
            arr[index++] = i;
            count[i]--;
        }
    }

    free(count);
    count = NULL;
}

int main(int argc, char **argv, char **envp)
{
    int length = LENGTH;
    int *arr = generateArray(length);
    countingSort(arr, length);
    isArraySorted(arr, length) ? printf("Sorted\n") : printf("Not sorted\n");
    free(arr);
    return 0;
}
