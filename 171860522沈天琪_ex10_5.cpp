#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

char * YaSuo(char ch[])//压缩全英文字符串，传入的字符串为全英文字母的
{
	char temp[256] = { '\0' };//临时字符串，用于存储中间结果
	char ch_temp = ch[0];
	int s = 0, j = 0, i = 0;

	for (i = 0; ch[i - 1] != '\0'; i++)//还要保留最后一位上的/0，否则会输出烫烫。。。。
	{                                  //遍历字符串
		if (ch[i] == ch_temp)//若为重复字母
		{
			++s;
			continue;
		}
		else//若非，首先输出数字，之后输出字母
		{
			if (s >= 2)
			{
				/*temp[j] = '0' + s;
				j++;//指向下一个待写入字符的位置
				s = 0;*/    //bug代码，不能正确处理重复字母大于10的情况。
				/*for (; s > 0; s /= 10)
				{
				temp[j] = '0' + s;
				j++;//指向下一个待写入字符的位置
				}*/        //bug版本2
				if (s < 10)//小于10时，原方法开销小。
				{
					temp[j] = '0' + s;
					j++;//指向下一个待写入字符的位置
					s = 0;
				}
				else//来自10-2的代码，处理s>=10时的情形
				{
					char ch_temp1[11] = { '\0' };
					for (int i1 = 0; i1 < 11; i1++)//将其反序输入字符数组  注意：最外层循环已经应用了i
					{
						if (s > 0)//将所有多余位置为 \0 
						{
							ch_temp1[i1] = s % 10 + '0';
							s /= 10;
						}
						else
							ch_temp1[i1] = '\0';
					}
					//cout << ch_temp1 << endl;
					for (int i1 = 10; i1 >= 0; i1--)//反向读取，由于两次反向，这次就是正向
					{
						if (ch_temp1[i1] == '\0')
							;
						else
						{
							temp[j] = ch_temp1[i1];
							j++;//指向下一个待写入字符的位置
						}
					}
				}
			}
			else//若数字仅为1，不输出数字
				;

			temp[j] = ch_temp;//以下输出字母
			j++;
			ch_temp = ch[i];
			s = 1;
		}
	}

	for (int k = 0; k < i; k++)//将临时结果覆盖原结果，临时字符数组空间将被收回
		ch[k] = temp[k];
	return ch;
}

char * JieYaSuo(char ch[])//解压缩字符串，为YaSuo函数的逆操作
{
	char temp[256] = { '\0' };
	char ch_temp = ch[0];
	int i = 0, j = 0, s = 0;
	for (i = 0; ch[i - 1] != '\0'; i++)//遍历字符串
	{
		if (ch[i] <= '9'&&ch[i] >= '0')//若为数字，将数字转化为整形数存储
			s = 10 * s + ch[i] - '0';
		else if (ch[i] <= 'z'&&ch[i] >= 'A')
		{
			if (s == 0)//对单字母
			{
				temp[j] = ch[i];
				j++;
			}
			else//对（n）x类型
			{
				for (; s > 0; s--, j++)//重复输出
					temp[j] = ch[i];
			}
		}

	}
	for (int k = 0; k < 256; k++)//将临时结果覆盖原结果，临时字符数组空间将被收回
		ch[k] = temp[k];
	return ch;
}

int main()
{
	char ch[256] = { '\0' };
	cin >> ch;
	//cout << ch;

	cout << YaSuo(ch) << endl;
	cout << JieYaSuo(ch) << endl;

	//system("pause");
	return 0;
}