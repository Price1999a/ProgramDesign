#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int c = 0;
	
	while (c != EOF)
	{
		printf("�˵���\n0:�ַ���1\n1:�ַ���2\n2:������1+1�����Ƕ��١�\n3:���������ĵĳ���\n");
		cin >> c;

		switch (c)
		{
		case 0: printf(">.<\n\n\n"); break;
		case 1: printf(">.<\n>.<\n��Ȼ�����ַ���2��\n\n\n"); break;
		case 2: printf("�⻹Ҫ�Ҹ����㣿\n�Ǻǡ�\n\n\n"); break;
		case 3: c = EOF; break;
		default: printf("��⵽���ش���\n...................\n�����Զ���ը��\n...........\n�뼴��������ȷֵ��\n\n\n"); break;
		}
	}
	printf("����Ϊ�һ����������ߣ�\n");
	system("pause");
	printf("�ٵ�㣿\n");
	system("pause");
	printf("�����Ե㡣\n");
	system("pause");
	printf("���ͣ���Ż���57�£�\n");
	system("pause");
	printf("���ͣ���Ż���56�£�\n");
	system("pause");
	printf("���ͣ���Ż���55�£�\n");
	system("pause");
	printf("�ټ���\n");
	system("pause");
	printf("ƭ��ġ�\n");
	system("pause");
	printf("���ͣ���Ż���52�£�\n");
	system("pause");
	printf("�ټ���\n");
	system("pause");
	printf("�������ġ�\n");
	system("pause");
	return 0;
}
