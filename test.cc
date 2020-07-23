#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;
class Test {
	public:
		Test() : a{1} {}
		int getA() { return a; }
		void setA(int b) { a = b; }
	private:
		int a;


};


int main(int argc, char** argv) {
	
	//Empty map container
	map<int, int> empty;
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
	cout << test[1].getA() << endl;
	return EXIT_SUCCESS;
}
