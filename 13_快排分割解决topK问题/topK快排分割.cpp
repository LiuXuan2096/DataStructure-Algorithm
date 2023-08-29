#include <iostream>
#include <algorithm>
using namespace std;

/* 哨兵划分 */
int partition(int nums[], int left, int right) {
	// 以 nums[left] 作为基准数
	int i = left, j = right;
	while (i < j) {
		while (i < j && nums[j] >= nums[left])
			j--; // 从右向左找首个小于基准数的元素
		while (i < j && nums[i] <= nums[left])
			i++;          // 从左向右找首个大于基准数的元素
		swap(nums[i], nums[j]); // 交换这两个元素
	}
	swap(nums[i], nums[left]); // 将基准数交换至两子数组的分界线
	return i;            // 返回基准数的索引
}

// 求topK的函数
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

	// 求值最小的前3个元素
	int k = 3;
	SelectTopK(arr, 0, size - 1, k);

	for (int i = 0; i < k; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}