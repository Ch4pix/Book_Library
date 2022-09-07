#ifndef MEMBER_H
#define MEMBER_H
#include <vector>
#include <string>
#include "Copy.h"

using namespace std;


#pragma once

class Member
{
public:
	string name;
	string last_name;
	int id;
	string vip = "novip";
	vector <Copy>rented_copies;
	int max_copies = 0;
	Copy copy;
public:
	void rentCheck();
	void rentCopy(Copy _copy);
	Copy returnCopy();
};
#endif
