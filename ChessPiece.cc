#include "ChessPiece.h"

//using namespace sf;
//using namespace std;
namespace chess_piece {

	ChessPiece::~ChessPiece() {}	
	void ChessPiece::setSprite(Sprite sprite) {
		this->sprite_ = sprite;
	}
	
	ostream& operator<<(ostream& out, const ChessPiece& chessPiece) {
		Vector2f vect = (chessPiece.sprite_).getPosition();
		out << "(" << vect.x << ", " << vect.y << ")";
		return out;
	}

	
}
