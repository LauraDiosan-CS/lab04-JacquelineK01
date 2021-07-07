#include "film.h"
#include <iostream>
#include <string.h>
using namespace std;

Filme::Filme()
{
	titlu = NULL;
	gen = NULL;
	data = 0;
}

Filme::Filme(char* titlu, int data, char* gen)
{
	this->titlu = new char[strlen(titlu) + 1];
	strcpy_s(this->titlu, 1 + strlen(titlu), titlu);
	this->gen = new char[strlen(gen) + 1];
	strcpy_s(this->gen, 1 + strlen(gen), gen);
	this->data = data;
}

Filme::Filme(const Filme& s)
{
	this->titlu = new char[strlen(s.titlu) + 1];
	strcpy_s(this->titlu, 1 + strlen(s.titlu), s.titlu);
	this->gen = new char[strlen(s.gen) + 1];
	strcpy_s(this->gen, 1 + strlen(s.gen), s.gen);
	this->data = s.data;
}

Filme& Filme::operator=(const Filme& t)
{
	if (this == &t) return *this; //self-assignment
	if (titlu) delete[] titlu;
	titlu = new char[strlen(t.titlu) + 1];
	strcpy_s(titlu, strlen(t.titlu) + 1, t.titlu);
	data = t.data;
	return *this;
	// TODO: insert return statement here
}

Filme::~Filme()
{
	if (this->titlu)
	{
		delete[] this->titlu;
		this->titlu = NULL;
	}
	if (this->gen)
	{
		delete[] this->gen;
		this->gen = NULL;
	}
	this->data = -1;
}

char* Filme::getTitlu()
{
	return titlu;
}

int Filme::getdata()
{
	return data;
}

char* Filme::getgen()
{
	return gen;
}

void Filme::setTitlu(char* titlu)
{
	if (this->titlu)
		delete[] this->titlu;
	this->titlu = new char[strlen(titlu) + 1];
	strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
}

void Filme::setdata(int data)
{
	this->data = data;
}

void Filme::setgen(char* genre)
{
	if (gen)
		delete[] gen;
	gen = new char[strlen(genre) + 1];
	strcpy_s(gen, strlen(genre) + 1, genre);
}

bool Filme::operator==(const Filme& t)
{
	return (strcmp(titlu, t.titlu) == 0) and (data == t.data) and strcmp(gen, t.gen) == 0;
}

bool Filme::operator<(const Filme& s)
{
	return (strcmp(titlu, s.titlu) < 0);
}

ostream& operator<<(ostream& os, Filme s) {
	os << s.getTitlu() << " " << s.getdata() << " " << s.getgen() << endl;
	return os;
}


istream& operator>>(istream& is, Filme& s)
{
	// TODO: insert return statement here
	cout << "Dati titlul: ";
	char* titlu = new char[10];
	is >> titlu;
	cout << "Dati data: ";
	int data;
	cin >> data;
	cout << "Dati genul: ";
	char* gen = new char[15];
	cin >> gen;
	s.setTitlu(titlu);
	s.setdata(data);
	s.setgen(gen);
	delete[] titlu;
	delete[] gen;
	return is;
}
