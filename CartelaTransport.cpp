#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <cstring>

using namespace std;
class CartelaTransport
{
private:

	const string serieCartela;
	string numePosesor;
	char* producatorCartela;
	int nrZileUtilizare;
	float sumaPortofel;
	int nrCalatorii;
	float* valoriCalatorii;
	float valoareMinCalatorie;


public:
	//constructor implicit
	CartelaTransport() :
		serieCartela("N/A"), nrZileUtilizare(0),
		sumaPortofel(0), nrCalatorii(0), valoriCalatorii(nullptr), valoareMinCalatorie(0)
	{
		numePosesor = "Anonim";
		producatorCartela = new char[strlen("Necunoscut")+1];
		strcpy(producatorCartela, "Necunoscut");
	}
	//constructor
	CartelaTransport(string fnumePosesor, float fsumaPortofel, float* fvaloriCalatorii, int fnrCalatorii) :
		serieCartela("N/A"), producatorCartela(nullptr), nrZileUtilizare(0) 
	{
		if (!fnumePosesor.empty())
		{
			numePosesor = fnumePosesor;
		}
		else fnumePosesor = "Anonim";

		if (fsumaPortofel >= 0.0f)
			sumaPortofel = fsumaPortofel;
		else {
			sumaPortofel = 0;
			cout << "Suma nu poate fi negativa, a fost setata la 0"<<endl;
		}

		if (fnrCalatorii > 0)
		{
			nrCalatorii = fnrCalatorii;
			valoriCalatorii = new float[nrCalatorii];
			for (int i = 0; i < nrCalatorii; i++)
				if (fvaloriCalatorii[i] >= valoareMinCalatorie)
					valoriCalatorii[i] = fvaloriCalatorii[i];
				else valoriCalatorii[i] = valoareMinCalatorie;

		}
		else
		{
			nrCalatorii = 0;
			valoriCalatorii = nullptr;
			cout << "Nr de calatorii a fost setat la 0"<<endl;

		}
		producatorCartela = new char[strlen("Necunoscut")+1];
		strcpy(producatorCartela, "Necunoscut");

	}
	//destructor
	~CartelaTransport()
	{
		if(producatorCartela!=nullptr)
		delete[] producatorCartela;
		if(valoriCalatorii!=nullptr)
		delete[] valoriCalatorii;
	}

	void afisareCartelaTransport()
	{
		cout << " Seria cartelei : "<<serieCartela << " "<<endl;
		cout << "Posesorul cartelei : "<<numePosesor << " "<<endl;
		cout <<"Producatorul cartelei :" <<producatorCartela << " "<<endl;
		cout << "Nr zile utilizare : " << nrZileUtilizare<<" "<<endl;
		cout << "Nr calatorii : " << nrCalatorii << " "<<endl;
		cout << "Valori calatorii : " << valoriCalatorii << " "<<endl;
		cout << "Valoare minima calatorie : " << valoareMinCalatorie << " "<<endl;
		if (nrCalatorii > 0 && valoriCalatorii) {
			cout << "Valori călătorii: ";
			for (int i = 0; i < nrCalatorii; i++) {
				cout << valoriCalatorii[i] << " ";
			}
			cout << endl;
		}
		else {
			cout << "Nu există valori pentru călătorii." << endl;
		}
	
	}

	//Să se facă getteri și setteri pentru atributele numePosesor și valoriCalatorii. Să se facă
	//verificarea parametrilor primiți în setteri.

	string getnumePosesor()
	{
		return numePosesor;
	}
	void setnumePosesor(string nume)
	{
		if (!nume.empty())
			numePosesor = nume;
		else cout << "Numele posesorului nu poate fi setat" << endl;
	}

	float* getvaloriCalatori()
	{
		if (nrCalatorii > 0 && valoriCalatorii != nullptr)
			return valoriCalatorii;
		else return nullptr;
	}

	void setvaloriCalatori(float* valori)
	{
		if (nrCalatorii > 0)
		{
			for (int i; i < nrCalatorii; i++)
				valoriCalatorii[i] = valori[i];
		}
		else cout << "Nu se pot seta valorile calatoriilor" << endl;
	}
	//sa se scrie construcorul de copiere
	CartelaTransport(const CartelaTransport& other) :
		serieCartela(other.serieCartela),
		numePosesor(other.numePosesor),
		nrZileUtilizare(other.nrZileUtilizare),
		sumaPortofel(other.sumaPortofel),
		nrCalatorii(other.nrCalatorii),
		valoareMinCalatorie(other.valoareMinCalatorie)
	{
		if (other.producatorCartela != nullptr)
		{
			producatorCartela = new char[strlen(other.producatorCartela) + 1];
			strcpy(producatorCartela, other.producatorCartela);
		}
		else producatorCartela = nullptr;


		if (other.nrCalatorii != 0 && other.valoriCalatorii != nullptr)
		{
			valoriCalatorii = new float[other.nrCalatorii];
			for (int i; i < nrCalatorii; i++)
				valoriCalatorii[i] = other.valoriCalatorii[i];


		}
		else valoriCalatorii = nullptr;

	}

	//supraincarcare operator = pt atribuire

	CartelaTransport& operator=(const CartelaTransport& other)
	{
		if (this != &other) 
		{ //se verifica auto-atribuirea

			//dezalocam memoria existenta
			if (producatorCartela != nullptr)
				delete[] producatorCartela;
			if (valoriCalatorii != nullptr)
				delete[]valoriCalatorii;

			//copiem atribute simple
			numePosesor = other.numePosesor;
			nrZileUtilizare = other.nrZileUtilizare;
			sumaPortofel = other.sumaPortofel;
			nrCalatorii = other.nrCalatorii;
			valoareMinCalatorie = other.valoareMinCalatorie;


			if (other.producatorCartela != nullptr)
			{
				producatorCartela = new char[strlen(other.producatorCartela) + 1];
				strcpy(producatorCartela, other.producatorCartela);
			}
			else producatorCartela = nullptr;


			if (other.nrCalatorii != 0 && other.valoriCalatorii != nullptr)
			{
				valoriCalatorii = new float[other.nrCalatorii];
				for (int i; i < nrCalatorii; i++)
					valoriCalatorii[i] = other.valoriCalatorii[i];

			}
			else valoriCalatorii = nullptr;



		}

		return *this;

	}
};



void main()
{
	// Testare constructor implicit
	CartelaTransport cartela1;
	cartela1.afisareCartelaTransport();

	// Testare constructor cu parametrii
	float valori[] = { 2.5f, 3.0f, 1.8f }; // Exemplu: valori pentru călătorii
	CartelaTransport cartela2("Ion Popescu", 50.0f, valori, 3);
	cartela2.afisareCartelaTransport();

}
