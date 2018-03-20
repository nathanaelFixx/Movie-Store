

#ifndef HISTORY_H
#define HISTORY_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class History
{

public:
	
	/////// Constructor /////////
	History();

	/////// Destructor /////////
	~History();
        
        /// adds the customerData to the movieHistory vector///
	void add(string& customerData);

	////print out history data ////
	void print();

private:
	
	vector<string> movieHistory;
};

#endif // !HISTORY_H
