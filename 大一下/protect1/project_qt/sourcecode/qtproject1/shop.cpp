#include "shop.h"

void CSoldlist::printsoldlist()
{
	//CTracker tracker("CSoldlist::printsoldlist");
	printf("***********************************************************************\n");
	printf("ID\t\t����\t\tƷ��\t\t�۸�\t\t����\n");
	int n = 0;
	while (soldlist[n].soldcommodity.id[0] != 0)
	{
		if (soldlist[n].soldcommodity.number == 0) { n++; continue; }
		printf("%s\t\t", soldlist[n].soldcommodity.id);
		if (soldlist[n].soldcommodity.name[7] == 0)
			printf("%s\t\t", soldlist[n].soldcommodity.name);
		else
			printf("%s\t", soldlist[n].soldcommodity.name);
		if (soldlist[n].soldcommodity.brand[7] == 0)
			printf("%s\t\t", soldlist[n].soldcommodity.brand);
		else
			printf("%s\t", soldlist[n].soldcommodity.brand);
		printf("%.1f\t\t", soldlist[n].soldcommodity.price);
		printf("%d\n", soldlist[n].soldcommodity.number);
		n++;
	}
	printf("***********************************************************************\n");
}

void CSoldlist::readsoldlist()
{
	//CTracker tracker("CSoldlist::readsoldlist");
	FILE * fp_in = fopen("�����嵥.txt", "r");
	Soldlist soldlisttemp;
	memset(&soldlisttemp, 0, sizeof(Soldlist));
	int n = 0;
	char temp[50];
	fgets(&temp[0], 50, fp_in);
	while (!feof(fp_in))
	{
		fscanf(fp_in, "%s\t", &soldlisttemp.soldcommodity.id);
		fscanf(fp_in, "%s\t", &soldlisttemp.soldcommodity.name);
		fscanf(fp_in, "%s\t", &soldlisttemp.soldcommodity.brand);
		fscanf(fp_in, "%f\t", &soldlisttemp.soldcommodity.price);
		fscanf(fp_in, "%d\n", &soldlisttemp.soldcommodity.number);
		fscanf(fp_in, "%s\n", &soldlisttemp.uesrname);
		for (n = 0; n < 2000; n++)
		{
			if(strcmp(soldlist[n].soldcommodity.id,soldlisttemp.soldcommodity.id)==0)
				if (soldlist[n].soldcommodity.price == soldlisttemp.soldcommodity.price)
				{
					soldlist[n].soldcommodity.number += soldlisttemp.soldcommodity.number;
					break;
				}
		}
		if (n < 2000)continue;
		n = 0;
		while (soldlist[n].soldcommodity.id[0] != 0)n++;
		strcpy(soldlist[n].soldcommodity.id, soldlisttemp.soldcommodity.id);
		strcpy(soldlist[n].soldcommodity.brand, soldlisttemp.soldcommodity.brand);
		strcpy(soldlist[n].soldcommodity.name, soldlisttemp.soldcommodity.name);
		soldlist[n].soldcommodity.price = soldlisttemp.soldcommodity.price;
		soldlist[n].soldcommodity.number = soldlisttemp.soldcommodity.number;
		strcpy(soldlist[n].uesrname, soldlisttemp.uesrname);
	}
	n = 0;
	while (soldlist[n].soldcommodity.id[0] != 0)n++;
	qsort(soldlist, n, sizeof(Soldlist), compare);
	fclose(fp_in);
}

int CSoldlist::compare(const void * a, const void * b)
{
	//CTracker tracker("CSoldlist::compare_");
	if (strcmp((*(Soldlist *)a).soldcommodity.id, (*(Soldlist *)b).soldcommodity.id) != 0)
		return strcmp((*(Soldlist *)a).soldcommodity.id, (*(Soldlist *)b).soldcommodity.id);
	else
		return (*(Soldlist *)a).soldcommodity.price - (*(Soldlist *)b).soldcommodity.price;
}

void CStock::readstockfile()
{
	//CTracker tracker("CStock::readstockfile");
	FILE * fp_in = fopen("���.txt", "r");
	int n = 0;
	char temp[50];
	fgets(&temp[0],50,fp_in );
	while (!feof(fp_in))
	{
		fscanf(fp_in, "%s\t", &stocklist[n].id);
		fscanf(fp_in, "%s\t", &stocklist[n].name);
		fscanf(fp_in, "%s\t", &stocklist[n].brand);
		fscanf(fp_in, "%f\t", &stocklist[n].price);
		fscanf(fp_in, "%d\n", &stocklist[n].number);
		n++;
	}
	fclose(fp_in);
	n = 0;
}

