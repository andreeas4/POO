#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <map>
using namespace std;

#define CIT 1
#define SCR 2

template<typename T>
class index
{
protected:
	map< T, long > vi;

	int nrel;
	
public:
	
	bool adauga(T k) { return vi.insert(pair<T, long>(k, vi.size().second); }//returneaza 1 cand adaugarea are succes -cand inregistrarea cu cheia k nu exista 
	long cauta(T k) { return vi.find(k) == vi.end ? -1 : vi.find(k).second; }
};










template<typename T>
bool index<T>::adauga(T k)
{
	bool vb = true;
	int i, j;
	for (i = 0; i < nrel && vb; i++)
	{
		if (vi[i].ch == k) return false;
		else if (vi[i].ch > k)
		{
			for (j = nrel; j > i; j--)vi[j] = vi[j - 1];
			vi[i].ch = k;
			vi[i].poz = nrel;
			vb = false;
		}
	}
	if (vb) { vi[nrel].ch = k; vi[nrel].poz = nrel; }
	nrel++;
}

template<typename T>
//long index<T>::caut(T keie, int li, int ls)
{
	int m;
	if (li <= ls)
	{
		m = (li + ls) / 2;
		if (vi[m].ch == keie) return vi[m].poz;
		else if (keie < vi[m].ch) return caut(keie, li, m - 1);
		else return caut(keie, m + 1, ls);
	}
	return -1;
}

template<typename T>
class Pozitie;

template <typename T>
class Fisier
{
	friend Pozitie<T>;
	FILE* pf;
	bool vb;
	char nf[100];
public:
	Fisier() :pf(NULL), vb(true) {}
	bool deschide(const char* numef, int md = SCR)
	{
		strcpy(nf, numef);
		if (md == SCR) pf = fopen(numef, "w+b");
		else if (md == CIT)  pf = fopen(numef, "r+b");
		return pf != NULL;
	}

	char* get_numef() { return nf; }

	Fisier& operator<<(T a)
	{
		if (pf) fwrite(&a, sizeof(T), 1, pf);
		return *this;
	}

	Fisier& operator>>(T& a)
	{
		if (pf) vb = fread(&a, sizeof(T), 1, pf) == 1;
		else vb = false;
		return *this;
	}

	Pozitie<T> operator[](int k)
	{
		fseek(pf, k * sizeof(T), SEEK_SET);
		return Pozitie<T>(*this);
	}

	bool is_eof() { return !vb; }

	void inchide() { if (pf) { fclose(pf); pf = NULL; } }
	~Fisier() { if (pf) 	fclose(pf); }
};


template<typename T>
class Pozitie
{
	Fisier<T>& f;
public:
	Pozitie(Fisier<T>& ff) :f(ff) { }
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


template<typename ART, typename K>
class Fisier_indexat : public Fisier<ART>, public index<K>
{
	bool exista;
public:
	Fisier_indexat() :exista(true) { }

	bool scrie_art(ART a, K k)
	{
		bool vb = true;
		if (this->adauga(k)) (*this) << a;
		else vb = false;
		return vb;
	}

	ART operator[](K ch)
	{
		long pz = this->cauta(ch);
		ART rez;
		if (pz != -1) { rez = Fisier<ART>::operator[](pz); exista = true; }
		else exista = false;
		return rez;
	}

	bool Exista_articol() { return exista; }
};

struct persoana
{
	int marca;
	char nume[20];
};

void main()
{
	Fisier_indexat<persoana, int> fi;
	fi.deschide("fis_persi.dat");
	persoana p1 = { 100, "Vasile" }, p2 = { 500, "Adam" }, p3 = { 300, "George" }, p4 = { 400, "Ionescu" }, p5;
	fi.scrie_art(p1, p1.marca); fi.scrie_art(p3, p3.marca);
	fi.scrie_art(p4, p4.marca); fi.scrie_art(p2, p2.marca);
	p5 = fi[400];
	if (fi.Exista_articol()) cout << p5.marca << "  " << p5.nume << endl;
	else cerr << "Nu exista articolul cu cheia cautata!!!";
}



