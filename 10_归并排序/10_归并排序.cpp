#include <iostream>
using namespace std;

void Merge(int arr[], int l, int m, int r, int* p)
{
	int index = 0;
	int i = l;
	int j = m + 1;

	while (i <= m && j <= r)
	{
		if (arr[i] <= arr[j])
		{
			p[index] = arr[i];
			i++;
			index++;
		}
		else
		{
			p[index] = arr[j];
			j++;
			index++;
		}
	}
	while (i <= m)
	{
		p[index] = arr[i];
		index++;
		i++;
	}
	while (j <= r)
	{
		p[index] = arr[j];
		index++;
		j++;
	}
	// 把合并后的数组放回原数组的对应位置
	for (int m = l, n = 0; m <= r; m++)
	{
		arr[m] = p[n];
		n++;
	}
}

void MergeSort(int arr[], int begin, int end, int *p)
{
	// 递归结束的条件
	if (begin >= end)
	{
		return;
	}

	int mid = (begin + end) >> 1;
	// 先递
	MergeSort(arr, begin, mid, p);
	MergeSort(arr, mid + 1, end, p);
	// 再归并 [begin, mid] [mid + 1, end] 把两个小段有序的序列，合并成大段有序的序列
	Merge(arr, begin, mid, end, p);

}

void MergeSort(int arr[], int size)
{
	int* p = new int[size];
	MergeSort(arr, 0, size - 1, p);
	delete[]p;
}

int main()
{
	int arr[10];
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 100 + 1;
	}

	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;

	MergeSort(arr, 10);

	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;
}