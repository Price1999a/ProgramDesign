#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

char * DeleteSubstring(char ch[], const char * ch_z)//在字符串中寻找子串并删除
{
	int n1 = strlen(ch_z);//判断子串长度，用于偏移量计算
	//cout << n1;

	for (char * pch = ch; (*pch) != '\0'; pch++)//遍历字符串
	{
		int i;
		for (i = 0; i < n1; i++)//判断是否指针指向子串头
			if (pch[i] != ch_z[i])
				break;
			else
				;
		if (i == n1)//如果是，将后方字符串复制到前方，进行覆盖
			for (char *temp = pch; (*temp) != '\0'; temp++)
				temp[0] = temp[n1];
		else;
	}

	return ch;//返回字符串首地址，方便引用该函数的函数直接进行简便的逻辑计算
}

int main()
{
	char ch[256] = "aaa1aaa2aaa345aaa67ag89aaa", ch_z[256] = "aaa";
	cin >> ch >> ch_z;
	cout << DeleteSubstring(ch, ch_z);

	//system("pause");
	return 0;
}
