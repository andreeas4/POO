#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

class Fisier {

private:

	const int codFisier;
	char numeFisier[5];
	int nrAccesari;
	string* editori;
	int dimensiuneFisier;//pentru a stii dimensiunea pe care o ocupa fisierul
	char tipFisier[10];//pentru a stii ce fel de fisier este (txt,binar...)


public:
	Fisier() :codFisier(0), nrAccesari(0), editori(nullptr), dimensiuneFisier(0) 
	{
		strcpy(numeFisier, "N/A");
		strcpy(tipFisier, "N/A");

	}
	Fisier(int fcodFisier, char fnumeFisier[5], int fnrAccesari, string* feditori, int fdimensiuneFisier, char ftipFisier[10]) :
		codFisier(fcodFisier), nrAccesari(fnrAccesari), dimensiuneFisier(fdimensiuneFisier) 
	{
		strcpy(numeFisier, fnumeFisier);
		strcpy(tipFisier, ftipFisier);
		editori = new string[nrAccesari];
		for (int i; i < nrAccesari; i++)
			editori[i] = feditori[i];


	}
	Fisier( Fisier& other) :codFisier(other.codFisier)
	{// Copiere numeFisier
		strcpy(this->numeFisier, other.numeFisier);

	}



	~Fisier() {
		delete editori;
	}

};






void main()

{



	// Exemplu de utilizare a clasei Fisier

	// Date pentru fișier
	string editori[] = { "Ana", "Maria", "Ion" };

	// Crearea unui obiect cu constructorul cu parametri
	

	







}
