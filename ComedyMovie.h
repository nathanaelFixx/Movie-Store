
#ifndef COMEDY_MOVIE_H
#define COMEDY_MOVIE_H

#include "Movie.h"

class ComedyMovie : public Movie
{
public:
  
    /////// Constructor /////////
    ComedyMovie(char genre, string directorName, 
    string movieTitle, int releaseYear);
    
    /////// Destructor /////////
    virtual ~ComedyMovie();

    ///////Operator overloads ///////
    virtual bool operator==(const Movie &rhs);
    virtual bool operator<(const Movie  &rhs);
    virtual bool operator>(const Movie  &rhs);

    /// Method used in classic movie //////
    virtual bool isSame(const Movie &rhs);

    ////print out movie data ////
    virtual void print();
};

#endif // !COMEDY_MOVIE_H