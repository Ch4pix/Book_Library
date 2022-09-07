#ifndef MEMBERVIP_H
#define MEMBERVIP_H


#pragma once
#include "Member.h"

class MemberVip :
	public Member
{
public:
	string name;
	string last_name;
	string vip = "vip";
	int id;
	vector <Copy>rented_copies;
	int max_copies = 0;

public:
	void rentCheck();
	void rentCopy(Copy _copy);
	Copy returnCopy(Copy _copy);

};
#endif;


