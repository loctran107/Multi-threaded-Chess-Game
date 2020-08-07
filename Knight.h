#ifndef _KNIGHT_H_
#define _KNIGHT_H_
#include "ChessPiece.h"
#include <string>
#include <SFML/Graphics.hpp>
using namespace chess_piece;
using namespace sf;
using namespace std;
namespace knight {
	class Knight : public ChessPiece {
		public:	
			//Constructor
			Knight(string color, Sprite sprite) : color_{color}, sprite_{sprite} {}
			~Knight() {}

			string getColor() { return color_; } //color accessor
			Sprite getSprite() const override { return sprite_; } //sprite accessor
			void setSprite(Sprite sprite) override { this->sprite_ = sprite; }

	private:
			string color_;
			Sprite sprite_;
	}; //class Knight
	
} //namespace knight

#endif //_KNIGHT_H_
