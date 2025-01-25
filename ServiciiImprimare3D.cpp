#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

enum class TipMaterial {
	LEMN,
	PLASTIC,
	SILICON,
	NECUNOSCUT

};

class ServiciiImprimare3D
{
private:
	const int cod;
	TipMaterial *tip;
	int nrExemplare;
	float* dimensiuni;

public:

	ServiciiImprimare3D(const int fcod, TipMaterial* ftip, int fnrExemplare, float* fdimensiuni) :cod(fcod), nrExemplare(fnrExemplare)
	{
		if (ftip != nullptr && fnrExemplare > 0)
		{
			tip = new TipMaterial[fnrExemplare+1];
			for (int i = 0; i < fnrExemplare; i++)
				tip[i] = ftip[i];
		}
		else tip = nullptr;
		if (fdimensiuni != nullptr && fnrExemplare > 0)
		{
			dimensiuni = new float[fnrExemplare + 1];
			for (int i = 0; i < fnrExemplare; i++)
				dimensiuni[i] = fdimensiuni[i];

		}
		else dimensiuni = nullptr;
	}
	ServiciiImprimare3D():cod(0),nrExemplare(0),tip(nullptr),dimensiuni(nullptr){}

	~ServiciiImprimare3D() {
		if (tip)delete[]tip;
		if (dimensiuni)delete[] dimensiuni;

	}
	int getCod()const { return cod; }
	int getNrExemplare() { return nrExemplare; }
	string getTipuriMateriale() const {
		string rezultat;
		for (int i = 0; i < nrExemplare; i++) {
			switch (tip[i]) {
			case TipMaterial::LEMN: rezultat += "Lemn "; break;
			case TipMaterial::PLASTIC: rezultat += "Plastic "; break;
			case TipMaterial::SILICON: rezultat += "Silicon "; break;
			case TipMaterial::NECUNOSCUT: rezultat += "Necunoscut "; break;
			}
		}
		return rezultat;
	}
	float* getDimensiuni() { return dimensiuni; }
	friend ostream& operator<<(ostream& os, ServiciiImprimare3D& s)
	{
		os << "Codul serviciului: " << s.cod<<endl;
		os << "Nr exemplare: " << s.nrExemplare << endl;
		os << "Tipul de materiale:" << s.getTipuriMateriale() << endl;
		os << "Dimensiuni: ";
		for (int i = 0; i < s.nrExemplare; i++)
			os << s.dimensiuni[i] << " ";
		os << endl;
		return os;

	}
	friend bool operator<(ServiciiImprimare3D &s1, ServiciiImprimare3D &s2) {
		if (s1.nrExemplare < s2.nrExemplare)return true;
		else return false;

	}
	ServiciiImprimare3D operator +=(ServiciiImprimare3D s1) {
		
			
	}

};
void main()
{
	TipMaterial materiale[] = { TipMaterial::LEMN, TipMaterial::PLASTIC };
	float dim[] = { 5.0f, 10.0f };

	ServiciiImprimare3D serviciu1(1, materiale, 2, dim);
	cout << "Tipuri de materiale: " << serviciu1.getTipuriMateriale() << endl;
	ServiciiImprimare3D serviciu2;
	if (serviciu1 < serviciu2)cout << "Sunt mai putine exemplare oferite de serviciul 1" << endl;
	else cout<< "Sunt mai putine exemplare oferite de serviciul 2" << endl;
	cout << serviciu1;
}

