#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <cstring>
#include <fstream>/*Nota 3
Să se definească clasa Vapor care are câmpurile:
• capacitate – întreg – numărul de persoane care pot fi îmbarcate;
• nrPersoaneImbarcate – întreg – numărul de persoane aflate la bord. Nu poate fi mai mare
decât capacitatea vaporului;
• varstePasageri – vector alocat dinamic reprezentând vârstele pasagerilor de pe vapor (int).
• Alte două atribute la alegere. Explicați prin comentariu utilitatea acestor atribute
adăugate.
Atributele clasei se definesc în zona privată a clasei.
Nota 4
Să se definească pentru clasa Vapor constructor fără parametri, constructor cu parametri și
destructor. Constructorul cu parametri conține validări pentru parametrii primiți.
Nota 5
Să se definească pentru clasa Vapor constructorul de copiere și metode accesor(get si set) pentru
cele doua atribute adăugate.
1 punct
Să se supraîncarce pentru clasa Vapor operatorul de atribuire (=) fără a genera memory leaks.
1 punct
Să se supraîncarce operatorul << pentru afișarea obiectelor de tipul Vapor. Elementele sunt afișate
pe aceeași linie despărțite prin virgula și spațiu.
1 punct
Să se definească metoda calculareVarstaMedie() care calculează media vârstelor pasagerilor.
1 punct
Să se supraîncarce operator functie care numărul de persoane care mai pot fi îmbarcate până la
atingerea capacității maxime a vaporului.
1 punct
Să se supraîncarce operatorul de cast la int care va returna numărul de pasageri minori de la bord.*/
using namespace std;

class Vapor {

private:

	int capacitate;
	int nrPersoaneImbarcate;
	int* varstePasageri;
	int idVapor; //pentru a identifica vapotul prin id propriu
	char* destinatie;//pentru a cunoaste destinatia unde vor ajunge pasagerii cu acest vapor



public:
	//constructor implicit
	Vapor() :capacitate(0), nrPersoaneImbarcate(0), varstePasageri(nullptr), idVapor(0) {

		destinatie = new char[strlen("Necunoscuta") + 1];
		strcpy(destinatie, "Necunoscuta");
	}

	//constructor cu parametri
	Vapor(int fcapacitate, int fnrPersoaneImbarcate,  const int* fvarstePasageri, int fidVapor, char* fdestinatie) :
		capacitate(fcapacitate), idVapor(fidVapor) 
	{
		if (fnrPersoaneImbarcate <= capacitate&&fnrPersoaneImbarcate>=0)
			nrPersoaneImbarcate = fnrPersoaneImbarcate;
		else {
			cout << "Nu se pot imbarca un numer de persoane mai mare decat capacitatea Vaporului" << endl;
			nrPersoaneImbarcate = 0;
		}

		if (fnrPersoaneImbarcate > 0)
		{
			varstePasageri = new int[fnrPersoaneImbarcate];
			for (int i = 0; i < fnrPersoaneImbarcate; i++)
				if (fvarstePasageri[i] >= 0)
					varstePasageri[i] = fvarstePasageri[i];
				else varstePasageri[i] = 0;

		}
		else varstePasageri = nullptr;
		
		if (fdestinatie != nullptr)
		{
			destinatie = new char[strlen(fdestinatie) + 1];
			strcpy(destinatie, fdestinatie);
		}
		else destinatie = nullptr;
	}
	//destructor
	~Vapor()
	{
		if (destinatie != nullptr)
			delete[]destinatie;
		if (varstePasageri != nullptr)
			delete[]varstePasageri;
	}
	//constructor de copiere
	Vapor(const Vapor& other) :idVapor(other.idVapor), capacitate(other.capacitate) {
		if (other.nrPersoaneImbarcate <= capacitate && other.nrPersoaneImbarcate >= 0)
			nrPersoaneImbarcate = other.nrPersoaneImbarcate;
		else {
			cout << "Nu se pot imbarca un numer de persoane mai mare decat capacitatea Vaporului" << endl;
			nrPersoaneImbarcate = 0;
		}

		if (other.nrPersoaneImbarcate > 0)
		{
			varstePasageri = new int[other.nrPersoaneImbarcate];
			for (int i = 0; i < other.nrPersoaneImbarcate; i++)
				if (other.varstePasageri[i] >= 0)
					varstePasageri[i] = other.varstePasageri[i];
				else varstePasageri[i] = 0;

		}
		else varstePasageri = nullptr;

		if (other.destinatie != nullptr)
		{
			destinatie = new char[strlen(other.destinatie) + 1];
			strcpy(destinatie, other.destinatie);
		}
		else destinatie = nullptr;
	}
	//get si set pt destinatie si idVapor
	
