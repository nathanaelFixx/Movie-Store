
#include "Customer.h"

using namespace std;

/////// Constructor /////////
Customer::Customer(int id, string firstName, string LastName)
{
	this->id = id;
	this->firstName = firstName;
	this->lastName = LastName;
}

/////// Destructor ///////// 
Customer::~Customer()
{
}

/// returns the customer id ///
int Customer::getId() const
{
	return id;
}

/// returns the customer last name ///
string Customer::getLastName() const
{
	return lastName;
}

/// returns the customer first name ///
string Customer::getFirstName() const
{
	return firstName;
}

/// Sets the customer id ///
void Customer::setId(int id)
{
	this->id = id;
}

/// Sets the customer last name ///
void Customer::setLastName(string lastName)
{
	this->lastName = lastName;
}

/// Sets the customer first name ///
void Customer::setFirstName(string firstName)
{
	this->firstName = firstName;
}

// adds the movie title to the customer history ///
void Customer::addHistory(string movieTitle)
{
	//string adder = command + " " + movieTitle;
	customerHistory.add(movieTitle);
}

////Prints out movie data ////
void Customer::printHistory()
{
	cout << firstName << " " << lastName << ": " << endl;
	customerHistory.print();
}
