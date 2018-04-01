#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Commodity
{
	char id[5];
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