/*
O instanță este o copie a unei clase care este creată și folosită în timpul executării unui program. 
Când creezi un obiect dintr-o clasă, acel obiect este numit o instanță a clasei respective.

Gândește-te la o clasă ca la un plan sau un tipar și la instanță ca la un obiect real creat pe baza acestui plan.*/


#include <iostream>
using namespace std;

class Club {
private:
    static Club* instanta;  // Membrii clubului (instanța unică)
    string numeClub;

    // Constructor privat pentru a preveni instanțierea clubului de mai multe ori
    Club(string nume) {
        numeClub = nume;
        cout << "Clubul '" << numeClub << "' este deschis!" << endl;
    }

public:
    // Metoda statică pentru a obține instanța unică a clubului
    static Club* getInstanta() {
        if (instanta == nullptr) {
            // Dacă clubul nu a fost încă creat, creăm instanța
            instanta = new Club("Clubul Exclusiv");
        }
        return instanta;  // Returnăm aceleași instanță la fiecare apel
    }

    // Metodă pentru a arăta informații despre club
    void afiseazaInfo() {
        cout << "Numele Clubului: " << numeClub << endl;
    }
};

// Inițializarea instanței statice
Club* Club::instanta = nullptr; //operatorul :: este denumit operator de rezoluție a domeniului (scope resolution operator) și este folosit pentru a face referire la elemente (variabile, funcții, clase, etc.) care sunt definite într-un anumit domeniu sau scop.
/*in contextul unui Singleton, operatorul :: este folosit pentru a accesa metoda statică care returnează instanța unică a clasei.
În această abordare, clasa Singleton garantează că există o singură instanță a acelei clase, iar accesul la aceasta se face printr-o metodă statică.*/


int main() {
    // Primul membru al clubului
    Club* club1 = Club::getInstanta();  // Aici se creează instanța clubului
    club1->afiseazaInfo();  // Afișează: Clubul Exclusiv

    // Încercăm să accesăm încă o dată clubul
    Club* club2 = Club::getInstanta();  // Va returna aceleași instanță
    club2->afiseazaInfo();  // Afișează din nou: Clubul Exclusiv

    // Verificăm dacă cele două obiecte sunt același club
    if (club1 == club2) {
        cout << "Ambele obiecte sunt același club!" << endl;  // Va afișa: Ambele obiecte sunt același club!
    }

    return 0;
}
/*

#include <iostream>
using namespace std;

class Club {
private:
    bool esteMembru;  // Variabilă booleană care arată dacă un membru este prezent sau nu

public:
    // Constructorul clasei, care setează inițial că nu sunt membri
    Club() {
        esteMembru = false;  // Inițial, nu avem membri
        cout << "Clubul a fost creat si nu are membri." << endl;
    }

    // Metoda pentru a adăuga un membru în club
    void adaugaMembru() {
        esteMembru = true;  // Membrii devin prezenți în club
        cout << "Un membru a fost adaugat in club!" << endl;
    }

    // Metoda pentru a arăta dacă există membri în club
    void verificaMembru() {
        if (esteMembru) {
            cout << "Un membru este prezent in club!" << endl;
        } else {
            cout << "Nu este niciun membru in club." << endl;
        }
    }
};

int main() {
    Club club1;  // Creăm un obiect de tip Club

    // Verificăm dacă avem membri în club înainte de a adăuga
    club1.verificaMembru();  // Afișează: Nu este niciun membru in club.

    // Adăugăm un membru
    club1.adaugaMembru();

    // Verificăm din nou
    club1.verificaMembru();  // Afișează: Un membru este prezent in club!

    return 0;
}



*/
