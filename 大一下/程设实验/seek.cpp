
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
		printf("���ļ�ʧ��!\n");
		exit(-1);
	}
	Student st;
	/*
	int fseek(FILE *stream, long offset, int fromwhere);���������ļ�ָ��stream��λ�á�
	���ִ�гɹ���stream��ָ����fromwhereΪ��׼��ƫ��offset��ָ��ƫ���������ֽڵ�λ�ã���������0�����ִ��ʧ��(����offset�����ļ������С)���򲻸ı�streamָ���λ�ã���������һ����0ֵ��
	fseek������lseek�������ƣ���lseek���ص���һ��off_t��ֵ����fseek���ص���һ�����͡�
	*/ 
	if(fseek(fp, sizeof(Student), SEEK_SET)==0) //ָ��ڶ���ѧ��
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

