#include <assert.h>
#include <string.h>
#include "Tests.h"
#include "Film.h"
#include "Repo.h"


void test() {
	void testGetTitlu();
	void testGetData();
	void testGetGen();
	void testSetTitlu();
	void testSetData();
	void testSetGen();
	void testRepo();

}

void testGetTitlu()
{
	char titlu1[30];
	char data1[30];
	char gen1[30];
	strcpy(titlu1, "Mickey Mouse");
	strcpy(data1, "12.03.2019");
	strcpy(gen1, "Cartoon");
	Film f = Film(titlu1, data1, gen1);
	assert(strcmp(f.getTitlu(), titlu1) == 0);
}

void testGetData()
{
	char titlu1[30];
	char data1[30];
	char gen1[30];
	strcpy(titlu1, "Mickey Mouse");
	strcpy(data1, "12.03.2019");
	strcpy(gen1, "Cartoon");
	Film f = Film(titlu1, data1, gen1);
	assert(strcmp(f.getData(), data1) == 0);
}

void testGetGen()
{
	char titlu1[30];
	char data1[30];
	char gen1[30];
	strcpy(titlu1, "Mickey Mouse");
	strcpy(data1, "12.03.2019");
	strcpy(gen1, "Cartoon");
	Film f = Film(titlu1, data1, gen1);
	assert(strcmp(f.getGen(), gen1) == 0);
}

void testSetTitlu(char* titlu)
{
	char titlu1[30];
	char data1[30];
	char gen1[30];
	strcpy(titlu1, "Minnie Mouse");
	strcpy(data1, "12.03.2019");
	strcpy(gen1, "Cartoon");
	Film f = Film(titlu1, data1, gen1);

	char titlu2[30];
	strcpy(titlu2, "Mickey Mouse");
	f.setTitlu(titlu2);

	assert(strcmp(f.getTitlu(), titlu2) == 0);
}

void testSetData(char* data)
{
	char titlu1[30];
	char data1[30];
	char gen1[30];
	strcpy(titlu1, "Minnie Mouse");
	strcpy(data1, "12.03.2019");
	strcpy(gen1, "Cartoon");
	Film f = Film(titlu1, data1, gen1);

	char data2[30];
	strcpy(data2, "12.04.2019");
	f.setData(data2);

	assert(strcmp(f.getData(), data2) == 0);
}

void testSetGen(char* gen)
{
	char titlu1[30];
	char data1[30];
	char gen1[30];
	strcpy(titlu1, "Minnie Mouse");
	strcpy(data1, "12.03.2019");
	strcpy(gen1, "Cartoon");
	Film f = Film(titlu1, data1, gen1);

	char gen2[30];
	strcpy(gen2, "Comedie");
	f.setGen(gen2);

	assert(strcmp(f.getGen(), gen2) == 0);
}



void testRepo()
{
	char titlu1[30];
	char data1[30];
	char gen1[30];
	strcpy(titlu1, "Minnie Mouse");
	strcpy(data1, "12.03.2019");
	strcpy(gen1, "Cartoon");
	Film f1 = Film(titlu1, data1, gen1);

	char titlu2[30];
	char data2[30];
	char gen2[30];
	strcpy(titlu2, "Batman");
	strcpy(data2, "17.10.2019");
	strcpy(gen2, "Action");
	Film f2 = Film(titlu2, data2, gen2);

	Film filme[2];

	filme[0] = f1;
	filme[1] = f2;

	Repo r;
	Repo res;
	r.addFilm(f1);
	r.addFilm(f2);

	
	assert(r.getAll()[0] == f1);
	assert(r.getAll()[1] == f2);
}