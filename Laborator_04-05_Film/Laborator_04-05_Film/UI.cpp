#include "UI.h"
#include <iostream>
using namespace std;

void addfilme(Service& s) {
	Filme films;
	cout << "Creare film " << endl;
	cin >> films;
	s.addFilm(films);
	cout << "Filmul a fost adaugat cu succes!" << endl;
}


void findfilme(Service& serv) {
	Filme films;
	cout << "Dati filmul: ";
	cin >> films;
	bool rez = serv.findOne(films);
	if (rez) cout << "Filmul a fost gasit!" << endl;
	else cout << "Filmul nu a fost gasit!" << endl;
}

void delfilme(Service& serv) {
	Filme films;
	cout << "Dati filmul:";
	cin >> films;
	int rez = serv.delFilm(films);
	if (rez == 0) cout << "Filmul a fost  sters cu succes!" << endl;
	else cout << "Filmul NU a fost sters!" << endl;
}

void showAll(Service& serv) {
	vector<Filme> stud = serv.getAll();
	for (Filme s : stud)//"range based for loop"~Java,C#
		cout << s;
}


void showAlphabeticallySorted(Service& serv) {
	vector<Filme> stud = serv.sortByTitle();
	for (Filme s : stud)
		cout << s;
}

void showDataSorted(Service& serv) {
	vector<Filme> stud = serv.sortByData();
	for (Filme s : stud)
		cout << s;
}


void showUI(Service& serv)
{
	bool gata = false;
	while (!gata) {
		cout << endl;
		cout << "OPTIUNI: " << endl;
		cout << "	1. Adauga film " << endl;
		cout << "	2. Cauta film " << endl;
		cout << "	3. Sterge film " << endl;
		cout << "	4. Afiseaza toate filmele " << endl;
		cout << "	0. EXIT!" << endl;
		cout << "Introduceti optiunea (prin numarul ei): " << endl;
		int opt;
		cin >> opt;
		switch (opt) {
		case 1: {addfilme(serv); break; }
		case 2: {findfilme(serv); break; }
		case 3: {delfilme(serv); break; }
		case 4: {showAll(serv); break; }
		case 0: {gata = true; cout << "LA REVEDERE!" << endl; }
		}
	}
}
