#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int FindReplaceStr(char str[], const char find_str[], const char replace_str[])//将子串用另一个字符串进行替代
{
	int n = 0, lfi, lre;
	lfi = strlen(find_str);//计算子串与替代串的长度
	lre = strlen(replace_str);
	char *pstr = str;
	for (; (*pstr) != '\0'; pstr++)//遍历源字符串
	{
		int i;
		for (i = 0; i < lfi; i++)
			if (pstr[i] == find_str[i])//寻找子串
				;
			else
				break;
		if (i != lfi)
			continue;//未找到则继续循环
		else//若找到，则将子串从首字符开始调整长度与替代串相同
		{
			n++;
			if (lfi >= lre)
				for (char *temp = pstr; (*temp) != '\0'; temp++)//缩小长度，无溢出风险
					temp[lre] = temp[lfi];
			else//增加长度，有潜在溢出风险
			{
				int temp = strlen(str);
				for (int i = 0; i <= temp; i++)
					pstr[temp - i + lre - lfi] = pstr[temp - i];//从操作顺序上，可以认为是向右缩进
			}
			for (int j = 0; j < lre; j++)//长度对齐后，简单的复制操作
			{
				*pstr = replace_str[j];
				pstr++;//此处会导致pstr被多加，line39修正
			}
			pstr--;
		}
		/*int temp = strlen(str);
		char * newstr = new char[temp + 1];
		for (int i = 0; i <= temp; i++)
		newstr[i] = str[i];
		str = newstr;*///失败的尝试。
	}

	return n;
}

int main()
{
	char str[256] = "aa1aaa2aaa3aaa4aaa5aaa6aaa7aaa8aaa9aaa0aaa", find_str[256] = "aaa", replace_str[256] = "bbbb";//"bbbb"会导致str在不确定长度时溢出，所以此时使用一个固定长度，以空间换安全。
	cin >> str >> find_str >> replace_str;
	cout << FindReplaceStr(str, find_str, replace_str) << endl;
	cout << str << endl;
	//cout << (void *)str << endl << (void *)find_str << endl << (void *)replace_str << endl;
	//cout << endl << sizeof(str) << endl << sizeof(find_str) << endl << sizeof(replace_str) << endl;

	//system("pause");
	return 0;
}