


#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
void functie(int p)
{

	p = 4;

}


void main()
{
	int var = 7;
	cout << var << " ";
	functie(var);
	cout << "dupa apel " << var;
	cout << endl;
	
	char*profNume = new char[strlen("ion") + 1];
	strcpy(profNume, "ion");
	cout << profNume;
	cout << endl;
	
	//cout<<strlen(profNume);
	//cout << endl;
	//cout << "profesorul," << profNume;
	int vagon = 4;
	int* locomotiva = &vagon;
	cout <<"locatia vagonului este "<< locomotiva<<" sau "<<&vagon<<" iar valoarea din vagon este "<<vagon<<" sau "<<*locomotiva;
//locatia vagonului este 0000000C4F34F894 sau 0000000C4F34F894 iar valoarea din vagon este 4 sau 4
}

/*
#include <iostream>
using namespace std;

int main() {
    int vagon = 42;       // Vagonul are marfa "42".
    int* locomotiva;      // Locomotiva nu știe încă unde este vagonul.
    
    locomotiva = &vagon;  // Operatorul `&` dă adresa vagonului locomotivei.
    
    cout << "Locomotiva știe unde e vagonul și accesează marfa: " << *locomotiva << endl;
    return 0;
}
*/
//& (operatorul "harta"):

//Îți spune unde este vagonul.
//Ex: locomotiva = &vagon; → Locomotiva primește adresa vagonului.
//* (dereferențierea):

//Îți permite să accesezi marfa din vagon.
//Ex: *locomotiva = 100; → Locomotiva pune marfa 100 în vagon.






