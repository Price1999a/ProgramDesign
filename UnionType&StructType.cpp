#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

enum Sex { male, female };//ö�������޷�ֱ�������������Ҫ������������male��Ӧ0��female��Ӧ1������ʱ����
struct Student       //��һ����������0��1���ٽ��и�ֵ�������������ʹ��switch��������Ӧ�ַ�����
{
	Sex sex;
	int no;
	double gpa;
	char group;
};

void print(Student a)//��������ʱ�β�ʹ�ýṹ���Ͷ��塣����ʹ�ýṹ���������֡�
{
	switch (a.sex)
	{
	case 0:cout << "male" << endl; break;
	case 1:cout << "female" << endl; break;
	default:;
	}
	cout << a.no << endl << a.gpa << endl << a.group << endl;
}

int main()
{

	Student stu_a = { female }, stu_b = { male,2,3.96,'b' };
	cout << stu_b.sex << endl << stu_b.no << endl << stu_b.gpa << endl << stu_b.group << endl;
	cin >> stu_a.no >> stu_a.gpa >> stu_a.group;
	cout << stu_a.sex << endl << stu_a.no << endl << stu_a.gpa << endl << stu_a.group << endl;
	cout << "����������£�\n";
	print(stu_a);
	print(stu_b);
	stu_b = stu_a;
	cout << stu_b.sex << endl << stu_b.no << endl << stu_b.gpa << endl << stu_b.group << endl;
	cout << "EOF" << endl;
	cout << sizeof(stu_a);
	cout << "\n�ṹ���ͽ������·��������͡�" << endl;

	union A {
		int i;
		char c;
		double d;
	};
	A a;//�������ͣ�һ��ֻ��ʹ�����е�һ���������

	a.i = 12;
	cout << a.c << endl;//��a.i=12.ʱ��a.c���ǽ�����12��Ӧ�Ķ������뷭��Ϊ�ַ����͡�
	system("pause");
	return 0;
}