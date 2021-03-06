#include "Chess.h"
#define PIECE_SIZE 56
#define CHESS_SIZE 64
#define ROW 8
#define COLUMN 8
#define CONVERT(i, j) ((i) * ROW + (j))
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
		Texture textureFrame, texturePiece, textureMove;
		
		//Create a chess field to get chess matrix
		ChessField chessField;

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

		//Check texture movement
		if (!textureMove.loadFromFile("images/moveSquare.png")) {
			cerr << "Failed to load the image square. Please try again." << endl;
			exit(EXIT_FAILURE);
		}

		Sprite spriteFrame(textureFrame);
		Sprite spriteMove(textureMove);

		//Load the chess pieces on the board
		loadChessBoard(chessField, texturePiece);
		map<int, ChessPiece*> mp = chessField.getMap();
		bool isMove = false;
		while (gameWindow.isOpen()) {
			
				
			//Getting vector coordinate of the mouse relative to the created window
			Vector2i vect = Mouse::getPosition(gameWindow); //see SFML documentation
			Sprite movePiece;
			//Convert vect coordinate to select the sprite
			int x_coor = (int) (vect.x / PIECE_SIZE);
			int y_coor = (int) (vect.y / PIECE_SIZE);
			int key;
			if (x_coor < COLUMN && y_coor < ROW) {	
				key = CONVERT(y_coor, x_coor);
				if (mp.find(key) == mp.end()) {
					continue;
				} else {
				//	isEmpty = false;
					movePiece = mp[key]->getSprite();
				}
			}	

			if (Mouse::isButtonPressed(Mouse::Left)) {
				if (movePiece.getGlobalBounds().contains(vect.x, vect.y)) {
						spriteMove.setPosition(PIECE_SIZE * x_coor + 1, PIECE_SIZE * y_coor + 3);
				//		isMove = !isMove;		
				}
			} 

			//Process the event
			Event event;
			while (gameWindow.pollEvent(event)) {
				if (event.type == Event::Closed) {
					gameWindow.close();
				} 

			/*	if (event.type == Event::MouseButtonPressed && isMove) {
					if (event.key.code == Mouse::Left) {
						if (!movePiece.getGlobalBounds().contains(vect.x, vect.y)) {
							movePiece.setPosition(
						}
					}
				}*/
				if (event.type == Event::MouseButtonReleased) {
					if (event.key.code == Mouse::Left) {
						isMove = !isMove;
					}
				}
			}	
				
			gameWindow.clear();
			gameWindow.draw(spriteFrame);

			if (isMove) {
				gameWindow.draw(spriteMove);
			}
					
			//Draw the chess board
//			map<int, ChessPiece*> mp = chessField.getMap();
			for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
				gameWindow.draw((itr->second)->getSprite());
			}
			gameWindow.display();
		
		}	

	}	

	void Chess::loadChessBoard(ChessField& chessField, const Texture& texturePiece) {
		int i, j;
		int key;
		String color;
		Sprite dummy(texturePiece);
		int** chessArray = chessField.getChessArray();
		map<int, ChessPiece*> mp;
		for (i = 0; i < ROW; ++i) {
			for (j = 0; j < COLUMN; ++j) {

				//Try shorten this statement later
				if (chessArray[i][j] != 0) {
					dummy.setTextureRect(IntRect(PIECE_SIZE * (abs(chessArray[i][j]) - 1), 
							     (chessArray[i][j] > 0 ? 0 : PIECE_SIZE), PIECE_SIZE, PIECE_SIZE));
				} else {
					continue;
				}
				
				dummy.setPosition(PIECE_SIZE * j, PIECE_SIZE * i);
			
				key = CONVERT(i, j); //Key to map the object
				color = (chessArray[i][j] > 0) ? "YELLOW" : "WHITE";
				switch (abs(chessArray[i][j])) {
					case 1:
						mp.insert(make_pair(key, new rook::Rook(color, dummy)));
						break;
					case 2:
						mp.insert(make_pair(key, new knight::Knight(color, dummy)));
						break;
					case 3:
						mp.insert(make_pair(key, new bishop::Bishop(color, dummy)));
						break;
					case 4:
						mp.insert(make_pair(key, new queen::Queen(color, dummy)));
						break;
					case 5:
						mp.insert(make_pair(key, new king::King(color, dummy)));
						break;
					case 6:
						mp.insert(make_pair(key, new pawn::Pawn(color, dummy)));
						break;
					default:
						break;
				}	
			}
		}
		chessField.setMap(mp);

		//Compiler control directives for testing
		#ifdef TEST
		chessField.printChessMap(); 
		#endif

		//Consider deleting chessArray here
	}	
}
