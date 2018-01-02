/*
设计C/C++程序，首先用链表建立两个集合（从键盘输入集合的元素），然后计算这两个集合的交集、并集与差集，最后输出计算结果。
*/

#include<iostream>
#include<cstdio>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node *Creat()//结束以-1为标记
{
	Node * head = NULL, *tail = NULL, *p = NULL;
	int x = 0;
	cin >> x;
	while (x != -1)
	{
		p = new Node;
		p->data = x;
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
		cin >> x;
	}
	return head;
}

int Print(Node * head)
{
	Node * p = head;
	if (p == NULL)
	{
		cout << "NULL" << endl;
		return 0;
	}
	else
		;
	while (p->next != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data << endl;
	return 0;
}

void Delete_(Node *&head)
{
	Node * p = head;
	while (p->next != NULL)
	{
		head = p->next;
		delete p;
		p = head;
	}
	head = p->next;
	delete p;
}

Node * IntersectionCreat(Node * head1, Node * head2)//交集
{
	Node * p1 = head1, *p2 = head2, *head3 = NULL, *tail3 = NULL, *p3 = NULL;
	while (p1->next != NULL)
	{
		while (p2->next != NULL)
		{
			if (p1->data == p2->data)
			{
				p3 = new Node;
				p3->data = p1->data;
				p3->next = NULL;
				if (head3 == NULL)
					head3 = p3;
				else
					tail3->next = p3;
				tail3 = p3;
			}
			else
				;
			p2 = p2->next;
		}
		if (p1->data == p2->data)
		{
			p3 = new Node;
			p3->data = p1->data;
			p3->next = NULL;
			if (head3 == NULL)
				head3 = p3;
			else
				tail3->next = p3;
			tail3 = p3;
		}
		else
			;
		p1 = p1->next;
		p2 = head2;
	}
	while (p2->next != NULL)
	{
		if (p1->data == p2->data)
		{
			p3 = new Node;
			p3->data = p1->data;
			p3->next = NULL;
			if (head3 == NULL)
				head3 = p3;
			else
				tail3->next = p3;
			tail3 = p3;
		}
		else
			;
		p2 = p2->next;
	}
	if (p1->data == p2->data)
	{
		p3 = new Node;
		p3->data = p1->data;
		p3->next = NULL;
		if (head3 == NULL)
			head3 = p3;
		else
			tail3->next = p3;
		tail3 = p3;
	}
	else
		;

	return head3;
}

Node * UnionCreate(Node * head1, Node * head2)//并集
{
	Node * p1 = head1, *p2 = head2, *head4 = NULL, *tail4 = NULL, *p4 = NULL;
	int i = 0;
	for (p1 = head1; p1;p1=p1->next)
	{
		p4 = new Node;
		p4->data = p1->data;
		p4->next = NULL;
		if (head4 == NULL)
			head4 = p4;
		else
			tail4->next = p4;
		tail4 = p4;
	}
	for (p2 = head2; p2; p2 = p2->next)
	{
		for (p1 = head1; p1; p1 = p1->next)
		{
			if (p1->data == p2->data)
				i++;
			else
				;
		}
		if (i == 0)
		{
			p4 = new Node;
			p4->data = p2->data;
			p4->next = NULL;
			if (head4 == NULL)
				head4 = p4;
			else
				tail4->next = p4;
			tail4 = p4;
		}
		else
			i = 0;
	}
	return head4;
}

Node * SubtractionCreate(Node * head1, Node * head2)//差集（前减后）
{
	Node * head4 = IntersectionCreat(head1, head2);
	Node * p1 = head1, *p4 = head4, *head5 = NULL, *tail5 = NULL, *p5 = NULL;
	int i = 0;
	for (p1 = head1; p1; p1 = p1->next)
	{
		for (p4 = head4; p4; p4 = p4->next)
		{
			if (p4->data == p1->data)
				i++;
			else
				;
		}
		if (i == 0)
		{
			p5 = new Node;
			p5->data = p1->data;
			p5->next = NULL;
			if (head5 == NULL)
				head5 = p5;
			else
				tail5->next = p5;
			tail5 = p5;
		}
		else
			i = 0;
	}
	return head5;
}

int main()
{
	Node * p1 = Creat(), *p2 = Creat();
	//Print(p1);
	//Print(p2);
	Print(IntersectionCreat(p1, p2));
	Print(UnionCreate(p1, p2));
	Print(SubtractionCreate(p1, p2));
	
	Delete_(p1);
	Delete_(p2);

	//system("pause");
	return 0;
}
