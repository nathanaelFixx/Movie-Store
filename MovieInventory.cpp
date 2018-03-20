
#include "MovieInventory.h"
#include <iostream>

using namespace std;

// constructor
MovieInventory::MovieInventory()
{
}

//// constructor //// 
MovieInventory::MovieInventory(Movie * movieptr)
{
	this->movie = movieptr;
	mediaType = "DVD";
	quantity = 1;
}

/////Destructor////
MovieInventory::~MovieInventory()
{
}

//// returns the quantity ////
int MovieInventory::getQuantity()
{
	return quantity;
}

/// increments the quantiy by one ///
void MovieInventory::incrementQuantity()
{
	quantity++;
}

/// decrements the quantiy by one ///
void MovieInventory::decrementQuantity()
{
	if (quantity > 0) {
		quantity--;
	}
	else {
		cout << "OUT OF STOCK" << endl;
	}
}

///set's the quantity to the given value ///
void MovieInventory::setQuantity(int val)
{
	quantity += val;
}

///returns a movie pointer///
Movie * MovieInventory::getMovie()
{
	return movie;
}

///returns the media type///
string MovieInventory::getMediaType()
{
	return mediaType;
}
