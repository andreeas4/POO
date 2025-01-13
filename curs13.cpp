#include <iostream>
#include <vector> //pot sa definesc un obiect vect pe baza unui sablon
#include <list>
#include <map>
#include <stack>


using namespace std;

//bibl de containere:(colectii definite in rapcu structuri de date cunoscute - masiv vector,lista care s secventiale -set multimap ,set map -stiva  )

//-contine iteratorii
//--------algoritmi

void main() 
{
	cout << "===============vector===============================" << endl;
	vector<int> vi;
	vi.push_back(200);
	vi.push_back(150);
	vi.push_back(600); //am adaugat el in vector 200 150 600
	for (int i = 0; i < vi.size(); i++)cout << vi[i] << endl; //vi.size()=3
	//for (auto el : vi)cout << el << endl;
	 //la vector merge iterator +1 pt ca e continuu
	vi.at(0) = 210;//adauga el 210



	list<double>ld;
	ld.push_back(45.67);
	ld.push_back(15.60);
	ld.push_back(10.69);
	ld.push_front(100.58);//in capul listei
	cout<<"===============lista================================" << endl;
	//for (int i = 0; i < ld.size(); i++)cout << ld[i] << endl; nu se poate
	//----trb folosita alta modalitate nu indexarea
	//folosim iteratorii
	//declaram o clasa inclusa in clasa
	list<double>::iterator it; //un iterator in obiectul list
	for (it=ld.begin();it!=ld.end(); it++)cout << *it << endl;


	//"struct de tip map care evident care evident deci trb inclusa deci includ map"
	map<int, string>mp;
	pair<int, string>el1(300, "Elena"), el2(200, "Elena"), el3(100, "Violeta");
	mp.insert(el1);//in arborele binar de cautare
	mp.insert(el2);
	mp.insert(el3);
	// asta nu merge nj de unde e luat mit    -----for (mit = mp.begin(); mit != mp.end(); mit++)cout << "(" << (*mit).first << "," << mit->second;





}


