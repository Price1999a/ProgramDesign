#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	double a, b, c, delta;

	cout << "���������뷽��ʽ������" << endl;
	cin >> a >> b >> c;
	delta = b * b - 4 * a * c;
	printf("delta = %.2f \n", delta);
	system("pause");
	return 0;
}