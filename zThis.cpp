/*Imaginează că fiecare obiect al clasei este o persoană, iar pointerul this este o oglindă.
Când persoana se uită în oglindă, ea vede doar pe sine (obiectul curent). Dacă două persoane diferite (obiecte) se uită în oglinzi separate (metode), 
fiecare vede doar propria reflecție.

Astfel, this ajută obiectul curent să știe că lucrează cu propriile date și nu cu ale altora!

*/

class Masina {
public:
    void compara(Masina& altaMasina) {
        if (this == &altaMasina) {
            cout << "Este același obiect." << endl;
        } else {
            cout << "Sunt obiecte diferite." << endl;
        }
    }
};

int main() {
    Masina masina1, masina2;
    masina1.compara(masina1);  // Output: Este același obiect.
    masina1.compara(masina2);  // Output: Sunt obiecte diferite.
    return 0;
}








