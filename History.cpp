
#include "History.h"

/////// Constructor /////////
History::History()
{
}

/////// Destructor /////////
History::~History()
{
}

/// adds the customerData to the movieHistory vector///
void History::add(string & customerData)
{
	movieHistory.push_back(customerData);
}

////print out movieHistory list data ////
void History::print()
{
	if (movieHistory.empty()) {
		cout << "No History " << endl << endl;
		return;
	}

	for (int i = 0; (unsigned)i < movieHistory.size(); i++) {
		cout << (movieHistory[i]) << endl;
	}
}
