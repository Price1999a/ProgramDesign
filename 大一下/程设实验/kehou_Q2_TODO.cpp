#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#�����С 
#define MAX_SIZE 1000

int cmp(int a, int b)
{
	if (a > b)
		return 1;
	else if (a == b)
		return 0;
	else if (a < b)
		return -1;
	// TODO
}

void sort(int *data, int n, int (*cmp)(int, int))
{
	int temp = 0;
	for (int i = 0; i < n; i++)
		for (int j = n - 1; i < j; j--)
		{
			if (cmp(data[j], data[j - 1]) < 0)
			{
				temp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = temp;
			}
		}
	// TODO: ����Ҫ������ʵ�ִ��� 
}


int main()
{
	//NOTE:�������������в��� 
	int data[MAX_SIZE], n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int m;
		puts("*****************");
		scanf("%d", &m);
		for (int j = 0; j < m; j++)
			scanf("%d", data + j);
		sort(data, m, cmp);
		puts("after sorting:");
		for (int j = 0; j < m; j++)
		{
			printf("%d ", data[j]);
		}
		puts("\n*****************");
	}
	return 0;	
}

// NOTE: ����ע��Ƭ���ǲ��Դ��룬�����޸ģ����޸ĺ����̲��Գ��ִ��� ����Ը� 
/*

int main()
{
	int data[MAX_SIZE] , n;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++)
	{
		int m;
		puts("*****************");
		scanf("%d",&m);
		for(int j = 0 ; j < m ; j++)
			scanf("%d",data+j); 
		sort(data, m, cmp);
		puts("after sorting:");
		for(int j = 0 ; j < m ; j++)
		{
			printf("%d ",data[j]);
		}
		puts("\n*****************");
	}
	
	return 0;	
}
*/

