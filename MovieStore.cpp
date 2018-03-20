// MovieStore.cpp : By Diego Guzman and Nathanael Fixx
//

#include "Movie.h"
#include "ClassicMovie.h"
#include "ComedyMovie.h"
#include "DramaMovie.h"
#include "MovieFactory.h"
#include "MovieInventory.h"
#include "MovieList.h"
#include "Customer.h"
#include "CustomerList.h"
#include "Store.h"
#include <iostream>
#include <vector>

using namespace std;


int main()
{

	Store diegoStore;
	diegoStore.populateCustomer("data4customers.txt");
	diegoStore.populateMovie("data4movies.txt");
	diegoStore.populateCommandsFile("data4commands.txt");

    return 0;
}

