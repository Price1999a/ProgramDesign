#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int temp = 0, n1 = 0, n2 = 0, n3 = 0, n4 = 0;
	while (temp != EOF)
	{
		printf("������һ��������Ȼ��:\nע�⣺����λ������Ȼ��ʱ����ܽϳ���������������������\n");
		cin >> temp;
		if (temp == 0)
			temp = EOF;
		else
		{
			for (int n1 = 0; n1 <= sqrt(temp); ++n1)
			{
				for (int n2 = 0; n2 <= sqrt(temp); ++n2)
				{
					for (int n3 = 0; n3 <= sqrt(temp); ++n3){
						for (int n4 = 0; n4 <= sqrt(temp); ++n4)
						if (temp == n1 * n1 + n2 * n2 + n3 * n3 + n4 * n4)
							cout << temp <<"="<<n1<<"*"<<n1 <<"+"<<n2<<"*"<< n2 <<"+"<<n3<<"*"<< n3 <<"+"<<n4<<"*"<< n4 << endl;
					}
				}
			}
		}
		
	}
	
	system("pause");
	return 0;
}