void CStock::printadminstocklist()
{
	//CTracker tracker("CStock::printadminstocklist");
	int n = -1;
	printf("***************************************************************************\n");
	printf("ID\t\t����\t\tƷ��\t\t�۸�\t\t����\n");
	while (n < 100)
	{
		n++;
		if (n == 100)break;
		if (stocklist[n].price == 0)continue;
		if (stocklist[n].number == -1)continue;
		printf("%s\t\t", stocklist[n].id);
		if (stocklist[n].name[7] == 0)
			printf("%s\t\t", stocklist[n].name);
		else
			printf("%s\t", stocklist[n].name);
		if (stocklist[n].brand[7] == 0)
			printf("%s\t\t", stocklist[n].brand);
		else
			printf("%s\t", stocklist[n].brand);
		printf("%.1f\t\t%d\n", stocklist[n].price, stocklist[n].number);
	}
	printf("***************************************************************************\n");
}

void CStock::printusersstocklist()
{
	//CTracker tracker("CStock::printusersstocklist");
	int n = -1;
	printf("***************************************************************************\n");
	printf("ID\t\t����\t\tƷ��\t\t�۸�\t\t����\n");
	while (n < 100)
	{
		n++;
		if (n == 100)break;
		if (stocklist[n].price == 0)continue;
		if (stocklist[n].number <= 0)continue;
		printf("%s\t\t", stocklist[n].id);
		if (stocklist[n].name[7] == 0)
			printf("%s\t\t", stocklist[n].name);
		else
			printf("%s\t", stocklist[n].name);
		if (stocklist[n].brand[7] == 0)
			printf("%s\t\t", stocklist[n].brand);
		else
			printf("%s\t", stocklist[n].brand);
		printf("%.1f\t\t%d\n", stocklist[n].price, stocklist[n].number);
	}
	printf("***************************************************************************\n");
}

void CStock::addstocklist()
{
	//CTracker tracker("CStock::addstocklist");
	Commodity addstock;
	memset(&addstock, 0, sizeof(Commodity));
	cout << "��������Ʒ����Ʒ��(�Կո����)��";
	cin >> addstock.name >> addstock.brand;
	int i;
	for (i = 0; i < 100; i++)
	{
		if(strcmp(addstock.name,stocklist[i].name)==0)
			if (strcmp(addstock.brand, stocklist[i].brand) == 0)
			{
				int n = 0;
				cout << "���������ӵ�������";
				cin >> n;
				if (stocklist[i].number == -1)
					stocklist[i].number += n + 1;
				else
					stocklist[i].number += n;
				break;
			}

	}
	if (i < 100)return;
	i = 0;
	while (stocklist[i].name[0] != 0)i++;
	char idtemp[6] = { 0 };
	idtemp[0] = '1';
	for (int j = 0; j < 5; j++)idtemp[j + 1] = stocklist[i - 1].id[j + 1];
	int idtemp1 = atoi(idtemp);
	idtemp1++;
	itoa(idtemp1,idtemp,10);
	idtemp[0] = stocklist[i - 1].id[0];
	strcpy(stocklist[i].id, idtemp);
	strcpy(stocklist[i].brand, addstock.brand);
	strcpy(stocklist[i].name, addstock.name);
	cout << "������۸����������Կո�ָ�����";
	cin >> stocklist[i].price >> stocklist[i].number;
}

void CStock::changeadminstocklist()
{
	//CTracker tracker("CStock::changeadminstocklist");
	char aimid[6] = { 0 };
	cout << "�������޸���Ʒ��ţ�";
	cin >> aimid;
	int i = 0;
	for (i = 0; i < 100; i++)
		if (strcmp(aimid, stocklist[i].id) == 0)
			break;
	if (i == 100)
	{
		cerr << "δ�ҵ���ţ�" << endl;
		return;
	}
	int c = 0;
	cout << "��ѡ���޸ķ���1.����2.�۸�3.����4.Ʒ�ƣ���";
	cin >> c;
	if (c == 1)
	{
		int newnumber = 0;
		cout << "����������������";
		cin >> newnumber;
		if (newnumber < 0)
		{
			cerr << "�Ƿ����룡" << endl;
			return;
		}
		stocklist[i].number = newnumber;
	}
	else if (c == 2)
	{
		float newprice = 0;
		cout << "���������¼۸�";
		cin >> newprice;
		if (newprice <= 0)
		{
			cerr << "�Ƿ����룡" << endl;
			return;
		}
		stocklist[i].price = newprice;
	}
	else if (c == 3)
	{
		cout << "���������ƣ�";
		char newname[40];
		cin >> newname;
		memset(stocklist[i].name, 0, 40 * sizeof(char));
		strcpy(stocklist[i].name, newname);
	}
	else if (c == 4)
	{
		cout << "������Ʒ�ƣ�";
		char newbrand[40];
		cin >> newbrand;
		memset(stocklist[i].brand, 0, 40 * sizeof(char));
		strcpy(stocklist[i].brand, newbrand);
	}
	else
	{
		cout << "�������" << endl;
		return;
	}
	cout << "�޸ĳɹ���" << endl;
}

