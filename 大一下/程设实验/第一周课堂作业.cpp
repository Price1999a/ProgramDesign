#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

struct Zidian {
	char word[20];
	int a[26];
};

struct Miyu {
	char word[20];
	int a[26];
};

bool compare(Zidian * p1, Miyu * p2)//����ָ��
{
	for (int i = 0; i < 26; i++)
	{
		if (p1->a[i] == p2->a[i])
			;
		else
			return false;
	}
	return true;
}

int main()//�����񲢲��á�������
{
	Zidian * a[100];//�ֵ�
	Miyu * b[100];//����
	char word[20] = {};
	Zidian * p;
	Miyu * p2;
	int nz = 0, nm = 0;
	gets_s(word);
	while (strcmp(word, "XXXXXX") != 0)//����XXXXXX֮ǰ��������ֵ�
	{
		p = new Zidian;
		strcpy(p->word, word);
		a[nz] = p;
		nz++;

		for (int i = 0; i < 20; i++)//��word�����Ա��´�ʹ��
			word[i] = 0;

		for (int i = 0; i < 26; i++)//��ʼ������
			p->a[i] = 0;

		int temp = 0;
		while (p->word[temp] != 0)//������������
		{
			p->a[p->word[temp] - 97]++;
			temp++;
		}
		gets_s(word);
	}
	for (int i = 0; i < 20; i++)//��word�����Ա��´�ʹ��
		word[i] = 0;
	{
		Zidian * temp = 0;
		for (int i = 0; i < nz; i++)
			for (int j = nz - 1; i < j; j--)
			{
				if (strcmp(a[j]->word,a[j-1]->word)<0)
				{
					temp = a[j];
					a[j] = a[j - 1];
					a[j - 1] = temp;
				}
			}
	}
	gets_s(word);
	while (strcmp(word, "XXXXXX") != 0)//����XXXXXX֮ǰ��������ֵ�
	{
		p2 = new Miyu;
		strcpy(p2->word, word);
		b[nm] = p2;
		nm++;

		for (int i = 0; i < 20; i++)//��word�����Ա��´�ʹ��
			word[i] = 0;

		for (int i = 0; i < 26; i++)//��ʼ������
			p2->a[i] = 0;

		int temp = 0;
		while (p2->word[temp] != 0)//������������
		{
			p2->a[p2->word[temp] - 97]++;
			temp++;
		}
		gets_s(word);
	}//�ֵ䡢����������ϡ�

	bool flag = false;
	for(int i = 0;i<nm;i++)
	{
		for (int j = 0; j < nz; j++)
		{
			if (compare(a[j], b[i]))
			{
				cout << a[j]->word << endl;
				flag = true;
			}
		}
		if (flag == false)
			cout << "NOT A VALID WORD" << endl;
		cout << "******" << endl;
		flag = false;
	}

	system("pause");
	return 0;
}