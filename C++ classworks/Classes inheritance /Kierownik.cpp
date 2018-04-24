#include "Kierownik.h"

namespace praca {

    Kierownik::Kierownik(const string &_imie, const string &_nazwisko, const Data &_rok_ur, double _pensja,
                         double _dodatek) : Pracownik(_imie, _nazwisko, _rok_ur, _pensja), dodatek(_dodatek) {}

    Kierownik::~Kierownik() {
        cout << "Destruktor KIEROWNIK pracuje." << endl;
    }

    string Kierownik::opis() const {
        return Pracownik::opis() + ", dodatek: " + to_string(dodatek);
    }

    double Kierownik::wyplata() const {
        return Pracownik::wyplata() + dodatek;
    }

    bool Kierownik::wczytaj(istream &is) {
        bool flag =  Pracownik::wczytaj(is);
        is >> dodatek;
        return is && flag;
    }

    bool Kierownik::zapisz(ostream &os) const {
        os << Pracownik::zapisz(os) << " dodatek " << dodatek;
        return !!os;
    }

}