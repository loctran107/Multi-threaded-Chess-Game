#include <memory>
#include <string>
#include <map>
#include <iostream>

class animal 
{

	public:
		virtual ~animal() {};
		virtual void make_sound() const = 0;
};

class dog : public animal {

	public:
		void make_sound() const { std::cout << "bark" << std::endl; }
};

class bird : public animal {
	void make_sound() const { std::cout << "chirp" << std::endl; }
};


int main() {

	//Option 1: pointer to the parent object class. Needs to free the object
	std::map<std::string, animal*> m;

	//Option 2: Smart pointer. No need to free (compile and check valgrind)
	//std::map<std::string, std::unique_ptr<animal>> m;
	m.insert(std::make_pair("stupid_dog_name", new dog()));
	m.insert(std::make_pair("stupid_bird_name", new bird()));
	m["stupid_dog_name"]->make_sound();

	//std::map<std::string, std::unique_ptr<animal>>::iterator itr;//
	//New keyword: auto. As its name suggest, it automatically deduce the d
	//data type of a variable. Use it wisely.
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		delete itr->second;
	}
	return 0;
}
