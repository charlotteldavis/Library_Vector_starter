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
	std::ifstream in(filename);
	std::string line;

	while (std::getline(in, line)){
		if(line.size() > 0) {
			cout << line + "\n";
			//books.push_back(line);
		}

	if (!in) {
		return COULD_NOT_OPEN_FILE;
	}
	if (books.size() == 0;) {
		return NO_BOOKS_IN_LIBRARY;
	}
//how do you check if all data is loaded
	if (data is loaded){
//if could not open file is returned or any of the other errors, data not loaded correctly
		return SUCCESS;
	}
	  }
}

/* serializes books to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_BOOKS_IN_LIBRARY if there are 0 entries books (do not create file)
 * 			SUCCESS if all data is saved
 * */
int saveBooks(std::vector<book> &books, const char* filename)
{
	std::fstream fs;
	fs.open (filename);

	if (!fs.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}
	if (books.size() == 0;){
		return NO_BOOKS_IN_LIBRARY;
	}
	//how do you check if all data saved
	if (all data saved) {
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
	std::ifstream fs;
	fs.open (filename);

	if (!fs.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}
	if (patrons.size() == 0;){
		return NO_BOOKS_IN_LIBRARY;
	}
	//how do you check if all data is loaded
		if (data is loaded){
			return SUCCESS;
		}
}

/* serializes patrons to the file filename
 * returns  COULD_NOT_OPEN_FILE if cannot open filename
 * 			NO_PATRONS_IN_LIBRARY if there are 0 entries in patrons  (do not create file)
 * 			SUCCESS if all data is saved
 * */
int savePatrons(std::vector<patron> &patrons, const char* filename)
{
	std::ifstream fs;
	fs.open (filename);

	if (!fs.is_open()) {
		return COULD_NOT_OPEN_FILE;
	}
	if (patrons.size() == 0;){
		return NO_BOOKS_IN_LIBRARY;
	}
	 //need to "serialize" patrons to file filename
	//return success if data all saved
	//how do you check if all data saved
	if (all data saved) {
		return SUCCESS;
	}
}
