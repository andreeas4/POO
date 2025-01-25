#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
class Marker {

private:
	const int cod;
	char* culoare;
	float dimensiune;
	string producator;
public:
	Marker():cod(0),culoare(nullptr),dimensiune(0.0f),producator("Necunoscut"){}
	Marker(const int fcod, const char* fculoare, float fdimensiune, string fproducator) :cod(fcod), dimensiune(fdimensiune), producator(fproducator) {
		if (fculoare != nullptr)
		{
			culoare = new char[strlen(fculoare) + 1];
			strcpy(culoare, fculoare);
		}
		else culoare = nullptr;
	}
	Marker(Marker &other):cod(other.cod), dimensiune(other.dimensiune), producator(other.producator) {
		if (other.culoare != nullptr)
		{
			culoare = new char[strlen(other.culoare) + 1];
			strcpy(culoare, other.culoare);
		}
		else culoare = nullptr;
	}
	char* getCuloare() { return culoare; }
	void setCuloare(const char* noua) {
		if (culoare)delete[]culoare;
		culoare = new char[strlen(noua) + 1];
		strcpy(culoare, noua);
	}

	friend ostream &operator<<(ostream &os, Marker &m) {

		os << "Markerul cu codul: " << m.cod << endl;
		os << "Culoare: " << m.culoare << endl;
		os << "Dimensiune: " << m.dimensiune << endl;
		os << "Producator: " << m.producator << endl;
		os << "---------------------------------------" << endl;

		return os;
	}
	friend bool operator==(Marker& m1, Marker& m2) {
		if (m1.dimensiune == m2.dimensiune && m1.producator == m2.producator)return true;
		else return false;
	}
	~Marker() {
		if (culoare)delete[]culoare;
	}


};
/*class MarkerElectronic :public Marker {
private:
	int nrBaterii;
	float razaActiune;
public:
	MarkerElectronic():Marker(),nrBaterii(0),razaActiune(0.0f){}
	MarkerElecronic(int fnrBaterii, float frazaActiune): 
		Marker(fcod, fculoare, fdimensiune, fproducator), nrBaterii(fnrBaterii),razaActiune(frazaActiune){}

};*/
void main()
{
	Marker m1;
	Marker m2(22, "Galben", 22.9f, "Dioda");
	cout << m2;
	m2.setCuloare("Albastru");
	cout << m2;



}
