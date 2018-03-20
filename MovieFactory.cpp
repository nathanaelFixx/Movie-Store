
#include "MovieFactory.h"
#include "Movie.h"
#include "ComedyMovie.h"
#include "ClassicMovie.h"
#include "DramaMovie.h"

/////constructor ////
MovieFactory::MovieFactory()
{
}

/// Returns a classic movie pointer ////
Movie * MovieFactory::createMovie(char genre, string directorName,
string movieTitle, string majorActor, int releaseMonth, int releaseYear)
{
	Movie * newMovie = NULL;

	newMovie = new ClassicMovie(genre,
	 directorName, movieTitle, majorActor, releaseMonth, releaseYear);
		return newMovie;
	
}

/// Returns a comedy or drama movie pointer ////
Movie * MovieFactory::createMovie(char genre,
	 string directorName, string movieTitle, int releaseYear)
{
	Movie * newMovie = NULL;

	if (genre == 'F') {
		newMovie = new ComedyMovie(genre, directorName,
		 movieTitle, releaseYear);
		return newMovie;
	}

	else if (genre == 'D') {
		newMovie = new DramaMovie(genre, directorName,
		 movieTitle, releaseYear);
		return newMovie;
	}
	
	return newMovie;
}

///Destructor////
MovieFactory::~MovieFactory()
{
}
