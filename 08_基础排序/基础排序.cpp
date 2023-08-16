#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


// 冒泡排序算法
void BubleSort(int arr[], int size)
{
	
	for (int i = size; i > 1; i--)
	{
		bool flag = true;  // flag为true表示当前数组有序
		for (int j = 0; j < i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = false;  // 发生交换时 将flag置为false 表示当前数组无序
			}
		}
		if (flag)
		{
			return;
		}
	}
}


// 选择排序算法
void ChoiceSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int min_index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min_index])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			int tmp = arr[min_index];
			arr[min_index] = arr[i];
			arr[i] = tmp;
		}
	}
}

// 插入排序算法
void InsertSort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int val = arr[i];
		int j = i - 1;
		for (; j >= 0; j--)
		{
			if (arr[j] <= val)
			{
				break;
			}
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = val;
	}
}

// 希尔排序
void ShellSort(int arr[], int size)
{
	for (int gap = size >> 1; gap > 0; gap = gap >> 1)
	{
		for (int i = gap; i < size; i++)
		{
			int val = arr[i];
			int j = i - gap;
			for (; j >= 0; j -= gap)
			{
				if (arr[j] <= val)
				{
					break;
				}
				arr[j + gap] = arr[j];
			}
			arr[j + gap] = val;
		}
	}
}


int main()
{
	const int COUNT = 100000;
	int* arr = new int[COUNT];
	int* brr = new int[COUNT];
	int* crr = new int[COUNT];
	int* drr = new int[COUNT];

	srand(time(nullptr));

	for (int i = 0; i < COUNT; i++)
	{
		int val = rand() % COUNT;
		arr[i] = val;
		brr[i] = val;
		crr[i] = val;
		drr[i] = val;
	}

	clock_t begin, end;

	begin = clock();
	BubleSort(arr, COUNT);
	end = clock();
	cout << "BubbleSort spend: " << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

	begin = clock();
	ChoiceSort(brr, COUNT);
	end = clock();
	cout << "ChoiceSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

	begin = clock();
	InsertSort(crr, COUNT);
	end = clock();
	cout << "InsertSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

	begin = clock();
	ShellSort(drr, COUNT);
	end = clock();
	cout << "ShellSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

}

#if 0
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

    // BubleSort(arr, 10);
	// ChoiceSort(arr, 10);
	// InsertSort(arr, 10);
	ShellSort(arr, 10);

	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;
}
#endif