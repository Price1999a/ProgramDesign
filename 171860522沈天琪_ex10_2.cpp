#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

bool HuiWen(unsigned int n)//判断一个unsigned int 是否为回文数
{
	char ch[11];//unsigned int最大为十位
	
	for (int i = 0; i < 11; i++)//将其反序输入字符数组
	{
		if (n>0)//将所有多余位置为 \0 
		{
			ch[i] = n % 10 + '0';
			n /= 10;
		}
		else
			ch[i] = '\0';
	}
	//cout << ch;
	//return true;
	char *pc1 = ch, *pc2 = ch;//产生两个指针，一个指向第一个字符，一个指向最后一个字符
	while ((*pc2) != '\0')//我会告诉你这里\/颠倒让我debug半天吗？
		++pc2;

	//cout << (void *)pc1 << endl << (void *)pc2;

	for (pc2--; pc1 < pc2;pc1++,pc2--)//第一个pc2--将pc2从\0指向最后一个字符
	if (*pc1 == *pc2);
	else//一旦发现不同，立刻返回false
		return false;

	return true;

}

int main()
{
	unsigned int n;
	cin >> n;
	if (HuiWen(n) == true)
		printf("是回文数\n");
	else
		printf("不是回文数\n");

	//system("pause");
	return 0;
}
