#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;

int str_times(char str1[], char str2[])
{
	int i = 0, j = 0;
	int times = 0;
	int strlen2 = strlen(str2);
	for (; str1[i] != '\0'&&i < 20;/*����i++������ͻ����ҵ�һ���Ӵ���ͬʱ���һ��*/)
	{
		for (j = 0; j < strlen2;j++)
		if (str1[i] == str2[j])
			i++;
		else
		{
			i++;
			times--;
			break;
		}
		times++;
	}
	return times;
}

int main()
{
	char str1[20] = {}, str2[20] = {};
	cin >> str1;
	cin >> str2;
	cout << str_times(str1, str2) << endl;

	system("pause");
	return 0;
}