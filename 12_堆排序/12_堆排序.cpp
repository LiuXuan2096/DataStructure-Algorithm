#include <iostream>
using namespace std;

// �ѵ��³�����
void siftDown(int arr[], int i, int size)
{
	int val = arr[i];
	while (i < (size >> 1))
	{
		int child = 2 * i + 1;  // child�ȼ�¼�����±�
		if (child + 1 < size && arr[child] < arr[child + 1])  // �Һ��Ӵ�������
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

// ������
void HeapSort(int arr[], int size)
{
	int n = size - 1;
	// �ӵ�һ����Ҷ�ӽڵ�
	for (int i = (n - 1) >> 1; i >= 0; i--)
	{
		siftDown(arr, i, size);
	}

	// �ѶѶ�Ԫ�غ�ĩβԪ�ؽ��н������ӶѶ����ǽ����³�����
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