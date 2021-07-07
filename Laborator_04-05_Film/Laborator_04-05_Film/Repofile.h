#pragma once
#include "film.h"
#include <vector>
using namespace std;

class RepositoryFile
{
private:
	vector<Filme> elem;
	const char* fis;
public:
	RepositoryFile();
	RepositoryFile(const char* fileName);
	void loadFromFile(const char* fileName);
	void addElem(Filme);
	void updateElem(Filme, char*, int, char*);
	int findElem(Filme);
	int delElem(Filme);
	vector<Filme> getAll();
	int size();
	void saveToFile();
	~RepositoryFile();
};


