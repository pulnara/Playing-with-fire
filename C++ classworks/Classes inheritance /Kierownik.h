#ifndef ZESTAW4_KIEROWNIK_H
#define ZESTAW4_KIEROWNIK_H

#include "Pracownik.h"

namespace praca {
    class Kierownik : public Pracownik {
    public:
        Kierownik(const string &_imie, const string &_nazwisko, const Data& _rok_ur, double _pensja, double _dodatek);
        ~Kierownik();
        virtual string opis() const override;
        double wyplata() const override;
        bool zapisz(ostream &os) const override;
        bool wczytaj(istream &is) override; /// wczytuje atrybuty ze strumienia
    protected:
        double dodatek;
    };
}

#endif //ZESTAW4_KIEROWNIK_H
