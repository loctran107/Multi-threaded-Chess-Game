#include "ChessField.h"

namespace chess_field {
	
	ChessField::ChessField() {
		//Dynamically allocate within memory
		//1. YELLOW ROOK     -1. WHITE ROOK
		//2. YELLOW KNIGHT   -2. WHITE KNIGHT
		//3. YELLOW BISHOP   -3. WHITE BISHOP
		//4. YELLOW QUEEN    -4. WHITE QUEEN
		//5. YELLOW KING     -5. WHITE KING
		//6. YELLOW PAWN     -6. WHITE PAWN

		//Note: 2D array in C++ is just an array of pointers to 1D array
		this->chessArray = new int*[ROW];	                             
		if (this->chessArray == nullptr) {
			std::cerr << "Error: Unable to allocate 2D chessArray in the heap" << std::endl;
		}
		
		//Allocate individual array to each pointer
		for (int i = 0; i < ROW; ++i) {
			this->chessArray[i] = new int[COLUMN];
			if (this->chessArray[i] == nullptr) {
				std::cerr << "Error: Unable to allocate memory for 1D chessArray" << std::endl;
			}

		}
		
		//Define the chess matrix based on the piece coordinate
		
		//1. Yellow Pieces 
		this->chessArray[0][0] = 1; //YELLOW ROOK
		this->chessArray[0][1] = 2; //YELLOW KNIGHT
		this->chessArray[0][2] = 3; //YELLOW BISHOP
		this->chessArray[0][3] = 4; //YELLOW QUEEN
		this->chessArray[0][4] = 5; //YELLOW KING
		this->chessArray[0][5] = 3; //YELLOW BISHOP
		this->chessArray[0][6] = 2; //YELLOW KNIGHT
		this->chessArray[0][7] = 1; //YELLOW ROOK
		
		for (int i = 0; i < ROW; ++i) { 
			this->chessArray[1][i] = 6; //YELLOW PAWN
		}
		
		//2. Empty spaces in between 
		for (int i = 2; i < ROW - 2; ++i) {
			for (int j = 0; j < COLUMN; ++j) {
				this->chessArray[i][j] = 0; //VOID
			}
		}

		//2. White Pieces 
		for (int i = 0; i < ROW; ++i) {
			this->chessArray[6][i] = -6; //WHITE PAWN
		}

		this->chessArray[7][0] = -1; //WHITE ROOK
		this->chessArray[7][1] = -2; //WHITE KNIGHT
		this->chessArray[7][2] = -3; //WHITE BISHOP
		this->chessArray[7][3] = -4; //WHITE QUEEN
		this->chessArray[7][4] = -5; //WHITE KING
		this->chessArray[7][5] = -3; //WHITE BISHOP
		this->chessArray[7][6] = -2; //WHITE KNIGHT
		this->chessArray[7][7] = -1; //WHITE ROOK		*/
	}	

	ChessField::~ChessField() {

		//Reverse deallocating. Deallocate 1D array first before
		//the array of pointer
		for (int i = 0; i < ROW; ++i) {
			delete[] chessArray[i];
		}
		delete[] chessArray;
	}
}
