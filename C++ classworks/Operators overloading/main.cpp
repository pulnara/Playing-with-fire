#include "obiekty.h"

int main() {
    Punkt p1;
    Punkt p2(21.313, 75.221, 98.1);
    Punkt p3(7.65, 9.121);
//    cout << p1 << endl;
//    cout << p2 << endl;
//    cout << p3 << endl;

    Wektor w1;
    Wektor w2(76.872, 99.1212, 9.12);
    Wektor w3(8.99, 2.311);
//    cout << w1 << endl;
//    cout << w2 << endl;
//    cout << w3 << endl;

    cout << w2 + w3 << endl;
    cout << w2 << endl;
    cout << (w2 += w3) << endl;
    cout << w2 << endl;
//    cout << (2 * w3) << endl;
//    cout << (w3 * 2);
//    cout << p1 + w3;
//    cout << ++p1 << endl;
//    cout << p1++ << endl;
//    cout << p1;
//    cout << -w2 << endl;
//    cout << w2;
//    cout << (float)w3 << endl;
//    cout << (float)w2 << endl;
//    cout << (w2 < w3);
//    cout << w3[0] << endl;
//    cout << w3[1] << endl;
//    cout << w3[7] << endl;
//    cout << w3[2] << endl;
}