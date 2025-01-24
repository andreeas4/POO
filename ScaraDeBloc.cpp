#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Apartament
{
private:
	int nrAp;
	int nrlocatari;
	string* numeLoc;
	bool datorii;
	float sumaDatorata;



public:
	//constructor 1
	Apartament(int fnrAp = 0, int fnrlocatari = 0, string* fnumeLoc = nullptr, bool fdatorii = 0, float fsumaDatorata = 0) :
		nrlocatari(fnrlocatari), datorii(fdatorii), nrAp(fnrAp) {

		if (datorii)
			sumaDatorata = fsumaDatorata;
		else sumaDatorata = 0;

		if (fnrlocatari != 0)
		{
			numeLoc = new string[nrlocatari];
			for (int i = 0; i < nrlocatari; i++)
				if (fnumeLoc)
					numeLoc[i] = fnumeLoc[i];
				else fnumeLoc[i] = "Anonim";

		}
		else numeLoc = nullptr;
	}
	//constructor 2
	Apartament(int fnrAp , int fnrlocatari ):nrAp(fnrAp),nrlocatari(fnrlocatari){}

	//constructor de copiere
	Apartament(Apartament &other):nrlocatari(other.nrlocatari), datorii(other.datorii), nrAp(other.nrAp) {

		if (datorii)
			sumaDatorata = other.sumaDatorata;
		else sumaDatorata = 0;

		if (other.nrlocatari != 0)
		{
			numeLoc = new string[nrlocatari];
			for (int i = 0; i < nrlocatari; i++)
				if (other.numeLoc)
					numeLoc[i] = other.numeLoc[i];
				else other.numeLoc[i] = "Anonim";

		}
		else cout << "Nu exista locatari in acest apartament " << endl;
	}

	//metode

	int getNrAp() {	return nrAp;}
	void setNrAp(int nr) { nrAp = nr; }

	int getNrLocatari() { return nrlocatari; }
	void setNrLocatari(int nr) { nrlocatari = nr; }
	
	bool getdatorii(){
		if (datorii)cout << "Exista datorii"<<endl;
		else cout << "Nu exista datorii"<<endl;
		return datorii;
	}
	void setDatorii(bool validare) { datorii = validare; }

	float getSumaDatorata() { return sumaDatorata; }
	void setSumadatorata(float suma) { sumaDatorata = suma; }

	string* getNumeLocatari() { return numeLoc; }
	void setNumeLoc(string*numele) {
		for (int i = 0; i < nrlocatari; i++)
			if (numele)
				numeLoc[i] = numele[i];
	}

	friend ostream& operator<<(ostream& os, Apartament& a)
	{
		os << "Apartamentul cu nr "<<a.nrAp<<endl;
		os << "Nr locatari: " << a.nrlocatari<<endl;
		if (a.nrlocatari)
		{
			os << "Numele locatarilor este :" << endl;
			for (int i = 0; i < a.nrlocatari; i++)
				os << a.numeLoc[i] << " , ";
			os << endl;

		}
		
		
		if (a.datorii)
			os << "Exista datorii de  " << a.sumaDatorata<<endl;
		else os << "Nu exista datorii " << endl;
		os << "-----------------------------------------------"<<endl;
			
		return os;
	}

	//destructor
	~Apartament() {
		if (numeLoc)
			delete[]numeLoc;
	}
	


};

class ScaraDeBloc {
private:
	const string denumire;
	int nrApartamente;
	int nrEtaje;
	Apartament*apartamente;
	
public:
	ScaraDeBloc(const string fdenumire,int fnrApartamente,int fnrEtaje,Apartament*fapartamente):denumire(fdenumire),nrApartamente(fnrApartamente),nrEtaje(fnrEtaje)
	{
		apartamente = new Apartament[nrApartamente];
		if (fapartamente)
		{
			for (int i = 0; i < nrApartamente; i++)
				apartamente[i] = fapartamente[i];
		}
		else apartamente = nullptr;

	}
	ScaraDeBloc(const string& fdenumire)
		: denumire(fdenumire), nrApartamente(0), nrEtaje(0), apartamente(nullptr) {}

	ScaraDeBloc(ScaraDeBloc &other): denumire(other.denumire), nrApartamente(other.nrApartamente), nrEtaje(other.nrEtaje)
	{
		apartamente = new Apartament[nrApartamente];
		if (other.apartamente)
		{
			for (int i = 0; i < nrApartamente; i++)
				apartamente[i] = other.apartamente[i];
		}
		else other.apartamente = nullptr;

	}

	~ScaraDeBloc() { if (apartamente) delete[] apartamente; }

	ScaraDeBloc& operator =(ScaraDeBloc& other) {
		if (this != &other)
		{
			if (apartamente)
				delete[]apartamente;
			nrApartamente = other.nrApartamente;
			nrEtaje = other.nrEtaje;
			apartamente = new Apartament[other.nrApartamente];
			if (other.apartamente)
			{
				for (int i = 0; i < other.nrApartamente; i++)
					apartamente[i] = other.apartamente[i];
			}
			else apartamente = nullptr;
			
		}
		return *this;
	}
	friend ostream& operator<<(ostream& os, ScaraDeBloc& sc) {
		os << "======================================"<<endl;
		os  << sc.denumire << endl;;
		os << "Numar etaje: " << sc.nrEtaje<<endl;
		os << "Numar apartamente: " << sc.nrApartamente<<endl;
		for (int i = 0; i < sc.nrApartamente; i++)
			os << sc.apartamente[i] << endl;
		os << "========================================"<<endl;
		return os;
		

	}
	string getDenumire() const{	return denumire;}
	int getNrEtaje() { return nrEtaje; }
	int getNrApartamente() { return nrApartamente; }
	Apartament getApartament(int index) { 
		if (index >= 0 && index < nrApartamente) {
			return apartamente[index];
		}
		throw out_of_range("Index invalid pentru apartamente!");
		 }

	void setNrEtaje(int nr) { nrEtaje = nr; }
	void setNrAp(int nr) { nrApartamente = nr; }

	ScaraDeBloc& operator+=(const Apartament& ap1) {
		Apartament* copie = new Apartament[nrApartamente];
		
		
			for (int i = 0; i < nrApartamente; i++)
				copie[i] = apartamente[i];
			
		
			delete[]apartamente;

		apartamente = new Apartament[nrApartamente + 1];
		for (int i = 0; i < nrApartamente; i++)
			apartamente[i]=copie[i];

		apartamente[nrApartamente] = ap1;
		nrApartamente++;

		delete[] copie;

		return *this;
	}
	
};

void main() {
	// Apartament cu locatari și datorii
	string locatari1[] = { "Ion Popescu", "Maria Ionescu" };
	Apartament ap1(1, 2, locatari1, true, 450.75f);
	cout << ap1;

	// Apartament fără locatari și fără datorii
	Apartament ap2(2, 0, nullptr, false, 0.0f);
	cout << ap2;

	// Scara de bloc
	Apartament apartamente[] = { ap1, ap2 };
	ScaraDeBloc scara("Scara A", 2, 4, apartamente);

	cout << scara;

	// Adăugarea unui nou apartament
	string locatari3[] = { "George Vasilescu", "Ana Vasilescu" };
	Apartament ap3(3, 2, locatari3, false, 0.0f);
	scara += ap3;
	string locatari20[] = { "Maria Antoaneta", "Ghita Don","Marcela Ciolacu"};
	Apartament ap20(20, 3, locatari3, true, 130.8f);
	scara += ap20;
	cout << scara;

}

