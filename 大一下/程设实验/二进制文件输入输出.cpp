#define PROGRAM 2 

#if PROGRAM==1
//Student Scores  Binary file  Input


#include <cstdio>
#include <cstdlib>
//using namespace std;
/*
001 ���� 0 1994 6 6 �Ͼ� 2 
002 ���� 1 1995 8 8 ���� 3 
E
*/ 
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
	FILE *fp=fopen("students.dat", "wb");  //Binary File
	if(fp==NULL)
	{
		printf("���ļ�ʧ��!\n");
		exit(-1);
	}
	Student st;
	int tsex; //�����Ա� 0: MALE, 1: FEMALE
	int tmajor; //����רҵ 
	printf("������ѧ��, ����, �Ա�, ��������, �����غ�רҵ(��ѧ��Ϊ'E'����):\n");
	scanf("%10s", st.id);  
	while(st.id[0]!='E')
	{
		scanf("%8s", st.name);
		scanf("%d", &tsex);
		switch(tsex)
		{
		case 0: st.sex=MALE; break;
		case 1: st.sex=FEMALE; break;
		default: printf("Sex Confusing!\n"); exit(-1);
		}
		scanf("%d %d %d", &st.birth_date.year, &st.birth_date.month, &st.birth_date.day);
		scanf("%39s", st.birth_place);
		scanf("%d", &tmajor);
		switch(tmajor)
		{
		case 0: st.major=MATHEMATICS; break;
		case 1: st.major=PHYSICS; break;
		case 2: st.major=CHEMISTRY; break;
		case 3: st.major=COMPUTER; break;
		case 4: st.major=GEOGRAPHY; break;
		case 5: st.major=ASTRONOMY; break;
		case 6: st.major=ENGLISH; break;
		case 7: st.major=CHINESE; break;
		case 8: st.major=PHILOSOPHY; break;
		default: printf("Major not Found!\n"); exit(-1);
		}
		/*
		size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream);
		����ֵ������ʵ��д������ݿ���Ŀ
		��1��buffer����һ��ָ�룬��fwrite��˵����Ҫ��ȡ���ݵĵ�ַ��
		��2��size��Ҫд�����ݵĵ��ֽ�����
		��3��count:Ҫ����д��size�ֽڵ�������ĸ�����
		��4��stream:Ŀ���ļ�ָ�룻
		��5������ʵ��д������������count��
		*/ 
		fwrite(&st, sizeof(Student), 1, fp);
		scanf("%10s", st.id);
	}
	fclose(fp);
	return 0;
}

#endif


#if PROGRAM==2
//Students.dat Binary File  Input
//Display all Record
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
	FILE *fp=fopen("students.dat", "rb");  //Binary File
	if(fp==NULL)
	{
		printf("���ļ�ʧ��!\n");
		exit(-1);
	}
	Student st;
	int count=0;

	printf("ѧ��\t����\t�Ա�\t��������\t������\tרҵ\n");
	fread(&st, sizeof(Student), 1, fp);
	while(!feof(fp))
	{
		printf("%s\t%s\t", st.id, st.name);
		switch(st.sex)
		{
		case MALE: printf("MALE\t"); break;
		case FEMALE: printf("FEMALE\t"); break;
		//default: printf("Sex Confusing!\n"); exit(-1);
		}
		printf("%d�� %d�� %d��\t", st.birth_date.year, st.birth_date.month, st.birth_date.day);
		printf("%s\t", st.birth_place);
		switch(st.major)
		{
		case MATHEMATICS: printf("MATHEMATICS"); break;
		case PHYSICS: printf("PHYSICS"); break;
		case CHEMISTRY: printf("CHEMISTRY"); break;
		case COMPUTER: printf("COMPUTER"); break;
		case GEOGRAPHY: printf("GEOGRAPHY"); break;
		case ASTRONOMY: printf("ASTRONOMY"); break;
		case ENGLISH: printf("ENGLISH"); break;
		case CHINESE: printf("CHINESE"); break;
		case PHILOSOPHY: printf("PHILOSOPHY"); break;
		//default: printf("Major not Found!\n"); exit(-1);
		}
		printf("\n");
		fread(&st, sizeof(Student), 1, fp);
	}
	fclose(fp);
	return 0;
}
#endif

