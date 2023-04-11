#include <iostream>
#include <SDLX/Rect.hpp>

using namespace std;

Rect::Rect(float xpos, float ypos, float wi, float he, int color[3]) {
	width = wi;
	height = he;
	x = xpos;
	y = ypos;


	rect.w = width;
	rect.h = height;
	rect.x = x;
	rect.y = y;

	red = color[0];
	green = color[1];
	blue = color[2];

};

void Rect::draw(SDL_Renderer* r) {
	rect.w = width;
	rect.h = height;
	rect.x = x;
	rect.y = y;
	SDL_SetRenderDrawColor(r, red, green, blue, 255);
	SDL_RenderFillRect(r, &rect);

};

bool Rect::collideRect(Rect obj) {
			
	if (SDL_HasIntersection(&obj.rect, &rect)) {
		return true;
	}
	else {
		return false;
	}

};

bool Rect::collidePoint(float point[2]) {
			
	if (point[0] > x && point[0] < x + width && point[1] > y && point[1] < y + height) {
		return true;
	}
	else {
		return false;
	}

};

bool Rect::collidePoint(float pointX, float pointY) {
			
	if (pointX > x && pointX < x + width && pointY > y && pointY < y + height) {
		return true;
	}
	else {
		return false;
	}

};

void Rect::setColor(int nc[3]) {

	this->red = nc[0];
	this->green = nc[1];
	this->blue = nc[2];

};

int * Rect::getColor() {
	static int rgbVals[] = {red, green, blue};
	return rgbVals;
};

void Rect::setX(float p_x) {
    this->x = p_x;
};

void Rect::setY(float p_y) {
    this->y = p_y;
};

void Rect::moveX(float p_x) {
    this->x += p_x;
};

void Rect::moveY(float p_y) {
    this->y += p_y;
};

void Rect::movePos(float p_x, float p_y) {
    this->x += p_x;
    this->y += p_y;
};

void Rect::setPos(float p_x, float p_y) {
    this->x = p_x;
    this->y = p_y;
};
