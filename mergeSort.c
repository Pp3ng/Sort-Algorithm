#include "sort.h"
void merge(int arr[], int tmp[], int left, int mid, int right)
{
    int leftCur = left;
    int rightCur = mid + 1;
    int cur = left;
    while (leftCur <= mid && rightCur <= right)
    {
        if (arr[leftCur] <= arr[rightCur])
            tmp[cur++] = arr[leftCur++];
        else
            tmp[cur++] = arr[rightCur++];
    }
    while (leftCur <= mid)
        tmp[cur++] = arr[leftCur++];
    while (rightCur <= right)
        tmp[cur++] = arr[rightCur++];
    memcpy(arr + left, tmp + left, (right - left + 1) * sizeof(int));
}
void merge_sort(int arr[], int tmp[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = (left + right) >> 1;
    merge_sort(arr, tmp, left, mid);
    merge_sort(arr, tmp, mid + 1, right);
    merge(arr, tmp, left, mid, right);
}
void mergeSort(int arr[], int len)
{
    int *tmp = (int *)malloc(len * (sizeof(int)));
    merge_sort(arr, tmp, 0, len - 1);
    free(tmp);
    tmp = NULL;
}
int main(void)
{
    int length = LENGTH;
    int *arr = generateArray(length);
    mergeSort(arr, length);
    isArraySorted(arr, length) ? printf("Sorted\n") : printf("Not sorted\n");
    free(arr);
    return 0;
}
