#define CATCH_CONFIG_MAIN 
#include "catch2/catch.hpp"
#include "movie.h"
#include "movie_factory.h"

TEST_CASE("Testing the Getter Functions")
{
	Movie newMovie("Hello World", "Nick Tan", 160, 9781, 9.6);

	REQUIRE(newMovie.GetTitle() == "Hello World");
	REQUIRE(newMovie.GetDirector() == "Nick Tan");
	REQUIRE(newMovie.GetRuntime() == 160);
	REQUIRE(newMovie.GetID() == 9781);
	REQUIRE(newMovie.GetRating() == 9.6);
}

TEST_CASE("Testing Constructor invalid cases")
{
	REQUIRE_THROWS(Movie("Hello World", "Nick Tan", -140, 9781, 9.6));
	REQUIRE_THROWS(Movie("Hello World", "Nick Tan", 100, 9781, 20));
}

TEST_CASE("Testing create movies functions", "[CreateMovies][valid]")
{
	// Vectors representing movie data
	std::vector<std::string> titles{ "Movie 1", "Movie 2", "Movie 3", "Movie 4", "Movie 5" };
	std::vector<std::string> directors{ "Director 1", "Director 2", "Director 3", "Director 4", "Director 5" };
	std::vector<int> runtimes{ 140, 175, 150, 160, 140 };
	std::vector<int> ids{ 1, 2, 3, 4, 5 };
	std::vector<double> ratings{ 9.1, 9.2, 9.0, 8.8, 8.9 };

	Movie* movie1 = new Movie("Movie 1", "Director 1", 140, 1, 9.1);
	Movie* movie2 = new Movie("Movie 2", "Director 2", 175, 2, 9.2);
	Movie* movie3 = new Movie("Movie 3", "Director 3", 150, 3, 9.0);
	Movie* movie4 = new Movie("Movie 4", "Director 4", 160, 4, 8.8);
	Movie* movie5 = new Movie("Movie 5", "Director 5", 140, 5, 8.9);
	vector<Movie*> movieTest = CreateMovies(titles, directors, runtimes, ids, ratings);
	vector<Movie*> movieList{ movie1, movie2, movie3, movie4, movie5 };

	for (int i = 0; i < movieList.size(); i++)
	{
		REQUIRE(movieTest[i]->GetTitle() == movieList[i]->GetTitle());
		REQUIRE(movieTest[i]->GetDirector() == movieList[i]->GetDirector());
		REQUIRE(movieTest[i]->GetRuntime() == movieList[i]->GetRuntime());
		REQUIRE(movieTest[i]->GetID() == movieList[i]->GetID());
		REQUIRE(movieTest[i]->GetRating() == movieList[i]->GetRating());
	}

}

TEST_CASE("Testing invalid create movie functions", "[CreateMovie][invalid]")
{
	std::vector<std::string> titles{ "Movie 1", "Movie 2", "Movie 3", "Movie 4", "Movie 5" };
	std::vector<std::string> directors{ "Director 1", "Director 2", "Director 3", "Director 4", "Director 5" };
	std::vector<int> runtimes{ 140, 175, 150, 160, 140 };
	std::vector<int> ids{ 1, 2, 3, 4, 5 };
	std::vector<double> ratings{ 9.1, 9.2, 9.0, 8.8, 8.9 };

	std::vector<std::string> inDirectors{"Director 2", "Director 3", "Director 4", "Director 5" };
	std::vector<int> inRuntimes{ 140, 175, 150, 160};
	std::vector<int> inIds{ 1, 2, 3, 4};
	std::vector<double> inRatings{ 9.1, 9.2, 8.8, 8.9 };

	REQUIRE_THROWS(CreateMovies(titles, inDirectors, runtimes, ids, ratings));
	REQUIRE_THROWS(CreateMovies(titles, directors, inRuntimes, ids, ratings));
	REQUIRE_THROWS(CreateMovies(titles, directors, runtimes, inIds, ratings));
	REQUIRE_THROWS(CreateMovies(titles, directors, runtimes, ids, inRatings));
}
