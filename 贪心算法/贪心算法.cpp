#include <iostream>
#include <algorithm>
using namespace std;

#if 0
/*
部分背包问题，有n个物体，第i个物体的重量为wi，价值为vi。在总重量不超过C的情况下让总价值尽量高。
每一个物体都可以只取走一部分，价值和重量按比例计算。求最大总价值。
*/

struct Product
{
	int id;
	int weight;
	int value;

	bool operator>(const Product& p) const {
		return get_price() > p.get_price();
	}

	double get_price()const  // 获取每种物品的性价比
	{
		return value * 1.0 / weight;
	}
};

int main()
{
	int w[] = { 8,6,4,2,5 };
	int v[] = { 6,4,7,8,6 };
	const int n = sizeof(w) / sizeof(w[0]);
	int bag = 12;
	int ans[n] = { 0 };
	int total_value = 0;
	int rest_w = 12;

	Product pros[n];
	for (int i = 0; i < n; i++)
	{
		pros[i].id = i;
		pros[i].weight = w[i];
		pros[i].value = v[i];
	}

	// 按物品的性价比降序排列
	sort(pros, pros + n, [](const Product& p1, const Product& p2) -> bool {return p1 > p2; });
	// 按性价比高的往背包里面放（只考虑局部的最优解）
	for (int i = 0; i < n; i++)
	{
		if (w[i] < rest_w)
		{
			total_value += pros[i].value;
			rest_w -= w[i];
			ans[pros[i].id] = 1;
		}
		else
		{
			total_value += pros[i].value * (rest_w * 1.0 / pros[i].weight);
			ans[pros[i].id] = 1;
			break;
		}
	}

	cout << "best_value: " << total_value << endl;
	cout << "[ ";
	for (int v : ans)
	{
		cout << v << " ";
	}
	cout << "]" << endl;

	return 0;
}
#endif

#if 0
/*
1,3,5分的硬币，现在给定一个价值c：11，问组成价值c需要的最少的硬币的数量？？？
*/
int main()
{
	int arr[] = { 1,3,5 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int c = 11;
	int cnt = 0; // 记录硬币个数

	sort(arr, arr + length, [](int a, int b) -> bool {return a > b; });
	int idx = 0;
	while (c > 0)
	{
		if (arr[0] < c)
		{
			c -= arr[0];
			cnt++;
			continue;
		}
		else if (arr[1] < c)
		{
			c -= arr[1];
			cnt++;
			continue;
		}
		else
		{
			c -= arr[2];
			cnt++;
		}
	}
	cout << "最少需要的硬币数量：" << cnt << endl;

	return 0;
}
#endif

/*
m个柜台提供服务，每个柜台给一个用户提供服务的时间是t(用数组表示每一个柜台提供服务的时间)，
问怎么排列，使得柜台给所有用户提供服务的时间最少
*/
struct Counter
{
	int id;  // 柜台id
	int time;  // 柜台提供服务所需时间
	bool operator<(const Counter& counter) const
	{
		return time < counter.time;
	}
};

int main()
{
	int arr[] = { 3,2,4 };  // 每一个柜台提供服务的时间
	const int length = sizeof(arr) / sizeof(arr[0]);  // 柜台的数量
	int persons = 15;  // 办理业务的人数

	// 初始化柜台id和时间
	Counter cons[length];
	for (int i = 0; i < length; i++)
	{
		cons[i].id = i;
		cons[i].time = arr[i];
	}
	// 按照柜台提供的服务时间 升序排列
	sort(cons, cons + length);

	int mintime = 0;  // 记录给所有用户提供服务的最少时间
	int x[length] = { 0 };  // 记录每一个柜台安排的用户数量

	for (int i = 0; i < length; i++)
	{
		// 先计算把用户放在0号柜台的时间
		int time = cons[i].time * (x[0] + 1);
		int j = 1;
		for (; j < length; j++)
		{
			int t = cons[j].time * (x[j] + 1);
			if (t < time)  // 放在其他柜台处理时间总体更快，直接放入j柜台
			{
				x[j]++;
				// 新添加了一个人，整体花费的时间有可能变得更长了，更新mintime
				if (t > mintime)
				{
					mintime = t;
				}
				break;
			}
		}
		// 最终还是放在0号柜台花费时间最少
		if (j == length)
		{
			x[0]++;
			mintime = cons[0].time * x[0];
		}
	}

	cout << mintime << endl;
	for (int i = 0; i < length; i++)
	{
		cout << arr[cons[i].id] << " : " << x[i] << endl;
	}
	
	return 0;
}