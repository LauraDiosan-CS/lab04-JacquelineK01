#pragma once
#include <ostream>
using namespace std;

class Film {
private:
	char* titlu;
	char* data;
	char* gen;

public:
	Film();
	Film(char* titlul, char* data, char* gen);
	Film(const Film& f);
	~Film();
	char* getTitlu();
	char* getData();
	char* getGen();
	void setTitlu(char* titlu);
	void setData(char* data);
	void setGen(char* gen);
	Film& operator= (const Film& f);
	bool operator== (const Film& f);
	friend ostream& operator<<(ostream& os, const Film& f);
};
