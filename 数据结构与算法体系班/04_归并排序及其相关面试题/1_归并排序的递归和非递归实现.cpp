#include <iostream>
#include <vector>

using namespace std;

void merge(int arr[], int l, int mid, int r);
void process(int arr[], int l, int r);
void mergeSort1(int arr[], int length);


int main()
{
    int nums[] = {56, 45, 34, 21, 14, 10, 9,8,7,6,5,4,3,2,1};
    mergeSort1(nums, sizeof(nums) / sizeof(int));
    cout << "[ ";
    for (int i = 0; i < sizeof(nums) / sizeof(int); ++i)
    {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;
}

// 归并排序的递归版本
void mergeSort1(int arr[], int length)
{
    if (length <= 1)
    {
        return;
    }
    process(arr, 0, length - 1);
}

void process(int arr[], int l, int r)
{
    if (l == r)  // base case
    {
        return;
    }
    int mid = l + ((r - l) >> 1);
    process(arr, l, mid);
    process(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

void merge(int arr[], int l, int mid, int r)
{
    int help[r - l + 1];
    int i = 0;
    int p = l, q = mid + 1;
    while (p <= mid && q <= r)
    {
        help[i] = arr[p] <= arr[q] ? arr[p] : arr[q];
        ++p;
        ++q;
        ++i;
    }
    // 走到这一步说明左边 或者 右边 一定有一方越界了
    if (p > mid)
    {
        while (q <= r)
        {
            help[i] = arr[q];
            ++i;
            ++q;
        }
    }
    else if (q > r)
    {
        while (p <= mid)
        {
            help[i] = arr[p];
            ++i;
            ++p;
        }
    }
    for (int j = 0; j < (r - l + 1); ++j)
    {
        arr[l + j] = help[j];       
    }
}