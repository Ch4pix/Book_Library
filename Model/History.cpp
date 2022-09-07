#include "History.h"

History::History()
{
}

void History::setRentVec(Rent _rent)
{
	RentVec.push_back(_rent);
}

vector<Rent>History::retHistory()
{
	return RentVec;
}
