#include "ChessPiece.h"

//using namespace sf;
//using namespace std;
namespace chess_piece {
	ChessPiece::~ChessPiece() {
		for (auto itr = this->chessMap_.begin(); itr != this->chessMap_.end(); ++itr) {
			delete itr->second;
		}
	}

	//void ChessPiece::setSprite(Sprite sprite) {
	//	this->sprite_ = sprite;
	//}
	void ChessPiece::printChessMap() const {
		for (auto itr = this->chessMap_.begin(); itr != this->chessMap_.end(); ++itr) {
			ChessPiece* piece = itr->second;
			Sprite dummy = piece->getSprite();
			IntRect d = dummy.getTextureRect();
			Vector2f vect = dummy.getPosition();
			cout << itr->first << " " << vect.x << " " << vect.y << endl;
			cout << d.left << " " <<  d.top << endl;
			cout << endl;			
		}
	}	
	void ChessPiece::setMap(map<int, ChessPiece*> chessMap) {
		this->chessMap_ = chessMap;
	}

	ostream& operator<<(ostream& out, const ChessPiece& chessPiece) {
		Vector2f vect = (chessPiece.sprite_).getPosition();
		out << "(" << vect.x << ", " << vect.y << ")";
		return out;
	}

	
}
