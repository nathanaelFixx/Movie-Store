#include "Store.h"
#include "Customer.h"
#include <fstream>
#include <sstream>

// Constructor
Store::Store()
{

}

// Destructor
Store::~Store()
{
}

//_____________________________________________________________________________
// Populate Movie
// 
// Reads in from a file, creates movieInventory objects, and adds those objects
// to the movieList
//_____________________________________________________________________________
void Store::populateMovie(string fileName)
{
	//_____________________________
	// creating variables
	char check = ' ';
	char putBack;
	char putBack2;
	string tempStr;
	string line;
	char genre;
	int quantity;
	string director = "";
	string title;
	string majorActor;
	int month;
	int year;
	MovieFactory factory;
	Movie * tempMoviePtr;
	ifstream fin;
	//______________________________
	
	fin.open(fileName);

	while (!fin.eof()) {
		fin >> genre;
		fin >> check;
		
		//_____________________________________________________________
		// If the line if for a classic movie
		if (genre == 'C') {
			fin >> quantity;
			fin >> check;

			// getting director___________________________________
			fin >> director;
			while (director[director.length() - 1] != ',') {
				fin >> tempStr;
				director += (" " + tempStr);
			}
			director.pop_back();
			//____________________________________________________

			
			// getting title______________________________________
			fin >> title;
			while (title[title.length() - 1] != ',') {
				fin >> tempStr;
				title += (" " + tempStr);
			}
			title.pop_back();
			//____________________________________________________

			// getting major actor________________________________
			fin >> majorActor;
			while (isalpha(majorActor[majorActor.length() - 1])) {
				fin >> tempStr;
				majorActor += (" " + tempStr);
			}
			
			// checks for two digit months
			if (isdigit(majorActor[majorActor.length() - 2])) {     
				putBack = majorActor[majorActor.length() - 1];
				putBack2 = majorActor[majorActor.length() - 2];

				stringstream ss;  //convert chars to string
				string s;
				ss << putBack2;
				ss >> s;

				s += putBack;
				
				// convert string to int
				stringstream convert(s); 
				convert >> month;

				majorActor.pop_back();
				majorActor.pop_back();
				majorActor.pop_back();
			}

			else {
				putBack = majorActor[majorActor.length() - 1];
				fin.putback(putBack);

				majorActor.pop_back();
				
				//gets rid of white space
				majorActor.pop_back(); 
			//____________________________________________________	
				//getting month
				fin >> month;
			}

			// getting year
			fin >> year;

			// creates the movieInventory and adding it to the list
			tempMoviePtr = factory.createMovie(genre,
			 director, title, majorActor, month, year);
			
			MovieInventory tempMovieInventory(tempMoviePtr);
			tempMovieInventory.setQuantity(quantity - 1);
			movieList.addMovie(tempMovieInventory);
			//_____________________________________________________
		}
		
		//_____________________________________________________________

		
		
		// if the movie is a comedy or drama___________________________
		else if (genre == 'F' || genre == 'D') {
			fin >> quantity;
			fin >> check;

			// getting director____________________________________
			fin >> director;
			while (director[director.length() - 1] != ',') {
				fin >> tempStr;
				director += (" " + tempStr);
			}
			director.pop_back();
			//_____________________________________________________


			// getting title_______________________________________
			fin >> title;
			while (title[title.length() - 1] != ',') {
				fin >> tempStr;
				title += (" " + tempStr);
			}
			title.pop_back();
			//_____________________________________________________

			// getting year
			fin >> year;

			// making the movieInventory and adding it to the list
			tempMoviePtr = factory.createMovie(genre, director,
			 title, year);
			
			MovieInventory tempMovieInventory(tempMoviePtr);
			tempMovieInventory.setQuantity(quantity - 1);
			movieList.addMovie(tempMovieInventory);
			//_____________________________________________________
		}

		else {
			cout << genre << " is not a valid genre" << endl;
			string line;
			getline(fin, line);
		}
	}
	cout << endl << endl << endl;
}

