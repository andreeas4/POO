
//SEMINAR 2 PROGRAMARE ORIENTATA OBIECT
#include <iostream>
using namespace std;

//definirea unei clase: produs unde sa avem numele produsului , unitatea de masura, cant si pretul unitar, definim o  clasa pt a descrie un produs,multimea prod pe caracterizarii sa definim constructori ,o met care sa faca afisarea produsului,o met care sa utilizeze valoarea produsului si niste functii de acces

class produs
{
	char np[100], um[4];//nume prod, unit de masura
	int q;//cant
	float pu;//pret unitar
public:
	produs(const char* fnp = "nedefinit", const char* fum = "?", int cant = 0, float pret = 0) : q(cant), pu(pret)
	{//parametri formali --apeleaza constructorii unor variabile elementare

		strcpy_s(np, strlen(fnp) + 1, fnp);
		strcpy_s(um, strlen(fum) + 1, fum);//nu inteleg nmc


	}
	//cum schimb numele produsului - operatiile de modif se realizeaza prin functii de acces
	void set_cant(int );//control asupra atribuirile datelor membre 
	
	int get_cant() //scoate starea
	{
		return q;

	}
	float get_valoare()
	{
		return pu * q;
	}
	//functie de afisare
	void afis_produs()
	{

		cout << " " << np << "  " << um << "  " << q << "  " << pu<<" "<<get_valoare()<<endl;
		
	}

	//functie de acces pt denumirea produsului  -prototip
	void set_denumire(const char*);//pointer la char
	char* get_denumire() { return np; }

};
void produs::set_cant(int fq)//control asupra atribuirile datelor membre pentru a nu considera ca este functie independenta punem NUME Clasa:: 
{
	if (fq >= 0) q = fq;

	else cerr << "Cantitate negativa!!";//cerr= console error ..msj de afisare erori
}
//functie de acces pt denumirea produsului
void produs::set_denumire( const char* fnp)
{
	strcpy_s(np, strlen(fnp) + 1, fnp);
}


void main()
{


	produs p1, p2("zahar", "kg", 20, 2.5);
	//p1.get_cant;cantitate de tip modificabila
	//p1.get-valoare ; .....valoarea este de tip read only-se modifica indirect prin pret sau cant
	


	//afisare obiect

	p2.afis_produs();
	p1.set_denumire("Faina");
	p1.set_cant(20);
	p1.afis_produs();
	cout << "Denumire: " << p1.get_denumire() << " Valoare: " << p1.get_valoare();
}
