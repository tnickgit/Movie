#ifndef MOVIE_H
#define MOVIE_H


#include <iostream>
#include <string>


using namespace std;

//movie.h
class Movie {
private:
	int id;

	std::string title;
	std::string director;
	int runtime; // runtime in minitues >= 0
	double rating; // range 0-10

public:
	Movie(std::string t, std::string d, int r, int i, double rate);

	std::string GetTitle() const; //returns title
	std::string GetDirector() const; // returns director
	double GetRating() const; // returns rating
	int GetRuntime() const; // returns the runtime
	int GetID() const; //returns the ID

	void PrintMovieData(); // to print details

};
#endif //MOVIE_H
