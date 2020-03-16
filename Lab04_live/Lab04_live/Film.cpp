#include "Film.h"
#include <cstring>

Film::Film()
{
	this->titlu = NULL;
	this->data = 0;
	this->gen = NULL;
}

Film::Film(char* titlu, char* data, char* gen)
{
	strcpy(this->titlu, titlu);
	strcpy(this->data,data);
	strcpy(this->gen, gen);
}

Film::Film(const Film& f)
{
	this->titlu = new char[strlen(f.titlu) + 1];
	strcpy(this->titlu, titlu);
	this->data = new char[strlen(f.data) + 1];
	strcpy(this->data, data);
	this->gen = new char[strlen(f.gen) + 1];
	strcpy(this->gen, gen);

}

Film::~Film()
{
	if (this->titlu) {
		delete[] this->titlu;
		this->titlu = NULL;
	}

	if (this->data) {
		delete[] this->data;
		this->data = NULL;
	}

	if (this->gen) {
		delete[] this->gen;
		this->gen = NULL;
	}
}

char* Film::getTitlu()
{
	return this->titlu;
}

char* Film::getData()
{
	return this->data;
}

char* Film::getGen()
{
	return this->gen;
}

void Film::setTitlu(char* ttlu)
{
	strcpy(this->titlu, titlu);
}

void Film::setData(char* data)
{
	strcpy(this->data, data);
}

void Film::setGen(char* gen)
{
	strcpy(this->gen, gen);
}

Film& Film::operator=(const Film& f)
{
	this->setTitlu(f.titlu);
	this->setData(f.data);
	this->setGen(f.gen);
	return *this;
}

bool Film::operator==(const Film& f)
{
	return strcmp(this->titlu, f.titlu) == 0 && strcmp(this->data,f.data) == 0 && strcmp(this->gen, f.gen) == 0;
}

ostream& operator<<(ostream& os, const Film& f)
{
	os << "Titlu: " << f.titlu << "Data: " << f.data << " Gen: " << f.gen;
	return os;
}