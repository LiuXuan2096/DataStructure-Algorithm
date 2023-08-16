#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// 快速分割函数
int Partition(int arr[], int l, int r)
{
	// 选择基准数的优化：“三数取中”法   arr[l]   arr[r]   arr[(l+r)/2]
	int left = arr[l];
	int right = arr[r];
	int middle = arr[(l + r) >> 1];
    if ((right > left && right < middle) || (right < left && right > middle))
	{
		arr[r] = arr[l];
		arr[l] = right;
	}
	else if ((middle > left && middle < right) || (middle < left && middle > right))
	{
		arr[l] = middle;
		arr[(l + r) >> 1] = left;
	}
	int base = arr[l];

	while (l < r)
	{
		while (l < r && arr[r] > base)
		{
			r--;
		}
		if (l < r)
		{
			arr[l] = arr[r];
			l++;
		}
		while (l < r && arr[l] < base)
		{
			l++;
		}
		if (l < r)
		{
			arr[r] = arr[l];
		    r--;
		}

	}
	arr[l] = base;
	return l;
}

// 快速排序递归接口
void QuickSort(int arr[], int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	// 优化一：当[begin, end]序列的元素个数小到指定数量，采用插入排序
    //if (end - begin <= 50)
    //{
	// InsertSort(arr, begin, end);
	//return;
    //}
	int pivot = Partition(arr, begin, end);
	QuickSort(arr, begin, pivot - 1);
	QuickSort(arr, pivot + 1, end);
}

// 快速排序
void QuickSort(int arr[], int size)
{
	QuickSort(arr, 0, size - 1);
}

int main()
{
	int arr[10];
	srand(time(nullptr));

	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100 + 1;
	}

	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	QuickSort(arr, 10);

	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;
}