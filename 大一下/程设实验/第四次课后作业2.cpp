#include <iostream>
#include <cstdio>
#include <cstring>
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

void printmune();

class Citylist
{
	friend class Route;
private:
	CITY citylist[20];
public:
	void setcitylist();
	void printcitylist();
	void changeprice();
	int citycount()
	{
		int n = 0;
		for (; n < 20; n++)
			if (citylist[n].price == 0)
				break;
		return n;
	}
	Citylist()
	{
		for (int i = 0; i < 20; i++)
			citylist[i].price = 0;
	}
	~Citylist() {}
};

class Route
{	
	//friend class Citylist;
	private:
		void printline();
		void saveroute();
	protected:
		Node * head;
	public:
		//Node * head;
		Citylist cityl;
		Route()
		{
			head = NULL; 
			cityl.setcitylist();
		}
		Route(const Route& a);
		void createline();
		void changecity();
		void insertcity();
		void delcity();
		void print() { printline(); }
		~Route()
		{
			while (head)
			{
				Node * ptemp = head;
				head = head->next;
				delete ptemp;
			}
		}
		bool check()
		{
			if (head == NULL)
				return false;
			else
				return true;
		}
		void save() { saveroute(); }
		int nodecount()
		{
			int n = 0;
			Node * p = head;
			while (p)
			{
				p = p->next;
				n++;
			}
			return n;
		}
		void readfile();
};

class VipRoute :public Route
{
	private:
		void printline();
		void saveroute();
	public:
		VipRoute(const Route&) :Route() { Route::~Route(); };
		VipRoute()
		{
			head = NULL;
			cityl.setcitylist();
		}
		~VipRoute()
		{
			while (head)
			{
				Node * ptemp = head;
				head = head->next;
				delete ptemp;
			}
		}
		void print() { printline(); }
		void save() { saveroute(); }
};

void Citylist::printcitylist()
{
	for (int i = 0; i < 20; i++)
	{
		if (citylist[i].price == 0)
			break;
		cout << i << '\t' << citylist[i].cityname << '\t' << citylist[i].price << '\n';
	}
}

void Citylist::setcitylist()
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
		fscanf(fp, "%d\t", &i);
		fscanf(fp, "%s\t", &citylist[i].cityname);
		fscanf(fp, "%d", &citylist[i].price);
	}
	fclose(fp);
}

void Citylist::changeprice()
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

void Route::createline()
{
	head = NULL;
	Node *tail = NULL, *p = NULL;
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
			if (strcmp(cityname, cityl.citylist[i].cityname) == 0)
				p->pcity = &cityl.citylist[i];
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
		if (strcmp(cityname, cityl.citylist[i].cityname) == 0)
			p->pcity = &cityl.citylist[i];
	}
	p->next = NULL;
	//if (head == NULL)
	//head = p;
	//else
	tail->next = p;
	tail = p;
	//return head;

	//printline();
}

void Route::printline()
{
	if (head == 0);//��������û�б�����
	else
	{
		Node * p = this->head;
		printf("������·��Ϊ��");//���ش��󣡣�����
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

void Route::changecity()
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
				if (strcmp(newcityname, cityl.citylist[i].cityname) == 0)
					p->pcity = &cityl.citylist[i];
			}
		}
		p = p->next;
	}

	//printline();
}

void Route::insertcity()
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
				if (strcmp(newcityname, cityl.citylist[i].cityname) == 0)
				{
					Node * q = new Node;
					q->pcity = &cityl.citylist[i];
					q->next = p->next;
					p->next = q;
				}
			}
		}
		p = p->next;
	}

	//printline();
}

