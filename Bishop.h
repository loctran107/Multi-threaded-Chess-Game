#ifndef _BISHOP_H_
#define _BISHOP_H_
#include "ChessPiece.h"
#include <string>
#include <SFML/Graphics.hpp>
using namespace chess_piece;
using namespace sf;
using namespace std;
namespace bishop {
	class Bishop : public ChessPiece {
		public:	
			//Constructor
			Bishop(string color, Sprite sprite) : color_{color}, sprite_{sprite} {}
			~Bishop() {}

			string getColor() { return color_; } //color accessor
			Sprite getSprite() const override { return sprite_; } //sprite accessor
			void setSprite(Sprite sprite) override { this->sprite_ = sprite; }



		private:
			string color_;
			Sprite sprite_;
	}; //class Bishop
	
} //namespace bishop

#endif //_BISHOP_H_
