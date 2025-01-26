#include <iostream>
using namespace std;

class Animal {
public:
    virtual void vorbeste() {
        cout << "Animalul face un sunet.\n";
    }
};

class Caine : public Animal {
public:
    void vorbeste() override {
        cout << "Cainele latră: Ham Ham!\n";
    }
};

class Pisica : public Animal {
public:
    void vorbeste() override {
        cout << "Pisica miaună: Miau Miau!\n";
    }
};

int main() {
    Animal* animal = new Caine();
    animal->vorbeste(); // Apelează "Caine::vorbeste()" datorită virtualizării

    animal = new Pisica();
    animal->vorbeste(); // Apelează "Pisica::vorbeste()" datorită virtualizării

    delete animal;
    return 0;
}
