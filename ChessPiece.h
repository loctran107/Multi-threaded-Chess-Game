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
			virtual ~ChessPiece() = 0; //destructor
			virtual Sprite getSprite() const = 0; // { return sprite_; } //Sprite accessor
			virtual void setSprite(Sprite sprite) = 0; //{ this->sprite_ = sprite; } //Sprite mutator

	};

	ChessPiece::~ChessPiece() {
		cout << "Finish deallocation" << endl;
	}

}

#endif //_CHESSPIECE_H_
