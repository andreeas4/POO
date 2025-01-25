#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
using namespace std;

class JocuriVideo {
private:
    const int cod;
    char* titlu;
    string consolaComp;
    string categorie;
    float pret;
    int lunaInchiriere; // Luna in care a fost inchiriat jocul

public:
    JocuriVideo() : cod(0), consolaComp("Necunoscuta"), pret(0.0f), categorie("Necunoscuta"), lunaInchiriere(0) {
        titlu = new char[strlen("Necunoscut") + 1];
        strcpy(titlu, "Necunoscut");
    }

    JocuriVideo(const int fcod, const char* ftitlu, string fconsolaComp, float fpret, string fcategorie, int flunaInchiriere = 0)
        : cod(fcod), consolaComp(fconsolaComp), pret(fpret), categorie(fcategorie), lunaInchiriere(flunaInchiriere) {
        if (ftitlu) {
            titlu = new char[strlen(ftitlu) + 1];
            strcpy(titlu, ftitlu);
        }
        else {
            titlu = new char[strlen("Necunoscut") + 1];
            strcpy(titlu, "Necunoscut");
        }
    }

    JocuriVideo(const JocuriVideo& other) : cod(other.cod), consolaComp(other.consolaComp), pret(other.pret), categorie(other.categorie), lunaInchiriere(other.lunaInchiriere) {
        titlu = new char[strlen(other.titlu) + 1];
        strcpy(titlu, other.titlu);
    }

    JocuriVideo& operator=(const JocuriVideo& other) {
        if (this != &other) {
            consolaComp = other.consolaComp;
            pret = other.pret;
            categorie = other.categorie;
            lunaInchiriere = other.lunaInchiriere;

            if (titlu) delete[] titlu;
            titlu = new char[strlen(other.titlu) + 1];
            strcpy(titlu, other.titlu);
        }
        return *this;
    }

    int getCod() const { return cod; }
    char* getTitlu() const { return titlu; }
    string getConsolaComp() const { return consolaComp; }
    float getPret() const { return pret; }
    string getCategorie() const { return categorie; }
    int getLunaInchiriere() const { return lunaInchiriere; }

    void setTitlu(const char* nume) {
        if (titlu) delete[] titlu;
        titlu = new char[strlen(nume) + 1];
        strcpy(titlu, nume);
    }

    friend ostream& operator<<(ostream& os, const JocuriVideo& j) {
        os << "Cod: " << j.cod << endl;
        os << "Titlu: " << j.titlu << endl;
        os << "Consola compatibila: " << j.consolaComp << endl;
        os << "Pret: " << j.pret << " RON" << endl;
        os << "Categorie: " << j.categorie << endl;
        os << "Luna inchiriere: " << j.lunaInchiriere << endl;
        return os;
    }

    ~JocuriVideo() {
        if (titlu) delete[] titlu;
    }
};

class BibliotecaJocuriVideo {
private:
    JocuriVideo* jocuriVideo;
    int nrJocuri;
    map<string, float> incasariLunareMap; // Map pentru încasări lunare

public:
    BibliotecaJocuriVideo(int fnrJocuri, JocuriVideo* fjocuriVideo) : nrJocuri(fnrJocuri) {
        if (fjocuriVideo && fnrJocuri > 0) {
            jocuriVideo = new JocuriVideo[fnrJocuri];
            for (int i = 0; i < fnrJocuri; i++) {
                jocuriVideo[i] = fjocuriVideo[i];
            }
        }
        else {
            jocuriVideo = nullptr;
            nrJocuri = 0;
        }
    }

    BibliotecaJocuriVideo() : nrJocuri(0), jocuriVideo(nullptr) {}

    BibliotecaJocuriVideo(const BibliotecaJocuriVideo& other) : nrJocuri(other.nrJocuri) {
        if (other.jocuriVideo && nrJocuri > 0) {
            jocuriVideo = new JocuriVideo[nrJocuri];
            for (int i = 0; i < nrJocuri; i++) {
                jocuriVideo[i] = other.jocuriVideo[i];
            }
        }
        else {
            jocuriVideo = nullptr;
        }
    }

