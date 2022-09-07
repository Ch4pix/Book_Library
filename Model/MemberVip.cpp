#include "MemberVip.h"
#include <iostream>

using namespace std;

void MemberVip::rentCheck()
{
	if (max_copies > 3)
	{
		cout << "Max copies rented " << endl;
	}
}

void MemberVip::rentCopy(Copy _copy)
{
	if (max_copies == 3)
	{
		cout << "Copies rented limit , maximum :3" << endl;
	}

	if (max_copies >=0 && max_copies <	3)
	{
		rented_copies.push_back(_copy);
		max_copies++;
	}
}

Copy MemberVip::returnCopy(Copy _copy)
{
	for (int i = 0; i < rented_copies.size(); i++)
	{
		if (rented_copies[i].edition_id == _copy.edition_id)
		{
			return _copy;
		}
	}
	if (max_copies == 0)
	{
		cout << "No copies to return " << endl;
	}
}
