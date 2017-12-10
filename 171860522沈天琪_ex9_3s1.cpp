#include"171860522ÉòÌìç÷_ex9_3h.h"

int Adjust(int a[])
{
	int times = 0;
	int temp[N];
	while (EndCheck(a) == false)
	{
		
		for (int i = 0; i < N; ++i)
		{
			temp[i] = 0;
			if (a[i] % 2 == 1)
				a[i]++;
			else;
			a[i] /= 2;
			temp[i] = a[i];
		}
		for (int i = 0; i < N; ++i)
		{
			a[(i+1)%N] = a[(i+1)%N] + temp[i];
		}
		times++;
	}
	return times;
}

int main()
{
	int a[10] = { 10, 2, 8, 22, 16, 4, 10, 6, 14, 20 };
	cout << Adjust(a) << " ";
	cout << a[0] << endl;

	//system("pause");
	return 0;
}