#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	FILE *fp_in = fopen("sample.txt", "r");
	if (fp_in == NULL)
	{
		printf("failed to open the file");
		return -1;
	}
	char temp[50] = { 0 }, str[3000] = { 0 };
	cin >> temp;
	int temp1 = strlen(temp);
	while (!feof(fp_in))
	{
		memset(str, 0, sizeof(str));//Çå³ý»º´æ
		fgets(str, sizeof(str), fp_in);
		
		//cout << temp1 << endl;
		for (int i = 0, j = 0; i < 3000; i++)
		{
			if (temp[j] == str[i]||abs(temp[j]-str[i])==26)
				j++;
			else
				j = 0;
			if (j == temp1 - 1)
			{
				cout << "True" << endl;
				system("pause");
				return 0;
			}
		}
	}
	cout << "False" << endl;
	system("pause");
	return 0;
}