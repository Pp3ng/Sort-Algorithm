#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    int n = 10000;
    int arr[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }
    countingSort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}
