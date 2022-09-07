#include "Menu.h"
#include "Book.h"
#include "Copy.h"
#include "Member.h"
#include "MemberVip.h"
#include "Rent.h"
#include "History.h"
#include "Controller.h"
#include "Enum.h"

#include<string>
#include <iostream>


using namespace std;

Menu::Menu()
{
}

void Menu::MenuRun()
{



	Enum ennum;
	History renthistory;
	Controller controller;
	int opc;
	int x = 1;
	while (x != 0)
	{
	Menu:
		cout << "Book Library" << endl;
		cout << "------------" << endl;
		cout << "Please select an option: " << endl;
		cout << "1: Add book to Library" << endl;
		cout << "2: Add Member" << endl;
		cout << "3: List Available books and copies" << endl;
		cout << "4: Rent book" << endl;
		cout << "5: Add copy to book" << endl;
		cout << "6: History of rents" << endl;
		cout << "7: Return book" << endl;
		cout << "0: Exit" << endl;
		cin >> opc;
		switch (opc)
		{
		case ennum.Add_book:
		{
			cout << "Please enter book's name: " << endl;
			cin >> controller.book.book_name;
			cout << "Please enter book's isbn: " << endl;
			cin >> controller.book.isbn;
			cout << "Please enter book's author " << endl;
			cin >> controller.book.author;
			cout << "Please enter book's copy number" << endl;
			cin >> controller.copy.edition_id;
			controller.copy.location = "Library";
			controller.book.addToCopyList(controller.copy);
			// adds the book to the list of books
			controller.BookVector.push_back(controller.book);
			break;
		}
		case ennum.Add_member:
		{
			// adds members to membervector
			Member member_obj;
			Member membervip_obj;
			int membership;

			cout << "Choose membership" << endl;
			cout << "1: Vip : Max copies = 3" << endl;
			cout << "2: Normal : Max copies = 1" << endl;
			cin >> membership;
			if (membership == 1)
			{
				controller.member.vip = "vip";
				cout << "Please enter new member's name " << endl;
				cin >> controller.member.name;
				cout << "Please enter new member's last name " << endl;
				cin >> controller.member.last_name;
				cout << "Please enter new member's id " << endl;
				cin >> controller.member.id;
				controller.MemberVector.push_back(controller.member);
			}
			if (membership == 2)
			{
				cout << "Please enter new member's name " << endl;
				cin >> controller.member.name;
				cout << "Please enter new member's last name " << endl;
				cin >> controller.member.last_name;
				cout << "Please enter new member's id " << endl;
				cin >> controller.member.id;
				controller.MemberVector.push_back(controller.member);
			}
			break;
		}
		case ennum.List_books:
		{
			//print available books and its copies with information.
			for (int i = 0; i < controller.BookVector.size(); i++)
			{
				cout << "------------" << endl;
				cout << "Book's Name: " << controller.BookVector[i].book_name << endl;
				cout << "Book's Author: " << controller.BookVector[i].author << endl;
				cout << "Book's isbn: " << controller.BookVector[i].isbn << endl;
				for (int j = 0; j < controller.BookVector[i].copy_list.size(); j++)
				{

					cout << " --> copy : " << controller.BookVector[i].copy_list[j].edition_id << endl;
					cout << "        " << controller.BookVector[i].copy_list[j].location << endl;
				}
				cout << "------------" << endl;
			}
			break;
		}
		case ennum.Rent_book:
		{
		StartRent:
			cout << "Please enter the book to rent" << endl;
			cout << "------------" << endl;
			cout << "Back to menu press /" << endl;

			//this should be controller - sends book to construct object rent
			string book_name;
			cin >> book_name;

			if (book_name == "/")
			{
				goto Menu;
			}

			cout << "Please enter your member id " << endl;
			int mid;
			cin >> mid;
			Rent rent;
			int rent_check = 0;
			int memb_check = 0;
			int a = 1;
			while (a != 0)
			{
				for (int i = 0; i < controller.MemberVector.size(); i++)
				{
					if (mid == controller.MemberVector[i].id)
					{
						if (controller.MemberVector[i].vip == "vip")
						{
							//sets the member in vector copies = 3
							if (controller.MemberVector[i].max_copies == 3)
							{
								cout << "Maximum rented copies reached." << endl;
								goto StartRent;
								a = 0;
							}
							// sets the member in vector rented copies = 1
							controller.MemberVector[i].max_copies++;
							rent.setMember(controller.MemberVector[i]);
						}
						if (controller.MemberVector[i].vip == "novip")
						{
							if (controller.MemberVector[i].max_copies == 1)
							{
								cout << "Maximum rented copies reached." << endl;
								goto StartRent;
								a = 0;
							}
							// sets the member in vector rented copies = 1
							controller.MemberVector[i].max_copies = 1;
							rent.setMember(controller.MemberVector[i]);
						}
					}
					if (mid != controller.MemberVector[i].id)
					{
						memb_check++;
						if (memb_check == controller.MemberVector.size())
						{
							cout << "Member id not registered" << endl;
							a = 0;
							goto StartRent;
						}
					}


					a = 0;
				}

			}

			for (int i = 0; i < controller.BookVector.size(); i++)
			{
				if (book_name == controller.BookVector[i].book_name)
				{
					for (int a = 0; a < controller.BookVector[i].copy_list.size(); a++)
					{
						cout << "entered copies for" << endl;

						if (controller.BookVector[i].copy_list[a].location == "Rented")
						{
							rent_check++;
							if (rent_check == controller.BookVector[i].copy_list.size())
							{
								cout << "No copies available" << endl;
								break;
							}
						}
						if (controller.BookVector[i].copy_list[a].location == "Library")
						{
							cout << "The book is available " << endl;
							Book book;
							book = controller.BookVector[i];
							book.copy = controller.BookVector[i].copy_list[a].edition_id;
							controller.BookVector[i].copy_list[a].location = "Rented";
							rent.setRBook(book);
							// sends member to construct object rent
							//this should be controller

							//test printing object rent
							cout << endl;
							cout << rent.member.name << endl;
							cout << rent.member.last_name << endl;
							cout << rent.member.id << endl;
							cout << "-------------\n";
							cout << rent.abook.book_name << endl;
							cout << rent.abook.author << endl;
							cout << rent.abook.isbn << endl;
							cout << rent.abook.copy << endl;
							break;
						}
					}

				}
			}
			controller.RentHistory.push_back(rent);
			break;
		}
		case ennum.Add_copy:
		{
			cout << "Which book to add copy?";
			string book_name;
			cin >> book_name;
			cout << "Please add copy number";
			Copy copy_number;
			cin >> copy_number.edition_id;
			for (int i = 0; i < controller.BookVector.size(); i++)
			{
				if (book_name == controller.BookVector[i].book_name)
				{
					controller.BookVector[i].addToCopyList(copy_number);
				}
			}
			break;
		}
		case ennum.History:
		{
			for (int i = 0; i < controller.RentHistory.size(); i++)
			{
				cout << "\n";
				cout << "Book name: " << controller.RentHistory[i].abook.book_name << endl;
				cout << "--> Copy: " << controller.RentHistory[i].abook.copy << endl;
				cout << "--> Author: " << controller.RentHistory[i].abook.author << endl;
				cout << "--> ISBN " << controller.RentHistory[i].abook.isbn << endl;
				cout << "-------------\n";
				cout << "Member name: " << controller.RentHistory[i].member.name << endl;
				cout << "Member last name: " << controller.RentHistory[i].member.last_name << endl;
				cout << "Member id: " << controller.RentHistory[i].member.id << endl;
			}
			break;
		}
		case ennum.Return_book:
		{
			cout << "Please enter the book to return" << endl;
			string book_name;
			int member_id;
			cin >> book_name;
			cout << "Please enter your member id" << endl;
			cin >> member_id;
			for (int i = 0; i < controller.BookVector.size(); i++)
			{
				if (book_name == controller.BookVector[i].book_name)
				{
					for (int a = 0; a < controller.BookVector[i].copy_list.size(); a++)
					{
						if (controller.BookVector[i].copy_list[a].location == "Rented")
						{
							controller.BookVector[i].copy_list[a].location = "Library";
							break;

						}
					}
				}
			}
			for (int i = 0; i < controller.MemberVector.size(); i++)
			{
				if (member_id == controller.MemberVector[i].id)
				{
					controller.MemberVector[i].max_copies--;
				}
			}
			break;
		}
		case ennum.Exit:
		{
			x = 0;
		}
		}
	}
}


