#include <iostream>
using namespace std;

#if 0
// 顺序栈
class SeqStack
{
public:
	SeqStack(int size = 10)
		: mtop(0)
		, mcap(size)
	{
		mpStack = new int[mcap];
	}
	~SeqStack()
	{
		delete[]mpStack;
		mpStack = nullptr;
	}
public:
	// 入栈
	void push(int val)
	{
		if (mtop == mcap)
		{
			expand(2 * mcap);
		}
		mpStack[mtop] = val;
		mtop++;
	}

	// 出栈
	void pop()
	{
		if (mtop == 0)
		{
			throw "stack is empty!";
		}
		mtop--;
	}

	// 获取栈顶元素
	int top() const
	{
		if (mtop == 0)
		{
			throw "stack is empty!";
		}
		return mpStack[mtop - 1];
	}

	// 栈空
	bool empty() const
	{
		return mtop == 0;
	}

	int size() const { return mtop; }
private:
	void expand(int size)
	{
		int* p = new int[size];
		memcpy(p, mpStack, mtop * sizeof(int));
		delete[] mpStack;
		mpStack = p;
		mcap = size;
	}
private:
	int* mpStack;
	int mtop; // 栈顶位置
	int mcap; // 栈空间大小
};
#endif

class LinkStack
{
public:
	LinkStack()
	{
		head_ = new Node();
	}
	~LinkStack()
	{
		Node* p = head_->next_;
		while (p != nullptr)
		{
			Node* tmp = p;
			p = p->next_;
			delete tmp;
		}
		delete head_;
	}
public:
	// 入栈 O（1）
	void push(int val)
	{
		Node* node = new Node(val);
		node->next_ = head_->next_;
		head_->next_ = node;
		size_++;
	}

	// 出栈
	void pop()
	{
		if (head_->next_ == nullptr)
		{
			throw "Stack is empty!";
		}
		Node* p = head_->next_;
		head_->next_ = p->next_;
		delete p;
		size_--;
	}

	// 获取栈顶元素
	int top() const
	{
		if (head_->next_ == nullptr)
		{
			throw "Stack is empty!";
		}
		return head_->next_->data_;
	}

	// 判空
	bool empty() const
	{
		return head_->next_ == nullptr;
	}

	// 返回栈元素个数
	int size() const
	{
		return size_;
	}
private:
	struct Node
	{
		int data_;
		Node* next_;
		Node(int val = 10)
			: data_(val)
			, next_(nullptr)
		{}
	};
	
	Node* head_;
	int size_;
};

int main()
{
	int arr[] = { 12,4,56,7,89,31,53,75 };
	LinkStack s;

	for (int v : arr)
	{
		s.push(v);
	}
	cout << s.size() << endl;
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	cout << s.size() << endl;
}