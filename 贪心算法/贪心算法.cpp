#include <iostream>
#include <algorithm>
using namespace std;

#if 0
/*
���ֱ������⣬��n�����壬��i�����������Ϊwi����ֵΪvi����������������C����������ܼ�ֵ�����ߡ�
ÿһ�����嶼����ֻȡ��һ���֣���ֵ���������������㡣������ܼ�ֵ��
*/

struct Product
{
	int id;
	int weight;
	int value;

	bool operator>(const Product& p) const {
		return get_price() > p.get_price();
	}

	double get_price()const  // ��ȡÿ����Ʒ���Լ۱�
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

	// ����Ʒ���Լ۱Ƚ�������
	sort(pros, pros + n, [](const Product& p1, const Product& p2) -> bool {return p1 > p2; });
	// ���Լ۱ȸߵ�����������ţ�ֻ���Ǿֲ������Ž⣩
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
1,3,5�ֵ�Ӳ�ң����ڸ���һ����ֵc��11������ɼ�ֵc��Ҫ�����ٵ�Ӳ�ҵ�����������
*/
int main()
{
	int arr[] = { 1,3,5 };
	int length = sizeof(arr) / sizeof(arr[0]);
	int c = 11;
	int cnt = 0; // ��¼Ӳ�Ҹ���

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
	cout << "������Ҫ��Ӳ��������" << cnt << endl;

	return 0;
}
#endif

/*
m����̨�ṩ����ÿ����̨��һ���û��ṩ�����ʱ����t(�������ʾÿһ����̨�ṩ�����ʱ��)��
����ô���У�ʹ�ù�̨�������û��ṩ�����ʱ������
*/
struct Counter
{
	int id;  // ��̨id
	int time;  // ��̨�ṩ��������ʱ��
	bool operator<(const Counter& counter) const
	{
		return time < counter.time;
	}
};

int main()
{
	int arr[] = { 3,2,4 };  // ÿһ����̨�ṩ�����ʱ��
	const int length = sizeof(arr) / sizeof(arr[0]);  // ��̨������
	int persons = 15;  // ����ҵ�������

	// ��ʼ����̨id��ʱ��
	Counter cons[length];
	for (int i = 0; i < length; i++)
	{
		cons[i].id = i;
		cons[i].time = arr[i];
	}
	// ���չ�̨�ṩ�ķ���ʱ�� ��������
	sort(cons, cons + length);

	int mintime = 0;  // ��¼�������û��ṩ���������ʱ��
	int x[length] = { 0 };  // ��¼ÿһ����̨���ŵ��û�����

	for (int i = 0; i < length; i++)
	{
		// �ȼ�����û�����0�Ź�̨��ʱ��
		int time = cons[i].time * (x[0] + 1);
		int j = 1;
		for (; j < length; j++)
		{
			int t = cons[j].time * (x[j] + 1);
			if (t < time)  // ����������̨����ʱ��������죬ֱ�ӷ���j��̨
			{
				x[j]++;
				// �������һ���ˣ����廨�ѵ�ʱ���п��ܱ�ø����ˣ�����mintime
				if (t > mintime)
				{
					mintime = t;
				}
				break;
			}
		}
		// ���ջ��Ƿ���0�Ź�̨����ʱ������
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