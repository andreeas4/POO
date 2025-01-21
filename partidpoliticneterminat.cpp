#include <iostream>

using namespace std;

class Persoana {
private:
    char cnp[11];
    string nume;

public:
    // Constructor
    Persoana(const char fcnp[10], string fnume = "Anonim") : nume(fnume) {
        if (strlen(fcnp) == 10)
        {
            strncpy(cnp, fcnp, 10);
            cnp[10] = '\0';
        }
        else {
            strcpy(cnp, "N/0");
            cout << "Nu exista o persoana cu acest Cnp" << endl;
        }
    }
    Persoana(Persoana &other):nume(other.nume){
        if (strlen(other.cnp) == 10)
        {
            strncpy(cnp, other.cnp, 10);
            cnp[10] = '\0';
        }
        else {
            strcpy(cnp, "N/0");
            cout << "Nu exista o persoana cu acest Cnp" << endl;
        }
    }

    const char* getCnp(){   return cnp;  }
    string getNume() {  return nume;    }
    void setNume(string newName) {  nume = newName;}
    virtual void afiseaza(ostream &os) const {   os << "CNP: " << cnp << ", Nume: " << nume << endl; }
    friend ostream& operator <<(ostream& os, const Persoana& p) {
        p.afiseaza(os);//POLIMORFISM DINAMIC
        return os;
    }
};

class PartidPolitic :public Persoana {
private:
    float cotizatie;
public:
    PartidPolitic(char)
};


void main()
{
    Persoana p1("4034562089", "Mariana Popescu");

    cout << p1;


}

