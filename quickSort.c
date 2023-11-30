#include <stdio.h>
#include <time.h>
void quickSort(int arr[], int left, int right);
int main()
{
    int n = 10000;
    int arr[n];
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100000;
    }
    int len = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, len - 1);
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", arr[i]);
    }
}
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
