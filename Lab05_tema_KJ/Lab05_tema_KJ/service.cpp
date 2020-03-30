#include<iostream>
#include "service.h"
using namespace std;

Service::Service()
{
    number_options = 0;
    options = new Repository[10];
    options[number_options++] = repository;
}

Service::Service(const Service& service)
{
    this->repository = service.repository;
    this->options = service.options;
    this->number_options = service.number_options;
}

Service::~Service()
{
    if (options != NULL)
        delete[] options;
}

Service& Service::operator=(const Service& service)
{
    if (this == &service)
        return *this;

    this->repository = service.repository;
    this->options = service.options;
    this->number_options = service.number_options;
}

void Service::addMovie(Movie& movie)
{
    repository.addMovie(movie);

    options[number_options++] = repository;
}

int Service::findMovie(Movie& movie)
{
    return repository.findMovie(movie);
}

Movie Service::getItemFromPosition(int i)
{
    return repository.getItemFromPosition(i);
}

Movie* Service::updateMovie(Movie& movie, char* title, char* date, char* genre)
{
    repository.updateMovie(movie, title, date, genre);

    options[number_options++] = repository;

    return &movie;
}

void Service::deleteMovie(Movie& movie)
{
    repository.deleteMovie(movie);

    options[number_options++] = repository;
}

Movie* Service::getAll()
{
    return repository.getAll();
}

int Service::getSize()
{
    return repository.getSize();
}

void Service::filter_movies_by_genre(char* gender, Movie filter_movies[100], int& m)
{
    int i;
    for (i = 0; i < repository.getSize(); i++)
    {
        Movie crt_Movie = repository.getItemFromPosition(i);
        if (strcmp(crt_Movie.getGenre(), gender) == 0)
        {
            filter_movies[m++] = crt_Movie;
        }
    }
    if (m == 0)
        cout << "Nu exista!" << endl;

}

void Service::delete_movies_by_date(char* date)
{
    int i = 0;
    while (i < repository.getSize())
    {
        Movie crt_Movie = repository.getItemFromPosition(i);
        if (strcmp(crt_Movie.getDate(), date) < 0)
        {
            repository.deleteMovie(crt_Movie);
        }
        i++;
    }

    options[number_options++] = repository;
}

int Service::undo()
{
    if (number_options > 1)
    {
        number_options--;
        this->repository = this->options[number_options - 1];
        return 0;
    }
    else
        return -1;
}