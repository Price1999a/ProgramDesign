#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	FILE *fp_in = fopen("sample.txt", "r+");
	if (fp_in == NULL)
	{
		printf("failed to open the file");
		return -1;
	}
	int a = 0;
	char str[100] = { 0 };
	cin >> a >> str;
	//cout << sizeof(str) << endl;
	fseek(fp_in, a - 1, 0);
	fwrite(str, sizeof(char), strlen(str), fp_in);
	fclose(fp_in);

	system("pause");
	return 0;
}