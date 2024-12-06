#include <iostream>
#include<iomanip>
using namespace std;

template <typename TIP=int,int DIM=100>
class vector 
{
	TIP	v[DIM];
	int nre;
public:
	vector():nre(0){}
	vector& operator << (TIP el)
	{
		v[nre++] = el;
		return *this;
	}
	friend ostream& operator << (ostream& os, vector& a)
	{
	// (el1; el2; ..)
		int i;
		os << "( ";
		for (i = 0; i < a.nre-1; i++) os << a.v[i] << "; ";
		os << a.v[i] << " )";
		return os;
	}
	void sortare()
	{
		int i, j;
		TIP aux;
		for (i=0;i<nre-1;i++)
			for(j=i+1;j<nre;j++)
				if (v[i] > v[j]) 
				{
					aux = v[i];
					v[i] = v[j];
					v[j] = aux;					
				}
	}
};

class material {
	string nume_material;
	float pret;
	int cantitate;
public:
	material(string fn = "-", float fp = 0, int fc=0): nume_material(fn),pret(fp),cantitate(fc) {}
	friend ostream& operator << (ostream& os, material& mat)
	{
		os << setw(15) << setiosflags(ios::left) << mat.nume_material << resetiosflags(ios::left) << "|" << setw(10)
			<< setiosflags(ios::fixed) << setprecision(2) << mat.pret << "|" << setw(10) << mat.cantitate;
		return os;
	}
	float get_valoare() { return pret * cantitate; }
	bool operator > (material& mat)
	{
		return (get_valoare() > mat.get_valoare());
	}

};
void main()
{
	vector <> obvi;
	vector <double, 50> obvd;
	vector <string, 10> obvsir;
	vector <material, 6> obvmat;
	obvi << 200 << 30 << 15;
	obvd << 193.33 << 125.25 << 9.4;
	obvsir << "sir1" << "sir2" << "3sir";
	obvmat << material() << material("Panza", 100.3172, 10) << material ("Otel",50,10);
	obvmat.sortare();
	cout << obvmat << endl;
	obvi.sortare();
	cout << obvi << endl;
	obvd.sortare();
	cout << obvd << endl;
	obvsir.sortare();
	cout << obvsir << endl;
}
