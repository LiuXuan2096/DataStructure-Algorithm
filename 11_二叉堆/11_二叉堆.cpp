#include <iostream>
#include <functional>
#include <stdlib.h>
#include <time.h>
using namespace std;

// ���ȼ�����ʵ��  priority_queue(vector) push pop top empty size
class PriorityQueue
{
public:
	using Comp = function<bool(int, int)>;
	PriorityQueue(int cap = 20, Comp comp = greater<int>())
		: size_(0)
		, cap_(cap)
		, comp_(comp)
	{
		que_ = new int[cap_];
	}
	PriorityQueue(Comp comp)
		: size_(0)
		, cap_(20)
		, comp_(comp)
	{
		que_ = new int[cap_];
	}
	~PriorityQueue()
	{
		delete[] que_;
		que_ = nullptr;
	}
public:
	// ��Ѳ���
	void push(int val)
	{
		if (size_ == cap_)  // ��Ҫ����
		{
			int* p = new int[2 * cap_];
			memcpy(p, que_, cap_ * sizeof(int));
			delete[] que_;
			que_ = p;
			cap_ *= 2;
		}

		if (size_ == 0)  // ����Ҫ�ϸ�
		{
			que_[size_] = val;
		}
		else
		{
			siftUp(size_, val);
		}
		size_++;
	}

	// ���Ѳ���
	void pop()
	{
		if (size_ == 0)
		{
			throw "container is empty!";
		}
		size_--;
		if (size_ > 0)
		{
			siftDown(0, que_[size_]);
		}
	}

	bool empty() const { return size_ == 0; }

	int top() const
	{
		if (size_ == 0)
		{
			throw "container is empty!";
		}
		return que_[0];
	}

	int size() const { return size_; }
private:
	// ����ϸ����� O(logn)
	void siftUp(int i, int val)
	{
		while (i > 0)  // ���Ƚϵ����ڵ�
		{
			int father = (i - 1) >> 1;
			if (comp_(val, que_[father]))
			{
				que_[i] = que_[father];
				i = father;
			}
			else
			{
				break;
			}
		}
		que_[i] = val;
	}
	// �����³����� O(logn)
	void siftDown(int i, int val)
	{
		// i���ܳ������һ���к��ӵĽڵ�
		while (i < (size_ >> 1))
		{
			int child = 2 * i + 1;  // child���ȼ�¼���ӵĽڵ�
			if (child + 1 < size_ && comp_(que_[child + 1], que_[child]))
			{
				child = child + 1;  // ����Һ��Ӵ������ӣ�child��¼�Һ��ӽڵ�
			}

			if (comp_(que_[child], val))
			{
				que_[i] = que_[child];
				i = child;
			}
			else
			{
				break;
			}
		}
		que_[i] = val;
	}
private:
	int* que_;  // ָ��̬���ݵ�����
	int size_;  // ����Ԫ�ظ���
	int cap_;  // ������ܿռ��С
	Comp comp_;  // �Ƚ�������
};

int main()
{
	// PriorityQueue que;  // ��������ʵ�ֵ����ȼ�����
	
	// ����С����ʵ�ֵ����ȼ�����
	PriorityQueue que([](int a, int b) {return a < b; });
	srand(time(nullptr));

	for (int i = 0; i < 10; i++)
	{
		que.push(rand() % 100);
	}

	while (!que.empty())
	{
		cout << que.top() << " ";
		que.pop();
	}
	cout << endl;
}