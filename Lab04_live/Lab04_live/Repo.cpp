#include "Repo.h"

Repo::Repo() {
	this->n = 0;
}

Repo::~Repo() {
	this->n = 0;
}

void Repo::addFilm(Film f) {
	this->filme[this->n++] = f;
}

Film* Repo::getAll() {
	return this->filme;
}