#include <iostream>
using namespace std;

class Masina {
public:
    string marca;
    string culoare;
    int anFabricatie;

    // Constructor cu parametri (valoare implicita pentru obiectele create cu parametri)
//din ce e format obiectul
    Masina(string m, string c, int an) {
        marca = m;
        culoare = c;
        anFabricatie = an;
    }

    // Constructor implicit (fără parametri)
    Masina() {
        marca = "Neidentificata";
        culoare = "default";
        anFabricatie = 0;
    }

    // Metoda pentru a arăta informațiile despre mașină
    void afiseazaMasina() {
        cout << "Marca: " << marca << ", Culoare: " << culoare << ", An Fabricatie: " << anFabricatie << endl;
    }
};

int main() {
    // Creăm un obiect al clasei Masina folosind constructorul implicit
    Masina masina1;  // Aici se va folosi constructorul implicit

    // Afișăm setările implicite
    masina1.afiseazaMasina();  // Afișează: Neidentificata, default, 0

    return 0;
}
