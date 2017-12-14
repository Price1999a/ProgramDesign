#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
	char c;
	int n = 0;
	while ((c = getchar()) != '#')
	{
		if (c == '(')//不支持中文全角括号！
			n++;
		else if (c == ')')
			n--;
		else
			;

		if (n < 0)//中间判断是否有过多的'）'
			break;
		else
			;
	}
	if (n == 0)
		printf("配对\n");
	else
		printf("不配对\n");

	//system("pause");
	return 0;
}
