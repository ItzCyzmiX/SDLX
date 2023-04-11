#include <SDLX/Event.hpp>
#include <SDL2/SDL.h>
#include <string>
#include <iostream>

Event::Event() {
	
};

bool Event::keyPressed(int key) {
	
	if (ee.type == SDL_KEYDOWN) {
		if (ee.key.keysym.sym == key) {
			return true;
		}
	}

	return false;
};


bool Event::keyUp(int key) {

	if (ee.type == SDL_KEYUP) {
		if (ee.key.keysym.sym == key) {
			return true;
		}
	}		
	
	return false;
};

int Event::getKeyPressed() {
	if (ee.type == SDL_KEYDOWN) {
		return ee.key.keysym.sym;
	}
	return -1;
};

bool Event::mouseMoved() {

	if (ee.type == SDL_MOUSEMOTION) {
		return true;
	}

	return false;
	
};

bool Event::mousePressed(char btnStr) {

	if (ee.type == SDL_MOUSEBUTTONDOWN) {
		if (btnStr == 'L') {
			if (ee.button.button == SDL_BUTTON_LEFT) {
				return true;	
			}
		} else if (btnStr == 'R') {
			if (ee.button.button == SDL_BUTTON_RIGHT) {
				return true;
			}
		}

	}

	return false;
};

bool Event::mouseUp(char btnStr) {
	if (ee.type == SDL_MOUSEBUTTONUP) {
		if (btnStr == 'L')
			if (ee.button.button == SDL_BUTTON_LEFT) { 
				return true;
			} 
		else if (btnStr == 'R') {
			if (ee.button.button == SDL_BUTTON_RIGHT) {
				return true;
			}		
		} 
	}

	return false;
};

char Event::getMouseButtonPressed() {
	if (ee.type == SDL_MOUSEBUTTONDOWN) {
		if (ee.button.button == SDL_BUTTON_RIGHT) {
			return 'R';
		} else if (ee.button.button == SDL_BUTTON_LEFT) {
			return 'L';
		}
	}

	return 'n';

};
