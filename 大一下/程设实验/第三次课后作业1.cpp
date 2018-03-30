#include <iostream>
#include <cstdio>
using namespace std;

void wine_cpl(double wine[][14],int x)
{
	for (int j = 1; j < 14; j++)
	{
		double sum_temp = 0, i_temp = 0, ave_temp = 0;
		for (int i = 0; i < 178; i++)
		{
			if (wine[i][0] != x)
				continue;
			if (wine[i][j] == -1)
				continue;
			sum_temp += wine[i][j];
			i_temp++;
		}
		ave_temp = sum_temp / i_temp;
		for (int i = 0; i < 178; i++)
		{
			if (wine[i][0] != x)
				continue;
			if (wine[i][j] == -1)
				wine[i][j] = ave_temp;
		}
	}
}

void wine_norm(double wine[][14], int x)
{
	for (int j = 1; j < 14; j++)
	{
		double max_temp = 0, min_temp = 1000;
		for (int i = 0; i < 178; i++)
		{
			if (wine[i][0] != x)
				continue;
			//if (wine[i][j] == -1)
				//continue;
			if (wine[i][j] < min_temp)
				min_temp = wine[i][j];
			if (wine[i][j] > max_temp)
				max_temp = wine[i][j];
		}
		
		for (int i = 0; i < 178; i++)
		{
			if (wine[i][0] != x)
				continue;
			//if (wine[i][j] == -1)
				//wine[i][j] = ave_temp;
			if (max_temp == min_temp)
				wine[i][j] = 1;
			else
				wine[i][j] = (wine[i][j] - min_temp) / (max_temp - min_temp);
		}
	}
}

int main()
{
	FILE *fp_in = fopen("wine.txt", "r");
	if (fp_in == NULL)
	{
		printf("fail to open\n");
		return -1;
	}
	double wine[178][14],temp_in;
	char ch_temp;
	for (int i = 0; i < 178; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			
			if (fscanf(fp_in, "%lf,", &temp_in))
				wine[i][j] = temp_in;
			else
			{
				fscanf(fp_in, "%c,", &ch_temp);
				wine[i][j] = -1;
			}
			
		}
	}
	
	wine_cpl(wine, 1);
	wine_cpl(wine, 2);
	wine_cpl(wine, 3);

	FILE *fp_out_cpl = fopen("wine_cpl.dat", "wb");
	fwrite(wine[0], sizeof(double), 178 * 14, fp_out_cpl);
	fclose(fp_out_cpl);

	wine_norm(wine, 1);
	wine_norm(wine, 2);
	wine_norm(wine, 3);
	
	FILE *fp_out_norm = fopen("wine_norm.csv", "w");
	for (int i = 0; i < 178; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			fprintf(fp_out_norm, "%.1lf", wine[i][j]);//%.1lf  一位小数
			if (j == 13)
				fprintf(fp_out_norm, "\n");
			else
				fprintf(fp_out_norm, ",");
		}
	}
	fclose(fp_out_norm);

	cout << sizeof(double) << endl;
	for (int i = 0; i < 178; i++)
	{
		for (int j = 0; j < 14; j++)
			cout << wine[i][j] << "  ";
		cout << endl;
	}


	system("pause");
	return 0;
}