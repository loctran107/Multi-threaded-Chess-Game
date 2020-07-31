#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

//Example of finding key value in a map
int main() {
	
	//Initialize container
	map<int, int> mp;

	//insert elements in random order
	mp.insert(make_pair(2, 30));
	mp.insert(make_pair(1, 40));
	mp.insert(make_pair(3, 50));
	mp.insert(make_pair(6, 70));
	
	map<int, int>::iterator itr;
	itr = mp.find(3);
	cout << itr->first << " " << itr->second << endl;
	return EXIT_SUCCESS;
	
	
}
