#include "Member.h"
#include <iostream>

using namespace std;

void Member::rentCheck()
{
	if (max_copies > 1)
	{
		cout << "Max copies rented " << endl;
	}
}

void Member::rentCopy(Copy _copy)
{
	if (max_copies == 1)
	{
		cout << "Copies rented limit , maximum :1" << endl;
	}

	if (max_copies == 0)
	{
		rented_copies.push_back(_copy);
		max_copies = 1;
	}
}


Copy Member::returnCopy()
{
	if (max_copies == 1)
	{
		copy = rented_copies[0];
		return copy;
	}
	if (max_copies == 0)
	{
		cout << "No copies to return " << endl;
	}
}
