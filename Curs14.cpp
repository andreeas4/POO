#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <iterator>
#include <algorithm>

using namespace std;
void f(int x)
{
	cout << x << endl;
	//afisez el
}


class Suma_el {
	int s;
public:
	Suma_el() :s(0) {}
	void operator()(int x)
	{
		s += x;
	}
	operator int() { //cast la int 
		return s;
	}

};

bool sens(int a, int b) { return a < b; }

void main() 
{


	vector<int> vi;
	vector<int>::iterator vit;
	vector<int>::reverse_iterator rit;
	vi.push_back(200); vi.push_back(150); vi.push_back(600);
	//for (int i = 0; i < vi.size(); i++) cout << vi[i] << endl;
	//for (auto el : vi)cout << el << endl;
	vi.at(0) = 210;
	for (rit = vi.rbegin(); rit != vi.rend(); rit++) cout << *rit << endl;
	cout << "======================================" << endl;
	list<double> ld;
	ld.push_back(45.67); ld.push_back(11.67); ld.push_back(98.23);
	ld.push_front(100.58);
	list<double>::iterator it;
	ostream_iterator<double> ostint(cout, " urmatorul \n");
	for (it = ld.begin(); it != ld.end(); it++) ostint = *it;
	cout << "======================================" << endl;
	map<int, string, greater<int>> mp;
	pair<int, string> el1(500, "Elena"), el2(100, "Gigi"), el3(700, "Violeta");
	mp.insert(el1); mp.insert(el3); mp.insert(el2);
	map<int, string>::iterator mit;
	for (mit = mp.begin(); mit != mp.end(); mit++)cout << "(" << (*mit).first << "," << mit->second << ")" << endl;
	cout << "======================================" << endl;
	stack<int, list<int>> st;
	st.push(400); st.push(200);
	cout << st.top() << endl;
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	cout << "======================================" << endl;

	//procesarea elem din container
	Suma_el obs;
	for_each(vi.begin(), vi.end(), f);
	for_each(vi.begin(), vi.end(), obs);
	
	int sel=for_each(vi.begin(), vi.end(), obs);
	cout << "Suma el:" << sel << endl;
	int s = 0, fm = 1;
	for_each(vi.begin(), vi.end(), [&s,fm](int x) {s += x*fm; });//expresii lambda
	//increementeaza in s 
	//int x el tip container
	cout << "Suma elementelor prin expresie lambda" << s << endl;

	sort(vi.begin(), vi.end(),sens);
	cout << "Sortat: " << endl;
	for_each(vi.begin(), vi.end(), obs);
	fm = 165;
	vit = find_if(vi.begin(), vi.end(), [/*nu exista parametri (bd exista)*/ fm](int x) { return x > fm; }); // returneaza un iterator
	if (vit == vi.end()) cout << "Element inexistent!!" << endl;
	else cout << "Elementul " << *vit << " exista !!" << endl;




}
