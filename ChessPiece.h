#ifndef _CHESSPIECE_H_
#define _CHESSPIECE_H_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <iterator>

//#include "Rook.h"
//#include "Knight.h"
//#include "Bishop.h"
//#include "Queen.h"
//#include "King.h"
//#include "Pawn.h"
using namespace sf;
using namespace std;
namespace chess_piece {

	class ChessPiece {
		public:
			ChessPiece() {} //empty-argument constructor
			~ChessPiece(); //destructor

			virtual Sprite getSprite() { return sprite_; } //Sprite accessor
		//	void setSprite(Sprite sprite); //Sprite mutator

			map<int, ChessPiece*> getMap() const { return chessMap_; }
			void setMap(map<int, ChessPiece*> chessMap);
			void printChessMap() const;
			friend ostream& operator<<(ostream& out, const ChessPiece& chessPiece);
		private:
			//Field member
			Sprite sprite_;
			map<int, ChessPiece*> chessMap_;
			
	};

}

#endif //_CHESSPIECE_H_
