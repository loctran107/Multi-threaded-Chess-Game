#include "Chess.h"
#define PIECE_SIZE 56
#define CHESS_SIZE 64
#define ROW 8
#define COLUMN 8
using namespace sf;
using namespace std;
using namespace chess_field;
using namespace chess_piece;

namespace chess {

	Chess::~Chess() {}
	
	void Chess::playChess() {

		//Set up framework for the game
		RenderWindow gameWindow(VideoMode(WIDTH, HEIGHT), "Chess game");
		
		//Load a sprite to display
		Texture textureFrame, texturePiece;
		
		//Create a chess field to get chess matrix
		ChessField chessField;
		int** chessArray = chessField.getChessArray();

		//Create an array of chess piece
		ChessPiece* chessPieceArray = new ChessPiece[32];

		//Check loading piece
		if (!texturePiece.loadFromFile("images/figures.png")) {
			cerr << "Failed to load the piece figures. Please try again." << endl;
			exit(EXIT_FAILURE);
		}

		//Check loading frame
		if (!textureFrame.loadFromFile("images/board0.png")) {
			cerr << "Failed to load the image. Please try again." << endl;
			exit(EXIT_FAILURE);	
		}
		Sprite spriteFrame(textureFrame);
		loadChessBoard(chessArray, chessPieceArray, texturePiece);
			
		bool isMove = false;
		float dx = 0;
	        float dy = 0;
		while (gameWindow.isOpen()) {
			
			//Getting vector coordinate of the mouse relative to the created window
//			Vector2i vect = Mouse::getPosition(gameWindow); //see SFML documentation
			
			//Convert vect coordinate to select the sprite
/*			int x_coor = (int) (vect.x / PIECE_SIZE);
			int y_coor = (int) (vect.y / PIECE_SIZE);
			if (x_coor < ROW && y_coor < COLUMN) {

				if (chessArray[x_coor][y_coor] > 0) {
					spritePiece.setTextureRect(IntRect(PIECE_SIZE * (chessArray[x_coor][y_coor] - 1), 0,
								   PIECE_SIZE, PIECE_SIZE));
				} else {
					spritePiece.setTextureRect(IntRect(PIECE_SIZE * (abs(chessArray[x_coor][y_coor]) - 1), 1, PIECE_SIZE, PIECE_SIZE));
				}
			}	*/	
				
			//Process the event
			Event event;
			while (gameWindow.pollEvent(event)) {
				if (event.type == Event::Closed) {
					gameWindow.close();
				} 
				
				/*<----Drag and drop---->*/
			/*	if (event.type == Event::MouseButtonPressed) {
					if (event.mouseButton.button == Mouse::Left) {
						if (spritePiece.getGlobalBounds().contains(vect.x, vect.y)) {
							isMove = true;
							dx = vect.x - spritePiece.getPosition().x;
							dy = vect.y - spritePiece.getPosition().y;				
						}

					}
				}

				if (event.type == Event::MouseButtonReleased) {
					if (event.mouseButton.button == Mouse::Left) {
						isMove = false;
					}
				}*/
			}
			
		/*	if (isMove) { 
				spritePiece.setPosition(vect.x - dx, vect.y - dy);
			}*/
			
			gameWindow.clear();
			gameWindow.draw(spriteFrame);
		
			//Draw the chess board
			for (int i = 0; i < 32; ++i) {
				gameWindow.draw((chessPieceArray+i)->getSprite());
			}
			gameWindow.display();
		
		}	

	}	

	void Chess::loadChessBoard(int** const chessArray, ChessPiece* const chessPieceArray,
			           const Texture& texturePiece) {
		int i, j, k;
		k = 0;
		Sprite dummy(texturePiece);
		for (i = 0; i < ROW; ++i) {
			for (j = 0; j < COLUMN; ++j) {
				if (chessArray[i][j] > 0) {
					dummy.setTextureRect(IntRect(PIECE_SIZE * (chessArray[i][j] - 1), 0,
							     PIECE_SIZE, PIECE_SIZE));
				} else if (chessArray[i][j] < 0) {
					dummy.setTextureRect(IntRect(PIECE_SIZE * ((abs(chessArray[i][j]) - 1)), 1,
							     PIECE_SIZE, PIECE_SIZE));
				} else {
					continue;
				}
				
				dummy.setPosition(PIECE_SIZE * j, PIECE_SIZE * i);

				(chessPieceArray+(k*ROW+j))->setSprite(dummy);
				
				//Update k when j reaches COLUMN	
				if (j == COLUMN - 1) {
					++k;
				}
			}
			
		}		
	}
}
