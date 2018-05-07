/*************************************************************************
	> File Name: main.cpp
	> Author:Shen Tianqi 
	> Mail: 
	> Created Time: Mon 23 Apr 2018 11:30:28 PM CST
 ************************************************************************/

#include<iostream>
#include "database.h"
#include <stdio.h>
using namespace std;

void commandinterpreter();
void printhelpmenu();

int main()
{
    string temp_123;
    //Cdatabase tablelist;
    Cdatabase * tablelist = Cdatabase::getglobledatabase();
    while(temp_123!="q")
    {
        cout<<"~$ ";
        cin>>temp_123;
        getchar();
        //cout<<"hello world, project2"<<endl;
        if(temp_123=="mySQL")
             commandinterpreter();
    }
    return 0;
}

void commandinterpreter()
{
    Cdatabase * tablelist = Cdatabase::getglobledatabase();
    bool flag =true;
    while(flag==true)
    {
        string commandtemp;
        cout<<"(mysql)==> ";
        //cin>>commandtemp;
        getline(cin,commandtemp,'\n');
        if(commandtemp.find("quit")!=string::npos)
        {
            flag=false;
            return;
        }

        else if(commandtemp=="help")
            {
                printhelpmenu();
                continue;
            }
            
        else if(commandtemp.find("CREATE TABLE")==0)
        {
            //cout<<"create table list"<<endl;
            if(commandtemp.find("(")!=string::npos)
                {
                    //cout<<"create to file"<<endl;
                    //done
                    tablelist->createnewtablefromcommand(commandtemp);
                }
            else
            {
                //cout<<"create from file"<<endl;
                // done 
                tablelist->createnewtablefromfile(commandtemp);
            }
        }

        else if(commandtemp.find("DROP TABLE")==0)//done
        {
            //cout<<"drop the table"<<endl;
            tablelist->dropatable(commandtemp);
        }

        else if(commandtemp=="TABLE LIST")//done
        {
            //cout<<"print table list"<<endl;
            tablelist->tablelist();
        }
        
        else if(commandtemp.find("INSERT INTO")==0)
        {
            //cout<<"insert into a new line"<<endl;
            if(commandtemp.find(") VALUES (")!=string::npos)
                {
                    //cout<<"insert into some values"<<endl;
                    //done
                    tablelist->insertaline(commandtemp);
                }
            else
                {
                    //cout<<"insert into all valus"<<endl;
                    //done
                    tablelist->insertafullline(commandtemp);
                }
        }

        else if(commandtemp.find("DELETE")==0)
        {
            //cout<<"delete some lines"<<endl;
            if(commandtemp.find("* FROM")!=string::npos)//done
                {
                    //cout<<"delete all the line"<<endl;
                    tablelist->deletealltable(commandtemp);
                }
            else
                {
                    //cout<<"delete some lines"<<endl;
                    //done
                    tablelist->deletesomeline(commandtemp);
                }
        }

        else if(commandtemp.find("UPDATE")==0)
        {
            //cout<<"update the table"<<endl;
            if(commandtemp.find("WHERE")!=string::npos)
                {
                    //cout<<"update some line"<<endl;
                    //done
                    tablelist->updatesomeline(commandtemp);
                }
            else
                {
                    //cout<<"update all lines"<<endl;
                    //done
                    tablelist->updateallline(commandtemp);
                }
        }

        else if(commandtemp.find("SELECT")==0)
        {
            //cout<<"select some lines to print"<<endl;
            //if(commandtemp.find("* FROM")!=string::npos)
                //{
                    //cout<<"print all the column"<<endl;
                    //done
                    tablelist->selecttable(commandtemp);
                //}
            //else
                //cout<<"print the selected column"<<endl;
        }

        else
        {
            //cout<<"waring! wrong command! check it!"<<endl;
        }

        //if(commandtemp.find("WHERE")!=string::npos)
            //cout<<"yes, where!"<<endl;
        //else
            //cout<<"no where"<<endl;
    }
}

void printhelpmenu()
{
	cout << "请注意，所有语句开头不允许有空格，分隔为一个空格，支持WHERE，所有命令应为大写。" << endl;
}
