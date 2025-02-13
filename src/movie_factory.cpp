#include "movie_factory.h"

//movie_factory.cpp
/*
Write function definition CreateMovies() that
accepts (attributes in the below order)
  vector of titles,
  vector of directors,
  vector of runtimes,
  vector of ids,
  vector of ratings and
return
  vector of pointers of Movie objects
*/

std::vector<Movie*> CreateMovies(const vector<string>& titles, const vector<string>& directors,
	const vector<int>& runtimes, const vector<int>& ids, const vector<double>& ratings)
{
	vector<Movie*> movies;

	//if the other vectors lengths does not equal the size of the titles then throw an exception
	if (directors.size() != titles.size() || runtimes.size() != titles.size() || ids.size() != titles.size() || ratings.size() != titles.size())
	{
		throw invalid_argument("Size of the title vector size does not match other vector sizes");
	}

	size_t list = titles.size(); //reason for this is since all the vectors are equal sizes this would create a size list for all vectors

	//for loop to go through on the entries of all the vectors
	for (size_t l = 0; l < list; l++)
	{
		string title = titles[l];
		string director = directors[l];
		int runtime = runtimes[l];
		int id = ids[l];
		double rating = ratings[l];

		Movie* movie = new Movie(title, director, runtime, id, rating);

		movies.push_back(movie);
	}

	return movies;

}