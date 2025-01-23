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
		else cout << "Nu exista locatari in acest apartament " << endl;
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
		os << "Numele locatarilor este :" << endl;
		for (int i = 0; i < a.nrlocatari; i++)
			os << a.numeLoc[i] << endl;
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
		else fapartamente = nullptr;

	}
	ScaraDeBloc(const string& fdenumire)
		: denumire(fdenumire), nrApartamente(0), nrEtaje(0), apartamente(nullptr) {}

	~ScaraDeBloc() { if (apartamente) delete[] apartamente; }

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

	ScaraDeBloc& operator+=(Apartament& ap1) {
		// Creăm un array nou cu o dimensiune mai mare
		Apartament* temp = new Apartament[nrApartamente + 1];

		// Copiem apartamentele existente în array-ul nou
		for (int i = 0; i < nrApartamente; i++) {
			temp[i] = apartamente[i];
		}

		// Adăugăm noul apartament
		temp[nrApartamente] = ap1;

		// Eliberăm memoria vechiului array
		if (apartamente) {
			delete[] apartamente;
		}

		// Actualizăm pointerul și numărul de apartamente
		apartamente = temp;
		nrApartamente++;

		return *this;
	}
	
};

void main()
{


	// Exemplu 2: Crearea unui apartament cu locatari și datorii
	string locatari1[] = { "Ion Popescu", "Maria Ionescu" };
	Apartament ap2(1, 2, locatari1, true, 450.75f);
	cout << "Exemplu 2: Apartament cu 2 locatari și datorii" << endl;
	cout << ap2;

	// Exemplu 3: Crearea unui apartament fără datorii și locatari
	Apartament ap3(2, 0, nullptr, false, 0.0f);
	cout << "Exemplu 3: Apartament fără datorii și fără locatari" << endl;
	cout << ap3;

	// Exemplu 7: Utilizarea operatorului << pentru afisare
	cout << "Exemplu 7: Utilizarea operatorului << pentru afișare" << endl;
	cout << ap2;

	string locatari7[] = { "Ion Popescu", "Maria Ionescu" };
	string locatari2[] = { "George Vasilescu", "Ana Vasilescu" };

	// Creăm două apartamente
	Apartament ap1(1, 2, locatari1, true, 500.5f);
	Apartament ap10(2, 2, locatari2, false, 0.0f);

	// Array de apartamente
	Apartament apartamente[] = { ap1, ap2 };

	// Creăm o scară de bloc
	ScaraDeBloc scara("Scara A", 2, 4, apartamente);

	// Afișăm scara de bloc
	cout << scara;
	string locatari5[] = { "Ion ", "Maria ","George","Patrocle","Cristina"};
	Apartament ap5(5, 2, locatari5, true, 450.75f);
	
	scara += ap5;
	cout << scara;

}
