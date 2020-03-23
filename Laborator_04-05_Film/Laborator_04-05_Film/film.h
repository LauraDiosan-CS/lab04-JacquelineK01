#pragma once
#include <string>
#include <iostream>
using namespace std;

class Filme
{
private:
	char* titlu;
	int data;
	char* gen;
	

public:
	Filme();
	Filme(char*, int, char*);
	Filme(const Filme&);
	Filme& operator=(const Filme&);
	char* getTitlu();
	int getdata();
	char* getgen();
	void setTitlu(char*);
	void setdata(int);
	void setgen(char*);
	bool operator==(const Filme&);
	bool operator<(const Filme&);
	~Filme();
	friend ostream& operator<<(ostream& os, Filme s);
	friend istream& operator>>(istream&, Filme&);
};
