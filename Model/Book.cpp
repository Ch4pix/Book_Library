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

void Book::searchCopyList(Book book)
{
	for (int i = 0; i < book.copy_list.size(); i++)
	{
		if (book.copy_list[i].location == "Rented")
		{
			cout << "Copy edition number: " << book.copy_list[i].edition_id << " //UNAVAILABLE " << endl;
		}
		if (book.copy_list[i].location == "Library")
		{
			cout << "Copy edition number: " << book.copy_list[i].edition_id << " //AVAILABLE " << endl;
		}
	}
}
void Book::retireCopy(Copy _copy, Member _member)
{
	Copy copy1;
	copy1 = _copy;
	if (_member.max_copies == 0)
	{
		for (int i = 0; i < copy_list.size(); i++)
		{
			if (copy_list[i].edition_id == copy1.edition_id && copy_list[i].location == "Rented")
			{
				cout << "The copy of the book is rented.\n";
			}
			if (copy_list[i].edition_id == copy1.edition_id && copy_list[i].location == "Library")
			{
				copy_list[i].location = "Rented";
			}
		}
	}
	if (_member.max_copies == 1)
	{
		cout << "Maximum copies rented reached." << endl;
	}
}

void Book::returnCopy(Copy _copy)
{
	for (int i = 0; i < copy_list.size(); i++)
	{
		if (copy_list[i].edition_id == _copy.edition_id)
		{
			copy_list[i].location = "Biblioteca";
		}
	}
}
