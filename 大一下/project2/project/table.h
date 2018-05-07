/*************************************************************************
	> File Name: table.h
	> Author: Shen Tianqi
	> Mail: 
	> Created Time: Mon 23 Apr 2018 11:17:38 PM CST
 ************************************************************************/

#ifndef _TABLE_H
#define _TABLE_H
#include <string>
#define COLUMN 10
#define LENGTH_ 500

using namespace std;

class Ctable
{
    private:
    string table[COLUMN][LENGTH_+1];

    public:
    void createtablefromfile(string &file);
    void createtablefromcommand(string &,string &);
    void printtable();
    bool isthelineempty(int);
    void printtableinfo();
    void deletealltable();
    void deletesomeline(string &);
    void writeinfile(string &);
    void insertafullline(string &);
    void insertaline(string &,string &);
    void updateallline(string &a);
    void updatesomeline(string &,string &);
    void selecttable(string &,string &,string &,string &,int,int,int,int);
};

#endif
