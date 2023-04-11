#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_shape.h>

using namespace std;

class Line{
	public:
		float y;
		float x;
		float x2;
		float y2;
		int red, green, blue;
		int thikness;

		Line(float xpos, float ypos, float x2pos, float y2pos, int color[3], int p_thikness);
		
		void draw(SDL_Renderer* r);
		
		void setColor(int nc[3]);

		int * getColor();

};