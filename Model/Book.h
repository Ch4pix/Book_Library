#ifndef BOOK_H
#define BOOK_H
#include <string>
#include<vector>
#include "Copy.h"
#include "Member.h"

#pragma once
using namespace std;

class Book
{
public:
	int copy;
	int isbn;
	vector<Copy>copy_list;
	string book_name;
	string author;
public:
	Book();
	void setBook(string _book_name, string _author, int _isbn);
	void addToCopyList(Copy _copy);
	void searchCopyList(Book book);
	void retireCopy(Copy _copy, Member _member);
	void returnCopy(Copy _copy);
};

#endif
