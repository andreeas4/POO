#include<iostream>
#include<map>
using namespace std;

class persoana
{
	int marca;
	int varsta;
	string nume;
public:
	persoana(int fmarca, int fvarsta, string fnume) :marca(fmarca), varsta(fvarsta), nume(fnume) {}
	int get_marca() { return marca; }
	int get_varsta() { return varsta; }
	string get_nume() { return nume; }

	friend ostream& operator<<(ostream& os, persoana& p)
	{
		os << endl;
		os << "Marca: " << p.marca << endl;
		os << "Varsta:" << p.varsta << endl;
		os << "Numele:" << p.nume << endl;
		return os;
	}
};

void main()
{
	persoana vp[] = { persoana(16,32,"Ana"),persoana(24,23,"Maria"),persoana(32,37,"Mihai") };
	map<int, persoana> mp;
	for (int i = 0; i < sizeof(vp) / sizeof(persoana); i++)
	{
		pair<int, persoana> el(vp[i].get_marca(), vp[i]);
		mp.insert(el);
	}
	map<int, persoana> ::iterator mit;
	for (mit = mp.begin(); mit != mp.end(); mit++)
		cout << mit->first <<" " << mit->second<<endl;
}
