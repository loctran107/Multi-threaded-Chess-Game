#include "Chess.h"
#define PIECE_SIZE 56
#define CHESS_SIZE 64
using namespace sf;
using namespace std;


namespace chess {

	Chess::~Chess() {}
	
	void Chess::playChess() {

		//Set up framework for the game
		RenderWindow gameWindow(VideoMode(this->width_, this->height_), "Chess game");
		
		//Load a sprite to display
		Texture textureFrame, texturePiece;
		
		//Check loading piece
		if (!texturePiece.loadFromFile("images/figures.png")) {
			cerr << "Failed to load the piece figures. Please try again." << endl;
			exit(EXIT_FAILURE);
		}

		//Check loading frame
		if (!textureFrame.loadFromFile("board2.png")) {
			cerr << "Failed to load the image. Please try again." << endl;
			exit(EXIT_FAILURE);	
		}
		Sprite spriteFrame(textureFrame);
		Sprite spritePiece(texturePiece);

		//Create a chess field to get chess matrix
		const ChessField chessField;
		int* chessArray = chessField.getChessArray();

			
	//	spritePiece.setTextureRect(IntRect(56, 0, PIECE_SIZE, PIECE_SIZE));
		while (gameWindow.isOpen()) {
			
			//Process the event
			Event event;
			while (gameWindow.pollEvent(event)) {
				if (event.type == Event::Closed) {
					gameWindow.close();
				}
			}
			gameWindow.clear(Color::White);
			gameWindow.draw(spriteFrame);
			
			drawPiece(chessArray, spritePiece, gameWindow);
			spritePiece.setPosition(PIECE_SIZE - 10, PIECE_SIZE - 6);
			gameWindow.draw(spritePiece);
			gameWindow.display();
		
		}
		
		
	}

	void drawPiece(int* const chessArray, Sprite spritePiece, RenderWindow gameWindow) {
		
		int i;
		for (i = 0; i < CHESS_SIZE; i++) {
			if (chessArray[i] > 0) {
				
				//Configure and draw

			}

		}
		
	}


}
