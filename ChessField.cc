
namespace chess_field {
	
	ChessField::ChessField() {
		//Dynamically allocate within memory
		this->chessArray = new int[CHESS_SIZE];
		if (chessArray == nullptr) {
			std::cerr << "Error: Unable to allocate chessArray in the heap" << std::endl;
		}
		
		//Define the chess matrix based on the piece coordinate
		
		/*1. Yellow Pieces */
		this->chessArray[0] = 1; //YELLOW ROOK
		this->chessArray[1] = 2; //YELLOW KNIGHT
		this->chessArray[2] = 3; //YELLOW BISHOP
		this->chessArray[3] = 4; //YELLOW QUEEN
		this->chessArray[4] = 5; //YELLOW KING
		this->chessArray[5] = 3; //YELLOW BISHOP
		this->chessArray[6] = 2; //YELLOW KNIGHT
		this->chessArray[7] = 1; //YELLOW ROOK
		
		for (int i = 0; i < CHESS_SIZE / 8; i++) { 
			this->chessArray[8 + i] = 6; //YELLOW PAWN
		}
		
		/*2. Empty spaces in between */
		for (int i = 0; i < CHESS_SIZE; i++) {
			this->chessArray[16 + i] = 0; //VOID
		}

		/*2. White Pieces */
		for (int i = 0; i < CHESS_SIZE / 8; i++) {

			this->chessArray[48 + i] = -6; //WHITE PAWN
		}

		this->chessArray[56] = -1; //WHITE ROOK
		this->chessArray[57] = -2; //WHITE KNIGHT
		this->chessArray[58] = -3; //WHITE BISHOP
		this->chessArray[59] = -4; //WHITE QUEEN
		this->chessArray[60] = -5; //WHITE KING
		this->chessArray[61] = -3; //WHITE BISHOP
		this->chessArray[62] = -2; //WHITE KNIGHT
		this->chessArray[63] = -1; //WHITE ROOK		
	}	

	ChessField::~ChessField() {
		delete[] chessArray;
	}
}
