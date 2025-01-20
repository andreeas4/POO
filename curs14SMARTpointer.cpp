#include <iostream>


using namespace std;


class demo
{
public:
	demo() { cout << "Constructor" << endl; }

	int get_valoare() { return 100; }

	~demo() { cout << "Destructor" << endl; }
};



void main()
{
	demo* pob = new demo(); //pointer la obiect i think

	cout<<pob->get_valoare() << endl;
	cout << "=========================";

	//smart pointer
	unique_ptr<demo> plob(new demo());

	cout << plob->get_valoare() << endl;
	cout << "=========================";
	//shared pointer???
	shared_ptr<demo> plm(new demo());
		shared_ptr<demo> p1 = plm;
		cout << plm->get_valoare() << endl;
		cout << "=========================";
}
