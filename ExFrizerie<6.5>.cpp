#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
class Serviciu
{
private:
	string nume;
	int cantitate;
	float pret;
public:
	
	Serviciu():cantitate(0),pret(0.0f){}
	Serviciu(int fcant,float fpret,string fnume):cantitate(fcant),pret(fpret),nume(fnume){}
	float cost() {
		float s;
		s = pret * cantitate;
		return s;
	}
	Serviciu(Serviciu &other):cantitate(other.cantitate),pret(other.pret),nume(other.nume){}
	Serviciu &operator =(const Serviciu& other) {
		if (this != &other)
		{
			cantitate = other.cantitate;
			pret = other.pret;
			nume = other.nume;
		}
		return *this;
	}
	void afiseazaServiciu() {
		cout<<"Serviciul: " << nume << endl;
		cout << "Pret: " << pret << endl;
		cout<< "Cantitate: " << cantitate << endl;
	}
	friend ostream &operator<<(ostream &os,Serviciu& s) {
		os << "Serviciul: " << s.nume << endl;
		os << "Pret: " << s.pret << endl;
		os << "Cantitate: " << s.cantitate << endl;

		return os;
	}
	friend istream& operator<<(istream& is, Serviciu& s) {
		
		cout << "Serviciul: "<< endl;
		getline(is, s.nume);
		cout << "Pret: " << endl;
		is>>s.pret;
		cout<< "Cantitate: "<< endl;
		is >> s.cantitate;
		return is;
	}
	/*friend bool operator==(Serviciu& s1, Serviciu& s2)
	{
		if (s1.nume == s2.nume && s1.pret == s2.pret)return true;
		else return false;

	}*/

};
class Tuns: public Serviciu {
private:
	
public:
	Tuns():Serviciu(0,0,"Tuns") {}
	
};
class Frezat :public Serviciu {
private:
	
public:
	Frezat() :Serviciu(0,0,"Frezat") {}
	

};



class Frizerie {
private:
	const string denumire;
	char* adresa;
	int nrFrizeri;
	Serviciu* servicii;
	int nrServicii;
protected:
	static int nrLocuriDisponibile;
public:
	Frizerie():denumire("Necunoscuta"),nrFrizeri(0),adresa(nullptr),servicii(nullptr),nrServicii(0){}
	Frizerie(const string fdenumire, const char* fadresa, int fnrFrizeri, Serviciu* fservicii,int fnrServicii) :denumire(fdenumire), nrFrizeri(fnrFrizeri),nrServicii(fnrServicii)
	{
		if (fadresa)
		{
			adresa = new char[strlen(fadresa) + 1];
			strcpy(adresa, fadresa);

		}
		else {
			adresa = new char[strlen("N/a") + 1];
			strcpy(adresa, "N/A");

		}
		if (fservicii != nullptr && fnrServicii > 0)
		{
			servicii = new Serviciu[fnrServicii];
			for (int i = 0; i < fnrServicii; i++)
				servicii[i] = fservicii[i];
		}
		else servicii = nullptr;
	}
	Frizerie(Frizerie& other) :denumire(other.denumire), nrFrizeri(other.nrFrizeri), nrServicii(other.nrServicii) {
		if (other.adresa)
		{
			adresa = new char[strlen(other.adresa) + 1];
			strcpy(adresa, other.adresa);

		}
		else {
			adresa = new char[strlen("N/a") + 1];
			strcpy(adresa, "N/A");

		}
		if (other.servicii != nullptr && other.nrServicii > 0)
		{
			servicii = new Serviciu[other.nrServicii];
			for (int i = 0; i < other.nrServicii; i++)
				servicii[i] = other.servicii[i];
		}
		else servicii = nullptr;
	}
	
	string getDenumire()const { return denumire; }
	char* getAdresa() { return adresa; }

	friend ostream &operator<<(ostream &os, Frizerie &f) {

		os << "Frizeria " << f.denumire<<endl;
		os << "Locatie: " << f.getAdresa() << endl;
		os << "NrFrizeri: " << f.nrFrizeri << endl;
		os << "Ofera " << f.nrServicii << " servicii dintre care:" << endl;
		for (int i = 0; i < f.nrServicii; i++)
			os<<f.servicii[i]<<" ";
		os << endl;
		return os;
	}
	/*friend istream& operator>>(istream& is, Frizerie& f)
	{
		char buffer[100];
		cout << "Frizeria ";
		getline(is, f.denumire); 
		os << "Locatie: " << f.getAdresa() << endl;
		os << "NrFrizeri: " << f.nrFrizeri << endl;
		os << "Ofera " << f.nrServicii << " servicii dintre care:" << endl;
		for (int i = 0; i < f.nrServicii; i++)
			is >> f.servicii[i];
		is << endl;

		return is;
	}
	*/
	float pretTotal() {
		float suma=0.0f;
		if (servicii)
		{
			for (int i = 0; i < nrServicii; i++)
				suma += servicii[i].cost();

		}
		else suma = 0.0f;
		
		return suma;

	}
	Frizerie &operator+=(const Serviciu &s) {
		Serviciu* copie;

		if (servicii)
		{
			copie = new Serviciu[nrServicii];
			for (int i = 0; i < nrServicii; i++)
				copie[i] = servicii[i];
		}
		delete[]servicii;
		servicii = new Serviciu[nrServicii + 1];
		for (int i = 0; i < nrServicii; i++)
			servicii[i] = copie[i];
		servicii[nrServicii + 1] = s;
		nrServicii++;
		delete[]copie;

		return *this;

	}
	/*Frizerie& operator-=(const Serviciu& s) {
		
		for(int i=0;i<nrServicii;i++)
			if(servicii[i]==s)

		return *this;

	}*/

};
void main() {
	// Testare clasa Serviciu
	Serviciu s1(5, 20.5f, "Spalat par");
	s1.afiseazaServiciu();
	cout << "Cost total: " << s1.cost() << " lei" << endl;

	// Testare constructor de copiere
	Serviciu s2(s1);
	cout << "Copie Serviciu:\n" << s2;

	// Testare operator= 
	Serviciu s3;
	s3 = s1;
	cout << "Operator= Serviciu:\n" << s3;

	// Testare clase derivate
	Tuns t;
	cout << "Serviciu derivat (Tuns):\n" << t;

	Frezat f;
	cout << "Serviciu derivat (Frezat):\n" << f;

	// Testare clasa Frizerie
	Serviciu servicii[] = { s1, t, f };
	Frizerie frizerie("Salon Elegant", "Str. Mihai Eminescu 10", 3, servicii, 3);
	cout << frizerie;

	// Testare constructor de copiere pentru Frizerie
	Frizerie frizerie2(frizerie);
	cout << "Copie Frizerie:\n" << frizerie2;


}
