#include <iostream>
#include <string>
using namespace std;

// Enum pentru tipurile de frizerii
enum class TipFrizerie {
    Standard,
    Barbershop,
    Salon
};

class Frizerie {
private:
    string denumire;   // Denumirea frizeriei
    int nrFrizeri;     // Numărul de frizeri
    TipFrizerie tipFrizerie; // Tipul frizeriei

    static int lungimeMinimaDenumire; // Lungimea minimă permisă pentru denumire

public:
    // Constructor
    Frizerie(string fdenumire = "Necunoscuta", TipFrizerie ftipFrizerie = TipFrizerie::Standard, int fnrFrizeri = 0)
        : tipFrizerie(ftipFrizerie), nrFrizeri(fnrFrizeri) {
        if (fdenumire.length() >= lungimeMinimaDenumire) {
            denumire = fdenumire;
        }
        else {
            denumire = "Invalid";
            cout << "Denumirea este prea scurtă. Setată automat la 'Invalid'.\n";
        }
    }

    // Metodă statică pentru setarea lungimii minime a denumirii
    static void setLungimeMinDenumire(int lungime) {
        if (lungime > 0) {
            lungimeMinimaDenumire = lungime;
        }
        else {
            cout << "Lungimea minimă trebuie să fie pozitivă.\n";
        }
    }

    // Metodă statică pentru a obține lungimea minimă a denumirii
    static int getLungimeMinDenumire() {
        return lungimeMinimaDenumire;
    }

    // Metodă pentru afișarea detaliilor despre frizerie
    void afiseazaDetalii() const {
        cout << "Denumire: " << denumire << endl;
        cout << "Număr frizeri: " << nrFrizeri << endl;
        cout << "Tip frizerie: " << getTipFrizerieString() << endl;
    }

private:
    // Metodă privată pentru a converti enum-ul în string
    string getTipFrizerieString() const {
        switch (tipFrizerie) {
        case TipFrizerie::Standard: return "Standard";
        case TipFrizerie::Barbershop: return "Barbershop";
        case TipFrizerie::Salon: return "Salon";
        default: return "Necunoscut";
        }
    }
};

// Inițializarea membrului static
int Frizerie::lungimeMinimaDenumire = 5; // Lungimea minimă implicită este 5

int main() {
    // Setăm lungimea minimă a denumirii
    Frizerie::setLungimeMinDenumire(3);

    // Afișăm lungimea minimă a denumirii
    cout << "Lungimea minimă a denumirii este: " << Frizerie::getLungimeMinDenumire() << endl;

    // Creăm o frizerie cu o denumire validă
    Frizerie f1("La Mihai", TipFrizerie::Barbershop, 3);
    f1.afiseazaDetalii();

    // Creăm o frizerie cu o denumire prea scurtă
    Frizerie f2("Hi", TipFrizerie::Salon, 5);
    f2.afiseazaDetalii();

    return 0;
}
