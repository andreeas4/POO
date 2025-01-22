#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector> // Pentru vector

using namespace std;

// Clasa de bază Persoana
class Persoana {
protected:
    char cnp[14]; // CNP-ul persoanei (lungime fixă de 13 caractere + '\0')
    string nume;  // Numele persoanei

public:
    // Constructor cu parametri
    Persoana(const char fcnp[14], string fnume = "Anonim") : nume(fnume) {
        if (strlen(fcnp) == 13) {
            strncpy(cnp, fcnp, 13);
            cnp[13] = '\0'; // Terminatorul '\0'
        } else {
            strcpy(cnp, "N/A");
            cout << "CNP invalid!" << endl;
        }
    }

    // Accesori
    const char* getCnp() const { return cnp; }
    string getNume() const { return nume; }

    virtual void afiseaza(ostream& os) const {
        os << "CNP: " << cnp << ", Nume: " << nume;
    }

    friend ostream& operator<<(ostream& os, const Persoana& p) {
        p.afiseaza(os); // Polimorfism
        return os;
    }
};

//-----------------------------------------------------------------------------------------------------------------------

// Clasa derivată PartidPolitic
class PartidPolitic : public Persoana {
protected:
    static float cotizatie; // Cotizatia comună pentru toți membrii partidului

public:
    // Constructor
    PartidPolitic(const char fcnp[14], string fnume)
        : Persoana(fcnp, fnume) {}

    static void setCotizatie(float newCotizatie) {
        cotizatie = newCotizatie;
    }

    static float getCotizatie() {
        return cotizatie;
    }

    void afiseaza(ostream& os) const override {
        Persoana::afiseaza(os);
        os << ", Cotizatie: " << cotizatie;
    }
};

//------------------------------------------------------------------------------------------------------------------------

// Inițializarea atributului static
float PartidPolitic::cotizatie = 0;

//------------------------------------------------------------------------------------------------------------------------

// Clasa derivată Asociatie
class Asociatie : public PartidPolitic {
private:
    vector<Persoana> membri; // Vector de persoane (membri)

public:
    // Constructor pentru Asociatie
    Asociatie(const char fcnp[14], string fnume)
        : PartidPolitic(fcnp, fnume) {}

    // Adaugă un membru în asociație
    void adaugaMembru(const Persoana& p) {
        membri.push_back(p);
    }

    // Afișează toți membrii asociației
    void afiseazaMembri() const {
        cout << "Membrii asociației:" << endl;
        for (const auto& membru : membri) {
            cout << membru << endl;
        }
    }

    void afiseaza(ostream& os) const override {
        PartidPolitic::afiseaza(os);
        os << " (Asociatie)" << endl;
    }
};

int main() {
    // Setăm cotizația
    PartidPolitic::setCotizatie(250.0);

    // Creăm o asociație
    Asociatie asociatie("1234567890123", "Asociatia Prieteniei");

    // Adăugăm membri în asociație
    Persoana p1("2345678901234", "Ion Popescu");
    Persoana p2("3456789012345", "Maria Ionescu");
    Persoana p3("4567890123456", "Vasile Dumitru");

    asociatie.adaugaMembru(p1);
    asociatie.adaugaMembru(p2);
    asociatie.adaugaMembru(p3);

    // Afișăm asociația
    cout << asociatie << endl;
    asociatie.afiseazaMembri();

    return 0;
}
