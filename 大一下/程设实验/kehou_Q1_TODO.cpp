#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define sort(a,n)\
{\
	int temp = 0;\
	for (int i = 0; i < n; i++)\
		for (int j = n - 1; i < j; j--)\
		{\
			if (a[j] < a[j - 1])\
			{\
				temp = a[j];\
				a[j] = a[j - 1];\
				a[j - 1] = temp;\
			}\
		}\
}

//#�����С 
#define MAX_SIZE 1000

void BubbleSort(int a[])
{
	int temp = 0;
	
}

int main()
{
	int data[MAX_SIZE], n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int m;
		puts("*****************");
		scanf("%d", &m);
		for (int j = 0; j < m; j++)
			scanf("%d", data + j);
		sort(data, m);
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
		sort(data, m);
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

