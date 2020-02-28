#include "../includes_usr/fileIO.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
/* clears, then loads books from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries in books
 * 			SUCCESS if all data is loaded
 * */
int loadBooks(std::vector<book> &books, const char* BOOKFILE)
{
	char delim = ',';
	book myBook;
	int bookID;
	string title;
	string author;
	int bookState;
	int loanPatronID;
	books.clear();
	// Open the File
	ifstream myInputFile;
	myInputFile.open(BOOKFILE);

	if (!myInputFile.is_open()) {
				return COULD_NOT_OPEN_FILE;
	}

	std::string line;
	while (!myInputFile.eof()) {
		bookID, title, author, bookState, loanPatronID = getline(myInputFile, line, delim);
		myBook.book_id = bookID;
		myBook.title = title;
		myBook.author = author;
		myBook.state = bookState;

		books.push_back(myBook);

		}

	if (books.size() == 0) {
		return NO_BOOKS_IN_LIBRARY;
	}
	else {
		return SUCCESS;
	}
}

/* serializes books to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries books (do not create file)
 * 			SUCCESS if all data is saved
 * */
int saveBooks(std::vector<book> &books, const char* BOOKFILE) //need to use const BOOKFILE
{
	ofstream myOutputfile;
	myOutputfile.open(BOOKFILE);

	if (!myOutputfile.is_open()) {
			return COULD_NOT_OPEN_FILE;
	}

	if (books.size() == 0) {
		return NO_BOOKS_IN_LIBRARY;
	}
	else {
		for (int i = 0; i < books.size(); ++i){
		myOutputfile << books[i].book_id << "," << books[i].title << "," << books[i].author << "," << books[i].state << "," << books[i].loaned_to_patron_id;
		}
	}

	myOutputfile.close();

		return SUCCESS;
}

/* clears, then loads patrons from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons
 * 			SUCCESS if all data is loaded
 * */
int loadPatrons(std::vector<patron> &patrons, const char* PATRONFILE)
{
	int id;
	string pName;
	int numCheckedOut;
	patron myPatron;

	int patron_id;
		std::string name;
		int number_books_checked_out;

	ifstream myInputFile;
	myInputFile.open(PATRONFILE);

	if (!myInputFile.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}

	std::string line;
	while (!myInputFile.eof()) {
		id, pName, numCheckedOut = getline(myInputFile, line);
		myPatron.patron_id = id;
		myPatron.name = pName;
		myPatron.number_books_checked_out = numCheckedOut;
		patrons.push_back(myPatron);
	}

	if (patrons.size() == 0){
		return NO_PATRONS_IN_LIBRARY;
	}
	else {
		return SUCCESS;
	}
}

/* serializes patrons to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons  (do not create file)
 * 			SUCCESS if all data is saved
 * */
int savePatrons(std::vector<patron> &patrons, const char* PATRONFILE) { //need to use const PATRONFILE //why in library does it ask for 3 params
	ofstream myOutputfile;
	myOutputfile.open(PATRONFILE);

	if (!myOutputfile.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}

	if (patrons.size() == 0){
		return NO_PATRONS_IN_LIBRARY;
	}

	else {
		for (int i = 0; i < patrons.size(); ++i) {
			myOutputfile << patrons[i].patron_id << "," << patrons[i].name << "," << patrons[i].number_books_checked_out;
			}
		return SUCCESS;
	}
}
