#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <codecvt>
using namespace std;

struct Commodity
{
	char id[6];
	char name[40];
	char brand[40];
	float price;
	int number;
};

struct User
{
	char username[20];
	char password[20];
};

struct Soldlist
{
	Commodity soldcommodity;
	char uesrname[20];
};

class CTracker//≤‚ ‘”√
{
private:
	string a1;
public:
	CTracker(string a) {
		a1 = a;
		cout << "enter " << a1 << endl;
	}
	~CTracker() {
		cout << "leave " << a1 << endl;
	}
};
