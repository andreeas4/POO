//early
#include <iostream>
using namespace std;

class Animal {
public:
    void sunet() { // Funcție non-virtuală
        cout << "Animalul scoate un sunet generic." << endl;
    }
};

class Caine : public Animal {
public:
    void sunet() {
        cout << "Câinele latră." << endl;
    }
};

int main() {
    Animal a;
    a.sunet(); // Apelul este determinat în timpul compilării (early binding)
    return 0;
}
//late
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sunet() { // Funcție virtuală
        cout << "Animalul scoate un sunet generic." << endl;
    }
};

class Caine : public Animal {
public:
    void sunet() override { // Rescrierea funcției virtuale
        cout << "Câinele latră." << endl;
    }
};

int main() {
    Animal* animal = new Caine(); // Tipul static este Animal, dar tipul dinamic este Caine
    animal->sunet(); // Apelul este rezolvat la runtime (late binding)
    delete animal;
    return 0;
}
