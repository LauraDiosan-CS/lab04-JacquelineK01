#include "UI.h"

#include <iostream>

using namespace std;

void initService(Service& s)
{
	RepositoryFile r;
	r.loadFromFile("Filme.txt");
	s.setRepo(r);
}

int main() {
	cout << "start..." << endl;
	Service serv;
	initService(serv);
	showUI(serv);
	cout << "succes";
	return 0;
}