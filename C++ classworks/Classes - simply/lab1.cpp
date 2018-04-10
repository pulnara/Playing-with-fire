#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string>
using namespace std;

class Punkt {
	private:
		double x, y, z;
		static int licznik;
		
	public:
		Punkt() {	// konstruktor bezparametrowy
			srand(time(NULL));
			this -> x = (double) rand() / (double) RAND_MAX;
			this -> y = (double) rand() / (double) RAND_MAX;
			this -> z = (double) rand() / (double) RAND_MAX;
			licznik++;
		}
		
		Punkt(double x, double y, double z = 1.0) : x{x}, y{y}, z{z} { // z parametrami, domyslnie z = 1.0
			licznik++;
		}
		
	double getX() {  // zwraca wartosc wspolrzednej x
		return this->x;
	}
	
	double getY() {  // zwraca wartosc wspolrzednej y
		return this->y;
	}
		
	double getZ() { // zwraca wartosc wspolrzednej z
		return this->z;
	}
	
	void setZ(double z) { // pozwala zmienic wartosc wspolrzednej z
		this -> z = z;
	}
	
	bool checkIfFurther (Punkt other);
	
	void print() { // wypisz - wypisuje wspolrzedne
		cout << endl << "\"" << this -> x << ", " << this -> y << ", " << this -> z << "\"" << endl;
	}
	
	static void setLicznik(int value) { // ustawia wartosc licznika
		licznik = value;
	}
	
	void printLicznik() {
		cout << this -> licznik;
	}
	
	ostream& zapisz(ostream& os);
	void wczytaj(istream& is);
};

bool Punkt::checkIfFurther (Punkt other) {  // czy jest dalej od srodka ukladu niz other
	double dist1 = z*z + y*y + z*z;
	double dist2 = other.x * other.x + other.y * other.y + other.z * other.z;
	if (dist1 > dist2) return true; // wystarczy, ze porownamy wartosci przed spierwiastkowaniem
	return false;
}

ostream& Punkt::zapisz(ostream& os) {
	os << "\"" << fixed << setw(8) << setprecision(2) << this -> x << "\t" << setw(8) << setprecision(2) << this -> y << "\t" << setw(8) << setprecision(2) << this -> z << "\"";
	return os;
}

void Punkt::wczytaj(istream& is)  {
  string tmp;
  char c;
  tmp.clear();

  for(int i = 0; i < 8; i++)  {
    is.get(c);
    tmp.push_back(c);
  }
  
  this -> x = atof(tmp.c_str());
  tmp.clear();
  is.get(c);

  for(int i = 0; i < 8; i++)  {
    is.get(c);
    tmp.push_back(c);
  }
  
  this -> y = atof(tmp.c_str());
  tmp.clear();
  is.get(c);

  for(int i = 0; i < 8; i++)  {
    is.get(c);
    tmp.push_back(c);
  }
  
  this -> z = atof(tmp.c_str());
}

int Punkt::licznik = 0;

int main() {
	Punkt point1;
	Punkt point2(3.5, 11.524, 8.2133);
//	cout << endl << point2.getX();
//	cout << endl << point2.getY();
//	cout << endl << point2.getZ();
	Punkt point3(87.9712, 6.233);
	point2.setZ(9.223);
	cout << point2.checkIfFurther(point3);
	point1.print();
	point1.zapisz(cout);

	point2.print();
	point2.zapisz(cout);
	point2.printLiczni
	point2.setLicznik(3);

	point3.print();
	point3.zapisz(cout);
	
	cout << endl;
	point1.wczytaj(cin);
	point1.zapisz(cout);

}
