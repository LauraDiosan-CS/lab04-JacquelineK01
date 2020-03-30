#pragma once
#include "repository.h"

class Service
{
private:
    Repository repository;
    Repository* options;
    int number_options;
public:
    Service();
    Service(const Service& service);
    ~Service();


    Service& operator = (const Service& service);

    void addMovie(Movie& movie);
    int findMovie(Movie& movie);
    Movie getItemFromPosition(int i);
    Movie* updateMovie(Movie& movie, char* title, char* date, char* genre);
    void deleteMovie(Movie& movie);
    Movie* getAll();
    int getSize();

    void filter_movies_by_genre(char* gender, Movie filter_movies[100], int& m);
    void delete_movies_by_date(char* date);

    int undo();
};

