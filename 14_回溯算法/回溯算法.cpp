#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

#if 0
/*
子集树代码
*/
void func(int arr[], int i, int length, int x[])
{
	if (i == length)
	{
		cout << "[ ";
		for (int j = 0; j < length; j++)
		{
			
			if (x[j] == 1)
			{
				cout << arr[j];
			}
		}
		cout << " ]" << endl;
	}
	else
	{
		x[i] = 1;
		// x[i] = 1 表示选择i节点 0表示不选择i节点
		func(arr, i + 1, length, x);
		x[i] = 0;
		func(arr, i + 1, length, x);
	}
}

int main()
{
	int arr[] = { 1,2,3 };
	int x[3] = { 0 };
	int length = sizeof(arr) / sizeof(arr[0]);
	func(arr, 0, length, x);
	return 0;
}
#endif

#if 0
/*
整数选择问题：给定一组整数，从里面挑选出一组整数，让选择的整数的和，和剩下的整数的和的差最小
*/
int arr[] = { 12,6,7,11,16,3,8 };
vector<int> x;
vector<int> bestx;
int minum = INT_MAX;
int sum = 0;
int rest = 0;
const int length = sizeof(arr) / sizeof(arr[0]);

void func(int arr[], int i, int length)
{
	if (i == length)
	{
		// 遍历到了子集树的叶子节点
		if (abs(sum - rest) < minum)
		{
			minum = abs(sum - rest);
			bestx = x;
		}
	}
	else
	{
		// 选择arr[i]
		rest -= arr[i];
		sum += arr[i];
		x.push_back(arr[i]);
		func(arr, i + 1, length);

		// 不选择arr[i]
		rest += arr[i];
		sum -= arr[i];
		x.pop_back();
		func(arr, i + 1, length);
	}
}

int main()
{
	for (int v : arr)
	{
		rest += v;
	}
	func(arr, 0, length);
	cout << "[ ";
	for (int v : bestx)
	{
		cout << v << " ";
	}
	cout << "]" << endl;
	cout << "min: " << minum << endl;

	return 0;
}
#endif

#if 0
/*
解空间-排列数的代码实现
*/
void func(int arr[], int i, int length)
{
	if (i == length)
	{
		cout << "[ ";
		for (int j = 0; j < length; j++)
		{
			cout << arr[j];
		}
		cout << " ]" << endl;
	}
	for (int k = i; k < length; k++)
	{
		swap(arr[k], arr[i]);
		func(arr, i + 1, length);
		swap(arr[k], arr[i]);
	}
}

int main()
{
	int arr[] = { 1,2,3,4 };
	int length = sizeof(arr) / sizeof(arr[0]);
	func(arr, 0, length);
	
	return 0;
}
#endif

#if 0
/*
整数选择问题：给定2n个整数，从里面挑选出n个整数，让选择的整数的和，和剩下的整数的和的差最小
*/
int arr[] = { 12,6,7,11,16,3,8,4 };
const int length = sizeof(arr) / sizeof(arr[0]);
vector<int> x;
vector<int> bestx;
int sum = 0;
int rest = 0;
int minum = INT_MAX;
int leftcnt = length;  // 记录未处理的数字的个数
int cnt = 0;  // 记录遍历的子集个个数 用于测试

void func(int i)
{
	if (i == length) // 说明递归到了子集树的叶子节点
	{
		
		if (x.size() == length >> 1)
		{
			int result = abs(sum - rest);
			if (result < minum)
			{
				minum = result;
				bestx = x;
			}
		}
		return;
	}
	else
	{
		leftcnt--; // 表示剩余的未处理的元素个数
		if (x.size() < (length >> 1))
		{
			rest -= arr[i];
			sum += arr[i];
			x.push_back(arr[i]);
			func(i + 1);
			
			rest += arr[i];
			sum -= arr[i];
			x.pop_back();
		}
		if (x.size() + leftcnt >= (length >> 1))
		{
			func(i + 1);
		}


		// 当前i节点已处理完成，回溯到其父节点了
		leftcnt++;
	}

}
int main()
{
	for (int v : arr)
	{
		rest += v;
	}
	func(0);
	cout << "[ ";
	for (int v : bestx)
	{
		cout << v << " ";
	}
	cout << "]" << endl;
	cout << "min: " << minum << endl;
	return 0;
}
#endif

#if 0
/*
挑选数字：有一组整数，请挑选出一组数字，让他们的和等于指定的值，存在解打印，不存在打印
*/
int arr[] = { 4,8,12,16,7,9,3 };
const int length = sizeof(arr) / sizeof(arr[0]);
int number = 18;
vector<int> x;  // 记录所选择的数字
int sum = 0;  // 记录所选择的数字的和
int rest = 0;  // 记录未选择的数字的和
void func(int i)
{
	if (i == length)  // 递归到了子集树的叶子节点
	{
		if (sum != number)
		{
			return;
		}
		cout << "[";
		for (int v : x)
		{
			cout << v << " ";
		}
		cout << "]" << endl;
	}
	else
	{
		rest -= arr[i];  // 处理当前i节点
		if (sum + arr[i] <= number)  // 剪左树枝 
		{
			sum += arr[i]; // 选择i节点
			x.push_back(arr[i]);
			func(i + 1);
			sum -= arr[i];  // 不选择i节点
			x.pop_back();
		}
		if (sum + rest >= number)  // 剪右树枝
		{
			func(i + 1);
		}
		rest += arr[i];
	}

}

