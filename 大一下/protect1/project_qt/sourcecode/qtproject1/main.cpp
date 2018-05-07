#include "stdafx.h"
#include "qtproject1.h"
//#include "qtproject1_login.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	//CUser userineed;
	CAdmin adminineed;
	CUser * newuser = CUser::getglobleuser();//单例模式的效果
	
	QApplication a(argc, argv);
	qtproject1 w;
	w.show();
	
	//project1login temp;
	//temp.show();
	return a.exec();
}
