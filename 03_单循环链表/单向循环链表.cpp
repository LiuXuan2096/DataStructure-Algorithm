#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct Node
{
	int val_;
	Node* next_;
	Node(int data = 0) : val_(data), next_(nullptr) {}
};

// 约瑟夫环问题
void Joseph(Node* head, int k, int m)
{
	Node* q = head;
	Node* p = head;

	// 让q指向尾结点，即p的前一个节点
	while (q->next_ != head)
	{
		q = q->next_;
	}

	// 从第k个人开始报数
	for (int i = 1; i < k; i++)
	{
		q = p;
		p = p->next_;
	}

	// 此时p指向第k个人
	for (; ; )
	{
		for (int i = 1; i < m; i++)
		{
			q = p;
			p = p->next_;
		}

		// 删除p指向的节点
		cout << p->val_ << " ";
		if (p == q)
		{
			delete p;
			break;
		}
		q->next_ = p->next_;
		delete p;
		p = q->next_;
	}
}

int main()
{
	Node* head = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);
	Node* n6 = new Node(6);
	Node* n7 = new Node(7);
	Node* n8 = new Node(8);

	head->next_ = n2;
	n2->next_ = n3;
	n3->next_ = n4;
	n4->next_ = n5;
	n5->next_ = n6;
	n6->next_ = n7;
	n7->next_ = n8;
	n8->next_ = head;

	Joseph(head, 1, 5);
}

# if 0
class CircleLink
{
public:
	CircleLink()
	{
		head_ = new Node();
		tail_ = head_;
		head_->next_ = head_;
	}
	~CircleLink()
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			head_->next_ = p->next_;
			delete p;
			p = head_->next_;
		}
		delete head_;
	}

public:
	// 尾差法 O（1）
	void InsertTail(int data)
	{
		Node* node = new Node(data);
		node->next_ = tail_->next_;
		tail_->next_ = node;
		tail_ = node;
	}

	// 头插法 O（1）
	void InsertHead(int data)
	{
		Node* node = new Node(data);
		node->next_ = head_->next_;
		head_->next_ = node;
		if (node->next_ == head_)
		{
			tail_ = node;
		}
	}

	// 删除节点
	void Remove(int data)
	{
		Node* q = head_;
		Node* p = head_->next_;
		while (p != head_)
		{
			if (p->val_ == data)
			{
				q->next_ = p->next_;
				delete p;
				if (q->next_ == head_)
				{
					tail_ = q;
				}
				return;
			}
			p = p->next_;
			q = q->next_;
		}
	}

	// 查询
	bool Find(int data) const
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			if (p->val_ == data)
			{
				return true;
			}
			p = p->next_;
		}
		return false;
	}

	// 打印链表
	void Show() const
	{
		Node* p = head_->next_;
		while (p != head_)
		{
			cout << p->val_ << " ";
			p = p->next_;
		}
		cout << endl;
	}

private:
	struct Node 
	{
		int val_;
		Node* next_;

		Node(int data = 0) : val_(data), next_(nullptr) {}
	};

	Node* head_; // 指向头结点
	Node* tail_; // 指向尾结点
};

int main()
{
	CircleLink clink;
	srand(time(NULL));

	clink.InsertHead(100);

	for (int i = 0; i < 10; i++)
	{
		clink.InsertTail(rand() % 100);
	}

	clink.Show();
	clink.InsertTail(200);
	clink.Show();
	clink.Remove(200);
	clink.Show();
}
#endif