//_____________________________________________________________________________
// populateCustomer
//
// Reads in data from a file, and uses it to create customer objects
//_____________________________________________________________________________
void Store::populateCustomer(string customerInfo)
{
	fstream infile(customerInfo);

	if (infile.fail())
	{
		cout << "No file found" << endl;
	}
	else
	{
		int Id;
		string lastName;
		string firstName;

		ifstream fin;
		fin.open(customerInfo);

		while (!fin.eof()) {
			fin >> Id;
			fin >> lastName;
			fin >> firstName;
		
			// making the new customer and adding it to the list
			Customer * temp
			 = new Customer(Id, firstName, lastName);
			
			overallCustomerList.addCustomer(temp);
		}
	}

}



void Store::populateCommandsFile(string fileName)
{   
    string p;
    fstream infile(fileName);

    while (getline(infile, p))
    {
		// defining variables
        Movie * tempMoviePtr = nullptr;
        Customer * tempCustomer = nullptr;
        MovieFactory factory;
        MovieInventory tempMovieInventory;
        string tempStr;
        char command;
        int customerId;
        char mediaType;
        char movieType;
        string title;
        string director;
        string actor;
        int year;
        int month;
        stringstream firstline(p);
       //_____________________________
		
		firstline >> command;

        if (command == 'I' || command == 'R' || command == 'B'
	 || command == 'H')
        
	{
            if (command == 'I')
            {
                printInventory(movieList);
            }

            else if (command == 'H')
            {
                firstline >> customerId;
                firstline >> mediaType;
                firstline >> movieType;

				// checks if the customer exists
                if (overallCustomerList.getCustomer(customerId) !=
			 nullptr && mediaType == 'D') {
                   overallCustomerList.getCustomer(customerId)->printHistory();
                }
            }

            else if (command == 'B') {
                firstline >> customerId;
                firstline >> mediaType;
                firstline >> movieType;

				// if the movie is not a DVD
                if (mediaType != 'D') {
                    cout << mediaType << " is not a valid genre" << endl;
                }

				// comedy movie
                else if (movieType == 'F') {
                    firstline >> title;
                    while (title[title.length() - 1] != ',') {
                        firstline >> tempStr;
                        title += (" " + tempStr);
                    }
                    title.pop_back();
                    firstline >> year;

		    // creatig the movie based on the information we are given
                    tempMoviePtr = factory.createMovie(movieType, "",
					 title, year);
		    Customer * tempCustomer = 
			overallCustomerList.getCustomer(customerId);
                    
			MovieInventory tempMovieInventory(tempMoviePtr);
                  
					// if the customer exists,
					// calls the borrowMovie function
			if (overallCustomerList.getCustomer(customerId)
				 != nullptr) {
                        borrowMovie(tempCustomer, tempMoviePtr);
                    }
                }

				// drama movie
                else if (movieType == 'D') {
                    firstline >> director;
                    while (director[director.length() - 1] != ',') {
                        firstline >> tempStr;
                        director += (" " + tempStr);
                    }
                    director.pop_back();
                    
                    firstline >> title;
                    while (title[title.length() - 1] != ',') {
                        firstline >> tempStr;
                        title += (" " + tempStr);
                    }
                    title.pop_back();

                    tempMoviePtr = factory.createMovie(movieType,
			 director, title, 0);
                    Customer * tempCustomer =
			 overallCustomerList.getCustomer(customerId);
                    MovieInventory tempMovieInventory(tempMoviePtr);
                    if (overallCustomerList.getCustomer(customerId)
			 != nullptr) {
                        borrowMovie(tempCustomer, tempMoviePtr);
                    }
                }

				// clasic movie
                else if (movieType == 'C') {
                    firstline >> month;
                    firstline >> year;

                    firstline >> actor;
                    while (!firstline.eof()) {
                        firstline >> tempStr;
                        actor += (" " + tempStr);
                    }

                    tempMoviePtr = factory.createMovie(movieType, "", "",
			 actor, month, year);
                    Customer * tempCustomer =
			 overallCustomerList.getCustomer(customerId);
                    MovieInventory tempMovieInventory(tempMoviePtr);
                    if (overallCustomerList.getCustomer(customerId)
			 != nullptr) {
                        borrowMovie(tempCustomer,
			 movieList.findMovieWithActor(tempMovieInventory));
                    }
                }

		// deletes the pointers that were created in this loop
                delete tempMoviePtr;
                tempMoviePtr = nullptr;
                delete tempCustomer;
                tempCustomer = nullptr;
            }

			// for returing movies
            else if (command == 'R') {
                firstline >> customerId;
                firstline >> mediaType;
                firstline >> movieType;

                if (mediaType != 'D') {
                    cout << mediaType << " is not a valid genre" << endl;
                }

                else if (movieType == 'F') {
                    firstline >> title;
                    while (title[title.length() - 1] != ',') {
                        firstline >> tempStr;
                        title += (" " + tempStr);
                    }
                    title.pop_back();
                    firstline >> year;

		     // creating the movie inventory and temp customer pointer
                    tempMoviePtr = factory.createMovie(movieType, "", title, year);
                    Customer * tempCustomer = overallCustomerList.getCustomer(customerId);
                    MovieInventory tempMovieInventory(tempMoviePtr);
                  
			// if the customer exists, return the movie
			if (overallCustomerList.getCustomer(customerId)
				 != nullptr) {
                        returnMovie(tempCustomer, tempMoviePtr);
                    }
                }

                else if (movieType == 'D') {
                    firstline >> director;
                    while (director[director.length() - 1] != ',') {
                        firstline >> tempStr;
                        director += (" " + tempStr);
                    }
                    director.pop_back();

                    firstline >> title;
                    while (title[title.length() - 1] != ',') {
                        firstline >> tempStr;
                        title += (" " + tempStr);
                    }
                    title.pop_back();

		    // creating the movie pointer and temp customer
                    tempMoviePtr = factory.createMovie(movieType,
			 director, title, 0);
                    Customer * tempCustomer =
			 overallCustomerList.getCustomer(customerId);
                    MovieInventory tempMovieInventory(tempMoviePtr);
                    if (overallCustomerList.getCustomer(customerId)
			 != nullptr) {
                        returnMovie(tempCustomer, tempMoviePtr);
                    }
                }

                else if (movieType == 'C') {
                    firstline >> month;
                    firstline >> year;

                    firstline >> actor;
                    while (!firstline.eof()) {
                        firstline >> tempStr;
                        actor += (" " + tempStr);
                    }

                    tempMoviePtr = factory.createMovie(movieType, "", "",
			 actor, month, year);
                    Customer * tempCustomer =
			 overallCustomerList.getCustomer(customerId);
                    MovieInventory tempMovieInventory(tempMoviePtr);
                    if (overallCustomerList.getCustomer(customerId)
			 != nullptr) {
                        returnMovie(tempCustomer,
			 movieList.findMovieWithActor(tempMovieInventory));
                    }
                }

		// deleting pointers that were created
                delete tempMoviePtr;
                tempMoviePtr = nullptr;
                delete tempCustomer;
                tempCustomer = nullptr;
            }

        }
        else {
            cout << command << " is not a valid command" << endl;
        }
    }
}


