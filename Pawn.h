#ifndef _PAWN_H_
#define _PAWN_H_
#include "ChessPiece.h"
#include <string>
#include <SFML/Graphics.hpp>
using namespace chess_piece;
using namespace sf;
using namespace std;
namespace pawn {
	class Pawn : public ChessPiece {
		public:	
			//Constructor
			Pawn(string color, Sprite sprite) : color_{color}, sprite_{sprite} {}
		//	~Knight();

			string getColor() { return color_; } //color accessor
			Sprite getSprite() { return sprite_; } //sprite accessor


		private:
			string color_;
			Sprite sprite_;
	}; //class Pawn
	
} //namespace pawn

#endif //_PAWN_H_
