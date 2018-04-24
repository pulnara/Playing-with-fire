#include "Osoba.h"

namespace praca {

    Osoba::Osoba(const string &_imie, const string &_nazwisko, const Data &_rok_ur) : imie(_imie), nazwisko(_nazwisko), rok_ur(_rok_ur) {}

    Osoba::~Osoba() {
        cout << "Destruktor OSOBA pracuje." << endl;
    }

    string Osoba::opis() const {
       return "Imie: " + imie + ", nazwisko: " + nazwisko + ", data urodzenia: " + rok_ur.getDate();
    }

    bool Osoba::zapisz(ostream &os) const {
        os << "Imie: " + imie + ", nazwisko: " + nazwisko + ", data urodzenia: " + rok_ur.getDate();
        return (bool)os;
    }

    bool Osoba::wczytaj(istream &is) {
        is >> imie >> nazwisko;
        bool flag = rok_ur.wczytaj(is);
        return is && flag;
    }

}

