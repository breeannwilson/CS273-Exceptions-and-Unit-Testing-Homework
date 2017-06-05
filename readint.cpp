#include "readint.h"
#include <stdexcept>
#include <iostream>

using namespace std;


int read_int(const string &prompt, int low, int high) {

	//EXCEPTION: if the range is empty - invalid argument
	if (low >= high)
		throw std::invalid_argument("This range is invalid.");

	//while loop will continue to ask user until user gives valid input
	while (true) {
		try {
			int number;
			cout << "Please enter a number within the range: " << endl;
			cin >> number;

			//EXCEPTION: if the entered number is not valid - EX: if enter a char, etc
			cin.exceptions(ios_base::failbit);

			//EXCEPTION: if the number given is out of range for low to high
			if (number < low || number > high) {
				throw std::range_error("This number is not within the range.");

			}
			return number;
		}
			//catch invalid input exception
			catch (std::ios_base::failure &e1) {
				cerr << "Exception: You must supply an integer for read_int!\n";
				cin.clear();		//clear the failbit
				cin.ignore();		//get rid of the bad data in cin
			}

			//catch out of range exception
			catch (std::range_error &e2) {
				cerr << "Exception: You must enter an integer within the range for read_int!\n";
			}
	}
	

}