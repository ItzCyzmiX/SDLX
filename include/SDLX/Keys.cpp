#include <SDLX/Keys.hpp>
#include <SDL2/SDL.h>

bool keyHold(int key) {
	const Uint8 * keys = SDL_GetKeyboardState(NULL);

	if (keys[key]) {
		return true;
	}
	else {
		return false;
	}
};
