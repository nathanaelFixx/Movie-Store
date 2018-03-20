
#ifndef DRAMAMOVIE_H
#define DRAMAMOVIE_H

#include "Movie.h"
#include <iostream>
#include <iomanip>

using namespace std;

class DramaMovie : public Movie
{
public:
      
    /////// Constructor /////////
    DramaMovie(char genre, string directorName, 
    string movieTitle, int releaseYear);
    
    /////// Destructor /////////	
    virtual ~DramaMovie();

    ///////Operator overloads ///////	
    virtual bool operator==(const Movie& rhs);
    virtual bool operator<(const Movie& rhs);
    virtual bool operator>(const Movie& rhs);
    
    /// Method used in classic movie //////
    virtual bool isSame(const Movie& rhs);

    ////print out movie data ////
    virtual void print();

private:

};
#endif // !DRAMAMOVIE_H
