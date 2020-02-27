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
int loadBooks(std::vector<book> &books, const char* filename)
{
	books.clear();
	// Open the File
	ifstream myInputFile;
	myInputFile.open(filename);

	if (!myInputFile.is_open()) {
				return COULD_NOT_OPEN_FILE;
	}

	std::string line;
	while (!myInputFile.eof()) {
		getline(myInputFile, line);
		cout << line;
		//books.push_back(line);
			//!!!!!!!!pushback is red
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
int saveBooks(std::vector<book> &books, const char* filename)
{
	ofstream myOutputfile;
	myOutputfile.open(filename);

	if (!myOutputfile.is_open()) {
			return COULD_NOT_OPEN_FILE;
	}

	myOutputfile << books;

	myOutputfile.close();
	if (books.size() == 0){
		return NO_BOOKS_IN_LIBRARY;
	}
	else {
		for (int i = 0; i < books.size(); ++i) {
				myOutputfile << books[i];
				}
		return SUCCESS;
	}
}

/* clears, then loads patrons from the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons
 * 			SUCCESS if all data is loaded
 * */
int loadPatrons(std::vector<patron> &patrons, const char* filename)
{
	ifstream myInputFile;
	myInputFile.open(filename);

	if (!myInputFile.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}

	std::string line;
	while (!myInputFile.eof()) {
		getline(myInputFile, line);
		cout << line;
		//patrons.push_back(line);
			//!!!!!!!!pushback is red
	}

	if (patrons.size() == 0;){
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
int savePatrons(std::vector<patron> &patrons, const char* filename) {
	ofstream myOutputfile;
	myOutputfile.open(filename);

	if (!myOutputfile.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}

	if (patrons.size() == 0;){
		return NO_PATRONS_IN_LIBRARY;
	}

	else {
		for (int i = 0; i < patrons.size(); ++i) {
			myOutputfile << patrons[i];
			}
		return SUCCESS;
	}
}
