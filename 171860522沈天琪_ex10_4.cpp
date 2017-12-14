#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int FindReplaceStr(char str[], const char find_str[], const char replace_str[])
{
	int n = 0, lfi, lre;
	lfi = strlen(find_str);
	lre = strlen(replace_str);
	char *pstr = str;
	for (; (*pstr) != '\0'; pstr++)
	{
		int i;
		for (i = 0; i < lfi; i++)
			if (pstr[i] == find_str[i])
				;
			else
				break;
		if (i != lfi)
			continue;
		else
		{
			n++;
			if (lfi >= lre)
				for (char *temp = pstr; (*temp) != '\0'; temp++)
					temp[lre] = temp[lfi];
			else
			{
				int temp = strlen(str);
				for (int i = 0; i <= temp; i++)
					pstr[temp - i + lre - lfi] = pstr[temp - i];
			}
			for (int j = 0; j < lre; j++)
			{
				*pstr = replace_str[j];
				pstr++;
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