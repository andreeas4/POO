	#include <iostream>

//---------------------------------------------el const--------------------
using namespace std;


class Salariat {


	const int marca;
	string nume;
public:
	//setez const doar in constructor
	Salariat(const int fm, string fn) :marca(fm), nume(fn) {

	}
	int getMarca() {
		return marca;

	}
	string getNume()const {
		return nume;

	}

	/*void setMarca(int nouamarca) {
		marca = nouamarca;                      nu merge ca e  const
	}*/
	void set_nume(string nn) { nume = nn; }
};


void main()
{
	Salariat obs(100, "Gigi");
	

	const Salariat obc(200, "Elena");
	obc.getNume();
	//NICIODATA NU SE POATE MODIFICA/SETA

}
