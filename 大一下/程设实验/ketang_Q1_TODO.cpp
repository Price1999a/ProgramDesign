#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <iostream>
//using namespace std;

//�ַ�������
#define MAX_LEN 101 
// �����С 
#define SIZE 201


int cmp_(const char * str1, const char * str2)
{
	if (strlen(str1) < strlen(str2))
		return -1;
	else if (strlen(str1) > strlen(str2))
		return 1;
	else
		return strcmp(str1, str2);
}

void sort(char (*strings)[MAX_LEN], int n)
{
	char temp[1][MAX_LEN];
	for (int i = 0; i < n;i++)
		for (int j = n - 1; i < j; j--)
		{
			if (cmp_(strings[j], strings[j - 1]) < 0)
			{
				strcpy(temp[0],strings[j]);
				strcpy(strings[j], strings[j - 1]);
				strcpy(strings[j - 1], temp[0]);
				//strings[j] = strings[j - 1];
				//strings[j - 1] = temp;
			}
		}
		
		// NOTE: ����Ҫ������ʵ�ִ��� 
}




int main()
{
	char str[SIZE][MAX_LEN];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int m;
		scanf("%d", &m);
		for (int j = 0; j < m; j++)
		{
			scanf("%s", str[j]);
		}
		sort(str, m);
		puts("*************");
		for (int j = 0; j < m; j++)
		{
			printf("%s\n", str[j]);
		}
		puts("*************");
	}
	return 0;
}


// NOTE: ����ע��Ƭ���ǲ��Դ��룬�����޸ģ����޸ĺ����̲��Գ��ִ��� ����Ը� 
/*

int main()
{
	char str[SIZE][MAX_LEN];
	int n;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++)
	{
		int m;
		scanf("%d",&m);
		for(int j = 0 ; j < m ; j++)
		{
			scanf("%s", str[j]);
		}
		sort(str, m);
		puts("*************");
		for(int j = 0 ; j < m ; j++)
		{
			printf("%s\n",str[j]);
		}
		puts("*************");
	}
	return 0;	
}

*/

