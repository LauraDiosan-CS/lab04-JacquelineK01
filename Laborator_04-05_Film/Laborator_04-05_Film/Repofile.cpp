#include "Repofile.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


RepositoryFile::RepositoryFile()
{

}

RepositoryFile::RepositoryFile(const char* fileName)
{
	fis = fileName;
	ifstream f(fileName);
	string linie;
	char* titlu = new char[10];
	int data;
	char* gen = new char[15];
	while (!f.eof()) {
		f >> titlu >> gen >> data;
		if (titlu != "") {
			Filme s(titlu, data, gen);
			elem.push_back(s);
		}
	}
	delete[] titlu;
	f.close();
}

void RepositoryFile::loadFromFile(const char* fileName)
{
	elem.clear();
	fis = fileName;
	ifstream f(fileName);
	char* titlu = new char[10];
	char* gen = new char[15];
	int data;
	while (!f.eof()) {
		f >> titlu >> data >> gen;
		if (strcmp(titlu, "") != 0) {
			Filme s(titlu, data, gen);
			elem.push_back(s);
		}
	}
	delete[] titlu;
	delete[] gen;
	f.close();
}

void RepositoryFile::addElem(Filme s)
{
	elem.push_back(s);
}

void RepositoryFile::updateElem(Filme s, char* newTitle, int newData, char* newGenre)
{
	vector<Filme>::iterator it;
	it = find(elem.begin(), elem.end(), s);
	if (it != elem.end())
	{
		(*it).setTitlu(newTitle);
		(*it).setdata(newData);
		(*it).setgen(newGenre);
	}

}

//returneaza pozitia la care se gaseste filmul s, sau -1, daca acesta nu apare
int RepositoryFile::findElem(Filme s)
{
	vector<Filme>::iterator it;
	it = find(elem.begin(), elem.end(), s);
	if (it != elem.end()) {
		return distance(elem.begin(), it);
	}
	return -1;
}

//sterge elementul s din repository, returneaza 0 la succes, -1 altfel
int RepositoryFile::delElem(Filme s)
{
	vector<Filme>::iterator it;
	it = find(elem.begin(), elem.end(), s);
	if (it != elem.end()) {
		elem.erase(it);
		return 0;
	}
	return -1;

}

vector<Filme> RepositoryFile::getAll()
{
	return elem;
}

int RepositoryFile::size()
{
	return elem.size();
}

void RepositoryFile::saveToFile()
{
	ofstream f(fis);
	for (size_t i = 0; i < elem.size(); i++) {
		f << elem[i];
	}
	f.close();
}


RepositoryFile::~RepositoryFile()
{

}

