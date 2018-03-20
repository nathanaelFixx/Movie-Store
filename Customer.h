

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include "History.h"
#include "Movie.h"
#include "MovieInventory.h"
using namespace std;

class Customer
{
public:
	/////// Constructor /////////
	Customer(int id, string firstName, string LastName);
	
        /////// Destructor /////////
        ~Customer();

        //////// getters /////////
	int getId() const;
	string getLastName() const;
	string getFirstName() const;

        //////// setters /////////
	void setId(int id);
	void setLastName(string lastName);
	void setFirstName(string firstName);
	
	/// Adds the the string into the history object ///
	void addHistory(string movieTitle);

	////print out history data ////
	void printHistory();

private:

	int id;
	string firstName;
	string lastName;
	History customerHistory;


};

#endif // !CUSTOMER_H

