#include <iostream>
#include <iomanip>

using namespace std;


class produs 
{
	char *np, um[5];
	int q;
	float pu;
public:
	produs(const char* fnp = "Nedefinit", const char* fum = "N/A", int cant = 0, float pret = 0) : q(cant), pu(pret)
	{
		np = new char[strlen(fnp) + 1];
		strcpy_s(np, strlen(fnp) + 1, fnp);
		strcpy_s(um, strlen(fum) + 1, fum);
	}

	produs(const produs& fprod) : q(fprod.q), pu(fprod.pu)
	{
		strcpy_s(um, strlen(fprod.um) + 1, fprod.um);
		np = new char[strlen(fprod.np) + 1];
		strcpy_s(np, strlen(fprod.np) + 1, fprod.np);
	}

	void set_cantitate(int);
	void set_denumire(const char*);

	int get_cantitate() { return q;}
	float get_valoare() { return pu*q;}
	char* get_denumire() { return np; }



	void afis_produs()
	{
		cout << setw(20) << setiosflags(ios::left) << np << "|" << resetiosflags(ios::left) << setw(4) << um << "|" << setw(5) << q << "|" << setw(8)<< setiosflags(ios::fixed) << setprecision(2) << pu << "|" << setw(8) << setiosflags(ios::fixed) << setprecision(2) << get_valoare() << endl;
	}

	void citire_produs()
	{
		char stemp[100];
		cout << "nume produs: "; cin >> stemp;
		set_denumire(stemp);
		cout << "unitate de masura: "; cin >> um;
		cout << "cantitatea: "; cin >> q;
		cout << "pretul unitar: "; cin >> pu;
	}

	produs& operator =(produs& obg)
	{
		set_denumire(obg.np);
		q = obg.q; pu = obg.pu;
		strcpy_s(um, strlen(obg.um) + 1, obg.um);
		return *this;
	}

	~produs() 
	{
		delete[] np;
	}
};

void produs::set_cantitate(int fq)
{
	if (fq >= 0) q = fq;
	else cerr << "Cantitate negativa!";
}

void produs::set_denumire(const char* fnp)
{
	if (strlen(fnp) > strlen(np))
	{
		delete[] np;
		np = new char[strlen(fnp) + 1];
	}
	strcpy_s(np, strlen(fnp)+1, fnp);
}

void main()
{
	produs *vp[10];// = { produs(), produs("Zahar", "KG", 20, 2.5) };
	int i, np;

	cout << "Nr. produse: "; cin >> np;
	vp[0] = new produs;
	vp[1] = new produs("Zahar", "KG", 20, 2.5);
	for(i=2;i<np+2;i++)
	{
		vp[i] = new produs;
		cout << "\tDate despre produs: "<<endl;
		vp[i]->citire_produs();
	}
	np += 2;

	produs obn = *vp[0];//produs obn(*vp[0]);
	for (i = 0; i < np; i++) vp[i]->afis_produs();
	obn.afis_produs(); cout << endl;


	obn.set_denumire("Cozonac");
	for (i = 0; i < np; i++) vp[i]->afis_produs();
	obn.afis_produs(); cout << endl;

	produs ob1;
	ob1 = obn;
	obn.afis_produs();ob1.afis_produs(); cout << endl;
	ob1.set_denumire("Palmier");
	obn.afis_produs(); ob1.afis_produs(); cout << endl;




	for (i = 0; i < np; i++) delete vp[i];
}
