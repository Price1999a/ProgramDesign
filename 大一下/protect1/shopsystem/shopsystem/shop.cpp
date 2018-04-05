#include "shop.h"

void CSoldlist::printsoldlist()
{
	CTracker tracker("CSoldlist::printsoldlist");
	printf("***********************************************************************\n");
	printf("ID\t\t名称\t\t品牌\t\t价格\t\t数量\n");
	int n = 0;
	while (soldlist[n].soldcommodity.id[0] != 0)
	{
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
	CTracker tracker("CSoldlist::readsoldlist");
	FILE * fp_in = fopen("已售清单.txt", "r");
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
	CTracker tracker("CSoldlist::compare_");
	if (strcmp((*(Soldlist *)a).soldcommodity.id, (*(Soldlist *)b).soldcommodity.id) != 0)
		return strcmp((*(Soldlist *)a).soldcommodity.id, (*(Soldlist *)b).soldcommodity.id);
	else
		return (*(Soldlist *)a).soldcommodity.price - (*(Soldlist *)b).soldcommodity.price;
}

void CStock::readstockfile()
{
	CTracker tracker("CStock::readstockfile");
	FILE * fp_in = fopen("库存.txt", "r");
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
	CTracker tracker("CStock::printadminstocklist");
	int n = -1;
	printf("***************************************************************************\n");
	printf("ID\t\t名称\t\t品牌\t\t价格\t\t数量\n");
	while (n < 100)
	{
		n++;
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
	CTracker tracker("CStock::printusersstocklist");
	int n = 0;
	printf("***************************************************************************\n");
	printf("ID\t\t名称\t\t品牌\t\t价格\t\t数量\n");
	while (n < 100)
	{
		n++;
		if (stocklist[n].price == 0)continue;
		if (stocklist[n].number == 0)continue;
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
	CTracker tracker("CStock::addstocklist");
	Commodity addstock;
	memset(&addstock, 0, sizeof(Commodity));
	cout << "请输入商品名与品牌(以空格相隔)：";
	cin >> addstock.name >> addstock.brand;
	int i;
	for (i = 0; i < 100; i++)
	{
		if(strcmp(addstock.name,stocklist[i].name)==0)
			if (strcmp(addstock.brand, stocklist[i].brand) == 0)
			{
				int n = 0;
				cout << "请输入增加的数量：";
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
	cout << "请输入价格与数量（以空格分隔）：";
	cin >> stocklist[i].price >> stocklist[i].number;
}

void CStock::changeadminstocklist()
{
	CTracker tracker("CStock::changeadminstocklist");
	char aimid[6] = { 0 };
	cout << "请输入修改商品编号：";
	cin >> aimid;
	int i = 0;
	for (i = 0; i < 100; i++)
		if (strcmp(aimid, stocklist[i].id) == 0)
			break;
	if (i == 100)
	{
		cerr << "未找到编号！" << endl;
		return;
	}
	int c = 0;
	cout << "请选择修改方向（1.数量2.价格）：";
	cin >> c;
	if (c == 1)
	{
		int newnumber = 0;
		cout << "请输入最新数量：";
		cin >> newnumber;
		if (newnumber < 0)
		{
			cerr << "非法输入！" << endl;
			return;
		}
		stocklist[i].number = newnumber;
	}
	else if (c == 2)
	{
		float newprice = 0;
		cout << "请输入最新价格：";
		cin >> newprice;
		if (newprice <= 0)
		{
			cerr << "非法输入！" << endl;
			return;
		}
		stocklist[i].price = newprice;
	}
	else
	{
		cout << "输入错误" << endl;
		return;
	}
	cout << "修改成功！" << endl;
}

void CStock::deletestocklist()
{
	CTracker tracker("CStock::deletestocklist");
	char aimid[6] = { 0 };
	cout << "请输入删除商品编号：";
	cin >> aimid;
	int i = 0;
	for (i = 0; i < 100; i++)
		if (strcmp(aimid, stocklist[i].id) == 0)
			break;
	if (i == 100)
	{
		cerr << "未找到编号！" << endl;
		return;
	}
	stocklist[i].number = -1;
	cout << "删除成功！" << endl;
}

void CStock::searchusersstocklist()
{
	CTracker tracker("CStock::searchusersstocklist");

}

void CStock::writeinstockfile()
{
	CTracker tracker("CStock::writeinstockfile");
	FILE * fp_out = fopen("库存.txt", "w");
	fprintf(fp_out, "ID\t名称\t品牌\t价格\t数量\n");
	int n = 0;
	while (stocklist[n].id[0] != 0)
	{
		fprintf(fp_out, "%s\t%s\t%s\t%.1f\t%d\n", stocklist[n].id, stocklist[n].name, stocklist[n].brand, stocklist[n].price, stocklist[n].number);
		n++;
	}
	fclose(fp_out);
}

void CShoppingCart::readshoppingcartfile(User)
{
	CTracker tracker("CShoppingCart::readshoppingcartfile");

}

void CShoppingCart::writeinshopplingcartfile(User)
{
	CTracker tracker("CShoppingCart::writeinshopplingcartfile");

}

bool CShoppingCart::checkshoppingcartrequest()
{
	CTracker tracker("CShoppingCart::checkshoppingcartrequest");
	return true;
}

void CShoppingCart::writeinsoldlistfile()
{
	CTracker tracker("CShoppingCart::writeinsoldlistfile");

}

void CShoppingCart::modifystocklist()
{
	CTracker tracker("CShoppingCart::modifystocklist");

}

void CShoppingCart::addshoppingcart()
{
}
