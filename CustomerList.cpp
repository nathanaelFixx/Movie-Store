
#include "CustomerList.h"

///// Constructor /////////
CustomerList::CustomerList()
{

}

//// Adds the customer pointer to the customerList hashtable //// 
void CustomerList::addCustomer(Customer * customer)
{
	customerList[hashFunction(customer->getId())].push_back(customer);
}


/// Returns a customer pointer if the customer is found in the customerList///
Customer * CustomerList::getCustomer(int id)
{
	int element = id % 30;

		for (int j = 0; 
		(unsigned) j < customerList[element].size(); j++)
		 {
			if (customerList[element][j]->getId() == id)
				return customerList[element][j];
                 }

	cout << "Customer not found! " << endl;
	return nullptr;
}

//// Hashes the customer id and returns it /////
int CustomerList::hashFunction(int id)
{
	int element = id % 30;
	
	return element;
}

///// Destructor /////////
CustomerList::~CustomerList()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; (unsigned)j < customerList[i].size(); j++)
		{
			delete customerList[i][j];
		}
	}
}
