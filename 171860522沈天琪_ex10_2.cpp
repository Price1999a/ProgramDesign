#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

bool HuiWen(unsigned int n)
{
	char ch[11];
	
	for (int i = 0; i < 11; i++)
	{
		if (n>0)
		{
			ch[i] = n % 10 + '0';
			n /= 10;
		}
		else
			ch[i] = '\0';
	}
	//cout << ch;
	//return true;
	char *pc1 = ch, *pc2 = ch;
	while ((*pc2) != '\0')//�һ����������\/�ߵ�����debug������
		++pc2;

	//cout << (void *)pc1 << endl << (void *)pc2;

	for (pc2--; pc1 < pc2;pc1++,pc2--)
	if (*pc1 == *pc2);
	else
		return false;

	return true;

}

int main()
{
	unsigned int n;
	cin >> n;
	if (HuiWen(n) == true)
		printf("�ǻ�����\n");
	else
		printf("���ǻ�����\n");

	//system("pause");
	return 0;
}
