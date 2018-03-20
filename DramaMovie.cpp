
#include "DramaMovie.h"

/////// Constructor /////////
DramaMovie::DramaMovie(char genre, string directorName,
string movieTitle, int releaseYear):
Movie(genre, directorName, movieTitle, releaseYear)
{
}

/////// Destructor ///////// 
DramaMovie::~DramaMovie()
{
}

//Returns a true if the passed in parameter is greater than the current movie//
bool DramaMovie::operator<(const Movie & rhs)
{
	if (directorName < rhs.getDirectorName()) 
	{ 
		return true;
	}
	else if (directorName == rhs.getDirectorName() &&
        movieTitle < rhs.getMovieTitle()) 
	{
		return true;
	}
	else 
	{
		return false;
	}

	
}

//Returns a true if the passed in parameter is less than the current movie//
bool DramaMovie::operator>(const Movie & rhs)
{
	if (directorName > rhs.getDirectorName()) 
	{
		return true;
	}
	else if(directorName == rhs.getDirectorName()
	 && movieTitle > rhs.getMovieTitle())
	{
		return true;
	}
	else
	{
		return false;
	}
}

/////Returns a true if two classic movies are equal to each other/////
bool DramaMovie::operator==(const Movie &rhs)
{
	if (directorName == rhs.getDirectorName() &&
		 movieTitle == rhs.getMovieTitle())  
	{
		return true;
	}
	else 
	{
		return false;
	}
}

////Prints out movie data ////
void DramaMovie::print()
{
	cout << setw(7) << getGenre() << setw(35) << getMovieTitle()
		<< setw(20) << getDirectorName()
		 << setw(7)  << getReleaseYear();
}

/////Returns a true if two drama movies are the same object/////
bool DramaMovie::isSame(const Movie & rhs)
{	
	if(*this == rhs){
		return true;
	}
	return false;
}