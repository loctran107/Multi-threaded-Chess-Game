#ifndef _CHESS_H_
#define _CHESS_H_

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include "ChessField.h"

#define WIDTH 454
#define HEIGHT 455
namespace chess {
	
	class Chess {
		public:
			Chess() {} //constructor 
			~Chess(); //destructor
			void playChess(); //play the game
		private:

			//Private helper methods
			//void drawPiece(int* const chessArray, Sprite spritePiece, RenderWindow gameWindow);
			
	}; //Chess class

} //chess namespace

#endif //_CHESS_H_
