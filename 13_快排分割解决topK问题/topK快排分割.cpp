#include <iostream>
#include <algorithm>
using namespace std;

/* �ڱ����� */
int partition(int nums[], int left, int right) {
	// �� nums[left] ��Ϊ��׼��
	int i = left, j = right;
	while (i < j) {
		while (i < j && nums[j] >= nums[left])
			j--; // �����������׸�С�ڻ�׼����Ԫ��
		while (i < j && nums[i] <= nums[left])
			i++;          // �����������׸����ڻ�׼����Ԫ��
		swap(nums[i], nums[j]); // ����������Ԫ��
	}
	swap(nums[i], nums[left]); // ����׼����������������ķֽ���
	return i;            // ���ػ�׼��������
}

// ��topK�ĺ���
void SelectTopK(int arr[], int begin, int end, int k)
{
	int pos = partition(arr, begin, end);
	if (pos == k - 1)
	{
		return;
	}
	if (pos < k - 1)
	{
		SelectTopK(arr, pos + 1, end, k);
	}
	else
	{
		SelectTopK(arr, begin, pos - 1, k);
	}
}

int main()
{
	int arr[] = { 64, 45, 52, 80, 66, 68, 0, 2, 18, 75 };
	int size = sizeof arr / sizeof arr[0];

	// ��ֵ��С��ǰ3��Ԫ��
	int k = 3;
	SelectTopK(arr, 0, size - 1, k);

	for (int i = 0; i < k; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}