#include "Menu.h"
#include "Book.h"
#include "Copy.h"
#include "Member.h"
#include "MemberVip.h"
#include "Rent.h"
#include "History.h"
#include<string>
#include <iostream>


using namespace std;

Menu::Menu()
{
}

void Menu::MenuRun()
{
	//Copy copy1;
	//Copy copy2;
	//Member member1;
	//Book HarryPotter;
	//Copy copy3;
	//Copy copy4;
	//Book LOTR1;
	//copy1.edition_id = 123;
	//copy2.edition_id = 456;
	//copy3.edition_id = 777;
	//copy4.edition_id = 211;
	//LOTR1.book_name = "Lord of the ringusae";
	//HarryPotter.book_name = "Harry potter";



	vector<Member>MemberVector;
	vector<Book>BookVector;
	//Book bookdummy;
	//bookdummy.book_name = "//";
	//BookVector.push_back(bookdummy);
	vector<Rent>RentHistory;
	History renthistory;

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
		cout << "0: Exit" << endl;
		cin >> x;

		if (x == 1)
		{
			Book book_obj;
			Copy copy_x;
			cout << "Please enter book's name: " << endl;
			cin >> book_obj.book_name;
			cout << "Please enter book's isbn: " << endl;
			cin >> book_obj.isbn;
			cout << "Please enter book's author " << endl;
			cin >> book_obj.author;
			cout << "Please enter book's copy number" << endl;
			cin >> copy_x.edition_id;
			copy_x.location = "Library";
			book_obj.addToCopyList(copy_x);
			// adds the book to the list of books
			BookVector.push_back(book_obj);
		}

		if (x == 2)
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
				membervip_obj.vip = "vip";
				cout << "Please enter new member's name " << endl;
				cin >> membervip_obj.name;
				cout << "Please enter new member's last name " << endl;
				cin >> membervip_obj.last_name;
				cout << "Please enter new member's id " << endl;
				cin >> membervip_obj.id;
				MemberVector.push_back(membervip_obj);
			}
			if (membership == 2)
			{
				cout << "Please enter new member's name " << endl;
				cin >> member_obj.name;
				cout << "Please enter new member's last name " << endl;
				cin >> member_obj.last_name;
				cout << "Please enter new member's id " << endl;
				cin >> member_obj.id;
				MemberVector.push_back(member_obj);
			}

		}
		if (x == 3)
		{
			//print available books and its copies with information.
			for (int i = 0; i < BookVector.size(); i++)
			{
				cout << "------------" << endl;
				cout << "Book's Name: " << BookVector[i].book_name << endl;
				cout << "Book's Author: " << BookVector[i].author << endl;
				cout << "Book's isbn: " << BookVector[i].isbn << endl;
				for (int j = 0; j < BookVector[i].copy_list.size(); j++)
				{

					cout << " --> copy : " << BookVector[i].copy_list[j].edition_id << endl;
					cout << "        " << BookVector[i].copy_list[j].location << endl;
				}
				cout << "------------" << endl;
			}
		}
		if (x == 4)
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
				for (int i = 0; i < MemberVector.size(); i++)
				{
					if (mid == MemberVector[i].id)
					{
						if (MemberVector[i].vip == "vip")
						{
							if (MemberVector[i].max_copies == 3)
							{
								cout << "Maximum rented copies reached." << endl;
								goto StartRent;
								a = 0;
							}
							// sets the member in vector rented copies = 1
							MemberVector[i].max_copies++;
							rent.setMember(MemberVector[i]);
						}
						if (MemberVector[i].vip == "novip")
						{
							if (MemberVector[i].max_copies == 1)
							{
								cout << "Maximum rented copies reached." << endl;
								goto StartRent;
								a = 0;
							}
							// sets the member in vector rented copies = 1
							MemberVector[i].max_copies = 1;
							rent.setMember(MemberVector[i]);
						}
					}
					if (mid != MemberVector[i].id)
					{
						memb_check++;
						if (memb_check == MemberVector.size())
						{
							cout << "Member id not registered" << endl;
							a = 0;
							goto StartRent;
						}
					}


					a = 0;
				}

			}

			for (int i = 0; i < BookVector.size(); i++)
			{
				if (book_name == BookVector[i].book_name)
				{
					for (int a = 0; a < BookVector[i].copy_list.size(); a++)
					{
						cout << "entered copies for" << endl;

						if (BookVector[i].copy_list[a].location == "Rented")
						{
							rent_check++;
							if (rent_check == BookVector[i].copy_list.size())
							{
								cout << "No copies available" << endl;
								break;
							}
						}
						if (BookVector[i].copy_list[a].location == "Library")
						{
							cout << "The book is available " << endl;
							Book book;
							book = BookVector[i];
							book.copy = BookVector[i].copy_list[a].edition_id;
							BookVector[i].copy_list[a].location = "Rented";
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
			RentHistory.push_back(rent);
		}
		if (x == 5)
		{
			cout << "Which book to add copy?";
			string book_name;
			cin >> book_name;
			cout << "Please add copy number";
			Copy copy_number;
			cin >> copy_number.edition_id;
			for (int i = 0; i < BookVector.size(); i++)
			{
				if (book_name == BookVector[i].book_name)
				{
					BookVector[i].addToCopyList(copy_number);
				}
			}
		}
		if (x == 6)
		{
			for (int i = 0; i < RentHistory.size(); i++)
			{
				cout << "\n";
				cout << "Book name: " << RentHistory[i].abook.book_name << endl;
				cout << "--> Copy: " << RentHistory[i].abook.copy << endl;
				cout << "--> Author: " << RentHistory[i].abook.author << endl;
				cout << "--> ISBN " << RentHistory[i].abook.isbn << endl;
				cout << "-------------\n";
				cout << "Member name: " << RentHistory[i].member.name << endl;
				cout << "Member last name: " << RentHistory[i].member.last_name << endl;
				cout << "Member id: " << RentHistory[i].member.id << endl;
			}
		}
	}
}

// add books to bookvector.




//Rent book with copy
/*Book rentBook()
{*/

//}




//	book_obj.retireCopy(copy_x, member1);
//	//podria agregar el objeto copy a book y hacer la lista ahi directo
//	// 
//	//1 add copys to LOTR1
//	LOTR1.addToCopyList(copy1);
//	cout << "Copy added" << endl;
//	LOTR1.addToCopyList(copy2);
//	cout << "Copy added" << endl;
//
//	//2 retire copy specify which copy and who rented the copy.
//	LOTR1.retireCopy(copy1, member1);
//	LOTR1.retireCopy(copy2, member1);
//	//3 search available copies for the book
//	LOTR1.searchCopyList(LOTR1);
//	//4 shows in the book list the list of the copies of the specific book.
//	BookVector[0].searchCopyList(book_obj);
//
//
//	cout << copy1.location << endl;
//	cout << copy1.edition_id << endl;
//	cout << copy1.location << endl;
//	cout << LOTR1.copy_list[0].location << endl;
//	LOTR1.searchCopyList(LOTR1);
//	LOTR1.returnCopy(copy1);
//	cout << "Copy returned" << endl;
//
//	member1.rentCopy(copy1);
//	cout << "Copy rented" << endl;
//	member1.rentCheck();
//	member1.returnCopy();
//	cout << "Copy returned" << endl;
//
//	MemberVip membervip1;
//	membervip1.rentCopy(copy1);
//	cout << "Copy rented" << endl;
//	membervip1.rentCopy(copy2);
//	cout << "Copy rented" << endl;
//	membervip1.rentCheck();
//	membervip1.returnCopy(copy1);
//	cout << "Copy returned" << endl;
//	Copy testcopy;
//	testcopy = membervip1.returnCopy(copy2);
//	cout << testcopy.edition_id << endl;
//	cout << "Copy returned" << endl;
//}

