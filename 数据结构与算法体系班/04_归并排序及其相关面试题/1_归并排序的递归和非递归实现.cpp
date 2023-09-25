# if 0
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void merge(int arr[], int l, int mid, int r, int *p);
void process(int arr[], int l, int r, int *p);
void mergeSort1(int arr[], int length, int *p);
void mergeSort2(int arr[], int length, int* help);

int main()
{
    int nums[] = {56, 45, 34, 21, 14, 10, 9,8,7,6,5,4,3,2,1};
    // int nums[] = { 3,4,1,2 };
    int size = sizeof(nums) / sizeof(int);
    int* p = new int[size];
    // mergeSort1(nums, size, p);
    mergeSort2(nums, size, p);
    cout << "[ ";
    for (int i = 0; i < sizeof(nums) / sizeof(int); ++i)
    {
        cout << p[i] << " ";
    }
    cout << "]" << endl;
    delete[] p;
}

// 归并排序的递归版本
void mergeSort1(int arr[], int length, int *p)
{
    if (length <= 1)
    {
        return;
    }
    process(arr, 0, length - 1, p);
}

void process(int arr[], int l, int r, int *p)
{
    if (l == r)  // base case
    {
        return;
    }
    int mid = l + ((r - l) >> 1);
    process(arr, l, mid, p);
    process(arr, mid + 1, r, p);
    merge(arr, l, mid, r, p);
}



void merge(int arr[], int l, int mid, int r, int* help)
{
    int i = l;
    int p = l, q = mid + 1;
    while (p <= mid && q <= r)
    {
        help[i++] = arr[p] <= arr[q] ? arr[p++] : arr[q++];
    }
    // p q中一定有一个越界
    while (p <= mid)
    {
        help[i] = arr[p];
        ++p;
        ++i;
    }
    while (q <= r)
    {
        help[i] = arr[q];
        ++q;
        ++i;
    }
    for (int j = l; j <= r; ++j)
    {
        arr[j] = help[j];
    }
}

// 归并排序的非递归版本
void mergeSort2(int arr[], int length, int* help)
{
    if (length <= 1)
    {
        return;
    }
    int N = length;
    int mergeSize = 1;  // 步长
    
    while (mergeSize < N)
    {
        int L = 0;  // 左组的起点
        while (L < N)
        {
            if (mergeSize > N - L)
            {
                break;
            }
            int M = L + mergeSize - 1;
            int R = M + min(mergeSize, N-M-1);
            merge(arr, L, M, R, help);
            L = R + 1;
        }
        // 防止溢出
        if (mergeSize > N / 2)
        {
            break;
        }
        mergeSize <<= 1;
    }

}

#endif