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
//
//int main()
//{
//	const int COUNT = 100000;
//	int* arr = new int[COUNT];
//
//	srand(time(nullptr));
//}

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

    BubleSort(arr, 10);

	for (int v : arr)
	{
		cout << v << " ";
	}
	cout << endl;
}