#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;
class Test {
	public:
		Test() : a{1} {
		//	m.insert(make_pair(1, new Test()));
		}
		void insertMap() {
			m.insert(make_pair(1, new Test()));
			m.insert(make_pair(2, new Test()));
		}
		map<int, Test*> getMap() { return m; }
		void setMap(map<int, Test*> m) { this->m = m; }
		int getA() { return a; }
		void setA(int b) { a = b; }
	private:
		int a;
		map<int, Test*> m;


};


int main(int argc, char** argv) {
	
/*	//Empty map container
	map<int, Test> empty;
	empty.insert(pair<int, int>(1, 40));
	empty.insert(pair<int, int>(2, 50));
	
	
	//Iterator
	map<int, int>::iterator itr;
	for (itr = empty.begin(); itr != empty.end(); ++itr) {
		cout << itr->first << " " << itr->second << endl;
	}
	int* array = new int[8]{1, 2, 3, 4, 5, 6, 7, 8};
	
	for (int i = 0; i < 8; i++) {
		cout << *(array + i) << endl;
	}
	
	delete[] array;
	
	Test* test = new Test[2];
	(test + 1)->setA(3);
	cout << test[1].getA() << endl;*/

	Test test;
//	map<int, Test*> mp = test.getMap();
//	mp.insert(make_pair(88, new Test));
//	test.setMap(mp);
	test.insertMap();
	map<int, Test*>::iterator itr;
	for (itr = test.getMap().begin(); itr != test.getMap().end(); ++itr) {
		cout << itr->first << " " << (itr->second)->getA() << endl;
	}
	//map<int, Test*> m = test.getMap();
	//cout << m[1]->getA() << endl;
	return EXIT_SUCCESS;
}
