#include "Book.h"
#include "Rent.h"
#include "Copy.h"
#include <iostream>

using namespace std;

Book::Book()
{
}

void Book::setBook(string _book_name, string _author, int _isbn)
{
	book_name = _book_name;
	author = _author;
	isbn = _isbn;
}

void Book::addToCopyList(Copy _copy)
{
	copy_list.push_back(_copy);
}

