#include<iostream>
using namespace std;

int main()
{
	int d1 = 0, d2 = 0, d3 = 1;
	while (d3 != EOF)
	{

		printf("����������������\nע�⣺0��ʾ���������\n");
		cin >> d1 >> d2;
		printf("�����������\nע�⣺0��ʾ���������\n");
		cin >> d3;
		if (d3 != 0&&d2 != 0&&d1 != 0)
		for (int i = d1; i <= d2; ++i)
		{
			if (i%d3 != 0)
				printf("���ܱ���������Ϊ��%d\n", i);
			else
				;
		}
		else
			d3 = EOF;
	}
		printf("��ӭʹ�ã��ټ���\n");
	
	system("pause");
	return 0;
}
