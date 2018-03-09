#define PROGRAM 1

#if PROGRAM==1
//Student Scores  ASCII file

//Test Data
/*
001 ���� 4 70 80 85 90
002 ���� 5 85 60 75 90 80
E
*/
//003 ���� 3 85 90 86
//004 ���� 5 88 90 98 78 90
//E

#include <cstdio>
#include <cstdlib>
//using namespace std;

int main()
{
	FILE *fp=fopen("scores.txt", "w");  //ASCII FILE
	if (fp==NULL)
	{
		printf("���ļ�ʧ��!\n");
		exit(-1);
	}
	char id[11], name[9];
	int num_of_courses, score;
	printf("������ѧ��, ����, ѡ���������ſγɼ�(��ѧ��Ϊ\"E\"����):\n");
	scanf("%10s", id);
	while(id[0]!='E')
	{
		scanf("%8s", name);
		scanf("%d", &num_of_courses);
		fprintf(fp, "%s %s %d ", id, name, num_of_courses);
		for(int i=0; i<num_of_courses; i++)
		{
			scanf("%d", &score);
			fprintf(fp, "%d ", score);
		}
		fputc('\n', fp);
		scanf("%10s", id);
	}
	fclose(fp);
	return 0;
}

#endif

#if PROGRAM==2
//Students.dat Binary File
//Test Data
//001 ���� 0 1980 5 3 �Ͼ� 5
//002 ���� 1 1985 12 4 �Ϻ� 3
//E


#include <cstdio>
#include <cstdlib>
//using namespace std;
//��ƽ���� 
int main()
{
	FILE *fp=fopen("scores.txt", "r");  //ASCII FILE
	if (fp==NULL)
	{
		printf("���ļ�ʧ��!\n");
		exit(-1);
	}
	char id[11], name[9];
	int num_of_courses, score, total;
	fscanf(fp, "%10s", id);
	while(!feof(fp))
	{
		fscanf(fp, "%8s", name);
		fscanf(fp, "%d", &num_of_courses);
		total=0;
		for(int i=0; i<num_of_courses; i++)
		{
			fscanf(fp, "%d", &score);
			total+=score;
		}
		printf("%s, %s, %d\n", id, name, total/num_of_courses);
		fscanf(fp, "%10s", id);
	}
	fclose(fp);
	return 0;
}
#endif