int main()
{
	for (int v : arr)
	{
		rest += v;
	}
	func(0);
	return 0;
}
#endif

#if 0
int arr[] = { 4,8,12,16,7,9,3,3 };
const int length = sizeof(arr) / sizeof(arr[0]);
int number = 18;
vector<int> vec;  // 存放选择的数字
void func(int i, int number)
{
	if (number == 0)
	{
		cout << "[ ";
		for (int v : vec)
		{
			cout << v << " ";
		}
		cout << "]" << endl;
	}
	else
	{
		// 以当前节点开始 把剩余孩子的节点生成
		for (int k = i; k < length; k++)
		{
			if (number >= arr[k])  // 剩余的元素小于number
			{
				vec.push_back(arr[k]);
				// 当前层遍历到下一层的时候  arr[k] != arr[k - 1]
				// 不允许选择重复元素
				func(k + 1, number - arr[k]);
				// 允许选择重复元素
				// func(k, number - arr[k]);
				vec.pop_back();
			}
		}
	}
}

int main()
{
	func(0, number);

	return 0;
}
#endif

#if 0
// 另一种实现全排列的代码   满足leetcode刷题测试用例
int arr[] = { 1,2,3 };
const int N = 3;
bool state[N];  // // 记录所有元素是否被选择的状态  true：选择了  false：未选择
vector<int> vec;
void func(int i)
{
	if (i == N)
	{
		cout << "[ ";
		for (int v : vec)
		{
			cout << v << " ";
		}
		cout << "]" << endl;
	}
	else
	{
		for (int k = 0; k < N; k++)
		{
			if (!state[k])
			{
				state[k] = true;
				vec.push_back(arr[k]);
				func(i + 1);  // k表示的是可选择元素的起始下标，i表示层数。
				vec.pop_back();
				state[k] = false;
			}
		}
	}

	return;
}

int main()
{
	func(0);

	return 0;
}
#endif

#if 0
/*
0-1背包问题：有一组物品，其重量分别是:w1,w2,...wn，其价值分别是v1,v2,...,vn，现在有一个背包，其容量是C，
问怎么把物品装入背包，能够使背包的价值最大化？
*/
int w[] = { 12,5,8,9,6 };  // 物品的重量
int v[] = { 9,2,4,7,8 };  // 物品的价值
const int length = sizeof(w) / sizeof(w[0]);
int bag = 20; 
int selected_w;
int selected_v;
vector<int> x; // 记录选择的物品
vector<int> bestx;  // 记录最优选择的物品
int bestv;  // 记录装入物品的最大价值
int restv;  // 记录未选择物品的价值

void func(int i)
{
	if (i == length)
	{
		if (selected_v > bestv)
		{
			bestx = x;
			bestv = selected_v;
		}
		
	}
	else
	{
		restv -= v[i];
		if (selected_w + w[i] <= bag)   // 剪枝 剪左枝 剪选择i的那个分支
		{
			selected_w += w[i];
			selected_v += v[i];
			x.push_back(w[i]);
			func(i + 1);
			x.pop_back();
			selected_w -= w[i];
			selected_v -= v[i];
		}

		if (selected_v + restv > bestv)  // 剪枝 剪右枝 剪不选择i的那个分支
		{
			func(i + 1);
		}
		restv += v[i];

	}
}

int main()
{
	for (int val : v)
	{
		restv += val;
	}
	func(0);
	cout << "[ ";
	for (int v : bestx)
	{
		cout << v << " ";
	}
	cout << "]  bestv:" << bestv << endl;
	
	return 0;
}
#endif

/*
八皇后问题
*/
int cnt = 0; // 统计排列次数
bool judge(int arr[], int i)  // i表示放置皇后的位置 第i行或者 
{
	for (int j = 0; j < i; j++)
	{
		if (arr[i] == arr[j] or (i - j) == abs((arr[i] - arr[j])))
		{
			return false;
		}
	}
	return true;
	
}
void func(int arr[], int i, int length)
{
	if (i == length)
	{
		cout << "[ ";
		for (int i = 0; i < length; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "]" << endl;
		cnt++;
	}
	else
	{
		for (int k = i; k < length; k++)
		{
			swap(arr[k], arr[i]);
			if (judge(arr, i))  // 交换后 i位置的皇后满足条件 剪枝
			{
				func(arr, i + 1, length);
			}
			swap(arr[k], arr[i]);
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8 };
	int length = sizeof(arr) / sizeof(arr[0]);
	func(arr, 0, length);
	cout << "排列方式有" << cnt << "种" << endl;

	return 0;
}
