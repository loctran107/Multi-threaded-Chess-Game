#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;

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
	return EXIT_SUCCESS;
}
