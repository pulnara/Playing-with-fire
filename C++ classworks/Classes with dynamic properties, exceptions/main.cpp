#include <iostream>
#include "classes.h"
using namespace std;

int main() {
    Point p1(1.5, 7.5);
    Point p2(4, 17.9);
    Point p3(2.12, 3.14);
    Point p4(9.99, 10.11);
    Point p5(8.21, 9.78);

    cout << "COPY CONSTRUCTOR" << endl;
    Polygon A;
    A.add(p3);
    A.add(p5);
    cout << "A:" << endl << A;
    cout << "-----" << endl;
    Polygon B = A;
    cout << "A:" << endl << A;
    cout << "B:" << endl << B;

    cout << "MOVE CONSTRUCTOR" << endl;
    cout << "A:" << endl << A;
    cout << "-----" << endl;
    Polygon C = move(A);
    cout << "A:" << endl << A;
    cout << "C:" << endl << C;

    cout << "COPY ASSIGNMENT" << endl;
    Polygon D(10);
    D.add(p1);
    D.add(p3);
    D.add(p2);
    cout << "B:" << endl << B;
    cout << "D:" << endl << D;
    cout << "-----" << endl;
    D = B;
    cout << "B:" << endl << B;
    cout << "D:" << endl << D;

    cout << "MOVE ASSIGNMENT" << endl;
    Polygon E(10);
    E.add(p5);
    cout << "E:" << endl << E;
    cout << "D:" << endl << D;
    cout << "-----" << endl;
    E = move(D);
    cout << "E:" << endl << E;
    cout << "D:" << endl << D;

    try {
        Polygon F(-10);
    } catch (invalid_argument e) {
        cout << "Error: " << e.what();
    }

    try {
        Polygon G;
        G.add(p1);
        G.add(p2);
        G.add(p3);
        G.add(p4);
    } catch (overflow_error e) {
        cout << "Error: " << e.what();
    }

    return 0;
}