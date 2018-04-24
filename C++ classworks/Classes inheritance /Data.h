#ifndef ZESTAW4_DATA_H
#define ZESTAW4_DATA_H

#include <iostream>
using namespace std;

namespace praca {
    class Data {
    public:
        Data(int _dzien, int _miesiac, int _rok);
        void setDzien(int d);
        int getDzien() const;
        string getDate() const;
        bool zapisz(ostream& os) const;
        bool wczytaj(istream& is);
        friend ostream& operator<<(ostream &os, Data &d);
    private:
        int dzien;
        int miesiac;
        int rok;
    };
}




#endif //ZESTAW4_DATA_H
