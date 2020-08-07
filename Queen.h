#ifndef _QUEEN_H_
#define _QUEEN_H_
#include "ChessPiece.h"
#include <string>
#include <SFML/Graphics.hpp>
using namespace chess_piece;
using namespace sf;
using namespace std;
namespace queen {
	class Queen : public ChessPiece {
		public:	
			//Constructor
			Queen(string color, Sprite sprite) : color_{color}, sprite_{sprite} {}
			~Queen() {}

			string getColor() { return color_; } //color accessor
			Sprite getSprite() const override{ return sprite_; } //sprite accessor
			void setSprite(Sprite sprite) override { this->sprite_ = sprite; }



		private:
			string color_;
			Sprite sprite_;
	}; //class Queen
	
} //namespace queen

#endif //_QUEEN_H_
