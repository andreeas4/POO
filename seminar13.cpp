//definim o clasa persoana
// shiftare pt afisare
// container asociativ intre pers si marca

#include <iostream>
#include <map>


using namespace std;

class persoana
{
	int marca;
	string nume;
	int varsta;
public:
	persoana(int fm = 0, string fnume = "N/A", int fv = 0) :marca(fm), nume(fnume), varsta(fv) {}
	string get_nume() { return nume; }
	int get_marca() { return marca; }
	int get_varsta() { return varsta; }
	friend ostream& operator << (ostream& os, persoana& pers)
	{
		os << "( " << pers.get_marca() << " " << pers.get_nume() << " " << pers.get_varsta() << " )";
		return os;
	}
};

void main()
{

	int m;
	persoana p1(11, "andrei", 24), p2, p3(1, "afro", 14);
	persoana vp[] = { persoana(11,"andrei",24) ,persoana(),persoana(1,"afro",14) };
	//for (int i = 0; i < 3; i++) cout << vp[i];
	map <int, persoana> mp;
	for (int i = 0; i < sizeof(vp) / sizeof(persoana); i++)
	{
		//pair <int, persoana> el(vp[i].get_marca(), vp[i]);
		mp.insert(pair <int, persoana>(vp[i].get_marca(), vp[i]));
	}
	map <int, persoana>::iterator mit;
	for (mit = mp.begin(); mit != mp.end(); mit++)
	{
		cout << "[ " << mit->first << " " << mit->second << " ]" << endl;
	}
	cout << "Marca pers cautata: "; cin >> m;
	mit=mp.find(m);
	if (mit == mp.end())//nu a fost gasit
		cout << "Pers cu marca " << m << " nu a fost gasita ";
	else cout << mit->second << endl;

	//mp.insert(el1); mp.insert(el2); mp.insert(el3);
	//map <int, string>::iterator mit;
	//for (mit)
}


