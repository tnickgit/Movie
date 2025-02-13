#include "movie.h"
#include "movie_factory.h"
#include <iostream>
#include <vector>
#include <limits>
#include <string>


Movie* FindHighestRatedMovie(vector<Movie*>& movies)
{
	double rating = 0;
	size_t highestMovie = 0;
	for (size_t i = 0; i < movies.size(); i++)
	{
		double movieRate = movies[i]->GetRating();
		if (movieRate > rating)
		{
			highestMovie = i;
			rating = movieRate;
		}
	}

	return movies[highestMovie];
}

int CalculateAverageRuntime(vector<Movie*> movies)
{
	int sum = 0;
	int amount = 0;
	for (int i = 0; i < movies.size(); i++)
	{
		sum += movies[i]->GetRuntime();
		amount++;
	}

	return sum / amount;
}

int main() {
	// Vectors representing movie data
	std::vector<std::string> titles{ "Movie 1", "Movie 2", "Movie 3", "Movie 4", "Movie 5" };
	std::vector<std::string> directors{ "Director 1", "Director 2", "Director 3", "Director 4", "Director 5" };
	std::vector<int> runtimes{ 140, 175, 150, 160, 140 };
	std::vector<int> ids{ 1, 2, 3, 4, 5 };
	std::vector<double> ratings{ 9.1, 9.2, 9.0, 8.8, 8.9 };

	// Create `movies` using the factory function `CreateMovies`
	vector<Movie*> movies = CreateMovies(titles, directors, runtimes, ids, ratings);
 
	// Perform analysis
    // Find `highest_rated` movie using `FindHighestRatedMovie`
    // Find `average_runtime` using `CalculateAverageRuntime`
	Movie* highestRated = FindHighestRatedMovie(movies);
	int average = CalculateAverageRuntime(movies);

	string highestMovie = highestRated->GetTitle();

	// Print data of the `highest_rated` movie
	cout << "Highest rated Movie: " << highestMovie << endl;

	// Print Average Runtime `average_runtime`
	cout << "Average Runtime: " << average << endl;

	return 0;
}