#pragma once

#include <iostream>
#include <vector>
#include "movie.h"

//movie_factory.h
/*
Write function declaration CreateMovies() that
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
	const vector<int>& runtimes, const vector<int>& ids, const vector<double>& ratings);
