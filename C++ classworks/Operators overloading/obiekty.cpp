#include "obiekty.h"

// PUNKT

//Konstruktor:
Punkt::Punkt(float x, float y, float z) : x{x}, y{y}, z{z} {}

// Metody klasy

Punkt Punkt::operator+ (const Wektor &w) {
    Punkt wynik;
    wynik.x = x + w.x;
    wynik.y = y + w.y;
    wynik.z = z + w.z;
    return wynik;
}

Punkt Punkt::operator++() {  // inkrementacja - prefix
    x++;
    y++;
    z++;
    return *this;
}

Punkt Punkt::operator++(int) {     // inkrementacja - postfix
    Punkt wynik = *this;
    ++*this;
    return wynik;
}

// Funkcje zewnetrzne
ostream& operator<<(ostream& os, const Punkt &p) {
    os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    return os;
}

// WEKTOR

// Konstruktor:
Wektor::Wektor(float x, float y, float z) : x{x}, y{y}, z{z} {}

// Metody klasy
Wektor Wektor::operator+ (const Wektor &other) const {
    Wektor wynik;
    wynik.x = x + other.x;
    wynik.y = y + other.y;
    wynik.z = z + other.z;
    return wynik;
}

Wektor Wektor::operator+= (const Wektor &other) {
   *this = *this + other;
    return *this;
}

Wektor Wektor::operator- () {
    Wektor wynik;
    wynik.x = -x;
    wynik.y = -y;
    wynik.z = -z;
    return wynik;
}

Wektor::operator float() const {
    return sqrt(x*x + y*y + z*z);
}

bool Wektor::operator> (const Wektor &other) {
    return (float)*this > (float)other;
}

float Wektor::operator[] (const int ind) {
    if (ind == 0) return x;
    if (ind == 1) return y;
    if (ind == 2) return z;
    cout << ind << ": index out of bounds";
    exit(0);
}

// Funkcje zewnetrzne
ostream& operator<<(ostream& os, const Wektor &w) {
    os << "[" << w.x << ", " << w.y << ", " << w.z << "]";
    return os;
}

Wektor operator* (float f, const Wektor &w) {
    Wektor wynik;
    wynik.x = f * w.x;
    wynik.y = f * w.y;
    wynik.z = f * w.z;
    return wynik;
}

Wektor operator* (const Wektor &w, float f) {
    return f * w;
}
