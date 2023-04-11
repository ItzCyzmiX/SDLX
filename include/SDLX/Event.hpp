#include <iostream>
#include <SDL2/SDL.h>
#include <string>

class Event {
	public:
		Event();

		bool checkEvents() {return SDL_PollEvent(&ee);};

		bool quit() {return ee.type == SDL_QUIT;};

		bool keyPressed(int key);

		bool keyUp(int key);

		bool mouseMoved();

		bool mousePressed(char btnStr);

		bool mouseUp(char btnStr);

		char getMouseButtonPressed();

		int getKeyPressed();
		
	private:
		SDL_Event ee;
};
