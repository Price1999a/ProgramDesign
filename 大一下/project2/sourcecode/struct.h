/*************************************************************************
	> File Name: struct.h
	> Author: Shen Tianqi
	> Mail: 
	> Created Time: Mon 23 Apr 2018 11:24:03 PM CST
 ************************************************************************/

#ifndef _STRUCT_H
#define _STRUCT_H
#include"table.h"
using namespace std;

struct database
{
    string tablename;
    string file;
    Ctable table;
    database * next;    
};

#endif