void CStock::deletestocklist()
{
	//CTracker tracker("CStock::deletestocklist");
	char aimid[6] = { 0 };
	cout << "������ɾ����Ʒ��ţ�";
	cin >> aimid;
	int i = 0;
	for (i = 0; i < 100; i++)
		if (strcmp(aimid, stocklist[i].id) == 0)
			break;
	if (i == 100)
	{
		cerr << "δ�ҵ���ţ�" << endl;
		return;
	}
	stocklist[i].number = -1;
	cout << "*************\n";
	cout << "ɾ���ɹ���" << endl;
	cout << "*************\n";
}

void CStock::searchusersstocklist()
{
	//CTracker tracker("CStock::searchusersstocklist");
	char inputcommodityname[40] = { 0 };
	cout << "������Ʒ���ƣ�";
	cin >> inputcommodityname;
	int n = -1;
	printf("***************************************************************************\n");
	printf("ID\t\t����\t\tƷ��\t\t�۸�\t\t����\n");
	bool flag = false;
	while (n<100)
	{
		n++;
		if (n == 100)break;
		if (stocklist[n].price == 0)continue;
		if (strstr(stocklist[n].name, inputcommodityname) == NULL)continue;
		if (stocklist[n].number <= 0)continue;
		printf("%s\t\t", stocklist[n].id);
		if (stocklist[n].name[7] == 0)
			printf("%s\t\t", stocklist[n].name);
		else
			printf("%s\t", stocklist[n].name);
		if (stocklist[n].brand[7] == 0)
			printf("%s\t\t", stocklist[n].brand);
		else
			printf("%s\t", stocklist[n].brand);
		printf("%.1f\t\t%d\n", stocklist[n].price, stocklist[n].number);
		flag = true;
	}
	if (flag == false)cout << "��Ʒ�����ڣ�" << endl;
	printf("***************************************************************************\n");
}

void CStock::writeinstockfile()
{
	//CTracker tracker("CStock::writeinstockfile");
	FILE * fp_out = fopen("���.txt", "w");
	fprintf(fp_out, "ID\t����\tƷ��\t�۸�\t����\n");
	int n = 0;
	while (stocklist[n].id[0] != 0)
	{
		fprintf(fp_out, "%s\t%s\t%s\t%.1f\t%d\n", stocklist[n].id, stocklist[n].name, stocklist[n].brand, stocklist[n].price, stocklist[n].number);
		n++;
	}
	fclose(fp_out);
}

void CShoppingCart::readshoppingcartfile(User a)
{
	//CTracker tracker("CShoppingCart::readshoppingcartfile");
	char userfilename[24] = { 0 };
	strcpy(userfilename, a.username);
	strcat(userfilename, ".txt");
	FILE * fp_in = fopen(userfilename, "r");
	int n = 0;
	char temp[50];
	fgets(&temp[0], 50, fp_in);
	while (!feof(fp_in))
	{
		fscanf(fp_in, "%s\t", &stocklist[n].id);
		fscanf(fp_in, "%s\t", &stocklist[n].name);
		fscanf(fp_in, "%s\t", &stocklist[n].brand);
		fscanf(fp_in, "%f\t", &stocklist[n].price);
		fscanf(fp_in, "%d\n", &stocklist[n].number);
		n++;
	}
}

void CShoppingCart::writeinshopplingcartfile(User a)
{
	//CTracker tracker("CShoppingCart::writeinshopplingcartfile");
	char userfilename[24] = { 0 };
	strcpy(userfilename, a.username);
	strcat(userfilename, ".txt");
	FILE * fp_out = fopen(userfilename, "w");
	fprintf(fp_out, "ID\t����\tƷ��\t�۸�\t����\n");
	int n = 0;
	while (stocklist[n].id[0] != 0)
	{
		fprintf(fp_out, "%s\t%s\t%s\t%.1f\t%d\n", stocklist[n].id, stocklist[n].name, stocklist[n].brand, stocklist[n].price, stocklist[n].number);
		n++;
	}
	fclose(fp_out);
}

bool CShoppingCart::checkshoppingcartrequest()
{
	//CTracker tracker("CShoppingCart::checkshoppingcartrequest");
	CStock temp;
	temp.readstockfile();
	int n = -1;//n���ڹ��ﳵ
	while (n < 100)
	{
		n++;
		if (stocklist[n].number <= 0)continue;
		int i = 0;
		for (i = 0; i < 100; i++)//i���ڿ��
		{
			if (strcmp(temp.stocklist[i].id, stocklist[n].id) == 0)
				break;
		}
		if (temp.stocklist[i].number < stocklist[n].number)
		{
			//cout << "�����������ʧ�ܡ�\n";
			return false;
		}
	}
	//printf("*****************\n");
	//printf("�Ѿ����빺�ﳵ��\n");
	//printf("*****************\n");
	return true;
}

