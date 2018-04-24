#include "Stazysta.h"

namespace praca {

    Stazysta::Stazysta(const string &_imie, const string &_nazwisko, const Data &_rok_ur, double _stypendium,
                       const Data &_koniec_stazu)
            : Osoba(_imie, _nazwisko, _rok_ur), stypendium(_stypendium), koniec_stazu(_koniec_stazu) {}

    Stazysta::~Stazysta() {
        cout << "Destruktor STAZYSTA pracuje." << endl;
    }

    void Stazysta::zmienKoniecStazu(const Data &d) {
        koniec_stazu = d;
    }

    string Stazysta::opis() const {
        return Osoba::opis() + ", stypendium: " + to_string(stypendium) + ", koniec stazu: " + koniec_stazu.getDate();
    }

    double Stazysta::wyplata() const {
        return stypendium;
    }

    bool Stazysta::wczytaj(istream &is) {
        bool flag1 = Osoba::wczytaj(is);
        is >> stypendium;
        bool flag2 = koniec_stazu.wczytaj(is);
        return flag1 && is && flag2;
    }

    bool Stazysta::zapisz(ostream &os) const {
        os << Osoba::zapisz(os) << " stypendium " << stypendium;
        return !!os;
    }

}