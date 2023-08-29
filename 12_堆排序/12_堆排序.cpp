#include <iostream>
using namespace std;

// 堆的下沉调整
void siftDown(int arr[], int i, int size)
{
	int val = arr[i];
	while (i < (size >> 1))
	{
		int child = 2 * i + 1;  // child先记录左孩子下标
		if (child + 1 < size && arr[child] < arr[child + 1])  // 右孩子大于左孩子
		{
			child = child + 1;
		}

		if (val < arr[child])
		{
			arr[i] = arr[child];
			i = child;
		}
		else
		{
			break;
		}
	}
	arr[i] = val;
}

// 堆排序
void HeapSort(int arr[], int size)
{
	int n = size - 1;
	// 从第一个非叶子节点
	for (int i = (n - 1) >> 1; i >= 0; i--)
	{
		siftDown(arr, i, size);
	}

	// 把堆顶元素和末尾元素进行交换，从堆顶还是进行下沉操作
	for (int i = n; i > 0; i--)
	{
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;

		siftDown(arr, 0, i);
	}
}

//int main()
//{
//	int arr[10];
//	srand(time(nullptr));
//
//	for (int i = 0; i < 10; i++)
//	{
//		arr[i] = rand() % 100 + 1;
//	}
//
//	for (int v : arr)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//
//	HeapSort(arr, 10);
//	for (int v : arr)
//	{
//		cout << v << " ";
//	}
//	cout << endl;
//}