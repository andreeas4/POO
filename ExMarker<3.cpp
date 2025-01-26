#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
class Marker {
public:
	virtual void scrie() = 0;

};
class MarkerElectronic:public Marker
{
private:
	const int cod;
	char* culoare;
	float dim;
	float cost;
	string prod;

public:
	MarkerElectronic() :cod(0),dim(0.0f), cost(0.0f), prod("Necunoscut"){
		culoare = new char[strlen("Necunoscuta") + 1];
		strcpy(culoare, "Necunoscuta");

	}
	MarkerElectronic(const int fcod,const char*fculoare,float fdim,float fcost,const string fprod)
		:cod(fcod),dim(fdim),cost(fcost),prod(fprod)
			{

			if (fculoare != nullptr)
				{
				culoare = new char[strlen(fculoare) + 1];
				strcpy(culoare, fculoare);
				}
			else {
				culoare = new char[strlen("Necunoscuta") + 1];
				strcpy(culoare, "Necunoscuta");
			}

			}
	MarkerElectronic(MarkerElectronic const &other) :cod(other.cod), dim(other.dim), cost(other.cost), prod(other.prod)
	{

		if (other.culoare != nullptr)
		{
			culoare = new char[strlen(other.culoare) + 1];
			strcpy(culoare, other.culoare);
		}
		else
		{
			culoare = new char[strlen("Necunoscuta") + 1];
			strcpy(culoare, "Necunoscuta");

		}

	}
	int getCod() const{ return cod; }
	char* getCuloare() { return culoare; }
	float getDim() { return dim; }
	float getCost() { return cost; }
	string getProd() { return prod; }

	void setCuloare(char*noua) {
		if (culoare)delete[]culoare;
		if (noua) {
			culoare = new char[strlen(noua) + 1];
			strcpy(culoare, noua);
		}
		else culoare = nullptr;

	}
	void setDim(float d) { dim = d; }
	void setCost(float c) { cost = c; }
	void setProd(string p) { prod = p; }
	//metoda virtuala
	void scrie()override {
		cout << "Pe tabla este scris cu culoarea : " << culoare<<endl;
	}

	MarkerElectronic operator=(MarkerElectronic& other) {
		if (this != &other) {

			culoare = other.culoare;
			dim = other.dim;
			cost = other.cost;
			prod = other.prod;
			if (other.culoare != nullptr)
			{
				delete[]culoare;
				culoare = new char[strlen(other.culoare) + 1];
				strcpy(culoare, other.culoare);
			}
			else
			{

				culoare = new char[strlen("Necunoscuta") + 1];
				strcpy(culoare, "Necunoscuta");

			}
		}
	}
	friend ostream& operator<<(ostream& os, const MarkerElectronic &m) {
		os << endl;
		os << "-" << m.cod << "-" << endl;
		os << "Culoare: " << m.culoare << endl;
		os << "Dimensiune: " << m.dim << endl;
		os << "Cost: " << m.cost << " lei" << endl;
		os << "Producator: " << m.prod << endl;
		

		return os;
	}
	friend istream& operator>>(istream &is, MarkerElectronic &m) {

		char buffer[100];
		cout << "Introdu date:" << endl;
		cout << "Culoare marker: ";
		is >> ws;
		is.getline(buffer, 100);
		if (m.culoare) {
			delete[] m.culoare; // Eliberează memoria veche
		}
		m.culoare = new char[strlen(buffer) + 1];
		strcpy(m.culoare, buffer);

		//is >> m.culoare;
		cout << endl;
		cout << "Dimensiune: ";
		is >> m.dim;
		cout << endl;
		cout << "Cost: ";
		is>> m.cost;
		cout << endl;
		cout << "Producator: ";
		is >> m.prod;

		return is;
	}
	friend bool operator==(MarkerElectronic& m1, MarkerElectronic& m2) {
		if (m1.cost == m2.cost && m2.prod == m1.prod)return true;
		else return false;

	}
	~MarkerElectronic() {
		if (culoare)delete[]culoare;
	}

};
class MarkerInteligent :public MarkerElectronic {
private:
	float grosime;
	string tipLinie;
	int nivpresiune;
public:
	MarkerInteligent():MarkerElectronic(),grosime(0.0f),tipLinie("Normala"),nivpresiune(0){}
	MarkerInteligent(const MarkerElectronic &baza,float fgrosime,const string ftipLinie,int fnivPresiune):
	MarkerElectronic(baza),grosime(fgrosime),tipLinie(ftipLinie),nivpresiune(fnivPresiune){}
	friend ostream& operator<<(ostream& os, const MarkerInteligent &m) {
		os << endl;
		os << "~Marker inteligent~"<<endl;
		os << (const MarkerElectronic&)m;
		os << "Grosime linie : " << m.grosime << endl;
		os << "Tip linie: " << m.tipLinie << endl;
		os << "Nivel presiune: " << m.nivpresiune << endl;
		

		return os;
	}
};
void main()
{
	MarkerElectronic m1;
	MarkerElectronic m2(2, "Galben", 3.3f, 12.5f, "Altex");
	MarkerElectronic m3(m2);
	MarkerElectronic m4(5, "Rosu", 7.6f, 40.99f, "Bic");
	MarkerElectronic m5(6, "Albastru", 9.10f, 40.99f, "Bic");
	cout << m1;
	cout << m2;
	cout << m3;
	//MarkerElectronic m4;
	//cin >> m4;
	//cout << m4;
	MarkerInteligent mi1(m2, 1.1f, "Stilou", 2);
	cout << mi1;
	cout << m4 << m5;
	cout << endl;
	cout << "TESTARE OPERATOR ==" << endl;
	if (m4 == m5)cout << "Markerul cu codul:" << m4.getCod() << " este facut de acelasi producator si are acelasi pret ca si Markerul cu codul : " << m5.getCod()<<endl;
	else cout<< "Markerul cu codul:" << m4.getCod()<<" nu este similar cu Markerul cu codul : " << m5.getCod() << endl; 
	cout << endl;
	cout << "Testare metoda virtuala: " << endl;
	m4.scrie();

	//mapare 



}