//_____________________________________________________________________________
// printCustomerHistory
//
// uses the printHistory method in customer to print all the data
//_____________________________________________________________________________
void Store::printCustomerHistory(Customer * customer)
{
	customer->printHistory();
}

//_____________________________________________________________________________
// printCustomerHistory
//
// uses the printByGenre method in movieList to print all the data
//_____________________________________________________________________________
void Store::printInventory(MovieList &movieList)
{
	movieList.printByGenre('F');
	cout << endl;
	movieList.printByGenre('D');
	cout << endl;
	movieList.printByGenre('C');
	cout << endl;
}

//_____________________________________________________________________________
// borrowMovie
//
// decreases the inventory count of a movieInventory and adds it to the
// cusstomer history
//_____________________________________________________________________________
void Store::borrowMovie(Customer * customer, MovieInventory movieInventory)
{
	movieList.checkOut(movieInventory);
	customer->addHistory("B | " +
	 movieInventory.getMovie()->getMovieTitle());
}

//_____________________________________________________________________________
// returnMovie
//
// increases the inventory count of a movieInventory and adds it to the
// cusstomer history
//_____________________________________________________________________________
void Store::returnMovie(Customer * customer, MovieInventory movieInventory)
{
	movieList.checkIn(movieInventory);
	customer->addHistory("R | " +
	 movieInventory.getMovie()->getMovieTitle());
}

