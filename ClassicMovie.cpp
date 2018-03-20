
#include "ClassicMovie.h"
#include <iomanip>
#include <iostream>

////// constructor //////
ClassicMovie::ClassicMovie(char genre, string directorName,
 string movieTitle, string majorActor, int releaseMonth, int releaseYear):
	Movie(genre, directorName, movieTitle, releaseYear)
{
	this->majorActor.push_back(majorActor);

	for (int i = 0;  
	     (unsigned) i < (unsigned) this->majorActor.size() ; i++) 
		{
		if (this->majorActor[i] != majorActor) {
			this->majorActor.push_back(majorActor);
		}
	}

	this->releaseMonth = releaseMonth;
}

/////// Destructor ///////// 
ClassicMovie::~ClassicMovie()
{
}


/////Returns the releaseMonth integer /////
int ClassicMovie::getReleaseMonth() const
{
	return releaseMonth;
}

////Print out movie data ////
void ClassicMovie::print()
{
	cout << setw(7) << getGenre() << setw(35) << getMovieTitle()
		<< setw(20) << getDirectorName() << setw(20) <<
               getMajorActor() << setw(7) << getReleaseMonth() << 
               setw(7) << getReleaseYear();
}

/////Returns the major actor string /////
string ClassicMovie::getMajorActor() const
{
	string returner = majorActor[0];
	return returner;
}

/////Returns a boolean value if the major actor is found in majorActor list///
bool ClassicMovie::findMajorActor(string actor) const
{
	for (int i = 0;  (unsigned) i < majorActor.size(); i++) {
		if (majorActor[i] == actor) {
			return true;
		}
	}
	return false;
}

/////Returns a true if two movies are equal to each other/////
bool ClassicMovie::operator==(const Movie & rhs)
{
	if (releaseMonth == rhs.getReleaseMonth() && 
        releaseYear == rhs.getReleaseYear() &&
        movieTitle == rhs.getMovieTitle() && 
        directorName == rhs.getDirectorName())
	{
		if (!findMajorActor(rhs.getMajorActor())) {
			majorActor.push_back(rhs.getMajorActor());
		}

		return true;
	}
	else 
	{
		return false;
	}
}

//Returns a true if the passed in parameter is greater than the current movie//
bool ClassicMovie::operator<(const Movie & rhs)
{
	if (releaseYear < rhs.getReleaseYear())
	{
		return true;
	}
	else if (releaseYear == rhs.getReleaseYear() &&
	 releaseMonth == rhs.getReleaseMonth())
	{
		if (getMajorActor() < rhs.getMajorActor()) {
			return true;
		}

		else {
			return false;
		}
	}

	else if (releaseYear == rhs.getReleaseYear()) {
		if (releaseMonth < rhs.getReleaseMonth()) {
			return true;
		}
		else {
			return false;
		}
	}

	return false;
}

//Returns a true if the passed in parameter is less than the current movie///
bool ClassicMovie::operator>(const Movie & rhs)
{
	if (releaseYear > rhs.getReleaseYear()) 
	{
		return true;
	}
	else if (releaseYear == rhs.getReleaseYear() &&
	 releaseMonth == rhs.getReleaseMonth()) 
	{
		if (getMajorActor() > rhs.getMajorActor()) {
			return true;
		}

		else {
			return false;
		}
	}

	else if (releaseYear == rhs.getReleaseYear()) {
		if (releaseMonth > rhs.getReleaseMonth()) {
			return true;
		}
		else {
			return false;
		}
	}

	return false;
}

/////Returns a true if two classic movies are equal to each other/////
bool ClassicMovie::isSame(const Movie & rhs)
{
	if (releaseMonth == rhs.getReleaseMonth() &&
           releaseYear == rhs.getReleaseYear() &&
           findMajorActor(rhs.getMajorActor()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

