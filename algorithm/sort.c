#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

void swap(int *arr, int i, int j)
{
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}
/**
 * 冒泡排序
 * arr: 待排数组
 * size: 待排数组大小
 * */
void bubble_sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i; j < size; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(arr, i, j);
            }
        }
    }
}

/**
 * 选择排序
 * arr: 待排数组
 * size: 待排数组大小
 * */
void selection_sort(int *arr, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = 0x7fff, idx = i;
        for (int j = i; j < size; j++)
        {
            if (arr[j] < min)
            {
                min = arr[j];
                idx = j;
            }
        }
        swap(arr, idx, i);
    }
}

/**
 * 插入排序
 * arr: 待排数组
 * size: 待排数组大小
 * */
void insertion_sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                int t = arr[i];
                for (int k = i; k > j; k--)
                {
                    arr[k] = arr[k - 1];
                }
                arr[j] = t;
                break;
            }
        }
    }
}

int partition(int *arr, int lo, int hi)
{
    int key = arr[lo];
    while (lo < hi)
    {
        while (lo < hi && arr[hi] > key)
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

void merge(int *arr, int lo, int mid, int hi)
{
    //printf("lo:%d, hi:%d\n", lo, hi);
    int *t = (int *)malloc(sizeof(int) * (hi - lo + 1));
    for (int i = 0, j = 0; i < hi - lo + 1; i++, j++)
    {
        t[i] = arr[lo + j];
    }
    // shit code
    mid = (hi - lo) / 2;
    int i = 0, j = mid + 1, idx = lo;
    while (i <= mid && j <= hi - lo)
    {
        if (t[i] > t[j])
        {
            arr[idx++] = t[j++];
        }
        else
        {
            arr[idx++] = t[i++];
        }
    }
    while (i <= mid)
    {
        arr[idx++] = t[i++];
    }
    while (j <= hi - lo)
    {
        arr[idx++] = t[j++];
    }
}

void _merge_sort(int *arr, int lo, int hi)
{
    if (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        _merge_sort(arr, lo, mid);
        _merge_sort(arr, mid + 1, hi);
        merge(arr, lo, mid, hi);
    }
}

void merge_sort(int *arr, int size)
{
    _merge_sort(arr, 0, size - 1);
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
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 100;
    }

    print(arr, N);
    merge_sort(arr, N);
    print(arr, N);
}