#include <iostream>
using namespace std;

// 使用双循环链表实现队列
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
	// 入队 (尾插法）
	void push(int val)
	{
		Node* node = new Node(val);
		node->next_ = head_;
		node->pre_ = head_->pre_;
		head_->pre_->next_ = node;
		head_->pre_ = node;
	}
	// 出队
	void pop()
	{
		Node* p = head_->next_;
		head_->next_ = p->next_;
		p->next_->pre_ = head_;
		delete p;
	}
	// 获取队头元素
	int front() const
	{
		if (head_->next_ == head_)
		{
			throw "queue is empty!";
		}
		return head_->next_->data_;
	}
	// 获取队尾元素
	int back() const
	{
		if (head_->next_ == head_)
		{
			throw "queue is empty!";
		}
		return head_->pre_->data_;
	}
	// 判空
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

	Node* head_;  // 指向头结点
};

#if 0
// 使用数组实现队列
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
	//  入队O（1）
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

	// 出队 O（1）
	void pop()
	{
		if (front_ == rear_)
		{
			throw "queue is empty!";
		}
		front_ = (front_ + 1) % cap_;
		size_--;
	}

	// 队头元素
	int front() const
	{
		if (front_ == rear_)
		{
			throw "queue is empty!";
		}
		return pQue_[front_];
	}

	// 队尾元素
	int back() const
	{
		if (front_ == rear_)
		{
			throw "queue is empty!";
		}
		return pQue_[(rear_ - 1 + cap_) % cap_];
	}

	// 队空
	bool empty() const
	{
		return front_ == rear_;
	}

	// 队列元素的个数
	int size() const
	{
		return size_;
	}
private:
	// 扩容接口
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
	int cap_;  // 空间容量
	int front_;  // 队头
	int rear_;  // 队尾
	int size_;  // 队列元素个数
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