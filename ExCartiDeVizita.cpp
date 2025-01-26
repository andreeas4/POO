#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;
class Date {

	virtual void oferaDate() = 0;
	virtual void furadate() {
		cout << "Te am furat!!";
	}
};
class CartiDeVizita:public Date
{
private:
	char* nume;
	int varsta;
	string companie;
	const string email;
	string nrTlf;

public:
	CartiDeVizita() :varsta(0), companie("Necunoscuta"), email("-"),nrTlf("000000000000") {
		nume = new char[strlen("Anonim") + 1];
		strcpy(nume, "Anonim");
	}
	CartiDeVizita(const char* fnume, int fvarsta, string fcompanie, const string femail,string fnrTlf) :varsta(fvarsta),companie(fcompanie),email(femail),nrTlf(fnrTlf)
	{
		if (fnume)
		{
			nume = new char[strlen(fnume) + 1];
			strcpy(nume, fnume);
		}
		else {
			nume = new char[strlen("Anonim") + 1];
			strcpy(nume, "Anonim");
		}
	}
	CartiDeVizita(const string femail):email(femail){}
	CartiDeVizita(const CartiDeVizita& other) : email(other.email) {
		varsta = other.varsta;
		companie = other.companie;
		if (other.nume) {
			nume = new char[strlen(other.nume) + 1];
			strcpy(nume, other.nume);
		}
		else {
			nume = nullptr;  // În caz că nume este nullptr
		}
	}


	char* getNume() { return nume; }
	int getVarsta() { return varsta; }
	string getCompanie() { return companie; }
	string getEmail()const { return email; }

	void setNume(char* nn) {
		if (nume)delete[]nume;
		nume = new char[strlen(nn) + 1];
		strcpy(nume, nn);
	}
	void setVartsa(int v) { varsta = v; }
	void setCompanie(string c) { companie = c; }
	void oferaDate()override {
		cout << "Scrie: " << endl;
		cout<< "Nume: " << nume << endl;
		cout << "Varsta: " << varsta << endl;
		cout << "Compania: " << companie << endl;
		cout<< "Ma poti contacta pe : " << email << endl;
		cout<< "Sau la nr de telefon: " << nrTlf << endl;
		cout<< endl;

	}
	void furadate()override{
		if (nume)delete[]nume;
		nume = new char[strlen("N/A") + 1];
		strcpy(nume, "N/A");
		varsta = 0;
		companie = "N/A";
		nrTlf = "N/A";
	}
	CartiDeVizita operator=(CartiDeVizita& other) {
		if (this != &other)
		{	
			varsta = other.varsta;
			companie = other.companie;
			if (other.nume) {
				nume = new char[strlen(other.nume) + 1];
				strcpy(nume, other.nume);
			}
			else {
				nume = nullptr;  // În caz că nume este nullptr
			}
		}
	}
	friend ostream &operator<<(ostream& os, const CartiDeVizita& c) {

		os << "Nume: " << c.nume << endl;
		os << "Varsta: " << c.varsta << endl;
		os << "Compania: " << c.companie << endl;
		os << "Ma poti contacta pe : " << c.email << endl;
		os << "Sau la nr de telefon: " << c.nrTlf << endl;
		os << endl;


		return os;
	}
	friend istream& operator>>(istream& is, CartiDeVizita& c) { //nj ce cacat are???
		char buffer[100];
		cout << "Introdu date personale: " << endl;

		cout << "Nume: "; 
		is >> ws;
		is.getline(buffer,100);
		c.setNume(buffer);

		cout << "Varsta: "; is >> c.varsta;
		cout << "Compania: "; 
		is >> ws;
		getline(is, c.companie);
		cout << "Nr de telefon: ";
		is >> ws;
		getline(is, c.nrTlf);
		

		return is;
	}
	friend bool operator>=(CartiDeVizita& c1, CartiDeVizita& c2) {
		if (c1.varsta >= c2.varsta)return true;
		else return false;
	}

	~CartiDeVizita() {
		if (nume)delete[]nume;
	}
};
class CartiDeVizitaDigitale :public CartiDeVizita {
private:
	const int id;
public:
	CartiDeVizitaDigitale():CartiDeVizita(),id(0){}
	CartiDeVizitaDigitale(const CartiDeVizita &baza,int const fid):CartiDeVizita(baza),id(fid){}
	~CartiDeVizitaDigitale() {}
	friend ostream& operator<<(ostream& os, const CartiDeVizitaDigitale& c) {
		os << (const CartiDeVizita&)c; 
		os << "ID: " << c.id << endl;   
		return os;
	}
};
void main()
{
	CartiDeVizita c1;

	CartiDeVizita c2("Marian Bucsa", 22, "Ubisoft", "marianb2000@gmail.com","075349321");
	//CartiDeVizita c3;
	cout << c2;
	//cin >> c3;
	//cout << c3;
	CartiDeVizita c4("Aritina Popa", 70, "Stat", "-", "0753493000");
	CartiDeVizita c5("Isabel Scarlet", 21, "Brd", "msa004@gmail.com", "0723432134");
	CartiDeVizita c6("Dan Popescu", 55, "Biserica", "danisyge@gmail.com", "075346521");
	if (c4 >= c5)cout << c4.getNume() << " este mai in varsta decat " << c5.getNume() << endl;
	else cout << c4.getNume() << " este mai in tanara decat " << c5.getNume() << endl;
	c2.furadate();
	cout << c2;
}
