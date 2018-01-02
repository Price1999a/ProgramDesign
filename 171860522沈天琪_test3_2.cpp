#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

struct Node
{
	int data;
	Node * next;
};

Node * NodeCreate()
{
	Node *p = NULL, *head = NULL, *tail = NULL;
	int x;
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

int NodeMid(Node *head)
{
	int len = 0;
	//int data_mid = 0;
	for (Node *p = head; p; p = p->next)
		len++;
	//cout << len << endl;
	Node *p = head;
	for (int i = 1; i <= len / 2; i++)
		p = p->next;
	//data_mid = p->data;

	return p->data;
}

int main()
{
	Node * node1 = NodeCreate();
	cout << NodeMid(node1) << endl;
	Delete_(node1);

	system("pause");
	return 0;
}