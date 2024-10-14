
//definire vector obiecte



//definim obiecte in masiv de obiete(vector)




//SEMINAR 3 PROGRAMARE ORIENTATA OBIECT
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
	void set_cant(int);//control asupra atribuirile datelor membre 

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
		cout << " " << np << "  " << um << "  " << q << "  " << pu << " " << get_valoare() << endl;
		//cout << setw(20) << np << " | " << setw(4) << um << " | " << setw(5) << q << " | " << setw(8) << setiosflags(ios::fixed) << setprecision(2) << pu << " | " << get_valoare() << endl;
		//setiosflags(ios::fixed)<<setprecision(2) - accepta 2 zecimale fixe
		//AM ERORI AICI la ce e comentat la setw = indentifier not found

	}
	//functie de acces pt denumirea produsului  -prototip

	void set_denumire(const char*);//pointer la char

	char* get_denumire() { return np; }

	///citirea de la tastatura a datelor pt un obiect
	void citire_produse()
	{
		cout << "Nume produs: ";
		cin >> np;
		cout << "Unitate de masura: ";
		cin >> um;
		cout << "Cantitate: ";
		cin >> q;
		cout << "Pret: ";
		cin >> pu;
	}
	 
	~produs()
	{
		
		cout << " apel destructor";
	}


};
void produs::set_cant(int fq)//control asupra atribuirile datelor membre pentru a nu considera ca este functie independenta punem NUME Clasa:: 
{
	if (fq >= 0) q = fq;
	else cerr << "Cantitate negativa!!";//cerr= console error ..msj de afisare erori
}
//functie de acces pt denumirea produsului
void produs::set_denumire(const char* fnp)
{
	strcpy_s(np, strlen(fnp) + 1, fnp);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------------------------------------------------

void main()

{	//-------------------------------------------------------------------------------------------------------------------------
	//produs p1, p2("malai", "kg", 50, 2.5);
	//p1.get_cant;cantitate de tip modificabila
	//p1.get-valoare ; .....valoarea este de tip read only-se modifica indirect prin pret sau cant
	//afisare obiect
	//p2.afis_produs();
	//p1.set_denumire("Faina");
	//p1.set_cant(20);
	//p1.afis_produs();
	//-----------------------------------------------------------------------------------------------------------------------------
	int i, nr_produse;
	produs vp[10] = { produs(),produs("zahar","kg",10,2.5) };
	cout << "Nr produse: ";
	cin >> nr_produse;
	cout << endl;
	for (i = 2; i < nr_produse; i++)
	{

		cout << "Introduceti date despre produse: " << endl;
		vp[i].citire_produse();
	}
	for (i = 0; i < nr_produse; i++)
		vp[i].afis_produs();
	//----------------------------------------------------------------------------------------------------------------------------------

	//vector de pointer la obiecte pt a nu ocupa spatiu

	produs* vpo[10]; 
	vpo[0] = new produs;//aloca pt un produs si apeleaza contructorul implicit
	vpo[1] = new produs("zahar", "kg", 10, 2.5);
		for (i = 2; i < nr_produse; i++)
		{
			vpo[i] = new produs;

			cout << "Introduceti date despre produse: " << endl;
			vpo[i]->citire_produse();//   -> pt ca e vector de adrese

		

		}
		for (i = 0; i < nr_produse; i++)
		{
			vpo[i]->afis_produs();
			delete vpo[i];//dezalocare

		}

	





}











