#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main()
{
	char c;
	int n = 0;
	while ((c = getchar()) != '#')
	{
		if (c == '(')//��֧������ȫ�����ţ�
			n++;
		else if (c == ')')
			n--;
		else
			;

		if (n < 0)//�м��ж��Ƿ��й����'��'
			break;
		else
			;
	}
	if (n == 0)
		printf("���\n");
	else
		printf("�����\n");

	//system("pause");
	return 0;
}
