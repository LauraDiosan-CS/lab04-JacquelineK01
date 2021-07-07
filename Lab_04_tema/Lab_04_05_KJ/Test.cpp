#include "Test.h"
#include "Repo.h"
#include <cassert>

void tests() {
	char* nume1 = new char[10], * data1 = new char[10], * gen1 = new char[10];
	char* nume2 = new char[10], * data2 = new char[10], * gen2 = new char[10];

	strcpy_s(nume1, sizeof "Spongebob", "Spongebob");
	strcpy_s(data1, sizeof "15.12.2010", "15.12.2010");
	strcpy_s(gen1, sizeof "Cartoon", "Cartoon");
	Filme s1(nume1, data1, gen1);

	strcpy_s(nume2, sizeof "Batman", "Batman");
	strcpy_s(data2, sizeof "12.08.2019", "12.08.2019");
	strcpy_s(gen2, sizeof "Actiune", "Actiune");
	Filme s2(nume2, data2, gen2);
	Repo repo;
	Filme gestiune[4];
	gestiune[0] = s1;
	gestiune[1] = s2;
	repo.insert(s1);
	repo.insert(s2);

	repo.deleteFilme(s2);
	assert(repo.get_Size() == 1);

	for (int i = 0; i < repo.get_Size(); i++)
	{
		assert(repo.get_All()[i] == gestiune[i]);
	}
}