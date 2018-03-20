#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H

#include "Customer.h"
#include <vector>

class CustomerList
{
public:
	/////// Constructor /////////
	CustomerList();
	
        /// Adds the the customer pointer to customerList vector/////
	void addCustomer(Customer * customer);
	
	//// getter ///
	Customer * getCustomer(int id);

	// It hashes the customer Id ////
	int hashFunction(int id);

	/////// Destructor /////////
	~CustomerList();

private:
	int hashNum;

	////// Hash function ///////
	vector<Customer *> customerList[30];  
};

#endif // !CUSTOMERLIST_H

