#include <iostream>
#include <iomanip>


using namespace std;

//-------------------------------------------------------------------------------------------------------------------------
//clasa produs angro


class produsG//angro
{

protected:		//clase in relatie de mostenire  (pt o singura clasa esre echivalentul private)
	string np;
	int cm, cs, p; //cheltuieli materiale,chelt ssalariale si profit
	//metoda calc pret
	//returneaza->
	int calcul_pret()
	{
		return cm + cs + p;
	}
public:
	produsG(string fnp="Nedefinit",int fcm=0,int fcs=0,int fp=0):np(fnp),cm(fcm),cs(fcs),p(fp){}
	//supraincarcare iperator
	friend ostream& operator<<(ostream& os,produsG& s) 
	{
		os << "Produsul: " << s.np << "are pretul" << s.calcul_pret() << endl;

		return os;
	}
	int get_pret()
	{

		return calcul_pret();

	}


};



// ----------------------------------------------------relatie de tip is a ------------------------------------------------
//-------------------------------------------------------clasa derivata----------------------------------------------------

//clasa produs retail (cu adaos comercial)

class produsA : public produsG //cu adaos comercial
{
	int ac;//adaos comercial
	int calcul_pret()
	{
		return produsG::calcul_pret() + ac;//(produsG::calcul_pret)va reutiliza codul deja scris si adauga adaus comercial
	}

public:
	produsA() :ac(0) {} //consructorul apeleaza elementele produsG (de baza,cu valori implicite) daca nu mentionez diferentele adica ac
	produsA(string fnp, int fcm, int fcs, int fp, int fac) :produsG(fnp, fcm, fcs, fp), ac(fac) {}

	



};
	


void main()
{
	//definim vecgtori de pointeri care sa aibqa si produseA si produseG

	produsG* vp[] = {

		new produsG(" pantaloni ",3,10,6), new produsA(" sacou ",4,20,6,20),new produsG(" caciula ",1,4,5)

	};
	for (int i = 0; i < 3; i++)
		cout << *vp[i];

}






	






















