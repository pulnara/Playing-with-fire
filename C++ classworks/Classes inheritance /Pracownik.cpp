#include "Pracownik.h"

namespace praca {

    Pracownik::Pracownik(const string &_imie, const string &_nazwisko, const Data &_rok_ur, double _pensja)
            : Osoba(_imie, _nazwisko, _rok_ur), pensja(_pensja) {}

    Pracownik::~Pracownik() {
        cout << "Destruktor PRACOWNIK pracuje." << endl;
    }

    string Pracownik::opis() const {
        return Osoba::opis() + ", pensja: " + to_string(pensja);
    }

    double Pracownik::wyplata() const {
        return pensja;
    }

    bool Pracownik::wczytaj(istream &is) {
        bool flag = Osoba::wczytaj(is);
        is >> pensja;
        return is && flag;
    }

    bool Pracownik::zapisz(ostream &os) const {
        os << Osoba::zapisz(os) << " pensja " << pensja;
        return !!os;
    }
}