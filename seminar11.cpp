#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<iomanip>

using namespace std;
#define CITIRE 1
#define SCRIERE 2

template <typename T>
class Pozitie;

template <typename T>
class Fisier
{
	friend Pozitie<T>;
	FILE* pf;
	bool vb;
	char numef[100];
public:
	Fisier() :pf(NULL), vb(true) {}
	bool deschide(const char* nf, int md = SCRIERE)
	{
		strcpy(numef, nf);
		if (md == SCRIERE) pf = fopen(nf, "w+b");
		else if (md == CITIRE) pf = fopen(nf, "r+b");
		return pf != NULL;
	}
	Fisier& operator << (T a)
	{
		if (pf)	fwrite(&a, sizeof(T), 1, pf);
		return *this;
	}

	void inchide() {if (pf)	{	fclose(pf);	pf = NULL;	}	}

	Fisier& operator >> (T& a)
	{
		if (pf) vb = fread(&a, sizeof(T), 1, pf) == 1;
		else vb = false;
		return *this;
	}

	bool is_eof() { return !vb; }
	char* get_nume_Fisier() { return numef; }

	Pozitie <T> operator [](int k)
	{
		fseek(pf, k * sizeof(T), SEEK_SET);
		return Pozitie<T>(*this);
	}

	~Fisier()	{		if (pf)	{fclose(pf);}	}
};

template <typename T>
class Pozitie
{
	Fisier<T>& f;
public:
	Pozitie(Fisier<T>& ff) :f(ff) {}
	operator T()
	{
		T art;
		f.vb = fread(&art, sizeof(T), 1, f.pf) == 1;
		return art;
	}
	Pozitie& operator=(T a)
	{
		fwrite(&a, sizeof(T), 1, f.pf);
		return *this;
	}
};

struct material
{
	int cantitate;
	float pret;
	char denumire[20];
	int cod;

	friend ostream& operator<<(ostream& os, material& m)
	{
		os << setw(5)<<m.cod<<"|"<<setw(22)<<setiosflags(ios::left)<<m.denumire<<"|"<< resetiosflags(ios::left)<<setw(7)<<m.cantitate<<"|"<<
			setw(10) << setiosflags(ios::fixed)<<setprecision(2)<<m.pret<<"|"<<
			setw(10)<<m.cantitate*m.pret<<"|";
		return os;
	}
};

void main()
{
	/*Fisier<int> fi;
	fi.deschide("fis.dat");
	fi << 100 << 20 << 54<<11;
	fi.inchide();
	if (!fi.deschide("fis.dat", CITIRE))
	{
		cerr << "Fisierul " << fi.get_nume_Fisier() << " nu exista" << endl;
	}
	int art;
	while (fi >> art, !fi.is_eof())	cout << art << endl;
	cout << "===========================" << endl;
	fi[0] = 1700;	fi[2] = 1166;
	for (int i = 0; art = fi[i], !fi.is_eof(); i++)	cout << art << endl;
	*/
	material v[] = { {4,2.5,"laptop",100},{7,4.5,"mouse",200},{9,5.5,"tastatura",300} };
	Fisier<material> fismat;
	fismat.deschide("fismat.dat");
	fismat << v[0] << v[2] << v[1];
	fismat.inchide();
	if (!fismat.deschide("fismat.dat", CITIRE)) {
		cerr << "Fisierul " << fismat.get_nume_Fisier() << " nu exista" << endl;
	}
	material art;
	//while (fismat >> art, !fismat.is_eof())	cout << art << endl;
	for (int i = 0; art = fismat[i], !fismat.is_eof(); i++)	cout << art << endl;


}
