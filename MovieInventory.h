
#ifndef MOVIE_INVENTORY_H
#define MOVIE_INVENTORY_H
#include "Movie.h"



class MovieInventory
{
public:
	// constructors
	MovieInventory();
	MovieInventory(Movie * movieptr);
	//______________________________

	// destructor
	~MovieInventory();

	// getters and setters
	int getQuantity();
	string getMediaType();
	void setQuantity(int val);
	Movie * getMovie();
	//_________________________

	// increments quantity
	void incrementQuantity();
	void decrementQuantity();
	
	


private:
	Movie * movie;
	string mediaType;
	int quantity;

};
#endif // !MOVIE_INVENTORY_H
