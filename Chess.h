#ifndef _CHESS_H_
#define _CHESS_H_

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <time.h>
#include <iostream>

namespace chess {
	
	class Chess {
		public:
			Chess() : width_{454}, height_{454} {} //constructor 
			~Chess(); //destructor
			void playChess(); //play the game

		private:
			//Field members
			int width_;
			int height_;
	}; //Chess class

} //chess namespace

#endif //_CHESS_H_
