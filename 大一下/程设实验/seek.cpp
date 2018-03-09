
#define PROGRAM 1

#if PROGRAM==1
//Students.dat Binary File  Seek

#include <cstdio>
#include <cstdlib>
//using namespace std;

enum Sex {MALE, FEMALE};

struct Date
{
	int year;
	int month;
	int day;
};

enum Major {MATHEMATICS, PHYSICS, CHEMISTRY, COMPUTER, GEOGRAPHY, ASTRONOMY, ENGLISH, CHINESE, PHILOSOPHY};

struct Student
{
	char id[11];
	char name[9];
	Sex sex;
	Date birth_date;
	char birth_place[40];
	Major major;
};

int main()
{
	FILE *fp=fopen("students.dat", "r+b");  //Binary File
	if(fp==NULL)
	{
		printf("打开文件失败!\n");
		exit(-1);
	}
	Student st;
	/*
	int fseek(FILE *stream, long offset, int fromwhere);函数设置文件指针stream的位置。
	如果执行成功，stream将指向以fromwhere为基准，偏移offset（指针偏移量）个字节的位置，函数返回0。如果执行失败(比如offset超过文件自身大小)，则不改变stream指向的位置，函数返回一个非0值。
	fseek函数和lseek函数类似，但lseek返回的是一个off_t数值，而fseek返回的是一个整型。
	*/ 
	if(fseek(fp, sizeof(Student), SEEK_SET)==0) //指向第二个学生
	{
		fread(&st, sizeof(Student), 1, fp);
		st.major=CHINESE;
		fseek(fp, -(long)sizeof(Student), SEEK_CUR);
		fwrite(&st, sizeof(st), 1, fp);
	}

	fclose(fp);
	return 0;
}
#endif

