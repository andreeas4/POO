#include <iostream>
using namespace std;

class Prăjitură {  // 1. Clasa este rețeta
private:
    // 2. Ingrediente: Zahăr, Ouă, Făină - Acestea sunt **private**, adică doar rețeta (clasa) știe despre ele.
    // Nu vrem ca oricine să poată modifica direct ingredientele, pentru că rețeta ar putea fi stricată.
    string ingredient1;  // Zahăr
    string ingredient2;  // Ouă
    string ingredient3;  // Făină

public:
    // 3. Constructorul este **public**, astfel încât oricine poate crea o prăjitură cu ingredientele dorite.
    // Constructorul este **public** pentru că vrem ca oricine care vrea să facă o prăjitură să poată să-i pună ingredientele.
    Prăjitură(string zahar, string oua, string faina) {
        ingredient1 = zahar;  // Ingredientele sunt setate aici, în constructor
        ingredient2 = oua;
        ingredient3 = faina;
    }

    // 4. Metodele `amestecaIngrediente`, `coace`, `afiseazaPrajitura` sunt **publice**, 
    // pentru că vrem ca oricine să poată apela aceste metode pentru a amesteca, coace sau afișa prăjitura.
    void amestecaIngrediente() {  // Public: Oricine poate apela această metodă pentru a amesteca ingredientele.
        cout << "Amestec ingredientele: " << ingredient1 << ", " << ingredient2 << ", " << ingredient3 << endl;
    }

    void coace() {  // Public: Oricine poate apela această metodă pentru a coace prăjitura.
        cout << "Coacere prajitura la cuptor..." << endl;
    }

    void afiseazaPrajitura() {  // Public: Oricine poate apela această metodă pentru a vedea rezultatul final.
        cout << "Prăjitura este gata! Ingrediente: " << ingredient1 << ", " << ingredient2 << ", " << ingredient3 << endl;
    }
};

int main() {
    // 5. Creăm o prăjitură cu ingredientele dorite. Acesta este un obiect **public** al clasei `Prăjitură`.
    Prăjitură prajitura1("zahar alb", "ouă", "făină");

    // 6. Apelăm metodele pentru a face prăjitura
    prajitura1.amestecaIngrediente();  // Metodă publică
    prajitura1.coace();  // Metodă publică
    prajitura1.afiseazaPrajitura();  // Metodă publică
//se pot modifica in main doar variabilele/datele din public
    return 0;
}
