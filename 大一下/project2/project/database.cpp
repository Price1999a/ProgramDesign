/*************************************************************************
	> File Name: database.cpp
	> Author: Shen Tianqi
	> Mail: 
	> Created Time: Mon 23 Apr 2018 11:29:19 PM CST
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include "database.h"
using namespace std;

Cdatabase::Cdatabase()
{
    head=NULL;
    database * head_temp=head;
    //FILE * fp_in = fopen("Cdatabase.txt","r");  //to open Cdatabase.txt 

	ifstream in_file("Cdatabase.txt", ios::in);
	if (!in_file)
		cerr << "failed to read" << endl;
    while(!in_file.eof())
    {
        database * temp = new database;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            //fscanf(fp_in,"%s\t%s",temp->tablename,temp->file);
            head_temp=temp;
			in_file >> temp->tablename >> temp->file;
        }
        else
        {
            while(head_temp->next!=NULL)
                head_temp=head_temp->next;
            head_temp->next=temp;
            head_temp=temp;
			in_file >> temp->tablename >> temp->file;
            //fscanf(fp_in,"%s\t%s",temp->tablename,temp->file);
        }
    }
	in_file.close();
 
    database * temp = head;
    while(temp->next!=NULL)
    {
        temp->table.createtablefromfile(temp->file);
		temp = temp->next;
    }
    
    /*temp =head;
    while(temp->next!=NULL)
    {
        temp->table.printtable();
        temp=temp->next;
    }*/
    

    /*database * temp=head;
    while (temp!=NULL)
    {
        cout<<temp->tablename<<"\t";
        cout<<temp->file<<endl;
        temp=temp->next;
    }//*///debuginfo
}

void Cdatabase::createnewtablefromfile(string &command)
{
    stringstream ss;
    ss<<command;
    database * temp=head,* tempnew= new database;
    while(temp->next!=NULL)temp=temp->next;
    temp->next=tempnew;
    tempnew->next=NULL;
    string useless;
    string tablenametemp;
    string filetemp;
    ss>>useless;
    ss>>useless;
    ss>>tablenametemp;
    ss>>useless;
    ss>>filetemp;

    temp=head;
    while(temp!=NULL)
    {
        if(temp->file==filetemp||temp->tablename==tablenametemp)
        {
            cerr<<"repeated tablename or file"<<endl;
            return;
        }
        temp=temp->next;
    }

    tempnew->file=filetemp;
    tempnew->tablename=tablenametemp;
    tempnew->table.createtablefromfile(tempnew->file);
    tempnew->table.printtable();

    //done
    writeindatabasefile();
}

void Cdatabase::createnewtablefromcommand(string &command)
{
    stringstream ss;
    string useless,tablenametemp,filetemp,columngroup;
    ss<<command;
    ss>>useless;
    ss>>useless;
    ss>>tablenametemp;
    ss>>columngroup;
    ss>>useless;
    ss>>filetemp;
    database * temp=head,* tempnew=new database;
    while(temp->next!=NULL)temp=temp->next;
    temp->next=tempnew;
    tempnew->next=NULL;

    temp=head;
    while(temp!=NULL)
    {
        if(temp->file==filetemp||temp->tablename==tablenametemp)
        {
            cerr<<"repeated tablename or file"<<endl;
            return;
        }
        temp=temp->next;
    }

    tempnew->file=filetemp;
    tempnew->tablename=tablenametemp;
    tempnew->table.createtablefromcommand(tempnew->file,columngroup);
    tempnew->table.printtable();

    writeindatabasefile();
}

void Cdatabase::writeindatabasefile()
{
    ofstream out_file("Cdatabase.txt",ios::out);
    if(!out_file)
    {
        cerr<<"failed to open file"<<endl;
        return;
    }
    database * temp=head;
    while(temp!=NULL)
    {
        if(temp->tablename.length()!=0)
            out_file<<temp->tablename<<'\t'<<temp->file<<'\n';
        temp=temp->next;
    }
    out_file.close();
}

void Cdatabase::dropatable(string &command)
{
    stringstream ss;
    ss<<command;
    database * temp=head;
    string useless,tablenametemp;
    ss>>useless;
    ss>>useless;
    ss>>tablenametemp;
    while(temp!=NULL)
    {
        if(tablenametemp==temp->tablename)
            break;
        else
        temp=temp->next;
    }
    if(temp==NULL)
    {
        cerr<<"failed to find the table"<<endl;
        return;
    }

    if(temp==head)
    {
        head=temp->next;
        delete temp;
    }
    else
    {
        database * temp2=head;
        while(temp2->next!=temp)temp2=temp2->next;
        temp2->next=temp->next;
        delete temp;
    }

    writeindatabasefile();
}

void Cdatabase::tablelist()
{
    database * temp=head;
    int total=0;
    while(temp!=NULL)
    {
        if(temp->tablename.length()!=0)
            total++;
        temp=temp->next;
    }
    cout<<"total:"<<total<<endl;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->tablename.length()!=0)
        {
            cout<<'\t'<<temp->tablename<<':';
            temp->table.printtableinfo();
            cout<<'\n';
        }
        temp=temp->next;
    }
}

void Cdatabase::deletealltable(string &command)
{
    stringstream ss;
    ss<<command;
    database * temp = head;
    string useless,tablenametemp;
    ss>>useless;
    ss>>useless;
    ss>>useless;
    ss>>tablenametemp;
    while(temp!=NULL)
    {
        if(tablenametemp==temp->tablename)
            break;
        else
            temp=temp->next;
    }
    if(temp==NULL)
    {
        cerr<<"no table you need"<<endl;
        return;
    }
    temp->table.deletealltable();
    temp->table.writeinfile(temp->file);
    temp->table.printtable();
}

