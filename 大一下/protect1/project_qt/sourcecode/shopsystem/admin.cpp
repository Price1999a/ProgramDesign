#include "admin.h"

bool CAdmin::adminconfirmaton()
{
	//CTracker tracker("CAdmin::adminconfirmaton");
	char admin[20] = { 0 }, adminpassword[20] = { 0 };
	cout << "�������ԱID��";
	cin >> admin;
	if (strcmp(admin, "Admin"))
	{
		cout << "����ԱID����" << endl;
		return false;
	}
	cout << "�������Ա���룺";
	cin >> adminpassword;
	if (strcmp(adminpassword, "admin"))
	{
		cout << "����Ա�������" << endl;
		return false;
	}
	return true;
}

void CAdmin::printadminmune()
{
	//CTracker tracker("CAdmin::printadminmune");

	printf("====================================================================================\n");
	printf("0.ע����½    1.��ѯ��Ʒ    2.������Ʒ    3.ɾ����Ʒ    4.�޸���Ʒ����    5.�ۻ��嵥\n");
	printf("====================================================================================\n");
	printf("�����������");
}

void CAdmin::adminbuild()
{
	//CTracker tracker("CAdmin::adminbuild");
	stocking.readstockfile();
}
