#ifndef _CHESS_H_
#define _CHESS_H_

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include "ChessField.h"
#include "ChessPiece.h"

#define WIDTH 454
#define HEIGHT 455
using namespace sf;
using namespace chess_piece;
using namespace chess_field;
using namespace std;
namespace chess {
	
	class Chess {
		public:
			Chess() {} //constructor 
			~Chess(); //destructor
			void playChess(); //play the game
		private:

			//Private helper methods
//			void drawChessBoard(RenderWindow gameWindow, ChessPiece* const chessPieceArray);

			void loadChessBoard(int** const chessArray, ChessPiece* const chessPieceArray,
					    const Texture& texturePiece);
			
	}; //Chess class

} //chess namespace

#endif //_CHESS_H_
