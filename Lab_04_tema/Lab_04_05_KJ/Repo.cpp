#include "Repo.h"
#include "Filme.h"
#include<iostream>
using namespace std;

Repo::Repo()
{
	this->n = 0;
}

Repo::~Repo()
{
	this->n = 0;
}

void Repo::insert(Filme fil)
{
	this->film[this->n++] = fil;
}

int Repo::get_Size()
{
	return this->n;
}

Filme* Repo::get_All()
{
	return this->film;
}

int Repo::findFilme(Filme s)
{
	for (int i = 0; i < this->n; i++)
	{
		if (s == this->film[i])
		{
			return i;
		}
	}
	return -1;
}

void Repo::deleteFilme(Filme s)
{
	int poz = this->findFilme(s);
	if (poz >= 0 && poz <= n - 1) {
		for (int i = poz; i <= n - 2; i++)
			this->film[i] = this->film[i + 1];
		n--;
	}
}

void Repo::UpdateFilme(Filme s, char* name, char* date, char* gen)
{
	if (findFilme(s) == -1)
	{
		cout << "Nu exista";
	}
	else
	{
		Filme f(name, date, gen);
		int i = findFilme(s);
		this->film[i] = f;
	}
}