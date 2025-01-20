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


using namespace std;

class Analize
{
private:
	string numePacient;
	int varstaPacient;
	int* dataNastere;
	float cost;

protected:
	//const int id_analiza;


public:
	
	Analize(string fnumePacient="Anonim", int fvarstaPacient=0, int* fdataNastere=nullptr, float fcost=0) 
		:numePacient(fnumePacient),varstaPacient(fvarstaPacient),cost(fcost)
	{
		if (fdataNastere != nullptr)
		{
			dataNastere = new int[3];
			for (int i = 0; i < 3; i++)
				dataNastere[i] = fdataNastere[i];
		}
		else {
			dataNastere = new int[3];
			for (int i = 0; i < 3; i++)
				dataNastere[i] = 0; // Inițializare cu valori implicite
		}
	
	}
	// constructor de copiere

	Analize(Analize& other) :numePacient(other.numePacient), varstaPacient(other.varstaPacient), cost(other.varstaPacient)
	{
		if (other.dataNastere != nullptr)
		{
			dataNastere = new int[3];
			for (int i = 0; i < 3; i++)
				dataNastere[i] = other.dataNastere[i];
		}
		else {
			dataNastere = new int[3];
			for (int i = 0; i < 3; i++)
				dataNastere[i] = 0; // Inițializare cu valori implicite
		}

	}



	~Analize() {
		if (dataNastere != nullptr)
			delete[] dataNastere;
		dataNastere = nullptr;

	}

	//----------------Metode


	//----------------operatori

	friend ostream& operator <<(ostream& os,const Analize& a) {
		os << "Numele pacientului: " << a.numePacient<<endl;
		os << "Varsta pacientului: " << a.varstaPacient << endl;
		os << "Data de nastere a pacientului: ";
		for (int i = 0; i < 3; i++)
			os << a.dataNastere[i] << " ";
		os << endl;
		os << "Cost analiza: " << a.cost<<endl;
		return os;


	}

	operator float() {
		return cost;
	}
//--op de atribuire
Analize &operator =(Analize const &b)
	{
	if (this != &b) {
		numePacient = b.numePacient;
		varstaPacient = b.varstaPacient;
		cost = b.cost;
		if (b.dataNastere != nullptr)
		{
			dataNastere = new int[3];
			for (int i = 0; i < 3; i++)
				dataNastere[i] = b.dataNastere[i];
		}
		else {
			dataNastere = new int[3];
			for (int i = 0; i < 3; i++)
				dataNastere[i] = 0; // Inițializare cu valori implicite
		}

		}
	return *this;
	}
//----op binar
	float operator+(Analize const& a)
	{
		cost += a.cost;
		return cost;

	}

//--op aritmetic ++op

	float operator++()
	{
		cost = cost + 100;
		return cost;
	}
//--op de comparare
	
	bool operator==(Analize& a,Analize &b)
	{
		if(this.)
	}





};
	//static atribut taxe


void main()
{
	int dataNastere[] = { 15, 8, 1990 };
	Analize a1("Ion Popescu", 33, dataNastere, 250.5f);
	Analize a2;

	cout << "Analiza 1:" << endl;
	cout << a1;

	cout << "\nAnaliza 2 (implicită):" << endl;
	cout << a2;
	//--operatorul cast 
	cout << float(a1)<<endl;
	

	//--operatorul = de atribuire
	a2 = a1;
	cout << "Analiza 2 dupa atribuire:" << endl;
	cout << a2;

	//--operatorul binar + de adunare

	float costTotal =a1 + a2;

	cout << "Costul total al analizelor 1 si 2 este : " << costTotal << endl;
	cout << endl;
	//--operator aritmetic unar ++

	int dataNastere3[] = { 2, 3, 1975 };
	Analize a3("Marinela Gheorghe", 49, dataNastere3, 100.9f);
	cout << "Analiza 3 inainte de adaugarea taxelor" << endl;
	cout << a3;
	cout << endl;

	++a3;

	cout << "Analiza 3 dupa adaugarea taxelor" << endl;
	cout << a3;
	cout << endl;


}



