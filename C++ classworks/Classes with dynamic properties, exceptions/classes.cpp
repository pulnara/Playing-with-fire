#include "classes.h"

// POINT
Point::Point(float x, float y) : x(x), y(y) {
}

float Point::get_x() const {
    return this -> x;
}

float Point::get_y() const {
    return this -> y;
}

// POLYGON

/// konstruktor
Polygon::Polygon(int size) : size(size), counter(0), table((Point*) (calloc(size, sizeof(Point)))) {
    if (size <= 0) throw invalid_argument("Array size must be positive.\n");
}

/// konstruktor kopiujacy
Polygon::Polygon(const Polygon& other) : size(other.size), counter(other.counter), table((Point*) (calloc(size, sizeof(Point)))) {
    cout << "Copy constructor working" << endl;
    for (int i = 0; i < counter; i++) {
        this -> table[i] = other.table[i];
    }
}

/// konstruktor przenoszacy
Polygon::Polygon(Polygon&& other) : size(other.size), counter(other.counter), table(other.table) {
    cout << "Move constructor working" << endl;
    other.table = nullptr;
    other.size = 0;
    other.counter = 0;
}

/// destruktor
Polygon::~Polygon() {
    free(table);
    table = nullptr;
}

/// operator podstawienia
Polygon& Polygon::operator= (const Polygon& other) {
    cout << "Copy assingment working" << endl;
    if (this != &other) {
        free(this -> table);
        this -> size = other.size;
        this -> counter = other.counter;
        this -> table = (Point*) (calloc(size, sizeof(Point)));
        for (int i = 0; i < counter; i++) {
            this -> table[i] = other.table[i];
        }
    }
    return *this;
}

/// przenoszacy operator podstawienia
Polygon& Polygon::operator= (Polygon&& other) {
    cout << "Move assignment working" << endl;
    if (this != &other) {
        free(this -> table);
        this -> size = other.size;
        this -> counter = other.counter;
        this -> table = other.table;
        other.table = nullptr;
        other.size = 0;
        other.counter = 0;
    }
    return *this;
}

/// metoda zwracajaca liczbe elementow w tablicy
int Polygon::length() const {
    return this -> counter;
}

void Polygon::set_size(int size) {
    if (size <= 0) throw invalid_argument("Size must be positive!\n");
    this -> size = size;
    free(this -> table);
    this -> table = (Point*) calloc(size, sizeof(Point));
}

/// metoda dodajaca obiekt do tablicy
void Polygon::add(const Point& point) {
    if (counter < size) {
        counter++;
        this -> table[counter - 1] = point;
    } else throw overflow_error("Array is full - couldn't add more elements.\n");
}

ostream& operator<< (ostream& o, const Polygon& p) {
    o << "Size: " << p.size << endl;
    o << "Counter: " << p.counter << endl;
    o << "{";
    for (int i = 0; i < p.counter; i++) {
        o << "(" << p.table[i].get_x() << ", " << p.table[i].get_y() << ")";
        if (i < p.counter - 1) o << ", ";
    }
    o << "}\n\n";
    return o;
}