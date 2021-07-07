#pragma once
#include <ostream>

class Filme {
private:
	char* date;
	char* name;
	char* gen;

public:
	Filme();//constructor implicit
	Filme(char*, char*, char*);//constructor de initializare
	Filme(const Filme&);//constructor de copiere
	~Filme();//destructor

//Getters

	char* get_name();
	char* get_date();
	char* get_gen();

	//Setters

	void set_name(char*);
	void set_date(char*);
	void set_gen(char*);

	//Overwrite operators '=' , "==" and "<<"

	Filme& operator =(const Filme&);
	bool operator==(const Filme&);
	friend std::ostream& operator << (std::ostream&, const Filme&);

};