	int const getIdVapor() {
		
			return idVapor;
		
	}

	void setIdVapor(int const id)
	{
		if (id != 0 && id > 0)
			idVapor = id;
		else {
			idVapor = 0;
			cout << "Id innacceptabil !!! Vaporul nu exista asa ca va fi setat id ul la 0 " << endl;
		}

	}

	char* getDestinatie() {

		return destinatie;
	}

	void setDestinatie(char* undeva) {
		if (undeva != nullptr)
		{
			delete[] destinatie;
			destinatie = new char[strlen(undeva) + 1];
			strcpy(destinatie, undeva);
		}
		else destinatie = nullptr;
	}
	//operatorul de atribuire
	Vapor& operator=(Vapor other)
	{
		if (this != &other)
		{
			idVapor = other.idVapor;
			capacitate = other.capacitate;

			if (other.nrPersoaneImbarcate <= capacitate && other.nrPersoaneImbarcate >= 0)
				nrPersoaneImbarcate = other.nrPersoaneImbarcate;
			else {
				cout << "Nu se pot imbarca un numer de persoane mai mare decat capacitatea Vaporului" << endl;
				nrPersoaneImbarcate = 0;
			}

			if (other.nrPersoaneImbarcate > 0)
			{
				varstePasageri = new int[other.nrPersoaneImbarcate];
				for (int i = 0; i < other.nrPersoaneImbarcate; i++)
					if (other.varstePasageri[i] >= 0)
						varstePasageri[i] = other.varstePasageri[i];
					else varstePasageri[i] = 0;

			}
			else varstePasageri = nullptr;

			if (other.destinatie != nullptr)
			{
				destinatie = new char[strlen(other.destinatie) + 1];
				strcpy(destinatie, other.destinatie);
			}
			else destinatie = nullptr;
		}
		return *this;
	}
	
	
	// Supraincarcare operator << pentru afisare in consola
	friend ostream& operator<<(ostream& os, const Vapor& v) {
		os << "ID Vapor: " << v.idVapor << ", Capacitate: " << v.capacitate
			<< ", Nr Persoane Imbarcate: " << v.nrPersoaneImbarcate
			<< ", Destinatie: " << v.destinatie << ", Varste Pasageri: ";

		if (v.varstePasageri != nullptr) {
			for (int i = 0; i < v.nrPersoaneImbarcate; ++i) {
				os << v.varstePasageri[i];
				if (i < v.nrPersoaneImbarcate - 1) os << ", ";
			}
		}
		else {
			os << "N/A";
		}

		os << endl;
		return os;
	}
	//metoda
	float calculareVarstaMedie()
	{
		float varstaMedie=0;
		if (nrPersoaneImbarcate > 0)
		{
			for (int i = 0; i < nrPersoaneImbarcate; i++)
				varstaMedie += varstePasageri[i];
			varstaMedie /= nrPersoaneImbarcate;
			return varstaMedie;
		}
		else return -1;
	}
	//Să se supraîncarce operator functie care numărul de persoane care mai pot fi îmbarcate până la
	//atingerea capacității maxime a vaporului.
	int operator()() {
		return capacitate - nrPersoaneImbarcate;
	}
};

void main()
{
	int nrPasageri = 6;
	int cap=10;
	int varste[6] = {1, 2, 3, 4, 5, 6};
	int cap2 = 20;
	char* unde =(char*) "Spania";
	Vapor vapor1(cap, nrPasageri, (int*)varste, 120, (char*)"Ibiza");
	Vapor vapor2(cap2, nrPasageri, (int*)varste, 200, (char*)"Tenerife");
	cout << vapor1;
	cout << "Destinatia vaporului este: " << vapor1.getDestinatie() << endl;
	vapor1.setDestinatie(unde);
	vapor1 = vapor2;
	cout << vapor1;
	cout << "Varsta medie a pasagerilor este : ";
	cout << vapor1.calculareVarstaMedie()<<endl;
	cout << "Nr de persoane care pot fi imbarcate pana la atingerea capacitatii : ";
	cout << vapor1();

}