void Route::delcity()
{
	char cityname[12] = {};
	cout << "��������Ҫɾ���ĳ��У�";
	cin >> cityname;
	Node * p = this->head;
	if (strcmp(cityname, head->pcity->cityname) == 0)
	{
		head = p->next;
		delete p;
		p = NULL;
	}
	while (p != NULL)
	{
		if (strcmp(p->next->pcity->cityname, cityname) == 0)
		{
			Node * q = p;
			p = p->next;
			q->next = p->next;
			delete p;
			p = NULL;
			break;
			//return head;
		}
		p = p->next;
	}

	//printline();
}

Route::Route(const Route& a)
{
	head = NULL;
	Node *tail = NULL, *p = NULL, *ptemp = a.head;
	char cityname[12] = {}, temp = 0;
	//int n = 0;
	strcpy(cityname, ptemp->pcity->cityname);
	/*temp = getchar();
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
	}//*/
	while (ptemp->next)
	{
		p = new Node;
		int i = 0;
		for (; i < 20; i++)
		{
			if (strcmp(cityname, cityl.citylist[i].cityname) == 0)
				p->pcity = &cityl.citylist[i];
		}
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
		//n = 0;
		ptemp = ptemp->next;
		strcpy(cityname, ptemp->pcity->cityname);
	}
	p = new Node;
	int i = 0;
	for (; i < 20; i++)
	{
		if (strcmp(cityname, cityl.citylist[i].cityname) == 0)
			p->pcity = &cityl.citylist[i];
	}
	p->next = NULL;
	//if (head == NULL)
	//head = p;
	//else
	tail->next = p;
	tail = p;
	//return head;

	//printline();
}

void VipRoute::printline()
{
	if (head == 0);//��������û�б�����
	else
	{
		Node * p = this->head;
		printf("������·��Ϊ��");//���ش��󣡣�����
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
		cout << sum*0.8 <<"(vip�ۿ�)"<< endl;
	}
}

void Route::saveroute()
{
	FILE *fp_out = fopen("route.dat", "wb");
	int temp1 = 0; int * temp2 = &temp1;
	fwrite(temp2, sizeof(int), 1, fp_out);
	Citylist * tempc = &cityl;
	fwrite(tempc, sizeof(CITY), 20, fp_out);
	temp1 = nodecount();
	fwrite(temp2, sizeof(int), 1, fp_out);
	Node * p = head;
	while (p)
	{
		fwrite(p->pcity->cityname, 12 * sizeof(char), 1, fp_out);
		p = p->next;
	}
	fclose(fp_out);
	cout << "������" << endl;
}

void VipRoute::saveroute()
{
	FILE *fp_out = fopen("route.dat", "wb");
	int temp1 = 255; int * temp2 = &temp1;
	fwrite(temp2, sizeof(int), 1, fp_out);
	Citylist * tempc = &cityl;
	fwrite(tempc, sizeof(CITY), 20, fp_out);
	temp1 = nodecount();
	fwrite(temp2, sizeof(int), 1, fp_out);
	Node * p = head;
	while (p)
	{
		fwrite(p->pcity->cityname, 12 * sizeof(char), 1, fp_out);
		p = p->next;
	}
	fclose(fp_out);
	cout << "������" << endl;
}

void Route::readfile()
{
	FILE *fp_in = fopen("route.dat", "r");
	int tempa = 0; int * tempb = &tempa;
	fread(tempb, sizeof(int), 1, fp_in);//������ȡ��־
	fread(cityl.citylist, sizeof(CITY), 20, fp_in);//д��citylist
	fread(tempb, sizeof(int), 1, fp_in);//��ȡ����ڵ�����
	char citynamefile[12] = {};
	head = NULL;
	Node *tail = NULL, *p = NULL;
	fread(citynamefile, sizeof(char) * 12, 1, fp_in); tempa--;
	while (tempa)
	{
		p = new Node;
		int i = 0;
		for (; i < 20; i++)
		{
			if (strcmp(citynamefile, cityl.citylist[i].cityname) == 0)
				p->pcity = &cityl.citylist[i];
		}
		p->next = NULL;
		if (head == NULL)
			head = p;
		else
			tail->next = p;
		tail = p;
		fread(citynamefile, sizeof(char) * 12, 1, fp_in); tempa--;
	}
	p = new Node;
	int i = 0;
	for (; i < 20; i++)
	{
		if (strcmp(citynamefile, cityl.citylist[i].cityname) == 0)
			p->pcity = &cityl.citylist[i];
	}
	p->next = NULL;
	//if (head == NULL)
	//head = p;
	//else
	tail->next = p;
	tail = p;
}

