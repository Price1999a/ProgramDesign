#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX_SIZE 500
#define MAX_LEN 101 
// TEST = 1 是整型测试，TEST = 2是字符串测试 
#define TEST 1

int int_cmp(const void *a, const void *b);int str_cmp(const void *a, const void *b);void sort(void *base, size_t num, size_t size, int(*comparator) (const void *, const void *));

// ********************************请在下方实现你的代码 ************* 
void swap(char *p1, char *p2, int size)
{
	int i = 0;
	char temp = 0;
	for (i = 0; i < size; i++)
	{
		temp = *(p1 + i);
		*(p1 + i) = *(p2 + i);
		*(p2 + i) = temp;
	}
}






// ********************************main供你自己测试使用*************** 
#if TEST==1

int main()
{
	int data[MAX_SIZE], n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		puts("*****************");
		cin >> m;
		for (int j = 0; j < m; j++)
			cin >> data[j];
		sort(data, m, sizeof(data[0]), int_cmp);
		puts("after sorting:");
		for (int j = 0; j < m; j++)
		{
			cout << data[j] << " ";
		}
		puts("\n*****************");
	}

	return 0;
}
#endif

#if TEST==2

int main()
{
	char str[500][MAX_LEN];
	int n;
	cin >> n;
	cout << "*********************" << endl;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		for (int j = 0; j < m; j++)
		{
			cin >> str[j];
		}
		sort(str, m, sizeof(str[0]), str_cmp);
		cout << "*************" << endl;
		for (int j = 0; j < m; j++)
		{
			cout << str[j] << endl;
		}
		cout << "*************" << endl;
	}
	return 0;
}
#endif 
// NOTE: 以下注释片段是整型数据排序的测试代码，请勿修改，若修改后，助教测试出现错误， 后果自负 
/*
#if TEST==1

int main()
{
int data[MAX_SIZE] , n;
cin>>n;
for(int i = 0 ; i < n ; i++)
{
int m;
puts("*****************");
cin>>m;
for(int j = 0 ; j < m ; j++)
cin>>data[j];
sort(data, m, sizeof(data[0]), int_cmp);
puts("after sorting:");
for(int j = 0 ; j < m ; j++)
{
cout<<data[j]<<" ";
}
puts("\n*****************");
}

return 0;
}
#endif

#if TEST==2

int main()
{
char str[500][MAX_LEN];
int n;
cin>>n;
for(int i = 0 ; i < n ; i++)
{
int m;
cin>>m;
for(int j = 0 ; j < m ; j++)
{
cin>>str[j];
}
sort(str, m, sizeof(str[0]), str_cmp);
cout<<"*************"<<endl;
for(int j = 0 ; j < m ; j++)
{
cout<<str[j]<<endl;
}
cout<<"*************"<<endl;
}
return 0;
}
#endif
*/

int int_cmp(const void * a, const void * b)
{
	if ((*(int *)a) - (*(int *)b) < 0)
		return 0;
	else
		return -1;
}

int str_cmp(const void * a, const void * b)
{
	return strcmp((char *)(*(int *)a), (char *)(*(int *)b));
}

void sort(void * base, size_t num, size_t size, int(*comparator)(const void *, const void *))
{
	for (int i = 0; i<num - 1; i++)
		    {
		        for (int j = 0; j<num - i - 1; j++)
			        {
					if ((*comparator)(((char *)base + (j*size)), ((char *)base + (j + 1)*size)) < 0)
					{
						swap((char *)base + (j*size), (char *)base + (j + 1)*size, size);
						/*char  temp = 0;
						for (int k = 0; k < size; k++)
						{
							temp = (char) *((char*)base + j * size + k);
							*((char*)base + j * size + k) = (char)*((char*)base + (j + 1) * size + k);
							*((char*)base + (j + 1) * size + k) = temp;
						}
						*/
					}
			        }
		    }

}
