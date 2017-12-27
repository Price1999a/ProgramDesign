/*
（选做）应用栈结构重新实现圆括号是否配对的检查任务。
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

void init(Stack &s)//初始化
{
	s.top = -1;
}

bool push(Stack &s, int i)//入栈
{
	if (s.top == N - 1)//栈溢出
		return false;
	else
	{
		s.top++;
		s.buffer[s.top] = i;
		return true;
	}
}

bool pop(Stack &s, int &i)//出栈
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
			cout << "不配对" << endl;
			return 0;
		}
		else
			;
	}
	if (b == false || st.top != -1)
		cout << "不配对" << endl;
	else
		cout << "配对" << endl;

	system("pause");
	return 0;
}