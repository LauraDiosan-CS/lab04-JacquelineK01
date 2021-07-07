#pragma once
#include "service.h"

class UserInterface
{
private:
    Service service;
public:
    UserInterface();
    UserInterface(const Service& service);
    ~UserInterface();

    void readingMovie();
    void displayMovie();
    void updateMovie();
    void deleteMovie();
    void filter_movies_by_genre();
    void delete_movies_by_date();
    void show_menu();
    int run();

    void undo();
};

