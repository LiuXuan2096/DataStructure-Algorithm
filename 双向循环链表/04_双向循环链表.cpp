#include <iostream>
using namespace std;

// ����˫����Ľڵ�����
struct Node
{
	Node(int data = 0)
		: val_(data)
		, pre_(nullptr)
		, next_(nullptr)
	{}
	int val_;
	Node* pre_;
	Node* next_;
};

// ˫��ѭ������
class DoubleCircleLink
{
public:
	DoubleCircleLink()
	{
		dummyHead_ = new Node();
		dummyHead_->next_ = dummyHead_;
		dummyHead_->pre_ = dummyHead_;
	}
	~DoubleCircleLink()
	{
		Node* p = dummyHead_->next_;
		while (p != dummyHead_)
		{
			dummyHead_->next_ = p->next_;
			p->next_->pre_ = dummyHead_;
			delete p;
			p = dummyHead_->next_;
		}
		delete dummyHead_;
		dummyHead_ = nullptr;
	}
public:
	// ͷ�巨O(1)
	void InsertHead(int data)
	{
		Node* node = new Node(data);
		node->pre_ = dummyHead_;
		node->next_ = dummyHead_->next_;
		dummyHead_->next_ = node;
		node->next_->pre_ = node;
	}

	// β�巨O(1)
	void InsertTail(int data)
	{
		Node* p = new Node(data);
		p->pre_ = dummyHead_->pre_;
		p->next_ = dummyHead_;
		dummyHead_->pre_ = p;
		p->pre_->next_ = p;

	}

	// �ڵ�ɾ��
	void Remove(int data)
	{
		Node* p = dummyHead_->next_;
		while (p != dummyHead_)
		{
			if (p->val_ == data)
			{
				p->pre_->next_ = p->next_;
				p->next_->pre_ = p->pre_;
				delete p;
				return;
			}
			p = p->next_;
		}
		return;
	}

	// �ڵ�����
	bool Find(int data)
	{
		Node* p = dummyHead_->next_;
		while (p != dummyHead_)
		{
			if (p->val_ == data)
			{
				return true;
			}
			p = p->next_;
		}
		return false;
	}

	// ����ڵ����
	void Show()
	{
		Node* p = dummyHead_->next_;
		cout << "[";
		while (p != dummyHead_)
		{
			cout << p->val_ << " ";
			p = p->next_;
		}
		cout << "]" << endl;
	}

private:
	Node* dummyHead_; // ����ͷ��� 
};

int main()
{
	DoubleCircleLink dlink;

	dlink.InsertHead(100);

	dlink.InsertTail(20);
	dlink.InsertTail(12);
	dlink.InsertTail(78);
	dlink.InsertTail(32);
	dlink.InsertTail(7);
	dlink.InsertTail(90);
	dlink.Show();

	dlink.InsertHead(200);
	dlink.Show();

	dlink.Remove(200);
	dlink.Show();

	dlink.Remove(90);
	dlink.Show();

	dlink.Remove(78);
	dlink.Show();
}