#pragma once
#include "Repofile.h"
#include "film.h"
#include <vector>
using namespace std;

class Service
{
private:
	RepositoryFile repo;
public:
	Service();
	Service(const RepositoryFile&);
	void setRepo(const RepositoryFile&);
	void addFilm(Filme&);
	int delFilm(Filme&);
	vector<Filme> getAll();
	Filme update(Filme, char*, int, char*);
	bool findOne(Filme);
	vector<Filme> sortByTitle();
	vector<Filme> sortByData();
	~Service();
};