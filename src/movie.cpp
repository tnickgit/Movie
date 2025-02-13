#include "movie.h"


Movie::Movie(std::string t, std::string d, int r, int i, double rate)
{
	this->title = t;
	this->director = d;

	if (r < 0){ throw invalid_argument("runtimes cannot be negative"); }
	else { this->runtime = r; }

	this->id = i;

	if (rate < 0 || rate > 10) { throw invalid_argument("Ratings must be between 0-10"); }
	else { this->rating = rate; }
}

string Movie::GetTitle() const
{
	return title;
}

string Movie::GetDirector() const
{
	return director;
}

double Movie::GetRating() const
{
	return rating;
}

int Movie::GetRuntime() const
{
	return runtime;
}

int Movie::GetID() const
{
	return id;
}

void Movie::PrintMovieData()
{
	cout << "ID: " << GetID() << " Title: " << GetTitle() <<
		" Director: " << GetDirector() << " Runtime: " << GetRuntime() <<
		" Rating: " << GetRating() << "\n";
}