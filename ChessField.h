#ifndef _CHESSFIELD_H_
#define _CHESSFIELD_H_

#include <cstdlib>
#include <iostream>
#include <map>
#include "ChessPiece.h"
#define ROW 8
#define COLUMN 8

using namespace chess_piece;
namespace chess_field {

	class ChessField {
		public:
			
			ChessField(); //Empty-argument constructor
			~ChessField(); //Destructor

			int** getChessArray() { return chessArray; }
			map<int, ChessPiece*> getMap() const { return this->chessMap_; }
			void setMap(map<int, ChessPiece*> chessMap); //map mutator
			void printChessMap() const;

		private:
			
			//Field member
			int** chessArray;
			map<int, ChessPiece*> chessMap_;	         	
	}; //class chess_field


} //chess_field namespace

#endif //_CHESSFIELD_H_