void Cdatabase::deletesomeline(string &command)
{
    stringstream ss;
    ss<<command;
    database * temp =head;
    string useless,tablenametemp,wherecommand;
    ss>>useless;
    ss>>useless;
    ss>>tablenametemp;
    ss>>useless;
    ss>>wherecommand;
    while(temp!=NULL)
    {
        if(tablenametemp==temp->tablename)
            break;
        else
            temp=temp->next;
    }
    if(temp==NULL)
    {
        cerr<<"no table you need"<<endl;
        return;
    }
    temp->table.deletesomeline(wherecommand);
    temp->table.writeinfile(temp->file);
    temp->table.printtable();
}

void Cdatabase::selecttable(string &command)
{
    stringstream ss;
    ss<<command;
    database * tempp=head;
    string useless,temp,columnname,tablenametemp,ordercolumn,wherecommand,filecommand;
    int distinct=0,order=0,where=0,tofile=0;
    ss>>useless;
    ss>>temp;
    if(temp=="DISTINCT")
    {
        distinct=1;
        ss>>temp;
    }
    columnname=temp;
    ss>>useless;
    ss>>tablenametemp;
    temp="";
    ss>>temp;
    while(temp!="")
    {
        if(temp=="ORDER")
        {
            ss>>useless;
            ss>>ordercolumn;
            ss>>temp;
            if(temp=="ASC")//sheng_xv
                order=1;
            if(temp=="DESC")//jiang_xv
                order=2;
            temp="";
            ss>>temp;
        }
        else if(temp=="WHERE")
        {
            ss>>wherecommand;
            where=1;
            temp="";
            ss>>temp;
        }
        else if(temp=="TO")
        {
            ss>>filecommand;
            tofile=1;
            temp="";
            ss>>temp;
        }
    }
    while(tempp!=NULL)
    {
        if(tablenametemp==tempp->tablename)
            break;
        else
            tempp=tempp->next;
    }
    if(tempp==NULL)
    {
        cerr<<"failed to find the tablename"<<endl;
        return;
    }
    tempp->table.selecttable(columnname,ordercolumn,wherecommand,filecommand,distinct,order,where,tofile);
}

void Cdatabase::insertafullline(string &command)
{
    stringstream ss;
    ss<<command;
    database * temp=head;
    string useless,tablenametemp,values;
    ss>>useless;
    ss>>useless;
    ss>>tablenametemp;
    ss>>useless;
    ss>>values;
    while(temp!=NULL)
    {
        if(tablenametemp==temp->tablename)
            break;
        else
            temp=temp->next;
    }
    if(temp==NULL)
    {
        cerr<<"fail to find the tablename"<<endl;
        return;
    }
    
    //done
    temp->table.insertafullline(values);
    temp->table.writeinfile(temp->file);
    temp->table.printtable();
}

void Cdatabase::insertaline(string &command)
{
    stringstream ss;
    ss<<command;
    database * temp=head;
    string useless,tablenametemp,columns,values;
    ss>>useless;
    ss>>useless;
    ss>>tablenametemp;
    ss>>columns;
    ss>>useless;
    ss>>values;
    while(temp!=NULL)
    {
        if(tablenametemp==temp->tablename)
            break;
        else
            temp=temp->next;
    }
    if(temp==NULL)
    {
        cerr<<"failed to find the table"<<endl;
        return;
    }

    //done
    temp->table.insertaline(columns,values);
    temp->table.writeinfile(temp->file);
    temp->table.printtable();
}

void Cdatabase::updateallline(string &command)
{
    stringstream ss;
    ss<<command;
    database * temp=head;
    string tablenametemp,valueschange[10],useless;
    ss>>useless;
    ss>>tablenametemp;
    ss>>useless;
    for(int i=0;i<10;i++)
        ss>>valueschange[i];
    while(temp!=NULL)
    {
        if(tablenametemp==temp->tablename)
            break;
        else
            temp=temp->next;
    }
    if(temp==NULL)
    {
        cerr<<"failed to find the table"<<endl;
        return;
    }
    //done
    for(int i=0;i<10;i++)
    {
        if(valueschange[i].length()==0)continue;
        temp->table.updateallline(valueschange[i]);
    }
    //temp->table.updateallline(valueschange[10]);
    temp->table.writeinfile(temp->file);
    temp->table.printtable();
}

void Cdatabase::updatesomeline(string &command)
{
    stringstream ss;
    ss<<command;
    database * temp = head;
    string tablenametemp,useless,valueschange[10],columnname,temptowhere;
    ss>>useless;
    ss>>tablenametemp;
    ss>>useless;
    while(temp!=NULL)
    {
        if(tablenametemp==temp->tablename)
            break;
        else
            temp=temp->next;
    }
    if(temp==NULL)
    {
        cerr<<"failed to find the table"<<endl;
        return;
    }
    //ss>>useless;
    //ss>>tablenametemp;
    //ss>>useless;
    for(int i=0;i<=10;i++)
    {
        ss>>temptowhere;
        if(temptowhere=="WHERE")break;
        valueschange[i]=temptowhere;
    }
    ss>>columnname;
    for(int i =0;i<10;i++)
    {
        if(valueschange[i].length()==0)continue;
        temp->table.updatesomeline(valueschange[i],columnname);
    }
    temp->table.writeinfile(temp->file);
    temp->table.printtable();
}
