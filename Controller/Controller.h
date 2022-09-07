#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <vector>
#include "Rent.h"
#include "Book.h"
#include "Copy.h"
#include "Member.h"

#pragma once
class Controller
{
public:
	Book book;
	Copy copy;
	Member member;
	vector<Member>MemberVector;
	vector<Book>BookVector;
	vector<Rent>RentHistory;
public:
	Controller();


};

#endif
