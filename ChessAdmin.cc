#include "ChessAdmin.h"
#include <iostream>

using namespace std;
using namespace chess;
namespace chess_admin {

	ChessAdmin::~ChessAdmin() {}
	void ChessAdmin::computerMode() const {
		Chess chessComputerMode;
		chessComputerMode.playChess();
	}	

	void ChessAdmin::playerMode() const {

	}


}
