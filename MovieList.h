
#ifndef MOVIELIST_H
#define MOVIELIST_H

#include "MovieInventory.h"
#include <vector>
using namespace std;

class MovieList
{
public:

	// Constructor
	MovieList();

	// Destructor
	virtual ~MovieList();

	// adds movieInventory to the list
	bool addMovie(MovieInventory movieInventory);

	// increment movie, adds one to the movie count
	bool incrementMovie(MovieInventory &movieInventory); 

	// decrement movie, subtracts one from the movie count
	bool decrementMovie(MovieInventory &movie);

	// print by genre, prints out all the movies in the list that are a
	// certain genre
	void printByGenre(const char x);

	// getWall, helper function for quickSort
	int getWall(vector<vector<MovieInventory>> &movieList, int left,
		 int right, int element);

	// quickSort, used to sort movieList
	void quickSort(vector<vector<MovieInventory>> &movieList, int left,
		int right, int element);

	//checkOut, finds a movie and then calls decrementMovie
	bool checkOut(MovieInventory &MovieInventory);

	// checkIn, finds a movie and then calls incrementMovie
	bool checkIn(MovieInventory &MovieInventory);

	// changeQuantity, used when quantity has to move up multiple movies
	bool changeQuantity(MovieInventory & movieInventory, int val);

	// findMovieWithActor,used when we need to find a movie and we are only
	// given an actor
	Movie * findMovieWithActor(MovieInventory &movieInventory);

private:
	
	vector<vector<MovieInventory>> movieList;
};

#endif // !MOVIELIST_H
