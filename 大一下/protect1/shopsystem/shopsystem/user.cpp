#include "user.h"

bool CUser::usercomfirmation()
{
	CTracker tracker("CUser::usercomfirmation");
	FILE * fp_in = fopen("�û�.txt", "r");
	char temp[20] = { 0 };
	fgets(temp, 20, fp_in);
	int n = 0;
	while (!feof(fp_in))
	{
		fscanf(fp_in, "%s\t%s\n", userslist[n].username, userslist[n].password);
		n++;
	}
	n = 0;
	cout << "�������û�����";
	cin >> inputuser.username;
	while (userslist[n].username[0] != 0)
		if (strcmp(userslist[n].username, inputuser.username) == 0)
			break;
		else
			n++;
	if (userslist[n].username[0] == 0)
	{
		cerr << "�û��������ڣ�" << endl;
		return false;
	}
	cout << "���������룺" << endl;
	cin >> inputuser.password;
	if (strcmp(userslist[n].password, inputuser.password) == 0)
		return true;
	else
	{
		cerr << "�������" << endl;
		return false;
	}
}

void CUser::userbuild()
{
	CTracker tracker("CUser::userbuild");
	strcpy(currentuser.username, inputuser.username);
	strcpy(currentuser.password, inputuser.password);
	stocking.readstockfile();
	shoppingcart.readshoppingcartfile(currentuser);
}

void CUser::printusermune()
{
	CTracker tracker("CUser::printusermune");
	printf("==========================================================================================================\n");
	printf("1.ע����½    2.�鿴��Ʒ    3.��Ʒ����    4.�����Ʒ�����ﳵ    5.ɾ�����ﳵ��Ʒ    6.�鿴���ﳵ    7.����\n");
	printf("==========================================================================================================\n");
	printf("�����������");
}

void CUser::builduserslist()
{
	CTracker tracker("CUser::builduserslist");
}

bool CUser::createnewuser()
{
	CTracker tracker("CUser::createnewuser");
	return true;
}

bool CUser::checkduplicationusername()
{
	CTracker tracker("CUser::checkduplicationusername");

	return true;
}
