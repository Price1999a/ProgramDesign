/*
��ѡ����Ӧ��ջ�ṹ����ʵ��Բ�����Ƿ���Եļ������
*/

#include<iostream>
#include<stdio.h>
#define N 256
using namespace std;

struct Stack
{
	int top;
	int buffer[N];
};

void init(Stack &s)//��ʼ��
{
	s.top = -1;
}

bool push(Stack &s, int i)//��ջ
{
	if (s.top == N - 1)//ջ���
		return false;
	else
	{
		s.top++;
		s.buffer[s.top] = i;
		return true;
	}
}

bool pop(Stack &s, int &i)//��ջ
{
	if (s.top == -1)
		return false;
	else
	{
		i = s.buffer[s.top];
		s.top--;
		return true;
	}
}

int main()
{
	char c; 
	Stack st;
	bool b;
	int x;
	init(st);
	while ((c = getchar()) != '#')
	{
		if (c == '(')
			b = push(st, 1);
		else if (c == ')')
			b = pop(st, x);
		else
			;

		if (b == false)
		{
			cout << "�����" << endl;
			return 0;
		}
		else
			;
	}
	if (b == false || st.top != -1)
		cout << "�����" << endl;
	else
		cout << "���" << endl;

	system("pause");
	return 0;
}