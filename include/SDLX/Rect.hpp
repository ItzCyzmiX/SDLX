#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_shape.h>

using namespace std;

class Rect{
	public:
		SDL_Rect rect;
		float width;
		float height;
		float y;
		float x;
		int red, green, blue;

		Rect(float xpos, float ypos, float wi, float he, int color[3]);
		
		void draw(SDL_Renderer* r);
		
		bool collideRect(Rect obj);
		
		bool collidePoint(float point[2]);

		bool collidePoint(float pointX, float pointY);

		void setColor(int nc[3]);

		int * getColor();

                void moveX(float p_x);
                void moveY(float p_y);
                
                void setX(float p_x);
                void setY(float p_y);
                
                void setPos(float p_x, float p_y);
                void movePos(float p_x, float p_y);
};