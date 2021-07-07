#include "repo.h"
#include "film.h"
#include <iostream>
using namespace std;
Repo::Repo()
{
	this->size = 0;
}

void Repo::addElem(Filme t)
{
	filme[this->size++] = t;
}

Filme* Repo::getall()
{
	return filme;
}

Repo::~Repo()
{
}

int Repo::dim()
{
	return size;
}