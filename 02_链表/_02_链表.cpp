#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// ������ڵ�����
struct Node
{
	int val_;
	Node* next_;

	Node(int data = 0) : val_(data), next_(nullptr) {}
};

// ���������ʵ��
class Clink
{
public:
	Clink()
	{
		// ��ʼ������ͷ���
		head_ = new Node();
	}
	~Clink()
	{
		// �ڵ���ͷ�
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
	// ����β� O(n) head_��ͷ��� tail_��β���
	void InsertTail(int val)
	{
		Node* p = head_;
		while (p->next_ != nullptr)
		{
			p = p->next_;
		}
		p->next_ = new Node(val);
	}

	// ����ͷ�巨 O��1��
	void InsertHead(int val)
	{
		Node* newNode = new Node(val);
		newNode->next_ = head_->next_;
		head_->next_ = newNode;
	}

	// ����ڵ��ɾ��
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

	// ɾ������ڵ�
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

	// �������� O(n)
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

	// �����ӡ
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
	Node* head_; // ���������ͷ��㣨���洢���� Ŀ����ͳһ������Ĳ���)

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
