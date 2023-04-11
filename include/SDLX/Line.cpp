#include <SDLX/Line.hpp>

Line::Line(float xpos, float ypos, float x2pos, float y2pos, int color[3], int p_thikness) {
	x = xpos;
	y = ypos;
	x2 = x2pos;
	y2 = y2pos;
	thikness = p_thikness;
	red, green, blue = color[0], color[1], color[2];
};

void Line::draw(SDL_Renderer* r) {
	SDL_SetRenderDrawColor(r, red, green, blue, 255);

	SDL_RenderDrawLine(r, x, y, x2, y2);
	
};

void Line::setColor(int nc[3]) {

	this->red = nc[0];
	this->green = nc[1];
	this->blue = nc[2];

};

int * Line::getColor() {
	static int rgbVals[] = {red, green, blue};
	return rgbVals;
};