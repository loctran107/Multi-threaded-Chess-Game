#ifndef _CHESS_H_
#define _CHESS_H_

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include "ChessField.h"

#define WIDTH 597
#define HEIGHT 600
namespace chess {
	
	class Chess {
		public:
			Chess() {} //constructor 
			~Chess(); //destructor
			void playChess(); //play the game
			void drawPiece(int* const chessArray, Sprite spritePiece, RenderWindow gameWindow);
			int getWidth() { return width_; }
			int getHeight() { return height_; }
		private:
			//Field members
			int width_ = WIDTH;
			int height_ = HEIGHT;
	}; //Chess class

} //chess namespace

#endif //_CHESS_H_
