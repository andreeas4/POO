#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;


class produs
{
	char* np, um[5];
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

	int get_cantitate() { return q; }
	float get_valoare() { return pu * q; }
	char* get_denumire() { return np; }

	//void afis_produs()
	//{
	//	cout << setw(20) << setiosflags(ios::left) << np << "|" << resetiosflags(ios::left) << setw(4) << um << "|" << setw(5) << q << "|" << setw(8)<< setiosflags(ios::fixed) << setprecision(2) << pu << "|" << setw(8) << setiosflags(ios::fixed) << setprecision(2) << get_valoare() << endl;
	//}

	/*void citire_produs()
	{
		char stemp[100];
		cout << "nume produs: "; cin >> stemp;
		set_denumire(stemp);
		cout << "unitate de masura: "; cin >> um;
		cout << "cantitatea: "; cin >> q;
		cout << "pretul unitar: "; cin >> pu;
	}*/

	produs& operator =(produs obg)
	{
		set_denumire(obg.np);
		q = obg.q; pu = obg.pu;
		strcpy_s(um, strlen(obg.um) + 1, obg.um);
		return *this;
	}

	friend ostream& operator << (ostream& os, produs& prod)
	{
		os << setw(20) << setiosflags(ios::left) << prod.np << "|" << resetiosflags(ios::left) << setw(4) << prod.um << "|" << setw(5) << prod.q << "|" << setw(8) << setiosflags(ios::fixed) << setprecision(2) << prod.pu << "|" << setw(8) << setiosflags(ios::fixed) << setprecision(2) << prod.get_valoare() << endl;
		return os;
	}

	friend ostream& operator << (ostream& os, produs* prod)
	{
		os << setw(20) << setiosflags(ios::left) << prod->np << "|" << resetiosflags(ios::left) << setw(4) << prod->um << "|" << setw(5) << prod->q << "|" << setw(8) << setiosflags(ios::fixed) << setprecision(2) << prod->pu << "|" << setw(8) << setiosflags(ios::fixed) << setprecision(2) << prod->get_valoare() << endl;
		return os;
	}
	friend istream& operator >> (istream& is, produs& prod)
	{
		char stemp[100];
		cout << "nume produs: "; is >> stemp;
		prod.set_denumire(stemp);
		cout << "unitate de masura: "; is >> prod.um;
		cout << "cantitatea: "; is >> prod.q;
		cout << "pretul unitar: "; is >> prod.pu;
		return is;
	}
	//presupunem ca 2 produse sunt egale daca au aceeasi valoare (get_valoare())

	bool operator == (produs& p) {
		return get_valoare() == p.get_valoare();
	}

	//vrem sa comparam valoarea cu un numar (float)
	bool operator == (float x) {
		return get_valoare() == x;
	}

	//asiguram comutativitatea operatorului ==
	friend bool operator == (float x, produs& p) {
		return p.get_valoare() == x;
	}
	//------------------------------------------------------------------------------------------------------------
	//preincrementare
	produs& operator++()
	{
		q++;
		return *this;


	}

	//pt a face deosebirea dintre post incrementaree si preincrementre dam un int 
	
	//postincrementare
	produs operator++(int )//int = deosebire apel
	{
		
		//pastram this in pn 
		produs pn(*this);//produs nou
		
		q++;
		return pn; //returneaza un produs
		
	}
//----------------------------------------------------------------------------------------------------------------------------------------
	//operator de conversie = operator cast

	operator float()
	{

		return get_valoare();


	}
//-----------------------------------------------------------------------------------------------------------------------------------------
	//operator + astfel incat sa poata fi folosit produs+intreg = cantitate produs plus intreg si produs+produs 
	produs operator+(int k)					//adunare cu scalar p+x
	{

		return produs(np, um, q + k, pu);


	}

	friend produs operator+(int k,produs &p)					//int + produs			
	{

		return produs(p.np, p.um, p.q +k, p.pu);


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
	strcpy_s(np, strlen(fnp) + 1, fnp);
}





void main()
{
	//produs *vp[10];// = { produs(), produs("Zahar", "KG", 20, 2.5) };
	//int i, np;

	//cout << "Nr. produse: "; cin >> np;
	//vp[0] = new produs;
	//vp[1] = new produs("Zahar", "KG", 20, 2.5);
	//for(i=2;i<np+2;i++)
	//{
	//	vp[i] = new produs;
	//	cout << "\tDate despre produs: "<<endl;
	//	cin >> *vp[i];
	//}
	//np += 2;

	//produs obn = *vp[0];//produs obn(*vp[0]);
	//for (i = 0; i < np; i++) cout << "Referinta: " << *vp[i];
	//cout << obn << endl;


	//obn.set_denumire("Cozonac");
	//for (i = 0; i < np; i++) cout<<"Adresa: " << vp[i];
	//cout << obn << endl;

	//produs ob1;
	//ob1 = obn;
	//cout << obn << ob1 << endl;
	//ob1.set_denumire("Palmier");
	//cout << obn << ob1 << endl;
	//cin >> obn >> ob1;
	//for (i = 0; i < np; i++) delete vp[i];

	float x = 20;
	produs p1("Mouse", "buc", 4, 5), p2("Tastatura", "buc", 3, 5),p3;

	if (x == p1)cout << "Adevarat "<<endl;

	else cout << "Fals"<<endl;


	p2 = p1++;
	cout << p1 << p2 << endl;
	x =(float) p1;//conversie explicita
	cout << "Valoarea produsului: " << p1.get_denumire() << " este :" << x << endl;
//-------AVEM IN VEDERE OPERATORUL + sa functioneze la toate 3


	p2 = p1 + 10; //cantitate produs 1
	//p3 = p1 + p2; //concatenare nume, suma cant ,suma preturi
	p3 = 2 + p1;  


	cout << p1 << " " << p2<< " " << p3 << endl;







}
