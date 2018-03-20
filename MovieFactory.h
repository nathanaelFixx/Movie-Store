

#ifndef MOVIE_FACTORY_H
#define MOVIE_FACTORY_H

#include "Movie.h"
using namespace std;

class MovieFactory
{
public:
	/// Constructor ///
	MovieFactory();
	
	/// Destructor ///
	~MovieFactory();

	/// Returns a classic movie pointer ////
	Movie * createMovie(char genre, string directorName,
	 string movieTitle, string majorActor, int releaseMonth,
	 int releaseYear);
	
	/// Returns a comedy or drama movie pointer ////
	Movie * createMovie(char genre, string directorName,
	 string movieTitle, int releaseYear);

};

#endif // !MOVIE_FACTORY_H

