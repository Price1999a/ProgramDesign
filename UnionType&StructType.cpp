#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

enum Sex { male, female };//枚举类型无法直接输入输出，需要间接输入输出，male对应0，female对应1，输入时引用
struct Student       //另一个变量输入0或1，再进行赋值操作；而输出则使用switch语句输出对应字符串。
{
	Sex sex;
	int no;
	double gpa;
	char group;
};

void print(Student a)//函数运用时形参使用结构类型定义。传参使用结构变量的名字。
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
	cout << "输出函数如下：\n";
	print(stu_a);
	print(stu_b);
	stu_b = stu_a;
	cout << stu_b.sex << endl << stu_b.no << endl << stu_b.gpa << endl << stu_b.group << endl;
	cout << "EOF" << endl;
	cout << sizeof(stu_a);
	cout << "\n结构类型结束，下方联合类型。" << endl;

	union A {
		int i;
		char c;
		double d;
	};
	A a;//联合类型，一次只能使用其中的一个数据类别。

	a.i = 12;
	cout << a.c << endl;//在a.i=12.时，a.c就是将整形12对应的二进制码翻译为字符类型。
	system("pause");
	return 0;
}