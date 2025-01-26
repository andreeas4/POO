#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Declararea unui map care leagă un nume de elev de nota acestuia
    map<string, float> catalog;

    // Adăugarea elementelor
    catalog["Andrei"] = 9.5;
    catalog["Maria"] = 8.7;
    catalog["Ioana"] = 10.0;
    catalog["Vlad"] = 7.8;

    // Iterare folosind un iterator
    cout << "Catalogul școlar (folosind iterator):" << endl;
    map<string, float>::iterator it;
    for (it = catalog.begin(); it != catalog.end(); ++it) {
        cout << "Elev: " << it->first << ", Nota: " << it->second << endl;
    }

    // Ștergerea unui element folosind iterator
    it = catalog.find("Ioana");
    if (it != catalog.end()) {
        catalog.erase(it); // Șterge elementul cu cheia "Ioana"
        cout << "\nIoana a fost eliminată din catalog." << endl;
    }

    // Reafisarea catalogului după ștergere
    cout << "\nCatalogul actualizat:" << endl;
    for (it = catalog.begin(); it != catalog.end(); ++it) {
        cout << "Elev: " << it->first << ", Nota: " << it->second << endl;
    }

    return 0;
}
