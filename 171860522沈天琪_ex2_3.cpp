#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int x = 0;

	while (x != EOF)
	{
		cout << "������һ�����ڵ�ĳһ�죺\nע�⣺666��ʾ�˳�����\n";
		cin >> x;

		switch (x)
		{
		case 0:cout << "Sunday\n"; break;
		case 1:cout << "Monday\n"; break;
		case 2:cout << "Tuesday\n"; break;
		case 3:cout << "Wednesday\n"; break;
		case 4:cout << "Thursday\n"; break;
		case 5:cout << "Friday\n"; break;
		case 6:cout << "Saturday\n"; break;
		case 666:x = EOF; cout << "��лʹ�ã�\n"; break;
		default:cout << "Error!\n"; break;
		}
	}

		
	system("pause");
	return 0;
}