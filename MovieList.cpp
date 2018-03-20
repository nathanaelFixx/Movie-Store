#include "MovieList.h"
#include <iostream>

using namespace std;

//_____________________________________________________________________________
// Constuctor
//
// sets the outside vector in the two-dimensional vector to size 3 (because we
// have three genres) and the inside vector to size 0, since they do not
// any movieInventories yet.
//_____________________________________________________________________________
MovieList::MovieList()
{
	movieList.assign(3, vector<MovieInventory>(0));
}

//_____________________________________________________________________________
// Destructor
//
// loops through the movie list and deletes all of the movie pointers
//_____________________________________________________________________________
MovieList::~MovieList()
{
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; (unsigned) j < movieList[i].size(); j++)
		{
			delete movieList[i][j].getMovie();
		}
	}
}

//_____________________________________________________________________________
// addMovie
//
// Adds a movie to the movie list. First it will determine which element of the
// outside vector it will need to be put in by determining the movie's genre,
// then it will check if that movie is already in the list and if it is not,
// adds it. After adding the movieInventory, it calls the quickSort function to
// insure that the List is always in the correct order
//_____________________________________________________________________________

bool MovieList::addMovie(MovieInventory movieInventory) 
{
	char genre;
	int element;
	int left;
	int right;

	genre = movieInventory.getMovie()->getGenre();
	// finding the right element in the outside vector
	if (genre == 'F')
		element = 0;
	else if (genre == 'D')
		element = 1;
	else if (genre == 'C')
		element = 2;
	else {
		cout << "INVALID GENRE" << endl;
		return false;
	}
	
	// if vector is empty
	if (movieList[element].empty()) {
		movieList[element].push_back(movieInventory);
		return true;
	}

	// checks if the movie is not already in the list. If it is not, adds it 
	for (int i = 0; (unsigned)i < movieList[element].size(); i++) {
		if (*movieList[element][i].getMovie()
		 == (*movieInventory.getMovie())) {
			
				changeQuantity(movieList[element][i],
				movieInventory.getQuantity());
			
			// deleting the movieInventory if it is not added
			// into the list
			delete movieInventory.getMovie();
			return false;
		}
	}

	movieList[element].push_back(movieInventory);

	// info for quicksort
	left = 0;
	right = movieList[element].size() - 1;

	// sorting function
	quickSort(movieList, left, right, element);

	return true;
}

//_____________________________________________________________________________
// incrementMovie
//
// adds one to the movieInventory quantity
//_____________________________________________________________________________
bool MovieList::incrementMovie(MovieInventory &movieInventory)
{
	movieInventory.incrementQuantity();
	return true;
}

//_____________________________________________________________________________
// decrementMovie
//
// subtracts one to the movieInventory quantity
//_____________________________________________________________________________
bool MovieList::decrementMovie(MovieInventory &movieInventory)
{
	movieInventory.decrementQuantity();
	return true;
}

//_____________________________________________________________________________
// changeQuantity
//
// adds whatever value is passed in to the movieInventory quantity
//_____________________________________________________________________________
bool MovieList::changeQuantity(MovieInventory & movieInventory, int val)
{
	movieInventory.setQuantity(val);
	return true;
}

//_____________________________________________________________________________
// findMovieWithActor
//
// Used if we are only given the actor and release date for a classic movie
//_____________________________________________________________________________
Movie * MovieList::findMovieWithActor(MovieInventory & movieInventory)
{
	int element = 2;

	for (int i = 0; (unsigned) i < movieList[element].size(); i++) {
		if ((*movieList[element][i].getMovie()).isSame
		(*movieInventory.getMovie())) {
			return movieList[element][i].getMovie();
		}
	}

	return nullptr;
}

//_____________________________________________________________________________
// printByGenre
//
// outputs all the movies of a specific genre that are contained in the list.
//_____________________________________________________________________________
void MovieList::printByGenre(const char x)
{
	char genre = x;
	int element;

	// finding which element to print out
	if (genre == 'F')
		element = 0;
	else if (genre == 'D')
		element = 1;
	else if (genre == 'C')
		element = 2;
	else {
		cout << "INVALID GENRE" << endl;
	}


	for (int i = 0; (unsigned) i < movieList[element].size(); i++) {
		
		movieList[element][i].getMovie()->print();
		cout << "  " << movieList[element][i].getMediaType() << "  ";
		cout << movieList[element][i].getQuantity() << endl;
	}


}

//_____________________________________________________________________________
// getWall
//
// helper function for quickSort
//_____________________________________________________________________________
int MovieList::getWall(vector<vector<MovieInventory>>& movieList, int left,
	int right, int element)
{
	MovieInventory temp;
	MovieInventory pivot = movieList[element][right];
	int i = (left - 1);

	for (int j = left; j <= right - 1; j++) {
		if (*movieList[element][j].getMovie() < *pivot.getMovie()) {   
			i++;
			
			// swapping out of order elemets
			temp = movieList[element][j];
			movieList[element][j] = movieList[element][i];
			movieList[element][i] = temp;
		}
	}

	// swapping out of order elements
	temp = movieList[element][right];
	movieList[element][right] = movieList[element][i + 1];
	movieList[element][i + 1] = temp;

	return (i + 1);
}

//_____________________________________________________________________________
// quickSort
// 
// recursive part of the sort
//_____________________________________________________________________________
void MovieList::quickSort(vector<vector<MovieInventory>>& movieList, int left,
	int right, int element)
{
	if (left < right) {
		int wall = getWall(movieList, left, right, element);

		quickSort(movieList, left, wall - 1, element);
		quickSort(movieList, wall + 1, right, element);
	}

}

//_____________________________________________________________________________
// checkOut
//
// checks if the movieInventory is in the list. If it is, it decrements
// the movie quantity
//_____________________________________________________________________________
bool MovieList::checkOut(MovieInventory &MovieInventory)
{
	char genre = MovieInventory.getMovie()->getGenre();
	int element;

	// finding the right element
	if (genre == 'F')
		element = 0;
	else if (genre == 'D')
		element = 1;
	else if (genre == 'C')
		element = 2;
	else {
		cout << "INVALID GENRE" << endl;
		return false;
	}

	// checking if movie is in the list
	for (int i = 0; (unsigned)i < movieList[element].size(); i++) {
		if (*movieList[element][i].getMovie()
		 == *MovieInventory.getMovie()) {
			decrementMovie(movieList[element][i]);
			return true;
		}
	}
	cout << "Movie Not in Stock!" << endl;
	return false;
}

//_____________________________________________________________________________
// checkIn
//
// checks if the movieInventory is in the list. If it is, it increments
// the movie quantity
//_____________________________________________________________________________
bool MovieList::checkIn(MovieInventory &MovieInventory)
{
	char genre = MovieInventory.getMovie()->getGenre();
	int element;

	if (genre == 'F')
		element = 0;
	else if (genre == 'D')
		element = 1;
	else if (genre == 'C')
		element = 2;
	else {
		cout << "INVALID GENRE" << endl;
		return false;
	}

	for (int i = 0; (unsigned)i < movieList[element].size(); i++) {
		if (*movieList[element][i].getMovie()
		 == *MovieInventory.getMovie()) {
			incrementMovie(movieList[element][i]);
			return true;
		}
	}
	cout << "Movie Not in Stock!" << endl;
	return false;
}




