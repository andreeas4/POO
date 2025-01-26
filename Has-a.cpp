#include <iostream>
#include <string>
using namespace std;

// Clasa Motor
class Motor {
private:
    int putere; // Puterea motorului în cai-putere (CP)
    string tipCombustibil;

public:
    // Constructor
    Motor(int p, string combustibil) : putere(p), tipCombustibil(combustibil) {}

    // Metodă pentru afișare
    void afiseazaDetalii() const {
        cout << "Motor: " << putere << " CP, combustibil: " << tipCombustibil << endl;
    }
};

// Clasa Masina (care "are" un Motor)
class Masina {
private:
    string marca;
    string model;
    Motor motor; // Relația "Has-A": Masina conține un Motor

public:
    // Constructor
    Masina(string m, string mod, Motor mot) : marca(m), model(mod), motor(mot) {}

    // Metodă pentru afișare
    void afiseazaDetalii() const {
        cout << "Masina: " << marca << " " << model << endl;
        motor.afiseazaDetalii(); // Apelăm metoda din clasa Motor
    }
};

int main() {
    // Cream un motor
    Motor motorBMW(300, "Benzină");

    // Cream o mașină care conține acel motor
    Masina masinaBMW("BMW", "M3", motorBMW);

    // Afișăm detaliile mașinii și motorului
    masinaBMW.afiseazaDetalii();

    return 0;
}
