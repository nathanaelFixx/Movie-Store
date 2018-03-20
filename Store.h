#ifndef STORE_H
#define STORE_H

#include "CustomerList.h"
#include "MovieList.h"
#include "MovieFactory.h"

class Store
{

public:
	// constructor
	Store();

	// desctuctor
	~Store();

	//_____________________________________________________________________
	// populating lists
	void populateMovie(string fileName);
	void populateCustomer(string customerInfo);
	//_____________________________________________________________________

	// reads in from command file and performs the commands
	void populateCommandsFile(string fileName);

	//_____________________________________________________________________
	// printing to console
	void printCustomerHistory(Customer * customer);
	void printInventory(MovieList &movieList);
	//_____________________________________________________________________

	// checking out a movie
	void borrowMovie(Customer * customer, MovieInventory movieInventory);

	// returning a movie
	void returnMovie(Customer * customer, MovieInventory movieInventory);

private:
	CustomerList overallCustomerList;
	MovieList movieList;
};

#endif // !STORE_
