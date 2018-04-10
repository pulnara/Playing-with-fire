#ifndef ZADANIE3_CLASSES_H
#define ZADANIE3_CLASSES_H
#include <cstdlib>
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;

class Point {
private:
    float x;
    float y;
public:
    Point(float, float);
    float get_x() const;
    float get_y() const;
};

class Polygon {
private:
    int size;
    int counter;
    Point* table;
public:
    explicit Polygon(int = 3);      // konstruktor
    Polygon(const Polygon&);        // konstruktor kopiujacy
    Polygon(Polygon&&);             // konstruktor przenoszacy
    ~Polygon();                     // destruktor
    Polygon& operator= (const Polygon&);  // operator podstawienia
    Polygon& operator= (Polygon&&);       // przenoszacy operator podstawienia
    int length() const;             // zwraca liczbe elementow w tablicy
    void set_size(int);
    void add(const Point&);         // dodaje obiekt do tablicy
    friend ostream& operator<< (ostream&, const Polygon&);
};

#endif //ZADANIE3_CLASSES_H
