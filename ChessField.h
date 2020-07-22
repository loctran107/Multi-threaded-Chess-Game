#ifndef _CHESSFIELD_H_
#define _CHESSFIELD_H_

#include <cstdlib>
#include <iostream>
#define ROW 8
#define COLUMN 8


namespace chess_field {

	class ChessField {
		public:
			
			ChessField(); //Empty-argument constructor
			~ChessField(); //Destructor

			int** getChessArray() { return chessArray; }
			
		private:
			
			//Field member
			int** chessArray; 
	}; //class chess_field


} //chess_field namespace

#endif //_CHESSFIELD_H_
