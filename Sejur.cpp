#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Sejur {

private:
	const int id;
	char destinatie[20];
	float pretBaza;
	int nrExcursiiOptionale;
	float *pretExcursie;
	int nrLocuriDisponibile;
	int nrZileSejur;
public:
	//constructor cu un parametru id de tip int
	//constructorul are numele Sejur si este o METODA care initializeaza obiectul
	Sejur(int id) :id(id), pretBaza(0), nrExcursiiOptionale(0), pretExcursie(nullptr), nrLocuriDisponibile(0), nrZileSejur(0)
	{
		strcpy(destinatie, "Necunoscuta");
	}

	//constructor cu mai multi parametri
	
	Sejur(int fid, char* fdestinatie, float fpretBaza, int fnrExcursiiOptionale, float* fpretExcursie, int fnrLocuriDisponibile,
		int fnrZileSejur) :id(fid), pretBaza(fpretBaza), nrExcursiiOptionale(fnrExcursiiOptionale),
		nrLocuriDisponibile(fnrLocuriDisponibile), nrZileSejur(fnrZileSejur)
	{
		strcpy(this->destinatie, fdestinatie);
		//creeam loc pt vectorul pret excursie alocat dinamic
		pretExcursie = new float[nrExcursiiOptionale];
		for (int i = 0; i < nrExcursiiOptionale; i++) 
			pretExcursie[i] = fpretExcursie[i];
		
	}

	//constructor pt exercitiul cu nr maxim pt un anumit buget
	Sejur(int fnrExcursiiOptionale, float fpretBaza, float* fpretExcursie) :
		id(0), pretBaza(fpretBaza), nrExcursiiOptionale(fnrExcursiiOptionale), nrLocuriDisponibile(0), nrZileSejur(0)
	{
		pretExcursie = new float[nrExcursiiOptionale];
		strcpy(destinatie, "Necunoscuta");
		for (int i = 0; i < nrExcursiiOptionale; i++)
			pretExcursie[i] = fpretExcursie[i];
	}

	//destructor-sterge doar memoria alocata dinamic
	~Sejur() {
		delete[] pretExcursie;
	}
	//-------------------------------------------------------------------------------------------getteri si setteri
	float getpretBaza() //------->Getter 
	{
		return pretBaza;
	}
	void setPretBaza(float pret)
	{
		if (pret > 0)
			pretBaza = pret;
		else cout << "Pretul nu poate fi setat" << endl;
	}
	//-------------------------
	char* getDestinatie() {
		return destinatie;
	}

	void setDestinatie(char* nouaDestinatie)
	{
		if (nouaDestinatie != NULL && strlen(nouaDestinatie)<=sizeof(destinatie))
			strcpy(destinatie, nouaDestinatie);
	}
	//------------------------
	int getnrExcursiiOptionale()
	{
		return nrExcursiiOptionale;
	
	}

	void setnrExcursiiOptionale(int nrExOpt) 
	{
		if (nrExOpt > 0)
			nrExcursiiOptionale = nrExOpt;
		else cout << "Nu se poate seta numarul" << endl;

	}
	//----------------------------
	float getpretExcursie(int numarulexcursiei) 
	{
		if (numarulexcursiei > 0 && numarulexcursiei < nrExcursiiOptionale)
			return pretExcursie[numarulexcursiei];

		else {
			cout << "numarul excursiei nu este valid" << endl;
			return NULL;
		}
	}
	void setpretExcursie(int numarulexcursiei,float pret)
	{
		if (pret > 0)
			pretExcursie[numarulexcursiei] = pret;
		else cout << "Pretul nu poate fi setat"<<endl;
	}
	//----------------------------
	int getnrLocuriDisponibile()
	{
		return nrLocuriDisponibile;

	}
	void setnrLocuriDisponibile(int locuriD)
	{
		nrLocuriDisponibile = locuriD;

	}
	//-------------------------------
	int getnrZileSejur()
	{
		return nrZileSejur;

	}
	void setnrZileSejur(int zile)
	{
		if (zile > 0)
			nrZileSejur = zile;
		else cout << "Nu se pot seta nr de zile de sejur" << endl;

	}
	//-----------------------------------------------------------------------------------------------pana aici getteri si setteri


	//1 punct Să se implementeze metoda getNrMaximExcursii(float bugetMaximSejur) ce
	//returneaza numarul maxim de excursii optionale pe care le poate achizitiona un client tinand
		//cont si de pretul de baza al sejurului.

	int getNrMaximExcursii(float bugetMaximSejur)
	{
		float costTotalSejur = pretBaza;
		if (bugetMaximSejur < pretBaza)
		{
			cout << "Bugetul nu acopera nici macar pretul de baza al sejurului" << endl;
			return 0;
		}

		else
		{

			float bugetRamas = bugetMaximSejur - pretBaza;
			sort(pretExcursie, pretExcursie + nrExcursiiOptionale);//sortam toate preturile excursiei

			int nrMaxExcursii = 0;//initiaizam numarul maxim de excursii cu 0 pe care putem sa le platim cu bugetul dat
			for (int i = 0; i < nrExcursiiOptionale; i++)
			{
				if (bugetRamas >= pretExcursie[i])
				{
					bugetRamas = bugetRamas - pretExcursie[i];
					nrMaxExcursii++;
				}
				else break;

			}
			return nrMaxExcursii;
		}

	}






};
void main()
{

	
	// Sejur cu 3 excursii, prețul de bază 300 și prețurile excursiilor
	float preturiExcursii2[] = { 100, 150, 200 };
	Sejur sejur2(3, 300, preturiExcursii2);  // 3 excursii, prețul de bază al sejurului este 300

	float bugetMaxim2 = 250;  // Bugetul maxim este 250
	cout << "Sejurul 2 - Numarul maxim de excursii ce pot fi achizitionate: "
		<< sejur2.getNrMaximExcursii(bugetMaxim2) << endl;

	// Sejur cu 3 excursii, prețul de bază 300 și prețurile excursiilor
	float preturiExcursii5[] = { 50, 150, 200 };
	Sejur sejur5(3, 300, preturiExcursii5);  // 3 excursii, prețul de bază al sejurului este 300

	float bugetMaxim5 = 500;  // Bugetul maxim este 500
	cout << "Sejurul 5 - Numarul maxim de excursii ce pot fi achizitionate: "
		<< sejur5.getNrMaximExcursii(bugetMaxim5) << endl;



}


 




