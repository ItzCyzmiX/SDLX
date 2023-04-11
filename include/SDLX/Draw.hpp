#include <SDL2/SDL.h>

#ifndef DRAW_HPP
#define DRAW_HPP


void drawRect(float x, float y, float width, float height, int color[3], SDL_Renderer* r);
        
void drawLine(float x, float y, float x2, float y2, int color[3], SDL_Renderer* r);



#endif /* DRAW_HPP */

