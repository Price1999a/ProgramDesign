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
	printf("                            菜单                            \n");
	printf("       1.打印旅游城市价格表                                   \n");
	printf("       2.创建旅游路线                                         \n");
	printf("       3.将旅游路线中的某个城市替换为其他的城市                  \n");
	printf("       4.在旅游城市中的两个城市之间，插入新的城市                \n");
	printf("       5.删除旅游线路的中的某个城市                             \n");
	printf("       6.调整旅游城市价格表中某个旅游城市价格                    \n");
	printf("       *.退出程序                                             \n");
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
		printf("文件打开失败，读取预设数据。/n");
		strcpy(citylist[0].cityname, "北京");
		citylist[0].price = 3000;
		strcpy(citylist[1].cityname, "南京");
		citylist[1].price = 2500;
		strcpy(citylist[2].cityname, "扬州");
		citylist[2].price = 2400;
		strcpy(citylist[3].cityname, "无锡");
		citylist[3].price = 2000;
		strcpy(citylist[4].cityname, "苏州");
		citylist[4].price = 2200;
		strcpy(citylist[5].cityname, "拉萨");
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
	cout << "请输入城市，以空格分割，换行结束：";
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
	if (head == 0);//假如链表还没有被创建
	else
	{
		Node * p = head;
		cout << "旅游线路现为：";
		while (p->next != NULL)
		{
			cout << p->pcity->cityname << "-";
			p = p->next;
		}
		cout << p->pcity->cityname << endl;
		
		p = head;
		int sum = 0;
		cout << "总价格：";
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
	cout << "请输入需要调整价格的城市：";
	cin >> cityname;
	for (; i < 20; i++)
	{
		if (strcmp(cityname, citylist[i].cityname) == 0)
			break;
	}
	cout << citylist[i].cityname << "原来的价格为" << citylist[i].price << "，请输入调整后的价格：";
	cin >> newprice;
	citylist[i].price = newprice;
}

void changecity(Node * head)
{
	char oldcityname[12] = {}, newcityname[12] = {};
	cout << "请输入被替换的城市：";
	cin >> oldcityname;
	cout << "请输入替换城市：";
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
	cout << "请输入两个在路线中连续的城市：";
	cin >> oldcityname1 >> oldcityname2;
	cout << "请输入需要插入的城市：";
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
	cout << "请输入需要删除的城市：";
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