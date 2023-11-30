#include <stdio.h>
#include <time.h>
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
    for (int i = 0; i < len; i++)
    {
        printf("%d\t", arr[i]);
    }
}
