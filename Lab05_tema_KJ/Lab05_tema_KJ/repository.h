#pragma once
#include "domain.h"

class Repository
{
private:
    Movie movies[100];
    int n;
public:
    Repository();
    Repository(const Repository& repository);
    ~Repository();

    Repository& operator = (const Repository& repository);

    void addMovie(Movie& movie);
    int findMovie(Movie& movie);
    Movie getItemFromPosition(int i);
    void updateMovie(Movie& movie, char*, char*, char*);
    void deleteMovie(Movie& movie);
    Movie* getAll();
    int getSize();

};