void CShoppingCart::writeinsoldlistfile(User a)
{
	//CTracker tracker("CShoppingCart::writeinsoldlistfile");
	FILE * fp_out = fopen("�����嵥.txt", "a+");
	int n = 0;
	while (stocklist[n].id[0] != 0)
	{
		fprintf(fp_out, "%s\t%s\t%s\t%.1f\t%d\t", stocklist[n].id, stocklist[n].name, stocklist[n].brand, stocklist[n].price, stocklist[n].number);
		fprintf(fp_out, "%s\n", a.username);
		n++;
	}
	fclose(fp_out);
}

void CShoppingCart::modifystocklistfile()
{
	//CTracker tracker("CShoppingCart::modifystocklist");
	CStock temp;
	temp.readstockfile();
	int n = -1;//n���ڹ��ﳵ
	while (n < 100)
	{
		n++;
		if (n == 100)break;
		if (stocklist[n].number <= 0)continue;
		int i = 0;
		for (i = 0; i < 100; i++)//i���ڿ��
		{
			if (strcmp(temp.stocklist[i].id, stocklist[n].id) == 0)
				break;
		}
		temp.stocklist[i].number -= stocklist[n].number;
	}
	temp.writeinstockfile();//д�����ļ�
	memset(stocklist, 0, 100 * sizeof(Commodity));//��չ��ﳵ
}

void CShoppingCart::addshoppingcart()
{
	char inputid[6] = { 0 };
	int inputnumber = 0;
	cout << "������ƷID���������м��Կո��������";
	cin >> inputid >> inputnumber;
	int n = 0;
	while (n<100)
	{
		if (strcmp(this->stocklist[n].id, inputid) == 0)
		{
			if (this->stocklist[n].number == -1)
				this->stocklist[n].number += inputnumber + 1;
			else
				this->stocklist[n].number += inputnumber;
			return;
		}
		n++;
	}
	n = 0;
	CStock temp;
	temp.readstockfile();
	while (n < 100)
	{
		if (strcmp(temp.stocklist[n].id, inputid) == 0)
			break;
		n++;
	}
	int i = 0;
	for (;; i++)
	{
		if (stocklist[i].price == 0)
			break;
	}
	//i++;
	strcpy(stocklist[i].id, temp.stocklist[n].id);
	strcpy(stocklist[i].brand, temp.stocklist[n].brand);
	strcpy(stocklist[i].name, temp.stocklist[n].name);
	stocklist[i].number = inputnumber;
	stocklist[i].price = temp.stocklist[n].price;
}

bool CShoppingCart::freshshoppingcart()
{
	CStock temp;
	temp.readstockfile();
	int n = -1;//n���ڹ��ﳵ
	bool flag = false;
	while (n < 100)
	{
		n++;
		if (stocklist[n].price == 0)break;
		int i = 0;
		for (i = 0; i < 100; i++)//i���ڿ��
		{
			if (strcmp(temp.stocklist[i].id, stocklist[n].id) == 0)
				break;
		}
		if (strcmp(temp.stocklist[i].name, stocklist[n].name) != 0 || strcmp(temp.stocklist[i].brand, stocklist[n].brand) != 0)
		{
			flag = true;
			strcpy(stocklist[n].name, temp.stocklist[i].name);
			strcpy(stocklist[n].brand, temp.stocklist[i].brand);
			stocklist[n].number = 0;
			stocklist[n].price = temp.stocklist[i].price;
		}
		if (temp.stocklist[i].number < stocklist[n].number)
		{
			flag = true;
			stocklist[n].number = 0;
			stocklist[n].price = temp.stocklist[i].price;
		}
		if (temp.stocklist[i].price != stocklist[n].price)
		{
			flag = true;
			stocklist[n].price = temp.stocklist[i].price;
		}
	}
		//cout << "ע�⣡��Ʒ��Ϣ�ѱ����£�\n";
	return flag;
}

bool CShoppingCart::sumprice()
{
	float sum = 0;
	for (int i = 0; i < 100; i++)
	{
		if (stocklist[i].number <= 0)continue;
		sum += stocklist[i].price*stocklist[i].number;
	}
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	printf("һ��Ҫ����%.1f��ȷ�ϸ����밴1��ȡ���밴0��", sum);
	int n = 0;
	cin >> n;
	printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
	if (n == 1)
		return true;
	else if (n==0)
	{
		return false;
	}
}
