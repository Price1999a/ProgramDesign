#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	FILE *fp_in = fopen("ex3_data.txt", "r");
	if (fp_in == NULL)
	{
		printf("fail to open\n");
		return -1;
	}
	int answer[100];
	for (int i = 0; i < 100; i++)
	{
		answer[i] = 0;
		int temp = 0;
		for (int j = 0; j < 5; j++)
		{
			fscanf(fp_in, "%d", &temp);
			answer[i] += temp;
		}
	}

	fclose(fp_in);

	int temp1 = 0;
	for (int i = 0; i < 100; i++)
	for (int j = 100 - 1; i < j; j--)
	{
		if (answer[j] < answer[j - 1])
		{
			temp1 = answer[j];
			answer[j] = answer[j - 1];
			answer[j - 1] = temp1;
		}
	}

	FILE *fp_out = fopen("result.txt", "w");
	if (fp_out == NULL)
	{
		printf("fail to open to write\n");
		return -1;
	}
	for (int i = 0; i < 100; i++)
	{
		fprintf(fp_out, "%d\n", answer[i]);
	}

	fclose(fp_out);

	/*for (int i = 0; i < 100; i++)
	{
		cout << answer[i] << endl;
	}*/

	system("pause");
	return 0;
}