#ifndef _ROOK_H_
#define _ROOK_H_
#include "ChessPiece.h"
#include <string>
#include <SFML/Graphics.hpp>
using namespace chess_piece;
using namespace sf;
using namespace std;
namespace rook {
	class Rook : public ChessPiece {
		public:	
			//Constructor
			Rook(string color, Sprite sprite) : color_{color}, sprite_{sprite} {}
			~Rook();

			string getColor() { return color_; } //color accessor
			Sprite getSprite() { return sprite_; } //sprite accessor


		private:
			string color_;
			Sprite sprite_;
	}; //class Rook
	
} //namespace rook

#endif //_ROOK_H_
