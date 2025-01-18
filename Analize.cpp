//Să se scrie o aplicație orientată obiect pentru evidenta analizelor
//medicale gestionate de un laborator; este necesară cunoașterea
//numelui pacientului, a vârstei, a datei nașterii (stocată ca vector dinamic
//de numere) și a costului.

//Pentru domeniul dat, să se definească o clasă cu membri de tip public,
//private, protected, const, static, care să conțină:
//(1p) definirea corectă a clasei;
//(2p) constructor cu parametri, constructor fără parametri, constructor de
//copiere, destructor și operator<< pentru afișare (0.5
//puncte/funcție/operator) ;
//(2p) operator=, un operator matematic binar, operatorul cast și încă doi
//operatori adecvați domeniului (de comparare, aritmetici sau indexare sau
//de alt tip) (0.5 puncte/funcție/operator) ;
//(1p) două funcții de tip accesor (dintre care cel puțin o metodă set care
//să valideze datele de intrare) și două metode proprii clasei (0.25
//puncte/funcție/operator);
//(1p) funcții sau operatori pentru salvarea și restaurarea obiectelor în/din
//fișiere binare, permanente.
//(2p) Definiți încă o clasă, care este într-o relație de ti „is a” cu prima
//clasă (noua clasa adaugă cel puțin 2 atribute); exemplificați conceptul de
//supradefinirea + funcții virtuale si in main() definiți un vector dinamic care
//sa conțină adrese de obiecte de ambele tipuri (exemplificați avantajele
//virtualizării).
//(1p) Transformați una din clase într-o clasă template sau instanțiați o
//clasă template STL, pentru domeniul dat.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class AnalizaMedica {
private:
    string numePacient;
    int varsta;
    int* dataNasterii;
    float cost;

protected:
    static int nrAnalize;

public:
    // Constructori
    AnalizaMedica(string fnumePacient = "Necunoscut", int fvarsta = 0, int* fdataNasterii = nullptr, float fcost = 0.0f)
        : numePacient(fnumePacient), varsta(fvarsta), cost(fcost) {
        if (fdataNasterii != nullptr) {
            dataNasterii = new int[3];
            for (int i = 0; i < 3; i++)
                dataNasterii[i] = fdataNasterii[i];
        }
        else {
            dataNasterii = nullptr;
        }
        nrAnalize++;
    }

    AnalizaMedica(const AnalizaMedica& other)
        : numePacient(other.numePacient), varsta(other.varsta), cost(other.cost) {
        if (other.dataNasterii != nullptr) {
            dataNasterii = new int[3];
            for (int i = 0; i < 3; i++)
                dataNasterii[i] = other.dataNasterii[i];
        }
        else {
            dataNasterii = nullptr;
        }
    }

    ~AnalizaMedica() {
        if (dataNasterii != nullptr) {
            delete[] dataNasterii;
        }
    }

    // Metode accesor
    void setCost(float fcost) {
        if (fcost >= 0) {
            cost = fcost;
        }
        else {
            cout << "Cost invalid!" << endl;
        }
    }

    float getCost() const {
        return cost;
    }

    virtual void afiseazaData() const {
        if (dataNasterii != nullptr) {
            cout << "Data nasterii: " << dataNasterii[0] << "/" << dataNasterii[1] << "/" << dataNasterii[2] << endl;
        }
        else {
            cout << "Data nasterii nu este setata!" << endl;
        }
    }

    // Operator=
    AnalizaMedica& operator=(const AnalizaMedica& other) {
        if (this != &other) {
            numePacient = other.numePacient;
            varsta = other.varsta;
            cost = other.cost;

            if (dataNasterii != nullptr) {
                delete[] dataNasterii;
            }
            if (other.dataNasterii != nullptr) {
                dataNasterii = new int[3];
                for (int i = 0; i < 3; i++)
                    dataNasterii[i] = other.dataNasterii[i];
            }
            else {
                dataNasterii = nullptr;
            }
        }
        return *this;
    }

    // Operator <<
    friend ostream& operator<<(ostream& os, const AnalizaMedica& analiza) {
        os << "Nume pacient: " << analiza.numePacient << endl;
        os << "Varsta: " << analiza.varsta << endl;
        os << "Cost: " << analiza.cost << endl;
        if (analiza.dataNasterii != nullptr) {
            os << "Data nasterii: " << analiza.dataNasterii[0] << "/" << analiza.dataNasterii[1] << "/" << analiza.dataNasterii[2] << endl;
        }
        else {
            os << "Data nasterii nu este setata!" << endl;
        }
        return os;
    }

    // Funcții pentru fișiere binare
    void salvareInFisier(const string& numeFisier) const {
        ofstream fout(numeFisier, ios::binary | ios::app);
        if (!fout) {
            cout << "Eroare la deschiderea fisierului pentru scriere!" << endl;
            return;
        }
        size_t lungimeNume = numePacient.size();
        fout.write((char*)&lungimeNume, sizeof(lungimeNume));
        fout.write(numePacient.c_str(), lungimeNume);
        fout.write((char*)&varsta, sizeof(varsta));
        fout.write((char*)&cost, sizeof(cost));
        if (dataNasterii != nullptr) {
            fout.write((char*)dataNasterii, 3 * sizeof(int));
        }
        fout.close();
    }

    void restaurareDinFisier(const string& numeFisier) {
        ifstream fin(numeFisier, ios::binary);
        if (!fin) {
            cout << "Eroare la deschiderea fisierului pentru citire!" << endl;
            return;
        }
        size_t lungimeNume;
        fin.read((char*)&lungimeNume, sizeof(lungimeNume));
        char* buffer = new char[lungimeNume + 1];
        fin.read(buffer, lungimeNume);
        buffer[lungimeNume] = '\0';
        numePacient = buffer;
        delete[] buffer;
        fin.read((char*)&varsta, sizeof(varsta));
        fin.read((char*)&cost, sizeof(cost));
        if (dataNasterii == nullptr) {
            dataNasterii = new int[3];
        }
        fin.read((char*)dataNasterii, 3 * sizeof(int));
        fin.close();
    }
};

int AnalizaMedica::nrAnalize = 0;

class AnalizaDetaliata : public AnalizaMedica {
private:
    string doctorResponsabil;
    string departament;

public:
    AnalizaDetaliata(string fnumePacient = "Necunoscut", int fvarsta = 0, int* fdataNasterii = nullptr, float fcost = 0.0f,
        string fdoctorResponsabil = "Necunoscut", string fdepartament = "General")
        : AnalizaMedica(fnumePacient, fvarsta, fdataNasterii, fcost), doctorResponsabil(fdoctorResponsabil), departament(fdepartament) {}

    void afiseazaData() const override {
        AnalizaMedica::afiseazaData();
        cout << "Doctor responsabil: " << doctorResponsabil << endl;
        cout << "Departament: " << departament << endl;
    }
};

void main() {
    AnalizaMedica analiza1("Ion Popescu", 30, new int[3] {15, 7, 1993}, 200);
    AnalizaDetaliata analiza2("Maria Ionescu", 28, new int[3] {20, 4, 1995}, 300, "Dr. Vasile", "Cardiologie");

    vector<AnalizaMedica*> analize;
    analize.push_back(&analiza1);
    analize.push_back(&analiza2);

    for (auto analiza : analize) {
        analiza->afiseazaData();
        cout << endl;
    }
}










