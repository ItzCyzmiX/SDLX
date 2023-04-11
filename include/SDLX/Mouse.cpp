#include <SDL2/SDL.h>
#include <SDLX/Mouse.hpp>

int getMouseY() {
    int x;
    int y;
    
    SDL_GetMouseState(&x, &y);

    return y;

};

int getMouseX() {
    int x;
    int y;
    
    SDL_GetMouseState(&x, &y);

    return x;
};

