#include"171860522ÉעÌלחק_ex9_3h.h"

bool EndCheck(int a[])
{
	for (int i = 0; i < N - 1; ++i)
	{
		if (a[i] != a[i + 1])
			return false;
		else;
	}
	return true;
}