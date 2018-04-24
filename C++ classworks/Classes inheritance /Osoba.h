#ifndef ZESTAW4_OSOBA_H
#define ZESTAW4_OSOBA_H

#include "Data.h"

namespace praca {
    class Osoba {
    public:
        Osoba(const string &_imie, const string &_nazwisko, const Data& _rok_ur);
        virtual ~Osoba();
        virtual string opis() const;
        virtual double wyplata() const = 0;
        virtual bool zapisz(ostream &os) const; /// zapisuje atrybuty do strumienia
        virtual bool wczytaj(istream &is); /// wczytuje atrybuty ze strumienia
    protected:
        string imie;
        string nazwisko;
        Data rok_ur;
    };
}




#endif //ZESTAW4_OSOBA_H
