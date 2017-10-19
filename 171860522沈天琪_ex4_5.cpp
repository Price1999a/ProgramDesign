#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int c = 0, y = 0, iYear = 0, iMonth = 0, iDay = 1, iWeek = 0, n = 0, i = 0;
	printf("请输入年月：\n注意：年数必须大于1600，月数应在1至12之间。\n");
	cin >> iYear >> iMonth;
	if (iMonth == 1)
	{
		iYear--;
		iMonth = 13;
	}
	else if (iMonth == 2)
	{
		iYear--;
		iMonth = 14;
	}
	else
		;
	c = iYear / 100;
	y = iYear % 100;

	iWeek = ((c / 4) - 2 * c + y + (y / 4) + (26 * (iMonth + 1) / 10) + iDay - 1) % 7;
	
	iDay -= iWeek;
	iYear++;
	if (iMonth == 13 || iMonth == 14)
		iMonth -= 12;
	else;
	printf("%d年%d月\n日\t一\t二\t三\t四\t五\t六\t\n", iYear, iMonth);
	                                                     
	if (iMonth == 3 || iMonth == 5 || iMonth == 7 || iMonth == 8 || iMonth == 10 || iMonth == 12 || iMonth == 13)
		n = 31;
	else if (iMonth == 4 || iMonth == 6 || iMonth == 9 || iMonth == 11)
		n = 30;
	else if (iYear % 4 != 0 || (iYear % 100 == 0 && iYear % 400 != 0))    //四年一闰；百年不闰,四百年再闰；
		n = 28;
	else
		n = 29;

	while (iDay <= n)
	{
		i++;
		if (i % 7 == 0 && i > 0)
			printf("%d\t\n",iDay);
		else
		{
			if (iDay <= 0)
				printf("\t");
			else
				printf("%d\t", iDay);
		}
		
		iDay++;
	}
	printf("\n");
	system("pause");
	return 0;
}