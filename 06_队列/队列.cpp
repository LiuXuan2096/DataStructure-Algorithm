#include <iostream>
using namespace std;

// ʹ��˫ѭ������ʵ�ֶ���
class Queue
{
public:
	Queue()
	{
		head_ = new Node();
		head_->next_ = head_;
		head_->pre_ = head_;
	}
	~Queue()
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			head_->next_ = p->next_;
			p->next_->pre_ = head_;
			delete p;
			p = head_->next_;
		}
		delete head_;
		head_ = nullptr;
	}
public:
	// ��� (β�巨��
	void push(int val)
	{
		Node* node = new Node(val);
		node->next_ = head_;
		node->pre_ = head_->pre_;
		head_->pre_->next_ = node;
		head_->pre_ = node;
	}
	// ����
	void pop()
	{
		Node* p = head_->next_;
		head_->next_ = p->next_;
		p->next_->pre_ = head_;
		delete p;
	}
	// ��ȡ��ͷԪ��
	int front() const
	{
		if (head_->next_ == head_)
		{
			throw "queue is empty!";
		}
		return head_->next_->data_;
	}
	// ��ȡ��βԪ��
	int back() const
	{
		if (head_->next_ == head_)
		{
			throw "queue is empty!";
		}
		return head_->pre_->data_;
	}
	// �п�
	bool empty() const
	{
		return head_->next_ == head_;
	}
private:
	struct Node
	{
		int data_;
		Node* pre_;
		Node* next_;
		Node(int data = 0)
			: data_(data)
			, pre_(nullptr)
			, next_(nullptr)
		{}
	};

	Node* head_;  // ָ��ͷ���
};

#if 0
// ʹ������ʵ�ֶ���
class Queue
{
public:
	Queue(int size = 10)
		: cap_(size)
		, front_(0)
		, rear_(0)
		, size_(0)
	{
		pQue_ = new int[cap_];
	}
	~Queue()
	{
		delete[] pQue_;
		pQue_ = nullptr;
	}
public:
	//  ���O��1��
	void push(int val)
	{
		if ((rear_ + 1) % cap_ == front_)
		{
			expand(2 * size_);
		}
		pQue_[rear_] = val;
		rear_ = (rear_ + 1) % cap_;
		size_++;
	}

	// ���� O��1��
	void pop()
	{
		if (front_ == rear_)
		{
			throw "queue is empty!";
		}
		front_ = (front_ + 1) % cap_;
		size_--;
	}

	// ��ͷԪ��
	int front() const
	{
		if (front_ == rear_)
		{
			throw "queue is empty!";
		}
		return pQue_[front_];
	}

	// ��βԪ��
	int back() const
	{
		if (front_ == rear_)
		{
			throw "queue is empty!";
		}
		return pQue_[(rear_ - 1 + cap_) % cap_];
	}

	// �ӿ�
	bool empty() const
	{
		return front_ == rear_;
	}

	// ����Ԫ�صĸ���
	int size() const
	{
		return size_;
	}
private:
	// ���ݽӿ�
	void expand(int size)
	{
		int* p = new int[size];
		int i = 0;
		int j = front_;
		for ( ; j != rear_; i++, j = (j + 1) % cap_)
		{
			p[i] = pQue_[j];
		}
		delete[] pQue_;
		pQue_ = p;
		front_ = 0;
		rear_ = i;
		cap_ = size;
	}
private:
	int* pQue_;
	int cap_;  // �ռ�����
	int front_;  // ��ͷ
	int rear_;  // ��β
	int size_;  // ����Ԫ�ظ���
};
#endif

int main()
{
	int arr[] = { 12,4,56,7,89,31,53,75 };
	Queue que;

	for (int v : arr)
	{
		que.push(v);
	}
	cout << que.front() << endl;
	cout << que.back() << endl;

	que.push(100);
	que.push(200);
	que.push(300);
	cout << que.front() << endl;
	cout << que.back() << endl;

	while (!que.empty())
	{
		cout << que.front() << " " << que.back() << endl;
		que.pop();
	}
}