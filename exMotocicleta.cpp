
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
			cout << "Date invalide pentru setarea distanțelor." << endl;
			return;
		}

		// Eliberăm memoria alocată anterior pentru distParcurse
		if (distParcursa != nullptr) {
			delete[] distParcursa;
		}

		// Actualizăm numărul de drumuri
		nrDrumuri = fNrDrumuri;

		// Alocăm memorie pentru noile distanțe și copiem valorile
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
	//opertor de atribuire
	


};

void main()
{
	Motocicleta m1;
	cout << m1;
	Motocicleta m2("Suzuki", 3, new int[3] {100, 150, 120});
	cout << m2;


}

