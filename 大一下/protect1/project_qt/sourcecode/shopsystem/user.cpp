#include "user.h"

bool CUser::usercomfirmation()
{
	//CTracker tracker("CUser::usercomfirmation");
	/*FILE * fp_in = fopen("�û�.txt", "r");
	char temp[20] = { 0 };
	fgets(temp, 20, fp_in);
	
	while (!feof(fp_in))
	{
		fscanf(fp_in, "%s\t%s\n", userslist[n].username, userslist[n].password);
		n++;
	}
	n = 0;//*/
	int n = 0;
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
	cout << "���������룺";
	cin >> inputuser.password;
	if (strcmp(userslist[n].password, inputuser.password) == 0)
	{
		printf("**********\n");
		printf("��½�ɹ���\n");
		printf("**********\n");
		return true;
	}
	else
	{
		cerr << "�������" << endl;
		return false;
	}
}

void CUser::userbuild()
{
	//CTracker tracker("CUser::userbuild");
	strcpy(currentuser.username, inputuser.username);
	//strcpy(currentuser.password, inputuser.password);//û�б�Ҫ��������
	stocking.readstockfile();
	shoppingcart.readshoppingcartfile(currentuser);
	shoppingcart.freshshoppingcart();
	shoppingcart.writeinshopplingcartfile(currentuser);
}

void CUser::printusermune()
{
	//CTracker tracker("CUser::printusermune");
	printf("==========================================================================================================\n");
	printf("1.ע����½    2.�鿴��Ʒ    3.��Ʒ����    4.�����Ʒ�����ﳵ    5.ɾ�����ﳵ��Ʒ    6.�鿴���ﳵ    7.����\n");
	printf("==========================================================================================================\n");
	printf("�����������");
}

void CUser::builduserslist()
{
	//CTracker tracker("CUser::builduserslist");
	FILE * fp_in = fopen("�û�.txt", "r");
	char temp[20] = { 0 };
	fgets(temp, 20, fp_in);
	int n = 0;
	while (!feof(fp_in))
	{
		fscanf(fp_in, "%s\t%s\n", userslist[n].username, userslist[n].password);
		n++;
	}
}

bool CUser::createnewuser()
{
	//CTracker tracker("CUser::createnewuser");
	cout << "�����û�����";
	cin >> inputuser.username;
	cout << "�������룺";
	cin >> inputuser.password;
	for (int i = 0; i < 20; i++)
	{
		if(strcmp(inputuser.username,userslist[i].username)==0)
			if (strcmp(inputuser.password, userslist[i].password) == 0)
			{
				strcpy(currentuser.username, inputuser.username);
				return true;
			}
			else
			{
				cout << "�û�����ռ�ã��������û�ʧ��" << endl;
				return false;
			}
	}
	FILE * fp_out = fopen("�û�.txt", "a+");
	fprintf(fp_out, "%s\t%s\n", inputuser.username, inputuser.password);
	fclose(fp_out);
	char userfilename[24] = { 0 };
	strcpy(userfilename, inputuser.username);
	strcat(userfilename, ".txt");
	FILE * fp_in = fopen(userfilename, "w");
	fprintf(fp_out, "ID\t����\tƷ��\t�۸�\t����\n");
	fclose(fp_out);
	printf("*******************\n");
	printf("ע��ɹ�����½�ɹ���\n");
	printf("*******************\n");
	return true;
}

