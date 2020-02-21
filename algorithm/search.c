#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 20

int partition(int *arr, int lo, int hi)
{
    int key = arr[lo];
    while (lo < hi)
    {
        while (lo < hi && arr[hi] >= key)
        {
            hi--;
        }
        arr[lo] = arr[hi];
        while (lo < hi && arr[lo] < key)
        {
            lo++;
        }
        arr[hi] = arr[lo];
    }
    arr[lo] = key;
    // lo == hi
    return lo;
}

void _qsort(int *arr, int lo, int hi)
{
    if (lo < hi)
    {
        int loc = partition(arr, lo, hi);
        _qsort(arr, lo, loc - 1);
        _qsort(arr, loc + 1, hi);
    }
}

void quick_sort(int *arr, int size)
{
    _qsort(arr, 0, size - 1);
}

int binary_search(int *arr, int lo, int hi, int target)
{
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return -1;
}

void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%2d\t", arr[i]);
        if ((i + 1) % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}

int main()
{
    srand(time(0));
    int arr[N];
    int mem[100];
    for (int i = 0; i < 100; i++)
    {
        mem[i] = 0;
    }
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 100;
        mem[arr[i]] += 1;
    }
    quick_sort(arr, N);
    print(arr, N);
    int t;
    do
    {
        t = rand() % 100;
    } while (mem[t] == 0);
    int idx = binary_search(arr, 0, N - 1, t);
    printf("target=%d, idx=%d\n", t, idx);
    return 0;
}