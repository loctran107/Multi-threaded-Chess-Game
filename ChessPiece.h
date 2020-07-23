#ifndef _CHESSPIECE_H_
#define _CHESSPIECE_H_
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;
namespace chess_piece {

	class ChessPiece {
		public:
			ChessPiece() {} //empty-argument constructor
			~ChessPiece(); //destructor
			Sprite getSprite() { return sprite_; } //Sprite accessor
			void setSprite(Sprite sprite); //Sprite mutator
			friend ostream& operator<<(ostream& out, const ChessPiece& chessPiece);
		private:
			//Field member
			Sprite sprite_;
			
	};

}

#endif //_CHESSPIECE_H_