    BibliotecaJocuriVideo& operator=(const BibliotecaJocuriVideo& other) {
        if (this != &other) {
            if (jocuriVideo) delete[] jocuriVideo;
            nrJocuri = other.nrJocuri;
            if (other.jocuriVideo && nrJocuri > 0) {
                jocuriVideo = new JocuriVideo[nrJocuri];
                for (int i = 0; i < nrJocuri; i++) {
                    jocuriVideo[i] = other.jocuriVideo[i];
                }
            }
            else {
                jocuriVideo = nullptr;
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const BibliotecaJocuriVideo& b) {
        os << "Numar de jocuri in biblioteca: " << b.nrJocuri << endl;
        for (int i = 0; i < b.nrJocuri; i++) {
            os << b.jocuriVideo[i] << endl;
        }
        return os;
    }
    std::vector<JocuriVideo> getJocuriPeCategorie(const string& categorie) const {
        std::vector<JocuriVideo> rezultate;
        for (int i = 0; i < nrJocuri; i++) {
            if (jocuriVideo[i].getCategorie() == categorie) {
                rezultate.push_back(jocuriVideo[i]);
            }
        }
        return rezultate;
    }
    BibliotecaJocuriVideo& operator+=(const JocuriVideo& joc) {
        incasariLunareMap["ianuarie"] += joc.getPret(); // Simulare adăugare încasare
        return *this;
    }

    BibliotecaJocuriVideo& operator-=(const JocuriVideo& joc) {
        incasariLunareMap["ianuarie"] -= joc.getPret(); // Simulare scădere încasare
        return *this;
    }

    float incasariLunare(const string& luna) const {
        auto it = incasariLunareMap.find(luna);
        if (it != incasariLunareMap.end()) {
            return it->second;
        }
        return 0.0f;
    }

    ~BibliotecaJocuriVideo() {
        if (jocuriVideo) delete[] jocuriVideo;
    }
};

class JocEducativ : public JocuriVideo {
private:
    int varstaMinima;
    string subiect;

public:
    JocEducativ() : JocuriVideo(), varstaMinima(0), subiect("Necunoscut") {}

    JocEducativ(const int fcod, const char* ftitlu, string fconsolaComp, float fpret, string fcategorie, int fvarstaMinima, string fsubiect)
        : JocuriVideo(fcod, ftitlu, fconsolaComp, fpret, fcategorie), varstaMinima(fvarstaMinima), subiect(fsubiect) {}

    friend ostream& operator<<(ostream& os, const JocEducativ& je) {
        os << (JocuriVideo&)je;
        os << "Varsta minima recomandata: " << je.varstaMinima << endl;
        os << "Subiect educativ: " << je.subiect << endl;
        return os;
    }

    int getVarstaMinima() const { return varstaMinima; }
};

int main() {
    JocuriVideo j1(1, "Super Mario", "Nintendo Switch", 199.99f, "Platformer");
    JocuriVideo j2(2, "FIFA 23", "PlayStation 5", 299.99f, "Sports");
    JocuriVideo j3(3, "FIFA 24", "PlayStation 5", 399.99f, "Sports");
    JocuriVideo jocuri[] = { j1, j2, j3 };

    BibliotecaJocuriVideo biblioteca(3, jocuri);

    cout << biblioteca;

    string categorie = "Sports";
    std::vector<JocuriVideo> rezultate = biblioteca(categorie);

    cout << "Jocuri din categoria \"" << categorie << "\":\n";
    for (const auto& joc : rezultate) {
        cout << joc;
    }

    // Testare operatori += și -= pentru închiriere/returnare
    biblioteca += j1;
    biblioteca -= j3;

    cout << "\nBiblioteca după închiriere și returnare:\n";
    cout << biblioteca;

    // Determinarea valorii totale a încasărilor din luna ianuarie
    cout << "\nValoarea totală a încasărilor din ianuarie: " << biblioteca.incasariLunare("ianuarie") << " RON\n";

    // Exemplificarea conceptului de virtualizare
    JocEducativ je1(4, "Learn Math", "PC", 99.99f, "Educational", 8, "Matematică");
    cout << "\nJoc educativ:\n" << je1;

    // Container STL pentru identificarea rapidă a jocurilor după vârsta minimă
    map<int, JocEducativ> jocuriEducative;
    jocuriEducative[je1.getVarstaMinima()] = je1;

    int varstaCautata = 8;
    if (jocuriEducative.find(varstaCautata) != jocuriEducative.end()) {
        cout << "\nJocuri recomandate pentru vârsta de " << varstaCautata << " ani:\n";
        cout << jocuriEducative[varstaCautata];
    }
    else {
        cout << "\nNu există jocuri recomandate pentru vârsta de " << varstaCautata << " ani.\n";
    }

    return 0;
}

