#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDLX/Text.hpp>
#include <iostream>

using namespace std;

Text::Text(SDL_Renderer* r, const char* fontFile, int fontSize, const char* msg, float p_x, float p_y, int p_color[3]) {

	TTF_Font * font = NULL;
	font = TTF_OpenFont(fontFile, fontSize);

	if (font == NULL) {
		cout << "Error opening font!\nError: " << SDL_GetError() << endl;
	}
	
	color.r = p_color[0];
	color.g = p_color[1];
	color.b = p_color[2];

	textSurf = TTF_RenderText_Solid(font, msg, color);
		
    if (textSurf == NULL) {
    	cout << "Error creating text!\nError: " << SDL_GetError() << endl;
    }

	textTexture = SDL_CreateTextureFromSurface(r, textSurf);

	textRect.w = textSurf->w;
	textRect.h = textSurf->h;
	textRect.x = p_x;
	textRect.y = p_y;

	TTF_CloseFont(font);

	setRotationPointToCenter();
}

void Text::kill() {
	if (!killed) {
		SDL_DestroyTexture(textTexture);
		SDL_FreeSurface(textSurf);
		killed = true;
	} else {
		cout << "Text is already killed!\n";
	}
}

void Text::setPos(float p_x, float p_y) {
	textRect.x = p_x;
	textRect.y = p_y; 
}

void Text::setRotationPointToCenter() {
	rotationPoint.x = textRect.w / 2;
	rotationPoint.y = textRect.h / 2;
}

void Text::setRotationPoint(float p_x, float p_y) {
	rotationPoint.x = textRect.x+p_x;
	rotationPoint.y = textRect.y+p_x;
}

void Text::setRotation(float p_angle) {
	angle = p_angle;
}

float Text::getRotation() {
	return angle;
}

void Text::rotateBy(float p_angle) {
	angle += p_angle;
}

void Text::draw(SDL_Renderer* r) {
	textTexture = SDL_CreateTextureFromSurface(r, textSurf);	
	SDL_RenderCopyEx(r, textTexture, NULL, &textRect, angle, &rotationPoint, SDL_FLIP_NONE);
	SDL_DestroyTexture(textTexture);
}

void Text::setColor(int p_color[3]) {
	color.r = p_color[0];
	color.g = p_color[1];
	color.b = p_color[2];
}
