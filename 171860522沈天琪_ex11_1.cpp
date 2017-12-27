/*
设计C/C++程序，对一个N个节点的单向链表中的一个int型数据成员求和（假设和非0，用非递归或递归函数实现求和功能均可。
除 main 函数外，需要实现链表的建立、输出、撤销和求和四个函数）。
*/

#define N 5
#include<iostream>
#include<cstdio>

using namespace std;
struct Node
{
	int data;
	Node *next;
};

Node *Creat()
{
	Node * head = NULL, *tail = NULL, *p = NULL;
	for (int i = 0; i < N; i++)
	{
		p = new Node;
		cin >> p->data;
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
	}
	return head;
}

int Sum(Node * head)
{
	Node * p = head;
	int s = 0;
	while (p->next != NULL)
	{
		s += p->data;
		p = p->next;
	}
	s += p->data;
	return s;
}

int Print(Node * head)
{
	Node * p = head;
	if(p==NULL)
	{
	cout<<"NULL"<<endl;
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

int main()
{
	Node * p = Creat();
	//Print(p);
	cout << Sum(p) << endl;
	Delete_(p);

	//system("pause");
	return 0;
}