int main()
{
	Citylist cityl;
	Route travelline;
	VipRoute viptravelline;
	//cityl.setcitylist();
	//cityl.printcitylist();
	char c = 0;
	while (c != '*')
	{
		printmune();
		cin >> c;
		if (c == '1')
		{
			if (viptravelline.check())
				viptravelline.cityl.printcitylist();
			else
				travelline.cityl.printcitylist();
		}
		else if (c == '2')//2.��������·��
		{
			if (viptravelline.check())
			{
				viptravelline.createline();
				viptravelline.print();
			}
			else
			{
				travelline.createline();
				travelline.print();
			}
			//travelline.printline();
		}
		else if (c == '3')//3.������·���е�ĳ�������滻Ϊ�����ĳ���
		{
			if (viptravelline.check())
			{
				viptravelline.changecity();
				viptravelline.print();
			}
			else
			{
				travelline.changecity();
				travelline.print();
			}
			//travelline.printline();
		}
		else if (c == '4')//4.�����γ����е���������֮�䣬�����µĳ��� 
		{
			if (viptravelline.check())
			{
				viptravelline.insertcity();
				viptravelline.print();
			}
			else
			{
				travelline.insertcity();
				travelline.print();
			}
			//travelline.printline();
		}
		else if (c == '5')//5.ɾ��������·���е�ĳ������
		{
			if (viptravelline.check())
			{
				viptravelline.delcity();
				viptravelline.print();
			}
			else
			{
				travelline.delcity();
				travelline.print();
			}
			//travelline.printline();
		}
		else if (c == '6')//6.�������γ��м۸����ĳ�����γ��м۸�  
		{
			if (viptravelline.check())
			{
				viptravelline.cityl.changeprice();
				viptravelline.cityl.printcitylist();
				viptravelline.print();
			}
			else
			{
				travelline.cityl.changeprice();
				travelline.cityl.printcitylist();
				travelline.print();
			}
		}
		else if (c == '7')//7.��������·����������ļ���
		{
			if (viptravelline.check())
			{
				viptravelline.save();
			}
			else
				travelline.save();
		}
		else if (c == '8')//8.���ļ��ж�ȡ����·������ 
		{
			FILE *fp_in = fopen("route.dat", "r");
			int tempa = 0; int * tempb = &tempa;
			fread(tempb, sizeof(int), 1, fp_in);
			fclose(fp_in);
			if (tempa == 0)//��ͨ�û�
			{
				cout << "��ͨ�û�"<<endl;
				travelline.readfile();
				travelline.print();
			}
			else
			{
				cout << "vip�û�" << endl;
				viptravelline.readfile();
				viptravelline.print();
			}
		}
		else if (c == '9')//9.vipģʽ
		{
			travelline.~Route();
			//VipRoute viptravelline;
			viptravelline.createline();
			viptravelline.print();
			//travelline.print();
		}
		else if (c == '0')//0.�˳�vipģʽ 
		{
			viptravelline.~VipRoute();
			//Route travelline;
			travelline.createline();
			travelline.print();
		}
	}
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
	printf("       7.��������·����������ļ���                             \n");
	printf("       8.���ļ��ж�ȡ����·������                              \n");
	printf("       9.vipģʽ                                             \n");
	printf("       0.�˳�vipģʽ                                         \n");
	printf("       *.�˳�����                                             \n");
	printf("************************************************************\n");
}