#include<iostream>
#include "repository.h"
using namespace std;

Repository::Repository()
{
	this->n = 0;
}

Repository::Repository(const Repository& repository)
{
	this->n = repository.n;
	for (int i = 0; i < this->n; i++)
	{
		this->movies[i] = repository.movies[i];
	}
}

Repository::~Repository()
{
	this->n = 0;
}


Repository& Repository:: operator=(const Repository& repository)
{
	this->n = repository.n;
	for (int i = 0; i < this->n; i++)
	{
		this->movies[i] = repository.movies[i];
	}
	return *this;
}

void Repository::addMovie(Movie& movie)
{
	this->movies[this->n++] = movie;
}

int Repository::findMovie(Movie& movie)
{
	int i = 0;
	while (i < getSize())
	{
		if (movies[i] == movie)
			return i;
		i++;
	}
	return -1;
}

Movie Repository::getItemFromPosition(int i)
{
	return movies[i];
}

void Repository::updateMovie(Movie& movie, char* title, char* date, char* genre)
{
	int i;
	for (i = 0; i < getSize(); i++)
	{
		if (movies[i] == movie)
		{
			movies[i].setTitle(title);
			movies[i].setDate(date);
			movies[i].setGenre(genre);
		}
	}
}

void Repository::deleteMovie(Movie& movie)
{
	int i = findMovie(movie);
	if (i != -1)
		movies[i] = movies[n - 1];
	n--;
}

Movie* Repository::getAll()
{
	return this->movies;
}

int Repository::getSize()
{
	return this->n;
}