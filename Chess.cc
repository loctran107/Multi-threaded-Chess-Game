#include "Chess.h"
using namespace sf;
using namespace std;

namespace chess {

	Chess::~Chess() {}
	
	void Chess::playChess() {

		//Set up framework for the game
		RenderWindow gameWindow(VideoMode(454, 455), "Chess game");
		
		//Load a sprite to display
		Texture texture;
		if (!texture.loadFromFile("images/board0.png")) {
			cerr << "Failed to load the image. Please try again." << endl;
			exit(EXIT_FAILURE);	
		}
		
		Sprite sprite(texture);
		
		while (gameWindow.isOpen()) {
			
			//Process the event
			Event event;
			while (gameWindow.pollEvent(event)) {
				if (event.type == Event::Closed) {
					gameWindow.close();
				}
			}
			
		}
		
		gameWindow.clear(Color::White);
		gameWindow.draw(sprite);
		gameWindow.display();
	}


}
