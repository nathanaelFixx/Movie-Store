//_____________________________________________________________________________
// By: Nathanael Fixx
//
// Abstract class for creation of movie objects. Allows user to get movie
// title, director name, release year, and genre. Also contains the methods
// getMajorActor and getReleaseMonth for the Classic Movie class
//_____________________________________________________________________________

#ifndef MOVIE_H
#define MOVIE_H

#include <string>

using namespace std;

class Movie
{
public:

	// constructor
	Movie(char genre, string directorName, string movieTitle,
		 int releaseYear);
	
	// destructor
	virtual ~Movie();

	//_____________________________________________________________________
	// Overloaded Operators
	virtual bool operator==(const Movie & rhs) = 0;
	virtual bool operator<(const Movie& rhs) = 0;
	virtual bool operator>(const Movie& rhs) = 0;
	virtual bool isSame(const Movie& rhs) = 0;
	//_____________________________________________________________________
	
	
	//_____________________________________________________________________
	// Accessors
	string getMovieTitle() const;
	string getDirectorName() const;
	int getReleaseYear() const;
	char getGenre() const;
	//_____________________________________________________________________

	
	//_____________________________________________________________________
	// For Classic Movie Class
	virtual int getReleaseMonth() const;
	virtual string getMajorActor() const;
	//_____________________________________________________________________


	// print function
	virtual void print() = 0;

protected:
	string movieTitle;
	string directorName;
	int releaseYear;
	char genre;
};

#endif