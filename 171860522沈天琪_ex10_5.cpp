#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

char * YaSuo(char ch[])//ѹ��ȫӢ���ַ�����������ַ���ΪȫӢ����ĸ��
{
	char temp[256] = { '\0' };//��ʱ�ַ��������ڴ洢�м���
	char ch_temp = ch[0];
	int s = 0, j = 0, i = 0;

	for (i = 0; ch[i - 1] != '\0'; i++)//��Ҫ�������һλ�ϵ�/0�������������̡�������
	{                                  //�����ַ���
		if (ch[i] == ch_temp)//��Ϊ�ظ���ĸ
		{
			++s;
			continue;
		}
		else//���ǣ�����������֣�֮�������ĸ
		{
			if (s >= 2)
			{
				/*temp[j] = '0' + s;
				j++;//ָ����һ����д���ַ���λ��
				s = 0;*/    //bug���룬������ȷ�����ظ���ĸ����10�������
				/*for (; s > 0; s /= 10)
				{
				temp[j] = '0' + s;
				j++;//ָ����һ����д���ַ���λ��
				}*/        //bug�汾2
				if (s < 10)//С��10ʱ��ԭ��������С��
				{
					temp[j] = '0' + s;
					j++;//ָ����һ����д���ַ���λ��
					s = 0;
				}
				else//����10-2�Ĵ��룬����s>=10ʱ������
				{
					char ch_temp1[11] = { '\0' };
					for (int i1 = 0; i1 < 11; i1++)//���䷴�������ַ�����  ע�⣺�����ѭ���Ѿ�Ӧ����i
					{
						if (s > 0)//�����ж���λ��Ϊ \0 
						{
							ch_temp1[i1] = s % 10 + '0';
							s /= 10;
						}
						else
							ch_temp1[i1] = '\0';
					}
					//cout << ch_temp1 << endl;
					for (int i1 = 10; i1 >= 0; i1--)//�����ȡ���������η�����ξ�������
					{
						if (ch_temp1[i1] == '\0')
							;
						else
						{
							temp[j] = ch_temp1[i1];
							j++;//ָ����һ����д���ַ���λ��
						}
					}
				}
			}
			else//�����ֽ�Ϊ1�����������
				;

			temp[j] = ch_temp;//���������ĸ
			j++;
			ch_temp = ch[i];
			s = 1;
		}
	}

	for (int k = 0; k < i; k++)//����ʱ�������ԭ�������ʱ�ַ�����ռ佫���ջ�
		ch[k] = temp[k];
	return ch;
}

char * JieYaSuo(char ch[])//��ѹ���ַ�����ΪYaSuo�����������
{
	char temp[256] = { '\0' };
	char ch_temp = ch[0];
	int i = 0, j = 0, s = 0;
	for (i = 0; ch[i - 1] != '\0'; i++)//�����ַ���
	{
		if (ch[i] <= '9'&&ch[i] >= '0')//��Ϊ���֣�������ת��Ϊ�������洢
			s = 10 * s + ch[i] - '0';
		else if (ch[i] <= 'z'&&ch[i] >= 'A')
		{
			if (s == 0)//�Ե���ĸ
			{
				temp[j] = ch[i];
				j++;
			}
			else//�ԣ�n��x����
			{
				for (; s > 0; s--, j++)//�ظ����
					temp[j] = ch[i];
			}
		}

	}
	for (int k = 0; k < 256; k++)//����ʱ�������ԭ�������ʱ�ַ�����ռ佫���ջ�
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