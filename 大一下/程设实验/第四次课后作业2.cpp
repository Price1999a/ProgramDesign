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

void Route::createline()
{
	head = NULL;
	Node *tail = NULL, *p = NULL;
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
	if (head == 0);//假如链表还没有被创建
	else
	{
		Node * p = this->head;
		printf("旅游线路现为：");//严重错误！！！！
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

void Route::changecity()
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
	cout << "请输入需要删除的城市：";
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
	cout << "请输入城市，以空格分割，换行结束：";
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
	if (head == 0);//假如链表还没有被创建
	else
	{
		Node * p = this->head;
		printf("旅游线路现为：");//严重错误！！！！
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
		cout << sum*0.8 <<"(vip折扣)"<< endl;
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
	cout << "输出完成" << endl;
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
	cout << "输出完成" << endl;
}

void Route::readfile()
{
	FILE *fp_in = fopen("route.dat", "r");
	int tempa = 0; int * tempb = &tempa;
	fread(tempb, sizeof(int), 1, fp_in);//跳过读取标志
	fread(cityl.citylist, sizeof(CITY), 20, fp_in);//写入citylist
	fread(tempb, sizeof(int), 1, fp_in);//读取链表节点数量
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
		else if (c == '2')//2.创建旅游路线
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
		else if (c == '3')//3.将旅游路线中的某个城市替换为其他的城市
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
		else if (c == '4')//4.在旅游城市中的两个城市之间，插入新的城市 
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
		else if (c == '5')//5.删除旅游线路的中的某个城市
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
		else if (c == '6')//6.调整旅游城市价格表中某个旅游城市价格  
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
		else if (c == '7')//7.将旅游线路数据输出到文件中
		{
			if (viptravelline.check())
			{
				viptravelline.save();
			}
			else
				travelline.save();
		}
		else if (c == '8')//8.从文件中读取旅游路线数据 
		{
			FILE *fp_in = fopen("route.dat", "r");
			int tempa = 0; int * tempb = &tempa;
			fread(tempb, sizeof(int), 1, fp_in);
			fclose(fp_in);
			if (tempa == 0)//普通用户
			{
				cout << "普通用户"<<endl;
				travelline.readfile();
				travelline.print();
			}
			else
			{
				cout << "vip用户" << endl;
				viptravelline.readfile();
				viptravelline.print();
			}
		}
		else if (c == '9')//9.vip模式
		{
			travelline.~Route();
			//VipRoute viptravelline;
			viptravelline.createline();
			viptravelline.print();
			//travelline.print();
		}
		else if (c == '0')//0.退出vip模式 
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
	printf("                            菜单                            \n");
	printf("       1.打印旅游城市价格表                                   \n");
	printf("       2.创建旅游路线                                         \n");
	printf("       3.将旅游路线中的某个城市替换为其他的城市                  \n");
	printf("       4.在旅游城市中的两个城市之间，插入新的城市                \n");
	printf("       5.删除旅游线路的中的某个城市                             \n");
	printf("       6.调整旅游城市价格表中某个旅游城市价格                    \n");
	printf("       7.将旅游线路数据输出到文件中                             \n");
	printf("       8.从文件中读取旅游路线数据                              \n");
	printf("       9.vip模式                                             \n");
	printf("       0.退出vip模式                                         \n");
	printf("       *.退出程序                                             \n");
	printf("************************************************************\n");
}