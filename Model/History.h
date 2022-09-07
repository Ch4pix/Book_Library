#ifndef HISTORY_H
#define HISTORY_H
#include "Rent.h"
#include <vector>

#pragma once

class History
{
public:
	vector<Rent>RentVec;

public:
	History();
	void setRentVec(Rent _rent);
	vector<Rent>retHistory();
};

#endif
