#ifndef LIBRERIA_H
#define LIBRERIA_H
#include "Book.h"
#include "Member.h"
#pragma once
class Rent
{
public:
	Book abook;
	Member member;
public:
	Rent();
	void setMember(Member _member);
	void setRBook(Book  _book);
};
#endif

