#include <stdio.h>
#include <time.h>
int less(int a, int b)
{
    return a < b;
}
int great(int a, int b)
{
    return a > b;
}
void bubbleSort(int *arr, int len, int (*compaper)(int, int))
{
    for (int i = 0; i < len - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (compaper(arr[j], arr[j + 1]))
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 1;
            }
        }
        if (0 == flag)
            break;
    }
}
int main(void)
{
    int n = 10000;
    int arr[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }
    int len = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, len, great);
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", arr[i]);
    }
}
