#ifndef TEMAT_2_OBIEKTY_H
#define TEMAT_2_OBIEKTY_H
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

// UWAGI prowadzacego - const - przy metodzie, gdzie nie modyfikujemy, zwracać też referencje, jeśli nie zwracamy kopii!!!


class Wektor {
    friend class Punkt;
    float x, y, z;
public:
    Wektor(float x = 0, float y = 0, float z = 0);
    Wektor operator+ (const Wektor &other) const;
    Wektor operator+= (const Wektor &other);
    Wektor operator- ();
    operator float() const;
    bool operator> (const Wektor &other);
    float operator[] (const int ind);
    friend ostream& operator<<(ostream& os, const Wektor &w);
    friend Wektor operator* (float f, const Wektor &w);
    friend Wektor operator* (const Wektor &w, float f);
};

class Punkt {
    float x, y, z;
public:
    Punkt(float x = 0, float y = 0, float z = 0);
    Punkt operator+ (const Wektor &w);
    Punkt operator++();
    Punkt operator++(int);
    friend ostream& operator<<(ostream& os, const Punkt &p);
};


#endif //TEMAT_2_OBIEKTY_H
