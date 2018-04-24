#include <iostream>
#include "Stazysta.h"
#include "Pracownik.h"
#include "Kierownik.h"

using namespace std;
using namespace praca;

int main() {
    Osoba* osoby[4];

    Data d1(1, 12, 1970);
    Data d2(5, 4, 1997);
    Data d3(24, 4, 2018);
    Data d4(17, 10, 2020);

    cout << d1 << endl;
    d1.zapisz(cout);
    cout << endl;
//    cout << "Podaj nowa date d1: " << endl;
//    bool result = d1.wczytaj(cin);
//    result ? cout << d1 << endl : cout << "Zle wartosci" << endl;

    osoby[0] = new Stazysta("Jozek", "Kowalski", d2, 800.50, d4);
    osoby[1] = new Pracownik("Ania", "Nowak", d1, 3500.1);
    osoby[2] = new Kierownik("Jan", "Wesoly", d3, 4300.2, 650.9);

    for (int i = 0; i < 3; i++) {
        cout << osoby[i] -> opis() << endl;
    }

    cout << "Wyplaty: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << osoby[i] -> wyplata() << endl;
    }

    osoby[3] = new Pracownik("Stanislaw", "Szczesliwy", d2, 0);
    cout << "Wczytaj osobe:" << endl;
    bool result_os = osoby[3] -> wczytaj(cin);
    result_os ? cout << osoby[3] -> opis() << endl : cout << "Zle wartosci" << endl;
    cout << endl;

    for (int i = 0; i < 4; i++) {
        osoby[i] -> zapisz(cout);
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < 4; i++) {
        delete osoby[i];
        cout << endl;
    }

    return 0;
}