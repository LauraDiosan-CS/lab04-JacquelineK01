#include "Filme.h"
#include <cstring>

Filme::Filme() {
	this->name = 0;
	this->date = NULL;
	this->gen = 0;
}

Filme::Filme(char* name, char* date, char* gen)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, 1 + strlen(name), name);

	this->date = new char[strlen(date) + 1];
	strcpy_s(this->date, 1 + strlen(date), date);

	this->gen = new char[strlen(gen) + 1];
	strcpy_s(this->gen, 1 + strlen(gen), gen);

}

Filme::Filme(const Filme& expence)
{
	this->name = new char[strlen(expence.name) + 1];
	strcpy_s(this->name, 1 + strlen(expence.name), expence.name);

	this->date = new char[strlen(expence.date) + 1];
	strcpy_s(this->date, 1 + strlen(expence.date), expence.date);

	this->gen = new char[strlen(expence.gen) + 1];
	strcpy_s(this->gen, 1 + strlen(expence.gen), expence.gen);
}

Filme::~Filme()
{
	if (this->date)
	{
		delete[] this->date;
		this->date = NULL;
	}
}

//------------------------------------------------------Getters

char* Filme::get_name()
{
	return this->name;
}

char* Filme::get_date()
{
	return this->date;
}

char* Filme::get_gen()
{
	return this->gen;
}
//-----------------------------------------------------------Setters

void Filme::set_name(char* new_name)
{
	this->name = new char[strlen(new_name) + 1];
	strcpy_s(this->name, 1 + strlen(new_name), new_name);
}

void Filme::set_date(char* new_date)
{
	this->date = new char[strlen(new_date) + 1];
	strcpy_s(this->date, 1 + strlen(new_date), new_date);
}

void Filme::set_gen(char* new_gen)
{
	this->gen = new char[strlen(new_gen) + 1];
	strcpy_s(this->gen, 1 + strlen(new_gen), new_gen);
}

Filme& Filme:: operator =(const Filme& gestiune)
{
	this->set_name(gestiune.name);
	this->set_date(gestiune.date);
	this->set_gen(gestiune.gen);
	return *this;
}

bool Filme:: operator==(const Filme& s)
{
	return strcmp(this->date, s.date) == 0 and strcmp(this->name, s.name) == 0 and strcmp(this->gen, s.gen) == 0;
}

std::ostream& operator <<(std::ostream& os, const Filme& gestiune)
{
	os << std::endl << "Titlu: " << gestiune.name << " Data: " << gestiune.date << " Gen: " << gestiune.gen << std::endl;
	return os;
}