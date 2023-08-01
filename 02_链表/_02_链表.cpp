#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// 单链表节点类型
struct Node
{
	int val_;
	Node* next_;

	Node(int data = 0) : val_(data), next_(nullptr) {}
};

// 单链表代码实现
class Clink
{
public:
	Clink()
	{
		// 初始化虚拟头结点
		head_ = new Node();
	}
	~Clink()
	{
		// 节点的释放
		Node* p = head_;
		while (p != nullptr)
		{
			head_ = head_->next_;
			delete p;
			p = head_;
		}
		head_ = nullptr;
	}
public:
	// 链表尾差法 O(n) head_：头结点 tail_：尾结点
	void InsertTail(int val)
	{
		Node* p = head_;
		while (p->next_ != nullptr)
		{
			p = p->next_;
		}
		p->next_ = new Node(val);
	}

	// 链表头插法 O（1）
	void InsertHead(int val)
	{
		Node* newNode = new Node(val);
		newNode->next_ = head_->next_;
		head_->next_ = newNode;
	}

	// 链表节点的删除
	void Remove(int val)
	{
		bool ifExit = Find(val);
		if (ifExit)
		{
			Node* p = head_;
			while (p->next_->val_ != val)
			{
				p = p->next_;
			}
			Node* tmp = p->next_;
			p->next_ = p->next_->next_;
			delete tmp;
		}
		return;
	}

	// 删除多个节点
	void RemoveAll(int val)
	{
		Node* p = head_;
		Node* q = head_->next_;
		while (q != nullptr)
		{
			if (q->val_ == val)
			{
				Node* tmp = q;
				q = q->next_;
				p->next_ = q;
				delete tmp;
			}
			else
			{
				p = q;
				q = q->next_;
			}
		}
	}

	// 搜索链表 O(n)
	bool Find(int val)
	{
		Node* p = head_->next_;
		while (p != nullptr)
		{
			if (p->val_ == val)
			{
				return true;
			}
			p = p->next_;
		}
		return false;
	}

	// 链表打印
	void Show()
	{
		Node* p = head_->next_;
		cout << "[ ";
		while (p != nullptr)
		{
			cout << p->val_ << "->";
			p = p->next_;
		}
		cout << "nullptr ]" << endl;
	}

private:
	Node* head_; // 链表的虚拟头结点（不存储数据 目的是统一对链表的操作)

};

int main()
{
	Clink link;
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		int val = rand() % 100;
		link.InsertHead(val);
	}
	link.Show();

	link.InsertTail(23);
	link.Show();
	link.InsertHead(23);
	link.Show();

	link.Remove(23);
	link.Show();
	link.InsertHead(23);
	link.Show();
	
	link.RemoveAll(23);
	link.Show();
}
