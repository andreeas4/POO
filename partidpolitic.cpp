#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // Pentru strncpy

using namespace std;

// Clasa de bază Persoana
class Persoana {
private:
    char cnp[14]; // CNP-ul persoanei, lungime fixa
    string nume;  // Numele persoanei

public:
    // Constructor cu parametri
    Persoana(const char fcnp[14], string fnume = "Anonim") : nume(fnume) {
        if (strlen(fcnp) <= 13) {
            strncpy(cnp, fcnp, 14); // Copiem CNP-ul
            cnp[14] = '\0';        // Asiguram terminarea sirului
        }
        else {
            strcpy(cnp, "N/A"); // CNP invalid
            cout << "CNP invalid!" << endl;
        }
    }

    // Constructor de copiere
    Persoana(const Persoana& other) : nume(other.nume) {
        strncpy(cnp, other.cnp, 10);
        cnp[10] = '\0';
    }

    // Accesori
    const char* getCnp() const { return cnp; }
    string getNume() const { return nume; }

    void setNume(string newName) { nume = newName; }

    // Metoda virtuala pentru afisare - baza polimorfismului
    virtual void afiseaza(ostream& os) const {
        os << "CNP: " << cnp << ", Nume: " << nume;
    }

    // Supraincarcare operator << (polimorfism dinamic prin metoda virtuala)
    friend ostream& operator<<(ostream& os, const Persoana& p) {
        p.afiseaza(os); // Apel polimorf la metoda afiseaza
        return os;
    }
};

// Clasa derivata PartidPolitic
class PartidPolitic : public Persoana {
private:
    float cotizatie; // Cotizatia platita de membrii partidului

public:
    // Constructor care apeleaza constructorul clasei de baza
    PartidPolitic(const char fcnp[14], string fnume, float fcotizatie)
        : Persoana(fcnp, fnume), cotizatie(fcotizatie) {}

    // Suprascrierea metodei virtuale pentru afisare
    void afiseaza(ostream& os) const override {
        // Apelam metoda afiseaza din clasa de baza
        Persoana::afiseaza(os);
        os << ", Cotizatie: " << cotizatie;
    }
};

int main() {
    // Obiect valid
    Persoana p3("1234567890123", "Ion Popescu");
    cout << p3 << endl;

    // Obiect cu CNP invalid
    Persoana p2("12345", "Invalid CNP");
    cout << p2 << endl;

    // Obiect de tip Persoana
    Persoana p1("123456789000", "Ion Popescu");

    // Obiect de tip PartidPolitic
    PartidPolitic pp("09876543210001", "Maria Ionescu", 250.5);

    // Demonstratie de polimorfism:
    cout << "Afisare obiect de tip Persoana:" << endl;
    cout << p1 << endl; // Apeleaza afiseaza() din Persoana

    cout << "Afisare obiect de tip PartidPolitic:" << endl;
    cout << pp << endl; // Apeleaza afiseaza() din PartidPolitic (polimorfism dinamic)

    return 0;
}

