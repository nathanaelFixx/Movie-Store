
#include "ComedyMovie.h"
#include <iostream>
#include <iomanip>

/////// Constructor /////////
ComedyMovie::ComedyMovie(char genre, string directorName,
string movieTitle, int releaseYear):
Movie(genre, directorName, movieTitle, releaseYear)
{
}

/////// Destructor ///////// 
ComedyMovie::~ComedyMovie()
{
}

//Returns a true if the passed in parameter is greater than the current movie//
bool ComedyMovie::operator<(const Movie & rhs)
{
	if (this->movieTitle < rhs.getMovieTitle())
	{
		return true;
	}
	else if (movieTitle == rhs.getMovieTitle() && releaseYear
		 < rhs.getReleaseYear())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Returns a true if the passed in parameter is less than the current movie//
bool ComedyMovie::operator>(const Movie & rhs) 
{
	if (movieTitle > rhs.getMovieTitle())
	{
		return true;
	}
	else if (movieTitle == rhs.getMovieTitle() && releaseYear
		 > rhs.getReleaseYear())
	{
		return true;
	}
	else
	{
		return false;
	}
}


/////Returns a true if two classic movies are equal to each other/////
bool ComedyMovie::operator==(const Movie &rhs) 
{
	if (movieTitle == rhs.getMovieTitle() && 
	releaseYear == rhs.getReleaseYear())
	{
		return true;
	}
	else
	{
		return false;
	}
}

////Print out movie data ////
void ComedyMovie::print()
{
	cout << setw(7) << getGenre() << setw(35) << getMovieTitle()
	  << setw(20) << getDirectorName() << setw(7) << getReleaseYear();
}

/////Returns a true if two classic movies are equal to each other/////
bool ComedyMovie::isSame(const Movie & rhs)
{	
	if(*this == rhs){
		return true;
	}

	return false;
}