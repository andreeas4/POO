//definiti clase care sa permita gestiunea datelor aferente unei motociclete (producator,nr drumuri, dist parcurse) folosind membri de tip public,private ,protected,const, static.Clasa va permite urmatoareele apeluri in main: Motocicleta m1; Motocicleta m2("Suzuki",3,new int[3]{100,150,120});Motocicleta m3=m2; m2.setproducator("Yamaha"); Motocicleta ::tipPermis='B';

#include <iostream>
#include <string>

using namespace std;

class Motocicleta
{
private:
	string producator;
	int nrDrumuri;
	int *distParcursa;


protected:

	

public:

	Motocicleta(string fproducator = "Necunoscut", int fnrDrumuri = 0, int* fdistParcursa = nullptr): producator(fproducator),nrDrumuri(fnrDrumuri)
	{
		if (nrDrumuri != 0)
		{
			distParcursa = new int[fnrDrumuri * sizeof(int)];
			for (int i = 0; i < fnrDrumuri; i++)
				distParcursa[i] = fdistParcursa[i];
		}
		else distParcursa = nullptr;

	}
	Motocicleta (Motocicleta &other):nrDrumuri(other.nrDrumuri),producator(other.producator)
	{
		if (nrDrumuri != 0)
		{
			distParcursa = new int[other.nrDrumuri * sizeof(int)];
			for (int i = 0; i < other.nrDrumuri; i++)
				distParcursa[i] = other.distParcursa[i];
		}
		else distParcursa = nullptr;

	}
	
	~Motocicleta() {
		if (distParcursa != nullptr) {
			delete[] distParcursa;
		}
	}
	//---------------------metode--------------------------------------
	void setProducator(string p)
	{
		producator = p;
	}

	string getProducator()
	{
		return producator;
	}

	void setNrDrumuri(int nr)
	{
		nrDrumuri = nr;
	}
	int getNrDrumuri()
	{
		return nrDrumuri;
	 }

	void setDist(int fNrDrumuri, const int* fDistParcurse) {
		if (fNrDrumuri <= 0 || fDistParcurse == nullptr) {
			cout << "Date invalide pentru setarea distantelor." << endl;
			return;
		}

		// Eliberam memoria alocata anterior pentru distParcurse
		if (distParcursa != nullptr) {
			delete[] distParcursa;
		}

		// Actualizam num?rul de drumuri
		nrDrumuri = fNrDrumuri;

		// Alocam memorie pentru noile distante si copiem valorile
		distParcursa = new int[nrDrumuri];
		for (int i = 0; i < nrDrumuri; i++) {
			distParcursa[i] = fDistParcurse[i];
		}
	}
	
	

friend ostream& operator <<(ostream& os, Motocicleta& m)
	{

		os << "Producatorul: " << m.producator << endl;
		os << "Numar de drumuri parcurse: " << m.nrDrumuri << endl;
		for (int i = 0; i < m.nrDrumuri; i++)
		{
			os << "Distanta parcursa in drumul cu numarul " << i + 1 << " : " << m.distParcursa[i];
			os << endl;
		}
		
		return os;
	}
	//operator de atribuire
Motocicleta operator =(Motocicleta& m)
{    
	if (this != &m) {
	setProducator(m.producator);
	setNrDrumuri(m.nrDrumuri);
	setDist(m.nrDrumuri, m.distParcursa);
	}
	
	return *this;
	}



};


void main()
{
	Motocicleta m1;
	cout << m1;
	Motocicleta m2("Suzuki", 3, new int[3] {100, 150, 120});
	cout << m2;
	Motocicleta m3 = m2;
	cout << m3;
	



}


