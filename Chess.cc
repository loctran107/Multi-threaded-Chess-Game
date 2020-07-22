#include "Chess.h"
#define PIECE_SIZE 56
#define CHESS_SIZE 64
#define ROW 8
#define COLUMN 8
using namespace sf;
using namespace std;
using namespace chess_field;
namespace chess {

	Chess::~Chess() {}
	
	void Chess::playChess() {

		//Set up framework for the game
		RenderWindow gameWindow(VideoMode(WIDTH, HEIGHT), "Chess game");
		
		//Load a sprite to display
		Texture textureFrame, texturePiece;
		
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
		Sprite spritePiece(texturePiece);

		//Create a chess field to get chess matrix
		ChessField chessField;
		int** chessArray = chessField.getChessArray();

			
//		spritePiece.setTextureRect(IntRect(168, 0, PIECE_SIZE, PIECE_SIZE));
		bool isMove = false;
		float dx = 0;
	        float dy = 0;
		while (gameWindow.isOpen()) {
			
			//Getting vector coordinate of the mouse relative to the created window
			Vector2i vect = Mouse::getPosition(gameWindow); //see SFML documentation
				

			//Process the event
			Event event;
			while (gameWindow.pollEvent(event)) {
				if (event.type == Event::Closed) {
					gameWindow.close();
				} 

				if (event.type == Event::MouseButtonPressed) {
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
					
				}
			}
			
			if (isMove) {
	//		        cout << dx << ", " << dy << endl;
	//		        
			//	spritePiece.setPosition(vect.x - dx, vect.y - dy);
			}
			gameWindow.clear();
			gameWindow.draw(spriteFrame);
			
			for (int i = 0; i < ROW; ++i) {
				for (int j = 0; j < COLUMN; ++j) { 
					
					if (chessArray[i][j] > 0) { //YELLOW PIECE
						spritePiece.setTextureRect(IntRect(PIECE_SIZE * (chessArray[i][j] - 1), 0,
									   PIECE_SIZE, PIECE_SIZE));
					} else if (chessArray[i][j] < 0) { //WHITE PIECE
						spritePiece.setTextureRect(IntRect(PIECE_SIZE * (abs(chessArray[i][j]) - 1), PIECE_SIZE,
									   PIECE_SIZE, PIECE_SIZE));
					} else {
						continue;
					}
					spritePiece.setPosition(PIECE_SIZE * j, PIECE_SIZE * i);
					gameWindow.draw(spritePiece);
				}

			}	
			gameWindow.display();
		
		}	
	}	
}
