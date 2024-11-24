/*Constructorul alocă memorie dinamică pentru un întreg folosind new.
Destructorul este apelat automat când obiectul obj iese din domeniu (la sfârșitul funcției main()).
delete ptr; eliberează memoria alocată dinamic de new.
Destructorul ajută la prevenirea scurgerilor de memorie prin asigurarea că resursele sunt eliberate corect.*/




#include <iostream>
using namespace std;

class Exemplu {
private:
    int* ptr;  // Pointer care va ține adresa unui spațiu de memorie alocat dinamic

public:
    // Constructor
    Exemplu() {
        ptr = new int(10);  // Alocăm dinamic memorie pentru un întreg
        cout << "Constructorul a fost apelat! Memorie alocata." << endl;
    }

    // Destructor
    ~Exemplu() {
        delete ptr;  // Eliberăm memoria alocată dinamic
        cout << "Destructorul a fost apelat! Memorie eliberata." << endl;
    }
};

int main() {
    Exemplu obj;  // Constructorul este apelat când obiectul este creat
    // Destructorul este apelat automat când obiectul `obj` iese din domeniu (la finalul funcției main)
    return 0;
}



