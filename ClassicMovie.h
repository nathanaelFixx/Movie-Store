

#ifndef CLASSIC_MOVIE_H
#define CLASSIC_MOVIE
#include "Movie.h"
#include <vector>

class ClassicMovie : public Movie
{
public:
    
    /////// Constructor /////////
    ClassicMovie(char genre, string directorName, 
    string movieTitle, string majorActor, int releaseMonth, int releaseYear);
    
    /////// Destructor ///////// 
    virtual ~ClassicMovie();

    ///////Operator overloads ///////	
    virtual bool operator==(const Movie& rhs);
    virtual bool operator<(const Movie& rhs);
    virtual bool operator>(const Movie& rhs);

    /// Method used in classic movie //////
    virtual bool isSame(const Movie& rhs);

    /////// getters ///////
    virtual int getReleaseMonth() const;
    virtual string getMajorActor() const; // get the major actor for the movie
    
    ////print out movie data ////
    virtual void print(); 

    //// returns a boolean value if it finds the pass in parameter ////
    virtual bool findMajorActor(string actor) const;

private:
	vector<string>majorActor;
	int releaseMonth;
};

#endif // !CLASSIC_MOVIE