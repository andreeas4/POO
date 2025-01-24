#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // pentru strlen și strcpy
using namespace std;

enum TipPreparat {
    NECUNOSCUT,
    VEGAN,
    VEGETARIAN,
    RAW_VEGAN,
    CARNIVOR
};

class Preparat {
private:
    const int cod;
    string denumire;
    int calorii;
    float cantitate;
    char* culoare;
    TipPreparat tip;

public:
    // Constructor implicit
    Preparat() : cod(0), denumire("Necunoscut"), calorii(0), cantitate(0.0f), tip(NECUNOSCUT) {
        culoare = new char[strlen("Necunoscuta") + 1];
        strcpy(culoare, "Necunoscuta");
    }

    // Constructor parametrizat
    Preparat(const int fcod, string fdenumire, int fcalorii, float fcantitate, const char* fculoare, TipPreparat ftip)
        : cod(fcod), denumire(fdenumire), calorii(fcalorii), cantitate(fcantitate), tip(ftip) {
        if (fculoare != nullptr) {
            culoare = new char[strlen(fculoare) + 1];
            strcpy(culoare, fculoare);
        }
        else {
            culoare = nullptr;
        }
    }

    // Constructor de copiere
    Preparat(const Preparat& other)
        : cod(other.cod), denumire(other.denumire), calorii(other.calorii), cantitate(other.cantitate), tip(other.tip) {
        if (other.culoare != nullptr) {
            culoare = new char[strlen(other.culoare) + 1];
            strcpy(culoare, other.culoare);
        }
        else {
            culoare = nullptr;
        }
    }

    Preparat& operator=(Preparat& other) {
        if (this != &other) {
            denumire = other.denumire;
            calorii = other.calorii;
            cantitate = other.cantitate;
            tip = other.tip;
            if (other.culoare != nullptr) {
                culoare = new char[strlen(other.culoare) + 1];
                strcpy(culoare, other.culoare);
            }
            else {
                culoare = nullptr;
            }
        }
        return *this;
    }

    // Metode getter
    int getCode() const { return cod; }
    string getDenumire() { return denumire; }
    int getCalorii() { return calorii; }
    char* getCuloare() { return culoare; }
    float getCantitate() { return cantitate; }

    string getTipPreparat() const {
        switch (tip) {
        case VEGAN: return "Vegan";
        case RAW_VEGAN: return "Raw-Vegan";
        case VEGETARIAN: return "Vegetarian";
        case CARNIVOR: return "Carnivor";
        default: return "Necunoscut";
        }
    }

    // Metode setter
    void setDenumire(string nume) { denumire = nume; }
    void setCalorii(int kcal) { calorii = kcal; }
    void setCantitate(float cant) { cantitate = cant; }
    void setCuloare(const char* cul) {
        if (culoare != nullptr) {
            delete[] culoare;
        }
        if (cul != nullptr) {
            culoare = new char[strlen(cul) + 1];
            strcpy(culoare, cul);
        }
        else {
            culoare = nullptr;
        }
    }

    // Supraincarcare operator++
    Preparat& operator++() {
        cantitate++;
        return *this;
    }

    // Supraincarcare operator<<
    friend ostream& operator<<(ostream& os, Preparat& p) {
        os << "Codul: " << p.cod << endl;
        os << "== " << p.denumire << " ==" << endl;
        os << "Tip preparat: " << p.getTipPreparat() << endl;
        os << "Numar calorii: " << p.calorii << endl;
        os << "Culoare: " << (p.culoare ? p.culoare : "Necunoscuta") << endl;
        os << "Cantitate: " << p.cantitate << endl;
        os << "===============================" << endl;
        os << endl;
        return os;
    }

    // Destructor
    ~Preparat() {
        if (culoare != nullptr) {
            delete[] culoare;
            culoare = nullptr;
        }
    }
};


class Meniu {
private:
    Preparat* preparate;
    int nrPreparate;

public:
    Meniu():preparate(nullptr),nrPreparate(0){}
    Meniu(Preparat* fpreparate,int fnrPreparate):nrPreparate(fnrPreparate) {
        if (fpreparate!=nullptr && fnrPreparate>0)
        {
            preparate = new Preparat[fnrPreparate + 1];
            for (int i = 0; i < fnrPreparate; i++)
                preparate[i] = fpreparate[i];
       }

    }
    ~Meniu() {
        if (preparate != nullptr) 
            delete[]preparate;


    }




};
void main() {
    Preparat p1;

    Preparat p2(223, "Ciolan", 1000, 10.2f, "Portocaliu", VEGAN);

    cout << p2;

    ++p2;

    cout << p2;
}
