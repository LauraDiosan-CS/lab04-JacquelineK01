#include "Service.h"
#include <algorithm> 

Service::Service()
{
}

Service::Service(const RepositoryFile& r)
{
	repo = r;
}

void Service::setRepo(const RepositoryFile& r)
{
	repo = r;
}

void Service::addFilm(Filme& s)
{
	repo.addElem(s);
}

int Service::delFilm(Filme& s)
{
	return repo.delElem(s);
}

vector<Filme> Service::getAll()
{
	return repo.getAll();
}

Filme Service::update(Filme s, char* t, int d, char* g)
{
	repo.updateElem(s, t, d, g);
	return s;
}

bool Service::findOne(Filme s)
{
	return repo.findElem(s);
}
//sorteaza Filmele alfabetic
vector<Filme> Service::sortByTitle()
{
	vector<Filme> all = repo.getAll();
	std::sort(all.begin(), all.end());
	return all;
}

bool myFilmCompare(Filme x, Filme y) { return (x.getdata() > y.getdata()); }
//sorteaza descrescator dupa data
vector<Filme> Service::sortByData()
{
	vector<Filme> all = repo.getAll();
	std::sort(all.begin(), all.end(), myFilmCompare);
	return all;
}

Service::~Service()
{
}
