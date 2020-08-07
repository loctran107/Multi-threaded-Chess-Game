#ifndef _KING_H_
#define _KING_H_
#include "ChessPiece.h"
#include <string>
#include <SFML/Graphics.hpp>
using namespace chess_piece;
using namespace sf;
using namespace std;
namespace king {
	class King : public ChessPiece {
		public:	
			//Constructor
			King(string color, Sprite sprite) : color_{color}, sprite_{sprite} {}
			~King() {}

			string getColor() { return color_; } //color accessor
			Sprite getSprite() const override{ return sprite_; } //sprite accessor
			void setSprite(Sprite sprite) override { this->sprite_ = sprite; }



		private:
			string color_;
			Sprite sprite_;
	}; //class King
	
} //namespace king

#endif //_KING_H_
