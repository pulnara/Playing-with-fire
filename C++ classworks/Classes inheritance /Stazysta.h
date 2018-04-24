#ifndef ZESTAW4_STAZYSTA_H
#define ZESTAW4_STAZYSTA_H

#include "Data.h"
#include "Osoba.h"

namespace praca {
    class Stazysta : public Osoba {
    public:
        Stazysta(const string &_imie, const string &_nazwisko, const Data& _rok_ur, double _stypendium, const Data& _koniec_stazu);
        ~Stazysta();
        void zmienKoniecStazu(const Data& d);
        virtual string opis() const override;
        double wyplata() const override;
        bool zapisz(ostream &os) const override;
        bool wczytaj(istream &is) override; /// wczytuje atrybuty ze strumienia
    protected:
        double stypendium;
        Data koniec_stazu;
    };

}



#endif //ZESTAW4_STAZYSTA_H
