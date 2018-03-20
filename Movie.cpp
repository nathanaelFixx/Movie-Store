//_____________________________________________________________________________
// By: Nathanael Fixx
//
// Abstract class for creation of movie objects. Allows user to get movie
// title, director name, release year, and genre. Also contains the methods
// getMajorActor and getReleaseMonth for the Classic Movie class
//_____________________________________________________________________________
#include "Movie.h"

#include <iostream>
#include <iomanip>

//_____________________________________________________________________________
// Constructor
//
// Sets movie title, director name, genre, and release year based off passed in
// information
//_____________________________________________________________________________
Movie::Movie(char genre, string directorName, string movieTitle,
	int releaseYear)
{
	this->movieTitle = movieTitle;
	this-> directorName = directorName;
	this->releaseYear = releaseYear;
	this->genre = genre;
}

// returns movie title
string Movie::getMovieTitle() const
{
	return movieTitle;
}

// returns director name
string Movie::getDirectorName() const
{
	return directorName;
}

// returns release year
int Movie::getReleaseYear() const
{
	return releaseYear;
}

// returns genre
char Movie::getGenre() const
{
	return genre;
}

// returns major actor (for classic movie class)
string Movie::getMajorActor() const
{
	return "";
}

// returns release month (for classic movie class)
int Movie::getReleaseMonth() const
{
	return 0;
}

//_____________________________________________________________________________
// Print
//
// Outputs all the data fields of the movie
//_____________________________________________________________________________
void Movie::print() 
{
	cout << setw(7) << getGenre() << setw(35) << getMovieTitle()
		<< setw(20) << getDirectorName() << setw(7) << getReleaseYear();
}

//_____________________________________________________________________________
// Operator ==
//
// Returns true if two movies have the same title and release year
//_____________________________________________________________________________
bool Movie::operator==(const Movie & rhs)
{
	return this->movieTitle == rhs.movieTitle && this->releaseYear 
		== rhs.releaseYear;
}

//_____________________________________________________________________________
// Operator <
//
// Compares movies based off of release year
//_____________________________________________________________________________
bool Movie::operator<(const Movie & rhs) 
{
	return this->releaseYear < rhs.releaseYear;
}

//_____________________________________________________________________________
// Operator >
//
// Compares movies based off of release year
//_____________________________________________________________________________
bool Movie::operator>(const Movie & rhs)
{
	return this->releaseYear > rhs.releaseYear;
}

// Destructor
Movie::~Movie()
{
}
