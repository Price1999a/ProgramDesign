#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int FindReplaceStr(char str[], const char find_str[], const char replace_str[])//���Ӵ�����һ���ַ����������
{
	int n = 0, lfi, lre;
	lfi = strlen(find_str);//�����Ӵ���������ĳ���
	lre = strlen(replace_str);
	char *pstr = str;
	for (; (*pstr) != '\0'; pstr++)//����Դ�ַ���
	{
		int i;
		for (i = 0; i < lfi; i++)
			if (pstr[i] == find_str[i])//Ѱ���Ӵ�
				;
			else
				break;
		if (i != lfi)
			continue;//δ�ҵ������ѭ��
		else//���ҵ������Ӵ������ַ���ʼ�����������������ͬ
		{
			n++;
			if (lfi >= lre)
				for (char *temp = pstr; (*temp) != '\0'; temp++)//��С���ȣ����������
					temp[lre] = temp[lfi];
			else//���ӳ��ȣ���Ǳ���������
			{
				int temp = strlen(str);
				for (int i = 0; i <= temp; i++)
					pstr[temp - i + lre - lfi] = pstr[temp - i];//�Ӳ���˳���ϣ�������Ϊ����������
			}
			for (int j = 0; j < lre; j++)//���ȶ���󣬼򵥵ĸ��Ʋ���
			{
				*pstr = replace_str[j];
				pstr++;//�˴��ᵼ��pstr����ӣ�line39����
			}
			pstr--;
		}
		/*int temp = strlen(str);
		char * newstr = new char[temp + 1];
		for (int i = 0; i <= temp; i++)
		newstr[i] = str[i];
		str = newstr;*///ʧ�ܵĳ��ԡ�
	}

	return n;
}

int main()
{
	char str[256] = "aa1aaa2aaa3aaa4aaa5aaa6aaa7aaa8aaa9aaa0aaa", find_str[256] = "aaa", replace_str[256] = "bbbb";//"bbbb"�ᵼ��str�ڲ�ȷ������ʱ��������Դ�ʱʹ��һ���̶����ȣ��Կռ任��ȫ��
	cin >> str >> find_str >> replace_str;
	cout << FindReplaceStr(str, find_str, replace_str) << endl;
	cout << str << endl;
	//cout << (void *)str << endl << (void *)find_str << endl << (void *)replace_str << endl;
	//cout << endl << sizeof(str) << endl << sizeof(find_str) << endl << sizeof(replace_str) << endl;

	//system("pause");
	return 0;
}