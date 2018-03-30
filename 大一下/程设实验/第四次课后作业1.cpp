#include <iostream>
#include <cstdio>

using namespace std;

struct CITY
{
	char cityname[12];
	int price;
};

struct Node
{
	CITY * pcity;
	Node * next;
};

CITY citylist[20];

void printmune();
void printcitylist(CITY citylist[20]);
void setcitylist(CITY citylist[20]);
Node * createline();
void printline(Node * head);
void changeprice();
void changecity(Node * head);
void insertcity(Node * head);
Node * delcity(Node * head);

int main()
{
	//CITY citylist[6];
	char c = 0;
	Node * p = 0;
	setcitylist(citylist);
	//printmune();
	while (c != '*')
	{
		printmune();
		cin >> c;
		if (c == '1')
			printcitylist(citylist);
		else if (c == '2')
		{
			p = createline();
			printline(p);
		}
		else if (c == '3')
		{
			changecity(p);
			printline(p);
		}
		else if (c == '4')
		{
			insertcity(p);
			printline(p);
		}
		else if (c == '5')
		{
			p = delcity(p);
			printline(p);
		}
		else if (c == '6')
		{
			changeprice();
			printcitylist(citylist);
			printline(p);
		}
		else;
	}
	//setcitylist(citylist);
	//printcitylist(citylist);

	system("pause");
	return 0;
}

void printmune()
{
	printf("************************************************************\n");
	printf("                            �˵�                            \n");
	printf("       1.��ӡ���γ��м۸��                                   \n");
	printf("       2.��������·��                                         \n");
	printf("       3.������·���е�ĳ�������滻Ϊ�����ĳ���                  \n");
	printf("       4.�����γ����е���������֮�䣬�����µĳ���                \n");
	printf("       5.ɾ��������·���е�ĳ������                             \n");
	printf("       6.�������γ��м۸����ĳ�����γ��м۸�                    \n");
	printf("       *.�˳�����                                             \n");
	printf("************************************************************\n");
}

void printcitylist(CITY citylist[20])
{
	for (int i = 0; i < 20; i++)
	{
		if (citylist[i].price == 0)
			break;
		cout << i << '\t' << citylist[i].cityname << '\t' << citylist[i].price << '\n';
	}
}

void setcitylist(CITY citylist[20])
{
	
	FILE * fp = fopen("pricelist.txt", "r");
	if (fp == NULL)
	{
		printf("�ļ���ʧ�ܣ���ȡԤ�����ݡ�/n");
		strcpy(citylist[0].cityname, "����");
		citylist[0].price = 3000;
		strcpy(citylist[1].cityname, "�Ͼ�");
		citylist[1].price = 2500;
		strcpy(citylist[2].cityname, "����");
		citylist[2].price = 2400;
		strcpy(citylist[3].cityname, "����");
		citylist[3].price = 2000;
		strcpy(citylist[4].cityname, "����");
		citylist[4].price = 2200;
		strcpy(citylist[5].cityname, "����");
		citylist[5].price = 3500;//*/
		//return -1;
	}
	while (!feof(fp))
	{
		int i = 0;
		fscanf(fp,"%d\t", &i);
		fscanf(fp, "%s\t", &citylist[i].cityname);
		fscanf(fp, "%d", &citylist[i].price);
	}
}

Node * createline()
{
	Node * head = NULL, *tail = NULL, *p = NULL;
	char cityname[12] = {}, temp = 0;
	int n = 0;
	temp = getchar();
	//temp = getchar();
	temp = 0;
	cout << "��������У��Կո�ָ���н�����";
	while (1)
	{
		temp = getchar();
		if (temp == ' ' || temp == '\n')
			break;
		cityname[n] = temp;
		n++;
	}
	while (temp != '\n')
	{
		p = new Node;
		int i = 0;
		for (; i < 20; i++)
		{
			if (strcmp(cityname, citylist[i].cityname) == 0)
				p->pcity = &citylist[i];
		}
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
		n = 0;
		while (1)
		{
			temp = getchar();
			if (temp == ' ' || temp == '\n')
				break;
			cityname[n] = temp;
			n++;
		}
	}
	p = new Node;
	int i = 0;
	for (; i < 20; i++)
	{
		if (strcmp(cityname, citylist[i].cityname) == 0)
			p->pcity = &citylist[i];
	}
	p->next = NULL;
	//if (head == NULL)
		//head = p;
	//else
		tail->next = p;
	tail = p;
	return head;
}

void printline(Node * head)
{
	if (head == 0);//��������û�б�����
	else
	{
		Node * p = head;
		cout << "������·��Ϊ��";
		while (p->next != NULL)
		{
			cout << p->pcity->cityname << "-";
			p = p->next;
		}
		cout << p->pcity->cityname << endl;
		
		p = head;
		int sum = 0;
		cout << "�ܼ۸�";
		while (p->next != NULL)
		{
			sum += p->pcity->price;
			p = p->next;
		}
		sum += p->pcity->price;
		cout << sum << endl;
	}
}

void changeprice()
{
	char cityname[12] = {};
	int newprice = 0, i = 0;
	cout << "��������Ҫ�����۸�ĳ��У�";
	cin >> cityname;
	for (; i < 20; i++)
	{
		if (strcmp(cityname, citylist[i].cityname) == 0)
			break;
	}
	cout << citylist[i].cityname << "ԭ���ļ۸�Ϊ" << citylist[i].price << "�������������ļ۸�";
	cin >> newprice;
	citylist[i].price = newprice;
}

void changecity(Node * head)
{
	char oldcityname[12] = {}, newcityname[12] = {};
	cout << "�����뱻�滻�ĳ��У�";
	cin >> oldcityname;
	cout << "�������滻���У�";
	cin >> newcityname;
	Node * p = head;
	while (p)
	{
		if (strcmp(p->pcity->cityname, oldcityname) == 0)
		{
			int i = 0;
			for (; i < 20; i++)
			{
				if (strcmp(newcityname, citylist[i].cityname) == 0)
					p->pcity = &citylist[i];
			}
		}
		p = p->next;
	}
}

void insertcity(Node * head)
{
	char oldcityname1[12] = {}, oldcityname2[12] = {}, newcityname[12] = {};
	cout << "������������·���������ĳ��У�";
	cin >> oldcityname1 >> oldcityname2;
	cout << "��������Ҫ����ĳ��У�";
	cin >> newcityname;
	Node * p = head;
	while (p)
	{
		if (strcmp(p->pcity->cityname, oldcityname1) == 0)
		{
			int i = 0;
			for (; i < 20; i++)
			{
				if (strcmp(newcityname, citylist[i].cityname) == 0)
				{
					Node * q = new Node;
					q->pcity = &citylist[i];
					q->next = p->next;
					p->next = q;
				}
			}
		}
		p = p->next;
	}
}

Node * delcity(Node * head)
{
	char cityname[12] = {};
	cout << "��������Ҫɾ���ĳ��У�";
	cin >> cityname;
	Node *p = head;
	if (strcmp(cityname, head->pcity->cityname) == 0)
	{
		p = p->next;
		delete head;
		return p;
	}
	while (p)
	{
		if (strcmp(p->next->pcity->cityname, cityname) == 0)
		{
			Node * q = p;
			p = p->next;
			q->next = p->next;
			delete p;
			return head;
		}
		p = p->next;
	}
}