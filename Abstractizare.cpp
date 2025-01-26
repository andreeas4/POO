#include <iostream>
using namespace std;

class FormaGeometrica {
public:
    virtual void desen() = 0; // Metodă pur virtuală
    virtual float arie() = 0; // Metodă pur virtuală
    virtual ~FormaGeometrica() {} // Destructor virtual pentru siguranță
};

class Cerc : public FormaGeometrica {
private:
    float raza;
public:
    Cerc(float raza) : raza(raza) {}
    void desen() override {
        cout << "Se desenează un cerc.\n";
    }
    float arie() override {
        return 3.14 * raza * raza;
    }
};

class Dreptunghi : public FormaGeometrica {
private:
    float lungime, latime;
public:
    Dreptunghi(float lungime, float latime) : lungime(lungime), latime(latime) {}
    void desen() override {
        cout << "Se desenează un dreptunghi.\n";
    }
    float arie() override {
        return lungime * latime;
    }
};

int main() {
    FormaGeometrica* forma = new Cerc(5.0);
    forma->desen();
    cout << "Arie: " << forma->arie() << endl;
    delete forma;

    forma = new Dreptunghi(4.0, 3.0);
    forma->desen();
    cout << "Arie: " << forma->arie() << endl;
    delete forma;

    return 0;
}
