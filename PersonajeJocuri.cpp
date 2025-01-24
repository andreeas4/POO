#define _CRT_SECURE_NO_WARNINGS

#include <iostream>


using namespace std;


class PersonajJoc 
{

private:
	string nume;
	int nrLovituri;
	int* punctePerLovitura;

public:
	PersonajJoc() :nume("Necunoscut"), nrLovituri(0), punctePerLovitura(nullptr) {}
	PersonajJoc(string fnume,int fnrLovituri,int*fpunctePerLovitura):nume(fnume),nrLovituri(fnrLovituri)
	{
		if (fnrLovituri>0 && fpunctePerLovitura)
		{ 
			punctePerLovitura = new int[fnrLovituri];
			for (int i = 0; i < fnrLovituri; i++)
				punctePerLovitura[i] = fpunctePerLovitura[i];

		}
			
		else punctePerLovitura = nullptr;
	
	}
	PersonajJoc(PersonajJoc &other):nume(other.nume), nrLovituri(other.nrLovituri)
	{
		if (other.nrLovituri > 0 && other.punctePerLovitura)
		{
			punctePerLovitura = new int[other.nrLovituri];
			for (int i = 0; i < other.nrLovituri; i++)
				punctePerLovitura[i] = other.punctePerLovitura[i];

		}

		else punctePerLovitura = nullptr;

	}
	//metode
	void setLovituri(int nr, int* puncte) {

		nrLovituri = nr;
		if (punctePerLovitura)
			delete[] punctePerLovitura;
		punctePerLovitura = new int[nr];
		for (int i = 0; i < nr; i++)
			punctePerLovitura[i] = puncte[i];


	}
	void adaugaLovituri(int nr,int*puncte)
	{

		int* copie = new int[nrLovituri];
		for (int i = 0; i < nrLovituri; i++)
			copie[i] = punctePerLovitura[i];
		
		if (punctePerLovitura)	delete[] punctePerLovitura;

		punctePerLovitura = new int[nrLovituri + nr];
		for (int i = 0; i < nrLovituri; i++) punctePerLovitura[i] = copie[i];
		for (int i = nrLovituri ; i < nrLovituri + nr; i++)
		{
			for (int j = 0; j < nr; j++)
				punctePerLovitura[i] = puncte[j];
		}

		nrLovituri += nr;
		
		delete[] copie;
	}
	void adaugaLovitura(int puncte)
	{

		int* copie = new int[nrLovituri];
		for (int i = 0; i < nrLovituri; i++)
			copie[i] = punctePerLovitura[i];

		if (punctePerLovitura)	delete[] punctePerLovitura;

		punctePerLovitura = new int[nrLovituri + 1];
		for (int i = 0; i < nrLovituri; i++) punctePerLovitura[i] = copie[i];
		
			punctePerLovitura[nrLovituri] = puncte;

		nrLovituri += 1;

		delete[] copie;
	}
	void afisareP() {
		cout << "Personajul: " << nume << endl;
		cout<< "Numar lovituri: " << nrLovituri << endl;
		for (int i = 0; i < nrLovituri; i++)
			cout<< "Puncte pe lovitura " << i + 1 << " : " << punctePerLovitura[i] << endl;

		cout<< "-------------------------------------------" << endl;
		
	}
	string getNume() { return nume; }
	void setNume(string nnume) { nume = nnume; }

	friend ostream& operator<<(ostream& os, PersonajJoc& p)
	{
		os << "Personajul: " << p.nume<<endl;
		os << "Numar lovituri: " << p.nrLovituri << endl;
		for (int i = 0; i < p.nrLovituri; i++)
			os << "Puncte pe lovitura " << i + 1 << " : " << p.punctePerLovitura[i] << endl;
		
		os << "-------------------------------------------" << endl;
		return os;
	}
	PersonajJoc& operator+=(string versiune) {
		nume = nume + " ";
		nume = nume + versiune;
		return *this;
	}
	friend bool operator >=(const PersonajJoc& p1,const PersonajJoc& p2)
	{
		int sumap1 = 0, sumap2 = 0;
		for (int i = 0; i < p1.nrLovituri; i++)
			sumap1 += p1.punctePerLovitura[i];
		for (int i = 0; i < p2.nrLovituri; i++)
			sumap2 += p2.punctePerLovitura[i];
		if (sumap1 >= sumap2)
			return true;
		else return false;

	}

	~PersonajJoc() {
		if (punctePerLovitura)
			delete[] punctePerLovitura;
	}
};
class PersonajNegativ:public PersonajJoc {
private:
	string putereSpeciala;
	int punctePS;


public:
	PersonajNegativ() :PersonajJoc(), putereSpeciala("Necunoscuta"),punctePS(0){}
	PersonajNegativ(PersonajJoc fpj, string fputereSpeciala,int fpunctePS) :PersonajJoc(fpj), putereSpeciala(fputereSpeciala),punctePS(fpunctePS) {
		adaugaLovitura(punctePS);
	}

	void afisarePn() {
		cout << "====Personaj Negativ====" << endl;
		afisareP();
		cout <<"Putere speciala: "<< putereSpeciala << endl;
		cout << "=========================" << endl;
		cout << endl;
	}

};

void main()
{
	PersonajJoc p1;
	cout << p1;

	PersonajJoc p2("Batman", 3, new int[3] {1, 2, 3});
	cout << p2;

	PersonajJoc p3(p2);
	//cout << p3;

	p2.adaugaLovituri(2, new int[2] {5, 5});
	p2 += "v2.0";
	cout << "Personajul " << p2.getNume() << " dupa update " << endl;
	cout << p2;
	p1.setLovituri(5, new int[5] {2, 3, 7, 22, 1});
	cout << p1;

	

	PersonajNegativ pn1;

	p1.setNume("Raven");
	cout << p1;
	cout << p2;
	if (p1 >= p2)cout << "Personajul -> " << p1.getNume() << "<- este mai puternic" << endl;
	else cout << "Personajul ->"<< p2.getNume()<< "<-este mai puternic" << endl;
	cout << endl;

	pn1.afisarePn();
	PersonajJoc p5("Joker", 6, new int[6] {1, 4, 6, 10, 20, 2});
	PersonajNegativ pn2(p5, "Crazy Eyes", 50);
	pn2.afisarePn();






}