/*Se consideră clasa Sejur, care include câmpurile:
• id – întreg pozitiv constant, asociat identificatorului sejur;
• destinatie – sir de caractere, reprezinta destinatia sejurului;
• pretBaza – numar real ce reprezinta pretul de baza al unui sejur (fara excursiile
optionale);
• nrExcursiiOptionale – numar intreg ce reprezinta numarul de excursii optionale
aferente sejurului;
• pretExcursie – vector alocat dinamic cu valori reale pozitive ce stocheaza pentru
fiecare excursie optionala pretul acesteia;
• inca 2 atribute la alegere care sa caracterizeze obiectele de tip Sejur.
Implementați cerințele următoare pentru clasa Sejur.
Nota 1 Să se creeze un proiect în Microsoft Visual Studio care să nu genereze erori de compilare
si de linkeditare.
Nota 2
• Definiți în fișierul sursă generat clasa Sejur. Toate atributele se definesc în zona privată a
clasei.
• Sa se implementeze constructorul cu un parametru (id) și metode de acces la membrii
noi adaugati in clasa (get si set). Acolo unde este cazul, metodele de tip set definesc validări
pentru parametri.
Nota 3 Să se implementeze constructorul cu toți parametri și destructorul clasei.
1 punct Să se implementeze metoda getNrMaximExcursii(float bugetMaximSejur) ce
returneaza numarul maxim de excursii optionale pe care le poate achizitiona un client tinand
cont si de pretul de baza al sejurului.
1 punct Implementați constructorul de copiere
1 punct Să se supraîncarce operatorul de atribuire (=).
1 punct Sa se supraincarca operatorul float care sa returneze costul total in cazul in care se
achizitioneaza toate excursiile optionale disponibile pentru acel sejur.
1 punct Să se supraîncarce operatorii << și >> pentru afișarea și citirea obiectelor de tip Sejur
(implementarea trebuie sa permita citirea sirurilor de caractere cu spatii).
1 punct Să se supraîncarce operatorul - - in forma de postdecrementare care sa elimine din
respectivul sejur excursiile cu pretul minim. Daca exista mai multe astfel de excursii, se vor
elimina toate aceste excursii.
1 punct Să se supraîncarce operatorii de comparatie <= si <. ( float<= Sejur si Sejur < float)
(Evaluarea se realizeaza din punct de vedere al celei mai costisitoare excursii ale unui Sejur).
Pentru implementare, nu se folosesc metode de tip accesor suplimentare fata de cele existente
in cerintele subiectului sau alte metode suplimentare de prelucrare sau folosirea conceptului de
friend.
Note:
1. Pentru a fi evaluate în vederea punctării, metodele se testează în funcția main() și sunt
incluse comentarii pentru evidențierea apelurilor
2. Acolo unde este cazul, metodele trebuie implementate astfel încât memoria alocată să
fie eliberată

Timp de lucru: 50 min*/
