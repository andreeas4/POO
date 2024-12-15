#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <cstring>

using namespace std;
class Contor {

private:

	const int idContor;
	char* numeClient;
	float tarifPekw;
	float consumLunar[12];
	int an;


public:
	//constructor implicit
	Contor() :idContor(0), tarifPekw(0.0f), an(0) {
		numeClient = new char[strlen("Anonim") + 1];
		strcpy(numeClient, "Anonim");
		

		for (int i = 0; i <=11; i++)
			consumLunar[i] = 0;
	}
	//constructor cu toti parametri
	Contor(const int fidContor, const char* fnumeClient, float ftarifPeKw, float fconsumLunar[12], int fan)
		:idContor(fidContor), tarifPekw(ftarifPeKw), an(fan) {
		
		if (fnumeClient != NULL)
		{
			numeClient = new char[strlen(fnumeClient) + 1];
			strcpy(numeClient, fnumeClient);
		}
		else numeClient = nullptr;

		for (int i = 0; i <= 11; i++)
			if (fconsumLunar[i]>= 0)
			{	
				consumLunar[i] = fconsumLunar[i];

			}
			else {
				consumLunar[i] = 0;
				cout << "Nu se poate a consumul lunar sa fie negativ pt luna " <<i+1<< endl;
			}
			


	}

	//destructor

	~Contor() {

		if (numeClient != NULL)
			delete[] numeClient;
	}

	char* getNumeClient() {
		if (numeClient != nullptr)
			return numeClient;
		else {
			cout << "Nu exista numele clientului"<<endl;
			return 0;
		}
	}
	void setNumeClient(const char* nume)
	{
		if (numeClient != nullptr)
		{
			delete[]numeClient;
		}
		if (nume != nullptr)
		{
			
			numeClient = new char[strlen(nume) + 1];
			strcpy(numeClient, nume);

		}
		else {
			numeClient = nullptr;
			cout << "Nu se poate seta numele clientului" << endl;
		}
		
	}
	//constructor de copiere
	Contor(const Contor& other) :idContor(other.idContor), tarifPekw(other.tarifPekw), an(other.an) {


		for (int i = 0; i <= 11; i++)
			if(other.consumLunar[i] >= 0)
			consumLunar[i] = other.consumLunar[i];
			else {
				consumLunar[i] = 0;
				cout << "Nu se poate seta o valoare negativa la consumul lunar in luna " << i + 1 << endl;
			}
		if (other.numeClient != nullptr)
		{
			numeClient = new char[strlen(other.numeClient) + 1];
			strcpy(numeClient, other.numeClient);
		}
		else numeClient=nullptr;
		


	}
	//supraincarcare operatorul de atribuire
	Contor& operator=(Contor other)
	{
		if (this != &other) {

			cout << "Id ul contorului nu poate fi modificat" << endl;
			if (numeClient != nullptr)
			{
				delete[] numeClient;
			}
			numeClient = new char[strlen(other.numeClient) + 1];
			strcpy(numeClient, other.numeClient);

			for (int i = 0; i <= 11; i++)
				if (other.consumLunar[i] >= 0)
					consumLunar[i] = other.consumLunar[i];
				else {
					consumLunar[i] = 0;
					cout << "Nu se poate seta o valoare negativa la consumul lunar in luna " << i + 1 << endl;
				}
			tarifPekw = other.tarifPekw;
			an = other.an;

		}
		return *this;

	}

	void afisareContor()
	{   
		cout << "--------------------------------------------------------------"<<endl;
		cout << "Contor ul : "<<endl;
		cout << "Id contor: " << idContor << endl;
		cout << "Nume client: " << numeClient << endl;
		cout << "Tariful pe KWH: " << tarifPekw << endl;
		cout << "Consumul Clientului : " << numeClient << " pe luni "<<endl;
		for (int i = 0; i <= 11; i++)
			cout << "Luna " << i + 1 << " : " << consumLunar[i]<<" KWH " << endl;
		cout << endl;
		cout << "Pentru Anul : " << an<<endl;

	}

	//operatorul unar  ++ astfel incat sa se incrementeze anul si tariful de consum
	Contor& operator++(int )
	{
		an = an + 1;
		tarifPekw += 1;

		return *this;
	}
	
	//operatorul aritmetic + ca o adunare a 2 obiecte astfel incat sa se concateneze numele clientilor si sa se insumeze consumul lunar
	Contor operator+(Contor other) {

		
		
			char* numeConcat = new char[strlen(this->numeClient) + strlen(other.numeClient) + 5];
			strcpy(numeConcat, this->numeClient);
			strcat(numeConcat, "  Si ");
			strcat(numeConcat, other.numeClient);
		
		float consumTotalLunar[12];
		for (int i = 0; i < 11; i++)
			consumTotalLunar[i] = this->consumLunar[i] + other.consumLunar[i];

		Contor rezultat(
			this->idContor,
			numeConcat,
			this->tarifPekw,
			consumTotalLunar,
			this->an

		) ;

		return rezultat;

	 }

	//operatorul / care returneaza doar consumul pe o anumita luna data
	float& operator/(const int a) {
		if (a > 0 && a < 12)
			return consumLunar[a-1];
		else {
			cout << "Cerere invalia,trebuie introdusa o luna existenta " << endl;
			cout << "De exemplu luna 1 " << endl;
			return consumLunar[0];
		}
	}


 };


void main()
{
	float consumLunar[12] = {1,4,4,2,8,0,-12,9,10,2,11,11};
	const int idContor1 = 100;
	Contor contor1(idContor1, "Alina Popescu", 23.1f, consumLunar, 2012);
	const char* numeNou="Maria Popescu";
	//testare set si get
	contor1.setNumeClient(numeNou);
	cout<<"Numele clientuli: "<<contor1.getNumeClient()<<endl;
	//testare operator de atribuire
	Contor contor2(idContor1, "Alina Vasile", 25.50f, consumLunar, 2000);
	contor1 = contor2;
	//testare functie de afisare (Nu am invatat sa supraincarc operatorii de intrare si iesire)
	//contor1.afisareContor();

	//testare operaator++
	contor1++;
	cout << "Contorul 1 dupa ce a fost incrementat" << endl;
	//contor1.afisareContor();

	//testare operator /
	int luna = 5;  // Luna Mai
	float consumPeLuna = contor1 / luna;
	cout << "Consumul pe luna " << luna << " este " << consumPeLuna<<endl; 
	 //testare opertor +
	int const idContorComun = 2;
	float consumLunarVeronica[12] = { 1,5,4,2,8,0,0,0,2,2,1,1 };
	float consumLunarGheorghe[12]= { 0,0,4,2,1,0,10,9,10,22,11,11 };
	Contor contorGh(idContorComun, "Gheorghe Stan", 20.1f, consumLunarGheorghe, 2020);
	Contor contorV(idContorComun, "Veronica Popescu", 20.1f, consumLunarVeronica, 2020);
	contorGh.afisareContor();
	contorV.afisareContor();
	cout << "CONTORUL COMUN : " << "-------------------------------------" << endl;
	(contorGh + contorV).afisareContor();


}

