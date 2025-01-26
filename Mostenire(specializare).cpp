#include <iostream>
#include <cmath> // pentru M_PI
using namespace std;

// Clasa de bază
class Forma {
public:
    virtual void afiseaza() const {
        cout << "Aceasta este o formă geometrică generică." << endl;
    }

    virtual double calculeazaAria() const = 0; // Metodă virtuală pură (abstractă)
};

// Clasa derivată pentru Cerc
class Cerc : public Forma {
private:
    double raza;

public:
    // Constructor
    Cerc(double r) : raza(r) {}

    // Specializarea metodei pentru Cerc
    void afiseaza() const override {
        cout << "Aceasta este un cerc cu raza " << raza << "." << endl;
    }

    // Calculul ariei pentru Cerc
    double calculeazaAria() const override {
        return M_PI * raza * raza;
    }
};

// Clasa derivată pentru Dreptunghi
class Dreptunghi : public Forma {
private:
    double lungime;
    double latime;

public:
    // Constructor
    Dreptunghi(double l, double L) : lungime(l), latime(L) {}

    // Specializarea metodei pentru Dreptunghi
    void afiseaza() const override {
        cout << "Aceasta este un dreptunghi cu lungimea " << lungime 
             << " și lățimea " << latime << "." << endl;
    }

    // Calculul ariei pentru Dreptunghi
    double calculeazaAria() const override {
        return lungime * latime;
    }
};

int main() {
    // Obiecte specializate
    Cerc cerc(5.0);               // Un cerc cu raza de 5
    Dreptunghi dreptunghi(4.0, 6.0); // Un dreptunghi cu dimensiunile 4 și 6

    // Folosirea polimorfismului pentru a lucra cu forme generice
    Forma* forma;

    forma = &cerc;
    forma->afiseaza();
    cout << "Aria: " << forma->calculeazaAria() << endl;

    forma = &dreptunghi;
    forma->afiseaza();
    cout << "Aria: " << forma->calculeazaAria() << endl;

    return 0;
}
