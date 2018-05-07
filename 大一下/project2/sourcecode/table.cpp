/*************************************************************************
	> File Name: table.cpp
	> Author: Shen Tianqi
	> Mail: 
	> Created Time: Mon 23 Apr 2018 11:21:54 PM CST
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<sstream>
#include "table.h"

using namespace std;

void Ctable::createtablefromfile(string &file)
{
    ifstream in_file(file.c_str(),ios::in);
    if(!in_file)
    {  
        cerr<<"fail to open"<<endl;
        cerr<<"check your command again"<<endl;
        return;
    }
    int linenum=0;
    while(!in_file.eof())
    {
        string templine;
        getline(in_file,templine);
        stringstream ss;
        ss<<templine;
        for(int columnnum=0;columnnum<10;columnnum++)
        {
            ss>>table[columnnum][linenum];
        }
        linenum++;
    }
    in_file.close();
}

void Ctable::createtablefromcommand(string &file,string &columngroup)
{
    ofstream out_file(file.c_str(),ios::out);
    if(!out_file)
    {
        cerr<<"failed to open file"<<endl;
        return;
    }
    columngroup.erase(columngroup.begin());
    columngroup.erase(columngroup.end()-1);
    int pos=0;
    while((pos=columngroup.find(",",pos))!=string::npos)
    {
        columngroup.erase(pos,1);
        columngroup.insert(pos," ");
        pos++;
    }
    stringstream ss;
    ss<<columngroup;
    for(int columnnum=0;columnnum<10;columnnum++)
    {
        ss>>table[columnnum][0];
        out_file<<table[columnnum][0]<<'\t';
    }
    out_file<<'\n';
    out_file.close();
}

void Ctable::insertafullline(string &values)
{
    stringstream ss;
    values.erase(values.begin());
    values.erase(values.end()-1);
    int pos=0;
    while((pos=values.find(",",pos))!=string::npos)
    {
        values.erase(pos,1);
        values.insert(pos," ");
        pos++;
    }
    ss<<values;
    for(int linenum=1;linenum<=500;linenum++)
    {
        if(isthelineempty(linenum)!=true)continue;
        for(int columnnum=0;columnnum<10;columnnum++)
        {
            ss>>table[columnnum][linenum];
            if(table[columnnum][linenum]=="")
            table[columnnum][linenum]=="_EMPTY_";
        }
    }
}

void Ctable::insertaline(string &columns,string &values)
{
   stringstream ssc,ssv;
    columns.erase(columns.begin());
    columns.erase(columns.end()-1);
    values.erase(values.begin());
    values.erase(values.end()-1);
    int pos=0;
    while((pos=values.find(",",pos))!=string::npos)
    {
        values.erase(pos,1);
        values.insert(pos," ");
        pos++;
    }
    pos=0;
    while((pos=columns.find(",",pos))!=string::npos)
    {
        columns.erase(pos,1);
        columns.insert(pos," ");
        pos++;
    }
    ssc<<columns;
    ssv<<values;
    string temp[2][10];
    for(int i=0;i<10;i++)
    {
        ssc>>temp[0][i];
        ssv>>temp[1][i];
    }
    for(int i=0;i<10;i++)//check the column
    {
        if(temp[0][i].length()==0)continue;
        bool flag=false;
        for(int j=0;j<10;j++)
        {
            if(table[j][0]==temp[0][i])
                flag=true;
        }
        if(flag==false)
        {
            cerr<<"failed to find the column"<<endl;
            return;
        }
    }
    int emptyline=1;
    while(isthelineempty(emptyline)!=true)emptyline++;
    for(int i=0;i<10;i++)
    {
        if(temp[0][i].length()==0)continue;
        for(int j=0;j<10;j++)
        {
            if(temp[0][i]==table[j][0])
            {
                table[j][emptyline]=temp[1][i];
            }
        }
    }
    for(int i=0;i<10;i++)
    {
        if(table[i][0].length()!=0&&table[i][emptyline].length()==0)
        table[i][emptyline]="_EMPTY_";
    }
}

int howmanytab(int);

void Ctable::printtable()
{
    int strlength[10]={0};
    for(int columnnum=0;columnnum<10;columnnum++)
        for(int linenum=0;linenum<=500;linenum++)
        {
            if(table[columnnum][linenum].length()>strlength[columnnum])
                strlength[columnnum]=table[columnnum][linenum].length();
        }

    int i_i=0;
    for(int linenum=0;linenum<=500;linenum++)
    {
        if(isthelineempty(linenum)==true)continue;
        for(int columnnum=0;columnnum<10;columnnum++)
        {
            if(columnnum==0)
            { 
                if(linenum==0)cout<<"ID\t";
                else cout<<i_i<<"\t";
                i_i++;
            }
            if(table[columnnum][linenum]=="_EMPTY_")
                cout<<"       ";
            else
                cout<<table[columnnum][linenum];
            for(int i=0;i<=(howmanytab(strlength[columnnum])-howmanytab(table[columnnum][linenum].length()));i++)
                cout<<'\t';
            //if(howmanytab(strlength[columnnum])==howmanytab(table[columnnum][linenum].length()))
               // cout<<'\t';
        }
        cout<<endl;
    }
}

int howmanytab(int n)
{
    int ans=n/8;
    //if(n%8!=0)
        //ans++;
    return ans;
}

bool Ctable::isthelineempty(int linenum)
{
    bool flag = true;
    for(int columnnum=0;columnnum<10;columnnum++)
    {
        if(table[columnnum][linenum].length()!=0)
        flag=false;
    }

    return flag;
}

void Ctable::printtableinfo()
{
    int columnnum=0,linenum=0;
    for(int i=0;i<10;i++)
    {
        if(table[i][0].length()!=0)
            columnnum++;
    }
    
    for(int i=1;i<=500;i++)
    {
        if(isthelineempty(i)==true)
            continue;
        linenum++;
    }
    cout<<'('<<columnnum<<','<<linenum<<')';
    cout<<'[';
    for(int i = 0;i<columnnum;i++)
    {
        if(i==0);
        else
            cout<<',';
        cout<<table[i][0];
    }
    cout<<']';
}

void Ctable::deletealltable()
{
    for(int linenum=1;linenum<=500;linenum++)
        for(int columnnum=0;columnnum<10;columnnum++)
            table[columnnum][linenum]="";
}

void Ctable::deletesomeline(string &wherecommand)
{
    stringstream ss;
    int pos=0;
    while((pos=wherecommand.find("=",pos))!=string::npos)
    {
        wherecommand.erase(pos,1);
        wherecommand.insert(pos," ");
        pos++;
    }
    ss<<wherecommand;
    string columns,values;
    ss>>columns;
    ss>>values;
    for(int i=0;i<10;i++)
    {
        if(table[i][0]==columns)
        {
            for(int j=1;j<=500;j++)
            {
                if(table[i][j]==values)
                    for(int i_i=0;i_i<10;i_i++)
                        table[i_i][j]="";
                else
                continue;
            }
        }
    }
}

void Ctable::updateallline(string &valueschange)
{
    //for(int i_=0;i_<10;i_++)
    //{
        //if(valueschange.length()==0)continue;
        stringstream ss;
        //valueschange.erase(valueschange.end()-1);
        int pos=0;
        while((pos=valueschange.find("=",pos))!=string::npos)
        {
            valueschange.erase(pos,1);
            valueschange.insert(pos," ");
            pos++;
        }
        pos=0;
        while((pos=valueschange.find(",",pos))!=string::npos)
        {
            valueschange.erase(pos,1);
            pos++;
        }
        ss<<valueschange;
        string columni,valuei;
        ss>>columni;
        ss>>valuei;
        for(int i=0;i<10;i++)
        {
            if(table[i][0]==columni)
            {
                for(int j=1;j<=500;j++)
                {
                    if(isthelineempty(j)==true)continue;
                    table[i][j]=valuei;
                }
            }
        }
    //}
}

void Ctable::selecttable(string &columnname,string &ordercolumn,string &wherecommand,string &filecommand,int distinct,int order,int where,int tofile)
{
    int pos=0;
    while((pos=columnname.find(",",pos))!=string::npos)
    {
        columnname.erase(pos,1);
        columnname.insert(pos," ");
        pos++;
    }
    string columnneed[10],tableselect[10][501];
    stringstream ss;
    ss<<columnname;
    for(int i=0;i<10;i++)
        ss>>columnneed[i];
    if(columnneed[0]=="*")
    {
        for(int i=0;i<10;i++)
            for(int j=0;j<=500;j++)
                tableselect[i][j]=table[i][j];
    }
    else
    {
        for(int i_=0;i_<10;i_++)
        {
            if(columnneed[i_].length()==0)continue;
            for(int i=0;i<10;i++)
            {
                if(table[i][0]==columnneed[i_])
                    for(int j=0;j<=500;j++)
                        tableselect[i_][j]=table[i][j];
            }
        }
    }
    if(distinct==1)//delete the same line
    {
        bool flag=true;
        for(int i=0;i<500;i++)
        {
            bool f=true;
            for(int temp=0;temp<10;temp++)
                if(tableselect[temp][i].length()!=0)
                    f=false;
            if(f==true)
                continue;
            for(int j=i+1;j<=500;j++)
            {
                f=true;
                for(int temp=0;temp<10;temp++)
                    if(tableselect[temp][j].length()!=0)
                        f=false;
                if(f==true)
                    continue;
                flag=true;
                for(int temp=0;temp<10;temp++)
                    if(tableselect[temp][i]!=tableselect[temp][j])
                        flag=false;
                if(flag==true)
                    for(int temp=0;temp<10;temp++)
                        tableselect[temp][j]="";
            }
        }
    }
    if(where==1)
    {
        stringstream ssw;
        pos=0;
        while((pos=wherecommand.find("=",pos))!=string::npos)
        {
            wherecommand.erase(pos,1);
            wherecommand.insert(pos," ");
            pos++;
        }
        string columni,valuei;
        ssw<<wherecommand;
        ssw>>columni;
        ssw>>valuei;
        for(int i=0;i<10;i++)
        {
            if(tableselect[i][0]==columni)
                for(int j =1;j<=500;j++)
                    if(tableselect[i][j]==valuei)continue;
                    else
                    {
                        for(int temp=0;temp<10;temp++)
                            tableselect[temp][j]="";
                    }
        }
    }
    if(order!=0)
    {
        if(order==1)//sheng_xv
        {
            stringstream sso;
            pos=0;
            while((pos=ordercolumn.find(",",pos))!=string::npos)
            {
                ordercolumn.erase(pos,1);
                ordercolumn.insert(pos," ");
                pos++;
            }
			sso << ordercolumn;
            string ordertemp[10];
            for(int i=0;i<10;i++)
                sso>>ordertemp[i];
            for(int i=10;i>=0;i--)
            {
                if(ordertemp[i].length()==0)continue;
                for(int i_=0;i_<10;i_++)
                {
                    if(tableselect[i_][0]==ordertemp[i])
                    {
                        for(int i1=1;i1<=500;i1++)
                        for(int j1=500;i1<j1;j1--)
                        {
                            bool f=true;
                            for(int temp=0;temp<10;temp++)
                                if(tableselect[temp][j1].length()!=0)
                                    f=false;
                            if(f==true)
                                continue;
                            
                            if(tableselect[i_][j1]<tableselect[i_][j1-1])
                            {
                                string temp1;
                                for(int temp=0;temp<10;temp++)
                                {
                                    temp1=tableselect[temp][j1];
                                    tableselect[temp][j1]=tableselect[temp][j1-1];
                                    tableselect[temp][j1-1]=temp1;
                                }
                            }
                        }
                    }
                }
            }
        }
        else if(order==2)//jiang_xv
        {
            stringstream sso;
            pos=0;
            while((pos=ordercolumn.find(",",pos))!=string::npos)
            {
                ordercolumn.erase(pos,1);
                ordercolumn.insert(pos," ");
                pos++;
            }
			sso << ordercolumn;
            string ordertemp[10];
            for(int i=0;i<10;i++)
                sso>>ordertemp[i];
            for(int i=10;i>=0;i--)
            {
                if(ordertemp[i].length()==0)continue;
                for(int i_=0;i_<10;i_++)
                {
                    if(tableselect[i_][0]==ordertemp[i])
                    {
                        for(int i1=1;i1<=500;i1++)
                        for(int j1=500;i1<j1;j1--)
                        {
                            bool f=true;
                            for(int temp=0;temp<10;temp++)
                                if(tableselect[temp][j1].length()!=0)
                                    f=false;
                            if(f==true)
                                continue;
                            
                            if(tableselect[i_][j1]>tableselect[i_][j1-1])
                            {
                                string temp1;
                                for(int temp=0;temp<10;temp++)
                                {
                                    temp1=tableselect[temp][j1];
                                    tableselect[temp][j1]=tableselect[temp][j1-1];
                                    tableselect[temp][j1-1]=temp1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(tofile==1)
    {
        ofstream out_file(filecommand.c_str(),ios::out);
        if(!out_file)
        {
            cerr<<"unexpected wrong, check the filesystem, and try to connect the author"<<endl;
            return;
        }
        for(int linenum=0;linenum<=500;linenum++)
        {
            bool f=true;
            for(int temp=0;temp<10;temp++)
                if(tableselect[temp][linenum].length()!=0)
                    f=false;
            if(f==true)
            continue;
            for(int columnnum=0;columnnum<10;columnnum++)
            {
                if(tableselect[columnnum][linenum].length()==0&&tableselect[columnnum][0].length()==0)
                    continue;
                if(tableselect[columnnum][linenum].length()==0&&tableselect[columnnum][0].length()!=0)
                    tableselect[columnnum][linenum]="_EMPTY_";
                out_file<<tableselect[columnnum][linenum]<<'\t';
            }
            out_file<<'\n';
        }
        out_file.close();
    }

    int strlength[10]={0};
    for(int columnnum=0;columnnum<10;columnnum++)
        for(int linenum=0;linenum<=500;linenum++)
        {
            if(tableselect[columnnum][linenum].length()>strlength[columnnum])
                strlength[columnnum]=tableselect[columnnum][linenum].length();
        }

    int i_i=0;
    for(int linenum=0;linenum<=500;linenum++)
    {
        bool f=true;
        for(int temp=0;temp<10;temp++)
            if(tableselect[temp][linenum].length()!=0)
                f=false;
		if (f == true)
			continue;
        
        for(int columnnum=0;columnnum<10;columnnum++)
        {
            if(columnnum==0)
            { 
                if(linenum==0)cout<<"ID\t";
                else cout<<i_i<<"\t";
                i_i++;
            }
            if(tableselect[columnnum][linenum]=="_EMPTY_")
                cout<<"       ";
            else
                cout<<tableselect[columnnum][linenum];
            for(int i=0;i<=(strlength[columnnum]/8-tableselect[columnnum][linenum].length()/8);i++)
                cout<<'\t';
            //if(howmanytab(strlength[columnnum])==howmanytab(table[columnnum][linenum].length()))
               // cout<<'\t';
        }
        cout<<endl;
    }
}

void Ctable::updatesomeline(string &valueschange,string &columnname)
{
    int pos=0;
    stringstream ssv,ssc;
    string columni,valuei,columnnamei,valuenamei;
    while((pos=valueschange.find("=",pos))!=string::npos)
    {
        valueschange.erase(pos,1);
        valueschange.insert(pos," ");
        pos++;
    }
    pos=0;
    while((pos=valueschange.find(",",pos))!=string::npos)
    {
        valueschange.erase(pos,1);
        pos++;
    }
    pos=0;
    while((pos=columnname.find("=",pos))!=string::npos)
    {
        columnname.erase(pos,1);
        columnname.insert(pos," ");
        pos++;
    }
    ssc<<columnname;
    ssv<<valueschange;
    ssc>>columnnamei;
    ssc>>valuenamei;
    ssv>>columni;
    ssv>>valuei;
    int columnnum=0;
    for(columnnum;columnnum<10;columnnum++)
        if(table[columnnum][0]==columnnamei)
            break;
    for(int i=0;i<10;i++)
    {
        if(table[i][0]==columni)
        {
            for(int j=1;j<=500;j++)
            {
                if(isthelineempty(j)==true)continue;
                if(table[columnnum][j]==valuenamei)
                    table[i][j]=valuei;
            }
        }
    }
}

void Ctable::writeinfile(string &file)
{
    ofstream out_file(file.c_str(),ios::out);
    if(!out_file)
    {
        cerr<<"unexpected wrong, check the filesystem"<<endl;
        return;
    }
    for(int linenum=0;linenum<=500;linenum++)
    {
        if(isthelineempty(linenum)==true)continue;
        for(int columnnum=0;columnnum<10;columnnum++)
        {
            if(table[columnnum][linenum].length()==0&&table[columnnum][0].length()==0)continue;
            if(table[columnnum][linenum].length()==0&&table[columnnum][0].length()!=0)
                table[columnnum][linenum]="_EMPTY_";
            out_file<<table[columnnum][linenum]<<'\t';
        }
        out_file<<'\n';
    }
    out_file.close();
}
