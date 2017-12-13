#include <iostream>
#include <cmath>
#include <cstdio>
#include <string.h>
using namespace std;

int main()//C程序，字符串处理 输入两个字符串，输出两个字符串从尾部开始相同的子字符串。
{
	char a[100], b[100];//例：sdfnbj sbnbj   ===>nbj
	scanf("%s\n%s", a, b);

	int a1 = strlen(a);
	int b1 = strlen(b);
	int i, j;
	int m, t;
	m = 0; t = 0;

	if (a[a1 - 1] != b[b1 - 1]) { printf("null"); }

	else if (a1 <= b1)
	{
		j = 0;
		for (i = a1 - 1; i >= 0; i--)
		{
			if (a[i] == b[b1 - 1 - j]) { m++; }
			j++;
		}
		for (i = a1 - m; i<a1; i++)
			printf("%c", a[i]);
	}


	else if (a1>b1)
	{
		i = 0;
		for (j = b1 - 1; j >= 0; j--)
		{
			if (a[a1 - 1 - i] == b[j]) { t++; }
			i++;
		}
		for (j = b1 - t; j<b1; j++)
			printf("%c", b[j]);
	}
	system("pause");
	return 0;
}
