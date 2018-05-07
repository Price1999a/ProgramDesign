/*************************************************************************
	> File Name: database.h
	> Author:Shen Tianqi 
	> Mail: 
	> Created Time: Mon 23 Apr 2018 11:27:05 PM CST
 ************************************************************************/

#ifndef _DATABASE_H
#define _DATABASE_H
#include "struct.h"

class Cdatabase
{
private:
    database * head;
public:
    Cdatabase();
    void createnewtablefromfile(string &);
    void createnewtablefromcommand(string &);
    static Cdatabase * getglobledatabase()
    {
        static Cdatabase globledatabase;
        return &globledatabase;
    }
    void writeindatabasefile();
    void dropatable(string &);
    void tablelist();
    void deletealltable(string &);
    void deletesomeline(string &);
    void selecttable(string &);
    void insertafullline(string &);
    void insertaline(string &);
    void updateallline(string &);
    void updatesomeline(string &);
};

#endif
