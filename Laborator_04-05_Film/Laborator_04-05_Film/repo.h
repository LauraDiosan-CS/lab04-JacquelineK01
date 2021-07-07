#pragma once
#include "film.h"
class Repo
{
private:
	Filme filme[10];
	int size;
public:
	Repo();
	void addElem(Filme);
	~Repo();
	int dim();
	Filme* getall();
};

void menu();