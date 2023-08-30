#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

#if 0
/*
�Ӽ�������
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
		// x[i] = 1 ��ʾѡ��i�ڵ� 0��ʾ��ѡ��i�ڵ�
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
����ѡ�����⣺����һ����������������ѡ��һ����������ѡ��������ĺͣ���ʣ�µ������ĺ͵Ĳ���С
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
		// ���������Ӽ�����Ҷ�ӽڵ�
		if (abs(sum - rest) < minum)
		{
			minum = abs(sum - rest);
			bestx = x;
		}
	}
	else
	{
		// ѡ��arr[i]
		rest -= arr[i];
		sum += arr[i];
		x.push_back(arr[i]);
		func(arr, i + 1, length);

		// ��ѡ��arr[i]
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
��ռ�-�������Ĵ���ʵ��
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
����ѡ�����⣺����2n����������������ѡ��n����������ѡ��������ĺͣ���ʣ�µ������ĺ͵Ĳ���С
*/
int arr[] = { 12,6,7,11,16,3,8,4 };
const int length = sizeof(arr) / sizeof(arr[0]);
vector<int> x;
vector<int> bestx;
int sum = 0;
int rest = 0;
int minum = INT_MAX;
int leftcnt = length;  // ��¼δ��������ֵĸ���
int cnt = 0;  // ��¼�������Ӽ������� ���ڲ���

void func(int i)
{
	if (i == length) // ˵���ݹ鵽���Ӽ�����Ҷ�ӽڵ�
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
		leftcnt--; // ��ʾʣ���δ�����Ԫ�ظ���
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


		// ��ǰi�ڵ��Ѵ�����ɣ����ݵ��丸�ڵ���
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
��ѡ���֣���һ������������ѡ��һ�����֣������ǵĺ͵���ָ����ֵ�����ڽ��ӡ�������ڴ�ӡ
*/
int arr[] = { 4,8,12,16,7,9,3 };
const int length = sizeof(arr) / sizeof(arr[0]);
int number = 18;
vector<int> x;  // ��¼��ѡ�������
int sum = 0;  // ��¼��ѡ������ֵĺ�
int rest = 0;  // ��¼δѡ������ֵĺ�
void func(int i)
{
	if (i == length)  // �ݹ鵽���Ӽ�����Ҷ�ӽڵ�
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
		rest -= arr[i];  // ����ǰi�ڵ�
		if (sum + arr[i] <= number)  // ������֦ 
		{
			sum += arr[i]; // ѡ��i�ڵ�
			x.push_back(arr[i]);
			func(i + 1);
			sum -= arr[i];  // ��ѡ��i�ڵ�
			x.pop_back();
		}
		if (sum + rest >= number)  // ������֦
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
vector<int> vec;  // ���ѡ�������
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
		// �Ե�ǰ�ڵ㿪ʼ ��ʣ�ຢ�ӵĽڵ�����
		for (int k = i; k < length; k++)
		{
			if (number >= arr[k])  // ʣ���Ԫ��С��number
			{
				vec.push_back(arr[k]);
				// ��ǰ���������һ���ʱ��  arr[k] != arr[k - 1]
				// ������ѡ���ظ�Ԫ��
				func(k + 1, number - arr[k]);
				// ����ѡ���ظ�Ԫ��
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
// ��һ��ʵ��ȫ���еĴ���   ����leetcodeˢ���������
int arr[] = { 1,2,3 };
const int N = 3;
bool state[N];  // // ��¼����Ԫ���Ƿ�ѡ���״̬  true��ѡ����  false��δѡ��
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
				func(i + 1);  // k��ʾ���ǿ�ѡ��Ԫ�ص���ʼ�±꣬i��ʾ������
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
0-1�������⣺��һ����Ʒ���������ֱ���:w1,w2,...wn�����ֵ�ֱ���v1,v2,...,vn��������һ����������������C��
����ô����Ʒװ�뱳�����ܹ�ʹ�����ļ�ֵ��󻯣�
*/
int w[] = { 12,5,8,9,6 };  // ��Ʒ������
int v[] = { 9,2,4,7,8 };  // ��Ʒ�ļ�ֵ
const int length = sizeof(w) / sizeof(w[0]);
int bag = 20; 
int selected_w;
int selected_v;
vector<int> x; // ��¼ѡ�����Ʒ
vector<int> bestx;  // ��¼����ѡ�����Ʒ
int bestv;  // ��¼װ����Ʒ������ֵ
int restv;  // ��¼δѡ����Ʒ�ļ�ֵ

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
		if (selected_w + w[i] <= bag)   // ��֦ ����֦ ��ѡ��i���Ǹ���֧
		{
			selected_w += w[i];
			selected_v += v[i];
			x.push_back(w[i]);
			func(i + 1);
			x.pop_back();
			selected_w -= w[i];
			selected_v -= v[i];
		}

		if (selected_v + restv > bestv)  // ��֦ ����֦ ����ѡ��i���Ǹ���֧
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
�˻ʺ�����
*/
int cnt = 0; // ͳ�����д���
bool judge(int arr[], int i)  // i��ʾ���ûʺ��λ�� ��i�л��� 
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
			if (judge(arr, i))  // ������ iλ�õĻʺ��������� ��֦
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
	cout << "���з�ʽ��" << cnt << "��" << endl;

	return 0;
}
