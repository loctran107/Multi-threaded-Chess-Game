#include <iostream>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <cstdlib>

#include "ChessAdmin.h"

#define MAX_ARGUMENT 2

int main(int argc, char** argv) {
	



	//Check if only 2 arguments
	if (argc < MAX_ARGUMENT) { 

		//Avoid using namespace here to avoid name collision
		std::cerr << "Error: Too few arguments. Please run the program again." << std::endl;
		exit(EXIT_FAILURE);
	} else if (argc > MAX_ARGUMENT) {

		std::cerr << "Error: Too many arguments. Please run the program again." << std::endl;
		exit(EXIT_FAILURE);
	} 

	//Instantiate Chess Administrator object
	const chess_admin::ChessAdmin admin;

	//Initialization
	int option;
	int pflag = 0;
	int cflag = 0;

	//Get the option
	while ((option = getopt(argc, argv, "cp")) != -1) {
		switch (option) {
			case 'c':
				cflag = 1;
				break;
			
			case 'p':
				pflag = 1;
				break;

			case '?':
				std::cerr << "Sorry the option " << optopt << " is not available." << std::endl;
				exit(EXIT_FAILURE);
			
			default:
				exit(EXIT_FAILURE);
		}		
	}
	
	//Play modes
	if (pflag) {
		admin.playerMode();
	} else if (cflag) {
		admin.computerMode();
	}

	return EXIT_SUCCESS;
}
