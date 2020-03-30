#include <iostream>
#include "Repo.h"
#include "Test.h"
#include "Service.h"

using namespace std;

void menu()
{
    cout << "---------------------------MENU-------------------------------" << endl;
    cout << "1.Adaugare film" << endl;
    cout << "2.Afisare filme" << endl;
    cout << "3.Stergere film" << endl;
    cout << "4.Update film" << endl;
    //cout << "5.Afisarea tuturor filmelor dintr-un anumit gen" << endl;
    //cout << "6.Eliminarea filmelor lansate inaintea unei date calendaristice" << endl;
    //cout << "7.Undo" << endl;
    cout << "x.EXIT" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;
}

bool except_date(char* string) {

    int list_of_days[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int nrok = 0, nrzile, nrluni, i;
    int nran = 0;
    if ('9' >= string[0] and string[0] >= '0' and '9' >= string[1] and string[1] >= '0' and string[2] == '.' and string[5] == '.')
    {
        nrzile = (string[0] - '0') * 10 + (string[1] - '0');
        nrluni = (string[3] - '0') * 10 + (string[4] - '0');
    }

    else
        return false;

    i = 6;
    while (i < strlen(string))
    {
        if (string[i] == '.')
            return false;
        nran = nran * 10 + (string[i] - '0');
        i = i + 1;
    }
    if (0 < nrluni and nrluni <= 12 and list_of_days[nrluni] >= nrzile and nrzile > 0 and (nran % 4 == 0 or nran % 400 == 0))
        nrok = nrok + 1;

    else
        if (0 < nrluni and nrluni <= 12 and list_of_days[nrluni] > nrzile and nrzile > 0)
            nrok = nrok + 1;

    if (nrok == 1)
        return true;

    else
        return false;
}

int main()
{
    tests();
    int op = 1;
    char date[250], name[250], gen[250];
    Service service;
    Repo repo;
    while (op)
    {
        cout << "Alege optiune " << endl;
        menu();
        cout << "Optiunea este: ";
        cin >> op;
        if (op == 1)
        {
            cout << "Dati titlu film: ";
            cin >> name;
            int ok = 1;
            while (ok == 1)
            {
                cout << "Dati data: ";
                cin >> date;
                if (except_date(date))
                    ok = 0;
            }
            cout << "Dati genul filmului: ";
            cin >> gen;
            cout << endl;
            cout << "Film adaugat cu succes!";
            cout << endl;
            cout << endl;
            Filme filme(name, date, gen);
            service.insert_service(name, date, gen);
        }
        if (op == 2)
        {
            for (int i = 0; i < service.get_Size(); i++)
                cout << service.get_All()[i];
            cout << endl;
        }
        if (op == 3)
        {
            repo.get_All();
            cout << endl;
            char name_sters[100];
            char date_sters[100];
            char gen_sters[100];

            cout << "Introduceti titlul: ";
            cin >> name_sters;
            cout << "Introduceti data: ";
            cin >> date_sters;
            cout << "Introduceti genul: ";
            cin >> gen_sters;

            Filme s(name_sters, date_sters, gen_sters);
            service.deleteFilme(s);
            cout << endl;
            cout << "  Film sters cu succes!   " << endl;
        }
        if (op == 4)
        {
            repo.get_All();
            cout << endl;

            char name[100];
            char date[100];
            char gen[100];

            char name_new[100];
            char date_new[100];
            char gen_new[100];
            cout << "Introduceti titlul vechi: ";
            cin >> name;
            cout << "Introduceti data veche: ";
            cin >> date;
            cout << "Introduceti gen vechi: ";
            cin >> gen;
            Filme f(name, date, gen);
            cout << "Introduceti titlul: ";
            cin >> name_new;
            cout << "Introduceti data: ";
            cin >> date_new;
            cout << "Introduceti genul: ";
            cin >> gen_new;

            Filme s(name_new, date_new, gen_new);
            service.UpdateFilme(f, name_new, date_new, gen_new);
            cout << endl;
            cout << "  Modificare cu succes! " << endl;


        }
        //if (op == 5) 
        //{
            //repo.get_All();
            //cout << endl;

            //char name[100];
            //char date[100];
            //char gen[100];

            //cout << "Introduceti genul filmelor: ";
            //cin >> gen;
        //}

        //if (op == 6) 
        //{
            //repo.get_All();
            //cout << endl;

            //char name[100];
            //char date[100];
            //char gen[100];

            //char date_new[100];
            //cout << "Introduceti data pana la care vreti sa eliminati filme: ";
            //cin >> date_new;
        //}
        
    }
    return 0;
}