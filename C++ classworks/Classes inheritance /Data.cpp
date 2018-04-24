#include "Data.h"

namespace praca {

    Data::Data(int _dzien, int _miesiac, int _rok) : dzien(_dzien), miesiac(_miesiac), rok(_rok)  {}

    void Data::setDzien(int d) {
        dzien = d;
    }

    int Data::getDzien() const {
        return dzien;
    }

    bool Data::zapisz(ostream &os) const {
        os << dzien << "." << miesiac << "." << rok;
        return !!os;
    }

    bool Data::wczytaj(istream &is) {
        is >> dzien >> miesiac >> rok;
        return !!is;
    }

    ostream &operator<<(ostream &os, Data &d) {
        os << d.dzien << "." << d.miesiac << "." << d.rok;
        return os;
    }

    string Data::getDate() const {
        return to_string(dzien) + "." + to_string(miesiac) + "." + to_string(rok);
    }
}
