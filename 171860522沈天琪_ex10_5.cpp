#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

char * YaSuo(char ch[])
{
	char temp[256] = { '\0' };
	char ch_temp = ch[0];
	int s = 0, j = 0, i = 0;

	for (i = 0; ch[i - 1] != '\0'; i++)//还要保留最后一位上的/0，否则会输出烫烫。。。。
	{
		if (ch[i] == ch_temp)
		{
			++s;
			continue;
		}
		else
		{
			if (s >= 2)
			{
				temp[j] = '0' + s;
				j++;
				s = 0;
			}
			else
				;

			temp[j] = ch_temp;
			j++;
			ch_temp = ch[i];
			s = 1;
		}
	}

	for (int k = 0; k < i; k++)
		ch[k] = temp[k];
	return ch;
}

char * JieYaSuo(char ch[])
{
	char temp[256] = { '\0' };
	char ch_temp = ch[0];
	int i = 0, j = 0, s = 0;
	for (i = 0; ch[i - 1] != '\0'; i++)
	{
		if (ch[i] <= '9'&&ch[i] > '0')
			s = 10 * s + ch[i] - '0';
		else if (ch[i] <= 'z'&&ch[i] >= 'A')
		{
			if (s == 0)
			{
				temp[j] = ch[i];
				j++;
			}
			else
			{
				for (; s > 0; s--, j++)
					temp[j] = ch[i];
			}
		}

	}
	for (int k = 0; k < 256; k++)
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