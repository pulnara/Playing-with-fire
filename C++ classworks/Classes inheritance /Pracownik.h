#ifndef ZESTAW4_PRACOWNIK_H
#define ZESTAW4_PRACOWNIK_H

#include "Osoba.h"

namespace praca {
    class Pracownik : public Osoba {
    public:
        Pracownik(const string &_imie, const string &_nazwisko, const Data& _rok_ur, double _pensja);
        ~Pracownik();
        virtual string opis() const override;
        double wyplata() const override;
        bool zapisz(ostream &os) const override;
        bool wczytaj(istream &is) override; /// wczytuje atrybuty ze strumienia

    protected:
        double pensja;
    };
}

#endif //ZESTAW4_PRACOWNIK_H
