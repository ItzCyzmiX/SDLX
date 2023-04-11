#include <SDLX/Draw.hpp>

void drawRect(float x, float y, float width, float height, int color[3], SDL_Renderer* r) {
    int red = color[0];
    int green = color[1];
    int blue = color[2];  
    
    
    SDL_Rect rect;
    
    rect.x = x;
    rect.y = y;
    rect.w = width;
    rect.h = height;
    
    SDL_SetRenderDrawColor(r, red, green, blue, 255);
    SDL_RenderFillRect(r, &rect);
};

void drawLine(float x, float y, float x2, float y2, int color[3], SDL_Renderer* r) {
    int red = color[0];
    int green = color[1];
    int blue = color[2];   
    
    SDL_SetRenderDrawColor(r, red, green, blue, 255);

    SDL_RenderDrawLine(r, x, y, x2, y2);    
};
