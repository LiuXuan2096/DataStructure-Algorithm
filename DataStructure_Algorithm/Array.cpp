// ʹ��C++ʵ�ֶ�̬����

#include <iostream>
using namespace std;

class Array
{
public:
	Array(int size = 10) : mCur(0), mCap_(size)
	{
		mpArr = new int[mCap_]();
	}
	~Array()
	{
		delete[]mpArr;
		mpArr = nullptr;
	}
public:
	// ĩβ����Ԫ��
	void push_back(int val)
	{
		if (mCur == mCap_)
		{
			expand(2 * mCap_);
		}
		mpArr[mCur++] = val;
	}
	// ĩβɾ��Ԫ��
	void pop_back()
	{
		if (mCur == 0)
		{
			return;
		}
		mCur--;
	}
	// ��λ������Ԫ��
	void insert(int pos, int val)
	{
		if (pos < 0 || pos > mCur)
		{
			return;
		}

		if (mCur == mCap_)
		{
			expand(2 * mCap_);
		}
		// �ƶ�Ԫ��O(n)
		for (int i = mCur - 1; i >= pos; i--)
		{
			mpArr[i + 1] = mpArr[i];
		}
		mpArr[pos] = val;
		mCur++;
	}
	// ��λ��ɾ��Ԫ��
	void erase(int pos)
	{
		if (pos < 0 || pos >= mCur)
		{
			return;
		}

		// O(n)
		for (int i = pos + 1; i < mCur; i++)
		{
			mpArr[i - 1] = mpArr[i];
		}
		mCur--;
	}
	// Ԫ�ز�ѯ
	int find(int val)
	{
		for (int i = 0; i < mCur; i++)
		{
			if (mpArr[i] == val)
			{
				return i;
			}
		}
		return -1;
	}
	// ��ӡ����
	void show()const
	{
		for (int i = 0; i < mCur; i++)
		{
			cout << mpArr[i] << " ";
		}
		cout << endl;
	}
private:
	// �ڲ��������ݽӿ�
	void expand(int size)
	{
		int* p = new int[size];
		memcpy(p, mpArr, sizeof(int) * mCap_);
		delete[]mpArr;
		mpArr = p;
		mCap_ = size;
	}
private:
	int* mpArr; // ָ����Ͽ��ٵ��ڴ��׵�ַ
	int mCap_;  // ���������
	int mCur;   // ������ЧԪ�ظ���
};

int main()
{
	Array arr;

	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		arr.push_back(rand() % 100);
	}

	arr.show();
	arr.pop_back();
	arr.show();


	arr.insert(0, 100);
	arr.show();

	arr.insert(10, 200);
	arr.show();

	int pos = arr.find(100);
	if (pos != -1)
	{
		arr.erase(pos);
		arr.show();
	}
}
